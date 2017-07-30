include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable (test-add
    test-add.c)
add_test(test-add test-add)

add_executable (test-mul
    test-mul.c)
add_test(test-mul test-mul)
