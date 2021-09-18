#ifndef Options05_h
#define Options05_h
#include "BinModel02.h"
class EurOption {
  private:
    //pointer to payoff function
    double (*Payoff) (double z, double K);
  
  protected:
    //steps to expiry
    int N;

  public:
    void SetN(int N_) {N = N_;}
    void SetPayoff(double (*Payoff_) (double z, double K)) {Payoff = Payoff_;}
    double PriceByCRR(BinModel binmodel, double K);
    double PriceByLooping(BinModel binmodel, double K);
};

//conputing call payoff
double CallPayoff(double z, double K);
//conputing put payoff
double PutPayoff(double z, double K);

class Call: public EurOption {
  private:
    double K; //StrikePrice
  public:
    Call() {SetPayoff(CallPayoff);}
    double GetK() {return K;}
    int GetInputData();
};

class Put: public EurOption {
  private:
    double K; //StrikePrice
  public:
    Put() {SetPayoff(PutPayoff);}
    double GetK() {return K;}
    int GetInputData();
};
#endif // Options05_h
