#include"DoubDigitOpt.h"
#include<iostream>
using namespace std;

double DoubDigitOpt::Payoff(double z) {
  if (K1 < z && z < K2) return 1.0;
  return 0.0;
}

int DoubDigitOpt::GetInputData() {
  cout << "Enter double-digital option data" << endl;
  cout << "Enter steps to expiry N : "; cin >> N;
  double k1, k2;
  cout << "Enter strike price K1 : "; cin >> k1;
  cout << "Enter strike price K2 : "; cin >> k2;
  K1 = max(k1, k2);
  K2 = min(k1, k2);
  if (!(0 < K1 && 0 < K2 && 0 < N)) {
    cout << "strike price and expiry steps count should be positive" << endl;
    return 1;
  }
  cout << endl;
  return 0;
}
