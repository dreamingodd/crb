// example2.cpp
#include "boost/bind.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int sum2(int a, int b){
  return a+b;
}

int sum3(int a, int b, int c){
  return a+b+c;
}

struct P{
  int x, y;
  P(int a=1, int b=9):x(a), y(b){}

  void print(){
    cout << "x:" << x << " y:" << y << endl;
  }
};

int main(){
  int x = 1, y = 2, z = 3;
  cout << boost::bind(sum2, x, y)() << endl; // f(x, y)
  cout << boost::bind(sum3, _1, _2, _3)(x, y, z) << endl; // g(x, y, z)
  cout << boost::bind(sum3, x, _2, x)(z, y, x) << endl; // g(x, y, x), 占位符表示的是实际传入的第几个参数

  vector<P> v(10);
  std::for_each(v.begin(), v.end(), boost::bind(&P::print, _1)); // print: P.x , P.y，当引用成员函数时，占位符第一个总表示对象实例
  return 0;
}
