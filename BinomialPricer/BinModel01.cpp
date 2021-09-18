#include<iostream>
#include<cmath>
using namespace std;

//computing risk-neutral probability
double RiskNeutProb(double U, double D, double R) {
  return (R - U) / (U - D);
}

//computing the stock price at node n, i
double S(double S0, double U, double D, int n, int i) {
  return S0 * pow(1 + U, i) * pow(1 + D, n - i);
}

//inputing, displaying and checking model data
int GetInputData(double& S0, double& U, double& D, double& R) {
  // entering data
  cout << "Enter S0: "; cin >> S0;
  cout << "Enter U: "; cin >> U;
  cout << "Enter D: "; cin >> D;
  cout << "Enter R: "; cin >> R;
  cout << endl;
  if (S0 <= 0.0 || U <= -1.0 || D <= -1.0 || U <= D || R <= -1.0) {
    cout << "Illegal data ranges" << endl;
    cout << "Terminating program" << endl;
    return 1;
  }

  if (R >= U || R <= D) {
    cout << "Arbitrage exists" << endl;
    cout << "Terminating program" << endl;
    return 1;
  }

  cout << "Input data checked" << endl;
  cout << "There is no arbitrage" << endl;
  return 0;
}
