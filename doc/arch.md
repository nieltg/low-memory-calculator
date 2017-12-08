# Naive Calculator Architecture

## Parser

**The parser** is implemented using recursive strategy. The parser is implemented using macros, then it can't retreat to the previous state. The parser is designed not to need any backtracking.

The extended Backus-Naur form (EBNF) of the parser is specified below.

```ebnf
eval1 = eval2, {"+" | "-" | "*" | "/" | "%", eval2}
eval2 = eval3, {"^", eval3}
eval3 = ("r", number) | number

eval = eval1
```

The parser is implmented in [parse/expr.h](../src/parse/expr.h).

## Math Operations

### Addition

**1-bit addition operation**, also known as half-adder, is implemented using XOR bitwise for calculating result bit, and AND bitwise for calculating carry bit.

**1-bit addition with carry operation**, also known as full-adder, is implemented by assembling several half-adders into single unit.

To preserve registers, output of carry bit is represented as sort of "lambda" execution. `_MATH_ADD_FULL_ADDER_STMT` macro accepts 2 parameters and both of them accept statements:

- `carry_stmt0` will be executed if the carry bit is off.
- `carry_stmt1` will be executed if the carry bit is on.

The result is **addition unit** which only uses 1 mutable register and 1 read-only register.

### Multiplication

**Multiplication** is implemented not operating on bits, but on bytes.

There are 2 operations which will be applied based on each bits in the multiplier passed to this multiplication unit:

- **Add by self** if processed the bit is off.
- **Add by self then with second byte** if the bit is on.

The result is **multiplication unit** which uses 2 mutable registers.

### Exponentiation

**Exponentiation** is implemented using same technique with multiplication operation althrough the original idea is implemented in exponentiation operation first.

There are 2 operations which will be applied based on each bits in the exponent passed to this exponentiation unit:

- **Multiply by self** if processed the bit is off.
- **Multiply by self then with second byte** if the bit is on.

The result is **exponentiation unit** which uses 2 mutable registers and 1 temporary register.

### Subtraction

**Subtraction** is implemented by utilizing two-complement number properties.

Negative subtrahend is calculated using known two-complement inversion formula, then the minuend is added by it using previous addition unit.

```
Negative Subtrahend = -Subtrahend = (NOT Subtrahend) + 1
Result = Minuend + Negative Subtrahend
```

The result is **subtraction unit** which uses 2 mutable registers and 1 temporary register.

### Division and Modulus

Division and modulus is implemented using long division technique. Divisor is subtracted with dividend, then subtract it again using shifted dividend, and so on.

There are 2 operations which will be applied based on subtraction status:

- **Minuend is less than subtrahend,** then subtract, shift dividend and set bit to 1.
- **Minuend is bigger than subtrahend,** then shift divident and set bit to 0.

The result is **division unit** which uses 2 mutable registers and 2 temporary register.

### Square Root

Square root is implemented using conditionals because the input domain is small enough.

The result is **square root unit** which uses 1 mutable register.
