#ifndef Options02_h
#define Options02_h
class BinModel {
  private:
    double S0;
    double U;
    double D;
    double R;

  public:
    // conputing risk-neutral probability
    double RiskNeutProb();

    // conputing the stock price at node n, i
    double S(int n, int i);

    //inputting, displaying and checking mnodel data
    int GetInputData();

    double GetR();
};
#endif // !Options02_h
