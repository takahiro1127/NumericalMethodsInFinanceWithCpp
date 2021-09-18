#ifndef Options03_h
#define Options03_h
//inputing and displaying option data
int GetInputData(int& N, double &K);

//pricing European option
double PriceByCRR(double S0, double U, double D, double R, int N, double K, double (*Payoff)(double z, double K));
double PriceByLooping(double S0, double U, double D, double R, int N, double K, double (*Payoff)(double z, double K));

//conputing call payoff
double CallPayoff(double z, double K);
//conputing put payoff
double PutPayoff(double z, double K);
#endif // !Options03_h
