#ifndef Options06_h
#define Options06_h
#include "BinModel02.h"
class EurOption {
  protected:
    //steps to expiry
    int N;
  public:
    void SetN(int N_) {N = N_;}
    virtual double Payoff(double z) {return 0.0;};
    double PriceByCRR(BinModel binmodel);
    double PriceByLooping(BinModel binmodel);
};

class Call: public EurOption {
  private:
    double K; //StrikePrice
  public:
    int GetInputData();
    double Payoff(double z);
};

class Put: public EurOption {
  private:
    double K; //StrikePrice
  public:
    int GetInputData();
    double Payoff(double z);
};

class Bull: public EurOption {
  private:
    double K1; //StrikePrice
    double K2; //StrikePrice
  public:
    int GetInputData();
    double Payoff(double z);
};

class Bear: public EurOption {
  private:
    double K1; //StrikePrice
    double K2; //StrikePrice
  public:
    int GetInputData();
    double Payoff(double z);
};

#endif // Options06_h
