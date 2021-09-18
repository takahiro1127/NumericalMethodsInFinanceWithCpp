#include"BinModel02.h"
#include"Options07.h"
#include<iostream>
#include<cmath>
using namespace std;


int main() {
  BinModel binmodel;
  if (binmodel.GetInputData() == 1) return 1;

  Call Option1;
  Option1.GetInputData();
  cout << "European call option price by CRR  = " << Option1.PriceByCRR(binmodel) << endl;
  cout << "European call option price by looping  = " << Option1.PriceByLooping(binmodel) << endl;
  cout << "American call option price by snell  = " << Option1.PriceBySnell(binmodel) << endl;
  return 0;
}
