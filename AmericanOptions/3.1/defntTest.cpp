#include"DefInt.cpp"
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
double square(double x) {
  return pow(x, 2);
}
int main() {
  int a = 0;
  int b = 1;
  DefInt MyInt(a, b, square);
  cout << "calc by trapezoid" << MyInt.Trapezoidal(200) << endl;
  cout << "calc by simpson" << MyInt.Simpson() << endl;
}
