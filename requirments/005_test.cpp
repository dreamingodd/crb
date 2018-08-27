// example5.cpp
#define BOOST_TEST_MODULE mytest
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(mytest)

BOOST_AUTO_TEST_CASE(test1){
  BOOST_CHECK( false );
}

BOOST_AUTO_TEST_CASE(test2){
  typedef enum {red = 8, blue, green = 1, yellow, black } color;
  color c = green;
  std::cout << "Char size: " << sizeof(char) << '\n';
  std::cout << "green size:" << sizeof(green)<< '\n';
  BOOST_WARN(sizeof(green) > sizeof(char));
  BOOST_CHECK(c == 2); // BOOST_CHECK断言失败继续执行
  BOOST_REQUIRE(yellow > red); //BOOST_REQUIRE断言失败，测试停止
  BOOST_CHECK(black != 4);
}

BOOST_AUTO_TEST_SUITE_END()

/*
g++ example5.cpp -lboost_unit_test_framework
./a.out
Running 2 test case...
example5.cpp(15): error in "test2": check c == 2 failed
example5.cpp(16): fatal error in "test2": critical check yellow > red failed

*** 2 failures detected in test suite "mytest"
*/
