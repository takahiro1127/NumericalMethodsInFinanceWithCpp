#ifndef Options07_h
#define Options07_h
#include "BinModel02.h"
class EurOption {
  protected:
    //steps to expiry
    int N;
  public:
    virtual double Payoff(double z) {return 0.0;};
    double PriceByCRR(BinModel binmodel);
    double PriceByLooping(BinModel binmodel);
};

class AmOption {
  protected:
    //steps to expiry
    int N;
  public:
    virtual double Payoff(double z) = 0;
    double PriceBySnell(BinModel binmodel);
};

class Call: public EurOption, public AmOption {
  private:
    double K; //StrikePrice
  public:
    int GetInputData();
    double Payoff(double z);
};

class Put: public EurOption, public AmOption {
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

#endif // Options07_h
