#ifndef solver_h
#define solver_h
#include <math.h>
#include <vector>
#include <string>
#include  <iostream>
#include "Eigen\Dense"
#include "Constants.h"
#include "AuxFuncs.h"
#include "Experiment.h"
using Eigen::MatrixXd;
double chi2(std::vector <double> u2, std::vector<double> u4, std::vector <double> u6, std::vector <double> lambda0,double n,double TwoJPlusOne,double o2, double o4, double o6, std::vector <double> fexp);
double chi2Solarz(std::vector <double> u2, std::vector<double> u4, std::vector <double> u6, std::vector <double> lambda0,double n,double TwoJPlusOne,double o2, double o4, double o6, std::vector <double> fexp);
double Residue(double fexp, double o2, double o4, double o6,double u2, double u4, double u6, double lambda, double n, double TwoJPlusOne);
void CalculateHessian(std::vector <double> u2, std::vector<double> u4, std::vector <double> u6, std::vector <double> lambda0,double n,double TwoJPlusOne,double o2, double o4, double o6, std::vector <double> fexp, MatrixXd &Hess, MatrixXd &Grad);
void FitLM(std::vector <double> u2, std::vector<double> u4, std::vector <double> u6, std::vector <double> lambda0,double n,double TwoJPlusOne,double &o2, double &o4, double &o6, std::vector <double> fexp,System::String^ &MSG,System::String^ &LATEX);
void FitSolarz(std::vector <double> u2, std::vector<double> u4, std::vector <double> u6, std::vector <double> lambda0,double n,double TwoJPlusOne,double &o2, double &o4, double &o6, std::vector <double> fexp,System::String^ &MSG,System::String^ &LATEX);
void FitBranching(Experiment &BExp,System::String^ &MSG,System::String^ &LATEX);

//void CalculateRates(std::vector <double> u2, std::vector<double> u4, std::vector <double> u6, double TwoJPlusOne, std::vector <double> lambda0,double n,double o2, double o4, double o6, std::vector <double> &a)
//{
//	int size;
//	double rate;
//	size=u2.size();
//	a.clear();
//	for(int i=0;i<size;i++){
//		rate=((64*pow(pi,4)*qe*qe)/(3*h*pow(lambda0[i],3)*TwoJPlusOne))*(n*pow(n*n+2,2)/9)*(u2[i]*o2+u4[i]*o4+u6[i]*o6);
//		cout <<1e7*lambda0[i] <<" "<< rate <<endl;
//		a.push_back(rate);
//	}
//}
#endif