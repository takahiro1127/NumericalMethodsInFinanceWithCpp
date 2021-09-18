#include"BinModel01.h"
#include<iostream>
#include<cmath>
using namespace std;


int main() {
  double S0, U, D, R;
  if (GetInputDate(S0, U, D, R) == 1) return 1;
  cout << "q = " << RiskNeutProb(U, D, R) << endl;

  int n, i;
  cout << "Enter n: "; cin >> n;
  cout << "Enter i: "; cin >> i;
  cout << endl;
  cout << "S(n, i) = " << S(S0, U, D, n, i) << endl;
  return 0;
}
