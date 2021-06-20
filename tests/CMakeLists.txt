enable_testing()

add_executable(1 createBigInt1.c ${src})
add_test(CreateBigInt1 1)

add_executable(2 createBigInt2.c ${src})
add_test(CreateBigInt2 2)

add_executable(3 createBigInt3.c ${src})
add_test(CreateBigInt3 3)

add_executable(4 createBigInt4.c ${src})
add_test(CreateBigInt4 4)

add_executable(1a arithmeticBigInt1.c ${src})
add_test(ArithmeticBigInt1 1a)

add_executable(2a arithmeticBigInt2.c ${src})
add_test(ArithmeticBigInt2 2a)

add_executable(3a arithmeticBigInt3.c ${src})
add_test(ArithmeticBigInt3 3a)

add_executable(4a arithmeticBigInt4.c ${src})
add_test(ArithmeticBigInt4 4a)

add_executable(5a arithmeticBigInt5.c ${src})
add_test(ArithmeticBigInt5 5a)

add_executable(6a arithmeticBigInt6.c ${src})
add_test(ArithmeticBigInt6 6a)