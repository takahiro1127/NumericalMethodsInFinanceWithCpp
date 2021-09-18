#ifndef BinLattice01_h
#define BinLattice01_h
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class BinLattice {
  private:
    int N;
    vector<vector<double> > Lattice;

  public:
    void SetN(int N_) {
      N = N_;
      Lattice.resize(N+1);
      // 二項モデルなら、各n期にn個のnodeしか存在しないはずなので、vectorのサイズを変更しても良い
      for (int i = 0; i < N + 1; i++) Lattice[i].resize(i + 1);
    }

    void SetNode(int n, int i, double x) {
      Lattice[n][i] = x;
    }

    double GetNode(int n, int i) {
      return Lattice[n][i];
    }

    void Display() {
      cout << setiosflags(ios::fixed) << setprecision(3);
      for (int n = 0; n < N + 1; n++) {
        for (int i = 0; i < n + 1; i++) {
          cout << setw(7) << GetNode(n, i);
          cout << endl;
        }
      }
      cout << endl;
    }
};
# endif // BinLattice01_h
