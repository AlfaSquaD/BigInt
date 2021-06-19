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

add_executable(test9 addStringTest1.c ${src})
add_test(AddString1 test9)

add_executable(test12 addStringTest2.c ${src})
add_test(AddString2 test12)

add_executable(test13 addStringTest3.c ${src})
add_test(AddString3 test13)

add_executable(test14 addStringTest4.c ${src})
add_test(AddString4 test14)

add_executable(test10 wrongAddStringTest1.c ${src})
add_test(WrongAdd test10)

add_executable(test11 wrongAddStringTest2.c ${src})
add_test(WrongAdd2 test11)

add_executable(test15 subStringTest1.c ${src})
add_test(SubString1 test15)

