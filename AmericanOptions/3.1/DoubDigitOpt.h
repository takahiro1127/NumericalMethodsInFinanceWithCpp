#ifndef DoubDigitOpt_h
#define DoubDigitOpt_h
#include "Options06.h"
class DoubDigitOpt: public EurOption {
  private:
    double K1;
    double K2;
  public:
    int GetInputData();
    double Payoff(double z);
};

#endif // DoubDigitOpt_h
