// Generated by Top2HPlus using FeynHiggs input
// http://cmsdoc.cern.ch/~slehti/Top2HPlus.git

#include <vector>

double fitFunction(double *x,double *par){
  return par[0]*x[0]*x[0] + par[1]*x[0] + par[2];
}

struct Parameters {
  void clear(){ mass = 0; mu = 0; fitParameters.clear();}
  double mass;
  double mu;
  std::vector<double> fitParameters;
};

double BR_top_Hplus_function(double mass,double tanb,double mu){
  std::vector<Parameters> fPars;
  Parameters fPar;
  fPar.mass = 90;
  fPar.mu   = -1000;
  fPar.fitParameters.push_back(0.000516889);
  fPar.fitParameters.push_back(-0.00757381);
  fPar.fitParameters.push_back(0.0514848);
  fPars.push_back(fPar);
  fPar.clear();

  fPar.mass = 90;
  fPar.mu   = -200;
  fPar.fitParameters.push_back(0.000220487);
  fPar.fitParameters.push_back(-0.00264012);
  fPar.fitParameters.push_back(0.0302147);
  fPars.push_back(fPar);
  fPar.clear();

  fPar.mass = 90;
  fPar.mu   = 200;
  fPar.fitParameters.push_back(9.86366e-05);
  fPar.fitParameters.push_back(-0.000296194);
  fPar.fitParameters.push_back(0.0182434);
  fPars.push_back(fPar);
  fPar.clear();

  fPar.mass = 90;
  fPar.mu   = 1000;
  fPar.fitParameters.push_back(3.14252e-05);
  fPar.fitParameters.push_back(0.000646076);
  fPar.fitParameters.push_back(0.0132899);
  fPars.push_back(fPar);
  fPar.clear();

  fPar.mass = 100;
  fPar.mu   = -1000;
  fPar.fitParameters.push_back(0.000433977);
  fPar.fitParameters.push_back(-0.00632324);
  fPar.fitParameters.push_back(0.0429652);
  fPars.push_back(fPar);
  fPar.clear();

  fPar.mass = 100;
  fPar.mu   = -200;
  fPar.fitParameters.push_back(0.000155348);
  fPar.fitParameters.push_back(-0.00126122);
  fPar.fitParameters.push_back(0.0195178);
  fPars.push_back(fPar);
  fPar.clear();

  fPar.mass = 100;
  fPar.mu   = 200;
  fPar.fitParameters.push_back(6.39473e-05);
  fPar.fitParameters.push_back(0.00048372);
  fPar.fitParameters.push_back(0.0102208);
  fPars.push_back(fPar);
  fPar.clear();

  fPar.mass = 100;
  fPar.mu   = 1000;
  fPar.fitParameters.push_back(2.73105e-05);
  fPar.fitParameters.push_back(0.000517489);
  fPar.fitParameters.push_back(0.0112916);
  fPars.push_back(fPar);
  fPar.clear();

  fPar.mass = 120;
  fPar.mu   = -1000;
  fPar.fitParameters.push_back(0.000313336);
  fPar.fitParameters.push_back(-0.0049744);
  fPar.fitParameters.push_back(0.0319866);
  fPars.push_back(fPar);
  fPar.clear();

  fPar.mass = 120;
  fPar.mu   = -200;
  fPar.fitParameters.push_back(9.86914e-05);
  fPar.fitParameters.push_back(-0.000739603);
  fPar.fitParameters.push_back(0.0113937);
  fPars.push_back(fPar);
  fPar.clear();

  fPar.mass = 120;
  fPar.mu   = 200;
  fPar.fitParameters.push_back(4.49664e-05);
  fPar.fitParameters.push_back(0.000146789);
  fPar.fitParameters.push_back(0.00724258);
  fPars.push_back(fPar);
  fPar.clear();

  fPar.mass = 120;
  fPar.mu   = 1000;
  fPar.fitParameters.push_back(1.80432e-05);
  fPar.fitParameters.push_back(0.00028589);
  fPar.fitParameters.push_back(0.00721618);
  fPars.push_back(fPar);
  fPar.clear();

  fPar.mass = 140;
  fPar.mu   = -1000;
  fPar.fitParameters.push_back(0.000159154);
  fPar.fitParameters.push_back(-0.00266406);
  fPar.fitParameters.push_back(0.0166828);
  fPars.push_back(fPar);
  fPar.clear();

  fPar.mass = 140;
  fPar.mu   = -200;
  fPar.fitParameters.push_back(5.38423e-05);
  fPar.fitParameters.push_back(-0.000618311);
  fPar.fitParameters.push_back(0.00700487);
  fPars.push_back(fPar);
  fPar.clear();

  fPar.mass = 140;
  fPar.mu   = 200;
  fPar.fitParameters.push_back(2.26846e-05);
  fPar.fitParameters.push_back(-4.95833e-06);
  fPar.fitParameters.push_back(0.00381163);
  fPars.push_back(fPar);
  fPar.clear();

  fPar.mass = 140;
  fPar.mu   = 1000;
  fPar.fitParameters.push_back(8.60687e-06);
  fPar.fitParameters.push_back(0.000112783);
  fPar.fitParameters.push_back(0.00346638);
  fPars.push_back(fPar);
  fPar.clear();

  fPar.mass = 160;
  fPar.mu   = -1000;
  fPar.fitParameters.push_back(2.93721e-05);
  fPar.fitParameters.push_back(-0.000506348);
  fPar.fitParameters.push_back(0.00324964);
  fPars.push_back(fPar);
  fPar.clear();

  fPar.mass = 160;
  fPar.mu   = -200;
  fPar.fitParameters.push_back(1.04431e-05);
  fPar.fitParameters.push_back(-0.000145629);
  fPar.fitParameters.push_back(0.00157789);
  fPars.push_back(fPar);
  fPar.clear();

  fPar.mass = 160;
  fPar.mu   = 200;
  fPar.fitParameters.push_back(4.14747e-06);
  fPar.fitParameters.push_back(-1.03944e-05);
  fPar.fitParameters.push_back(0.00083553);
  fPars.push_back(fPar);
  fPar.clear();

  fPar.mass = 160;
  fPar.mu   = 1000;
  fPar.fitParameters.push_back(1.52205e-06);
  fPar.fitParameters.push_back(1.57684e-05);
  fPar.fitParameters.push_back(0.00073166);
  fPars.push_back(fPar);
  fPar.clear();

  Parameters massMuPoint;
  for(int i = 0; i < fPars.size(); ++i){
    if(fPars[i].mass != mass || fPars[i].mu != mu) continue;
    massMuPoint = fPars[i];
  }

  int nPar = massMuPoint.fitParameters.size();
  double parameters[nPar];
  for(int i = 0; i < nPar; ++i){
    parameters[i] = massMuPoint.fitParameters[i];
  }

  return fitFunction(&tanb,parameters);
}