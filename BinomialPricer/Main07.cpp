#include"BinModel01.h"
#include"Options03.h"
#include<iostream>
#include<cmath>
using namespace std;


int main() {
  double S0, U, D, R;
  if (GetInputData(S0, U, D, R) == 1) return 1;
  double K; //stock price
  int N; //steps to expiry

  cout << "European call option data : " << endl;
  GetInputData(N, K);

  cout << "European call option price by CRR  = " << PriceByCRR(S0, U, D, R, N, K, CallPayoff) << endl;
  cout << "European call option price by looping  = " << PriceByLooping(S0, U, D, R, N, K, CallPayoff) << endl;
  return 0;
}
