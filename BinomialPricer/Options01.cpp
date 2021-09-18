#include"Options01.h"
#include"BinModel01.h"
#include<iostream>
#include<cmath>
using namespace std;

int GetInputData(int &N, double &K) {
  cout << "Enter steps to expiry N : "; cin >> N;
  cout << "Enter strike price K : "; cin >> K;
  if (!(0 < K && 0 < N)) {
    cout << "strike price and expiry steps count should be positive" << endl;
    return 1;
  }
  cout << endl;
  return 0;
}

double CallPayoff(double z, double K) {
  if (z > K) return z - K;
  return 0.0;
}

double DiscountFactor(double rate, int TermCount) {
  return pow(1 + rate, TermCount);
}

double combination(int n, int k) {
  if (n == k || k == 0)
    return 1;
  else {
    return combination(n - 1, k - 1) + combination(n - 1, k);
  }
}

double Probability(int TermCount, int count_of_occurrences, double probability) {
  // todo 階乗を実装
  return combination(TermCount, count_of_occurrences) * pow(probability, count_of_occurrences) * pow(1 - probability, TermCount - count_of_occurrences);
}

double PriceByLooping(double S0, double U, double D, double R, int N, double K) {
  double q = RiskNeutProb(U, D, R);
  double Price[N+1];
  for (int i = 0; i < N + 1; i++) {
    //N期後のpayoffをi(上昇回数)を全通り試しながら計算している。
    Price[i] = CallPayoff(S(S0, U, D, N, i), K);
  }
  for (int n = N - 1; n >= 0; n--) {
    for (int i = 0; i < n + 1; i++) {
      //N期目のpayOffの種類数(S0の種類数)はN個である。
      //N - 1期目のpriceはN期目のpayOffの期待値である。
      //端っこのnodeの方がN - 1 → 0の過程の中での参照回数が少ない。なぜなら端っこのnodeにしか認知されないから。
      //真ん中のnodeは色々なnodeに認知されている、つまり参照回数が多い。
      //↑参照回数のロジックは、codeで見るよりも、図に書いた方がわかりやすい。
      //参照回数 = 生起確率である。
      Price[i] = (q * Price[i + 1] + (1 - q) * Price[i]) / (1 + R);
    }
  }
  return Price[0];
}

double PriceByCRR(double S0, double U, double D, double R, int N, double K) {
  double q = RiskNeutProb(U, D, R);
  double d = DiscountFactor(R, N);
  double Price;
  for (int i = 0; i < N + 1; i++) {
    Price += d * Probability(N, i, q) * CallPayoff(S(S0, U, D, N, i), K);
  }
  return Price;
}
