#ifndef Options08_h
#define Options08_h
#include "BinModel02.h"
class Option {
  protected:
    //steps to expiry
    int N;
  public:
    virtual double Payoff(double z) = 0;
    int GetN() {return N;};

};
class EurOption: public virtual Option {
  public:
    double PriceByCRR(BinModel binmodel);
    double PriceByLooping(BinModel binmodel);
};

class AmOption: public virtual Option {
  public:
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

#endif // Options08_h
