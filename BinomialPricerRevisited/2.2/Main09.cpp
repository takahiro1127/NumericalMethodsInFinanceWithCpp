#include"BinModel02.h"
#include"Options05.h"
#include<iostream>
#include<cmath>
using namespace std;


int main() {
  BinModel binmodel;
  if (binmodel.GetInputData() == 1) return 1;

  Call Option1;
  cout << "European call option data : " << endl;
  Option1.GetInputData();
  cout << "European call option price by CRR  = " << Option1.PriceByCRR(binmodel, Option1.GetK()) << endl;
  cout << "European call option price by looping  = " << Option1.PriceByLooping(binmodel, Option1.GetK()) << endl;
  return 0;
}
