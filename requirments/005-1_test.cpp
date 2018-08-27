// example5_2.cpp
#define BOOST_TEST_MODULE mytest
#include <boost/test/included/unit_test.hpp>
#include <iostream>

struct F{
  F(){std::cout << "setup" << '\n';}
  ~F(){std::cout << "teardown" << '\n';}
};

BOOST_AUTO_TEST_SUITE(mytest)
// BOOST_FIXTURE_TEST_SUITE(mytest, F)， 也可以直接为该Suite中所有的Case都配置F上下文

// CASE执行前先调用F()，执行完后调用~F()
BOOST_FIXTURE_TEST_CASE(test1, F){ 
  BOOST_CHECK( true );
}

//test2不受影响
BOOST_AUTO_TEST_CASE(test2){
  typedef enum {red = 8, blue, green = 1, yellow, black } color;
  color c = green;
  BOOST_WARN(sizeof(green) > sizeof(char));
  BOOST_CHECK(c == 2); // BOOST_CHECK断言失败继续执行
  BOOST_REQUIRE(yellow > red); //BOOST_REQUIRE断言失败，测试停止
  BOOST_CHECK(black != 4);
}

BOOST_AUTO_TEST_SUITE_END()
