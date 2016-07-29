#ifndef solver_h
#define solver_h
#include <math.h>
#include <vector>
#include <string>
#include  <iostream>
#include "Eigen\Dense"
#include "Constants.h"
#include "AuxFuncs.h"
using namespace std;
using Eigen::MatrixXd;
double chi2(vector <double> u2, vector<double> u4, vector <double> u6, vector <double> lambda0,double n,double twojplusone,double o2, double o4, double o6, vector <double> fexp);
double chi2Solarz(vector <double> u2, vector<double> u4, vector <double> u6, vector <double> lambda0,double n,double twojplusone,double o2, double o4, double o6, vector <double> fexp);
double Residue(double fexp, double o2, double o4, double o6,double u2, double u4, double u6, double lambda, double n, double twojplusone);
void CalculateHessian(vector <double> u2, vector<double> u4, vector <double> u6, vector <double> lambda0,double n,double twojplusone,double o2, double o4, double o6, vector <double> fexp, MatrixXd &Hess, MatrixXd &Grad);
void FitLM(vector <double> u2, vector<double> u4, vector <double> u6, vector <double> lambda0,double n,double twojplusone,double &o2, double &o4, double &o6, vector <double> fexp,System::String^ &MSG,System::String^ &LATEX);
void FitSolarz(vector <double> u2, vector<double> u4, vector <double> u6, vector <double> lambda0,double n,double twojplusone,double &o2, double &o4, double &o6, vector <double> fexp,System::String^ &MSG,System::String^ &LATEX);

//void CalculateRates(vector <double> u2, vector<double> u4, vector <double> u6, double twojplusone, vector <double> lambda0,double n,double o2, double o4, double o6, vector <double> &a)
//{
//	int size;
//	double rate;
//	size=u2.size();
//	a.clear();
//	for(int i=0;i<size;i++){
//		rate=((64*pow(pi,4)*qe*qe)/(3*h*pow(lambda0[i],3)*twojplusone))*(n*pow(n*n+2,2)/9)*(u2[i]*o2+u4[i]*o4+u6[i]*o6);
//		cout <<1e7*lambda0[i] <<" "<< rate <<endl;
//		a.push_back(rate);
//	}
//}
#endif