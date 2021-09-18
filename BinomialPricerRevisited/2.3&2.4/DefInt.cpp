#include<iostream>
using namespace std;
typedef long long ll;
class DefInt {
  public:
    DefInt(double a_, double b_, double (*integrand_) (double x)) {
      a = min(a_, b_);
      b = max(a_, b_);
      integrand = integrand_;
    }
    double Trapezoidal(int N) {
      double h = (b - a) / N;
      double sum_of_edge_length = integrand(a) + integrand(b);
      for (double start = a + h; start < b; start += h) {
        sum_of_edge_length += integrand(start) * 2;
      }
      return (h / 2) * sum_of_edge_length;
    }

    double Simpson() {
      return ((b - a) / 6) * (integrand(a) + 4 * integrand((a + b) / 2) + integrand(b));
    }
  private:
    double a, b;
    double (*integrand) (double x);
};
