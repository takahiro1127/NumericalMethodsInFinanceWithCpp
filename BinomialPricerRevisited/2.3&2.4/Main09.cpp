#include"BinModel02.h"
#include"Options06.h"
#include<iostream>
#include<cmath>
using namespace std;


int main() {
  BinModel binmodel;
  if (binmodel.GetInputData() == 1) return 1;

  Call Option1;
  cout << "European call option data : " << endl;
  Option1.GetInputData();
  cout << "European call option price by CRR  = " << Option1.PriceByCRR(binmodel) << endl;
  cout << "European call option price by looping  = " << Option1.PriceByLooping(binmodel) << endl;
  return 0;
}
