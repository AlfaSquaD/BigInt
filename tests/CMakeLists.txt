cmake_minimum_required(VERSION 3.16)
project(BigInt C)

set(CMAKE_C_STANDARD 99)

enable_testing()

add_executable(test1 createreadtest.c ${src})
add_test(CreateReadTest test1)

add_executable(test2 createreadtest_negative.c ${src})
add_test(CreateReadTestNegative test2)

add_executable(test3 zeroskiptest.c ${src})
add_test(ZeroSkipCheck test3)

add_executable(test4 comparetest1.c ${src})
add_test(CompareTest1 test4)

add_executable(test5 comparetest2.c ${src})
add_test(CompareTest2 test5)

add_executable(test6 comparetest3.c ${src})
add_test(CompareTest3 test6)

add_executable(test7 comparetest4.c ${src})
add_test(CompareTest4 test7)

add_executable(test8 createzero.c ${src})
add_test(CreateZeroTest test8)