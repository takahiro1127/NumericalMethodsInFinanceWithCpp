#include"BinModel02.h"
#include"Options04.h"
#include<iostream>
#include<cmath>
using namespace std;


int main() {
  BinModel binmodel;
  if (binmodel.GetInputData() == 1) return 1;
  double K; //stock price
  int N; //steps to expiry

  cout << "European call option data : " << endl;
  GetInputData(N, K);
  cout << "European call option price by CRR  = " << PriceByCRR(binmodel, N, K, CallPayoff) << endl;
  cout << "European call option price by looping  = " << PriceByLooping(binmodel, N, K, CallPayoff) << endl;
  return 0;
}
