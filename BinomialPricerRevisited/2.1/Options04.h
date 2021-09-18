#ifndef Options04_h
#define Options04_h
#include "BinModel02.h"
//inputing and displaying option data
int GetInputData(int& N, double &K);

//pricing European option
double PriceByCRR(BinModel binmodel, int N, double K, double (*Payoff)(double z, double K));
double PriceByLooping(BinModel binmodel, int N, double K, double (*Payoff)(double z, double K));

//conputing call payoff
double CallPayoff(double z, double K);
//conputing put payoff
double PutPayoff(double z, double K);

#endif // Options04_h
