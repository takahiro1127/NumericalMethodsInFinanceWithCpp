#include"Options08.h"
#include"BinModel02.h"
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
typedef long long ll;

double Put::Payoff(double z) {
  if (z < K) return K - z;
  return 0.0;
}

double Call::Payoff(double z) {
  if (z > K) return z - K;
  return 0.0;
}

double Bull::Payoff(double z) {
  if (z < K1) return 0.0;
  if (z < K2) return z - K1;
  return K2 - K1;
}

double Bear::Payoff(double z) {
  if (K2 < z) return 0.0;
  if (K1 < z) return K2 - z;
  return K2 - K1;
}

double DiscountFactor(double rate, int TermCount) {
  return 1 / pow(1 + rate, TermCount);
}

long long comb(long long n, long long k) {
  if (n == k || k == 0)
    return 1;
  else {
    return comb(n - 1, k - 1) + comb(n - 1, k);
  }
}

double Probability(int TermCount, int count_of_occurrences, double probability) {
  return comb(TermCount, count_of_occurrences) * pow(probability, count_of_occurrences) * pow(1 - probability, TermCount - count_of_occurrences);
}

double EurOption::PriceByCRR(BinModel binmodel) {
  double q = binmodel.RiskNeutProb();
  double d = DiscountFactor(binmodel.GetR(), N);
  double Price;
  for (int i = 0; i < N + 1; i++) {
    Price += d * Probability(N, i, q) * Payoff(binmodel.S(N, i));
  }
  return Price;
}

double EurOption::PriceByLooping(BinModel binmodel) {
  double q = binmodel.RiskNeutProb();
  double Price[N+1];
  for (int i = 0; i < N + 1; i++) {
    //N期後のpayoffをi(上昇回数)を全通り試しながら計算している。
    Price[i] = Payoff(binmodel.S(N, i));
  }
  for (int n = N - 1; n >= 0; n--) {
    for (int i = 0; i < n + 1; i++) {
      //N期目のpayOffの種類数(S0の種類数)はN個である。
      //N - 1期目のpriceはN期目のpayOffの期待値である。
      //端っこのnodeの方がN - 1 → 0の過程の中での参照回数が少ない。なぜなら端っこのnodeにしか認知されないから。
      //真ん中のnodeは色々なnodeに認知されている、つまり参照回数が多い。
      //↑参照回数のロジックは、codeで見るよりも、図に書いた方がわかりやすい。
      //参照回数 = 生起確率である。
      Price[i] = (q * Price[i + 1] + (1 - q) * Price[i]) / (1 + binmodel.GetR());
    }
  }
  return Price[0];
}

double AmOption::PriceBySnell(BinModel binmodel) {
  double q = binmodel.RiskNeutProb();
  vector<double> Price(N + 1);
  double ContVal;
  for (int i = 0;  i < N+1; i++) {
    Price[i] = Payoff(binmodel.S(N, i));
  }
  for (int n = N - 1; n >= 0; n--) {
    for (int i = 0; i < N + 1; i++) {
      ContVal = (q * Price[i + 1] + (1 - q) * Price[i]) / (1 + binmodel.GetR());
      Price[i] = Payoff(binmodel.S(n, i));
      if (ContVal > Price[i]) Price[i] = ContVal;
    }
  }
  return Price[0];
}

int Call::GetInputData() {
  cout << "Enter call option data" << endl;
  cout << "Enter steps to expiry N : "; cin >> N;
  cout << "Enter strike price K : "; cin >> K;
  if (!(0 < K && 0 < N)) {
    cout << "strike price and expiry steps count should be positive" << endl;
    return 1;
  }
  cout << endl;
  return 0;
}

int Put::GetInputData() {
  cout << "Enter put option data" << endl;
  cout << "Enter steps to expiry N : "; cin >> N;
  cout << "Enter strike price K : "; cin >> K;
  if (!(0 < K && 0 < N)) {
    cout << "strike price and expiry steps count should be positive" << endl;
    return 1;
  }
  cout << endl;
  return 0;
}

int Bull::GetInputData() {
  cout << "Enter bull option data" << endl;
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

int Bear::GetInputData() {
  cout << "Enter bear option data" << endl;
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
