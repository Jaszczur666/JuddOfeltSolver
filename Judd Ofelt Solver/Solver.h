#include <math.h>
#include <vector>
#include <string>
#include  <iostream>
#include "Eigen\Dense"
using namespace std;
double const pi=3.141592653589793238462643383279502884;
double const m=9.1093897e-28;//SI 9.10938291e-31;
double const c=2.99792458e10;//SI 299792458;
double const h=6.6260755e-27; //SI6.62606957e-34;
double const qe=4.8032068e-10;
using Eigen::MatrixXd;

double f(double u2, double u4, double u6, double lambda0,double n,double twojplusone ,double o2, double o4, double o6)
{
	return (((pow(n*n+2,2)/(9*n))*(8*pi*pi*m*c))/(3*h*twojplusone*lambda0))*(u2*o2+u4*o4+u6*o6);
};

double sellmeier(double a, double b, double c, double d, double lambda)
{
return sqrt(a+b/(lambda*lambda-c)-d*lambda*lambda);
};

double chi2(vector <double> u2, vector<double> u4, vector <double> u6, vector <double> lambda0,double n,double twojplusone,double o2, double o4, double o6, vector <double> fexp)
{
int size;
double tempchi2=0;
size=u2.size();
for (int i=0;i<size;i++){
tempchi2=tempchi2+pow(f(u2[i],u4[i],u6[i],lambda0[i],n,twojplusone,o2,o4,o6)-fexp[i],2);
};
return tempchi2;
};

double Residue(double fexp, double o2, double o4, double o6,double u2, double u4, double u6, double lambda, double n, double twojplusone)
{
	return f(u2,u4,u6,lambda, n,twojplusone,o2, o4,o6)-fexp;
};

void CalculateHessian(vector <double> u2, vector<double> u4, vector <double> u6, vector <double> lambda0,double n,double twojplusone,double o2, double o4, double o6, vector <double> fexp, MatrixXd &Hess, MatrixXd &Grad)
{
	int i,size;
	MatrixXd Hessian;
	double ro2,ro4,ro6,res,delta;
	size=u2.size();
	MatrixXd Res(size,1);
	delta=1e-28;
	MatrixXd Jaco(size,3);
	//cout <<"Debug " <<o2<<" "<<o4<<" "<<o6<<endl;
	for (i=0;i<size;i++){
	res=Residue(fexp[i], o2, o4, o6,u2[i], u4[i], u6[i], lambda0[i],n,twojplusone);
	ro2=Residue(fexp[i], o2+delta, o4, o6,u2[i], u4[i], u6[i], lambda0[i],n,twojplusone);
	ro4=Residue(fexp[i], o2, o4+delta, o6,u2[i], u4[i], u6[i], lambda0[i],n,twojplusone);
	ro6=Residue(fexp[i], o2, o4, o6+delta,u2[i], u4[i], u6[i], lambda0[i],n,twojplusone);
	Jaco(i,0)=(ro2-res)/delta;
	Jaco(i,1)=(ro4-res)/delta;
	Jaco(i,2)=(ro6-res)/delta;
	Res(i,0)=res;
	};
	Hess=Jaco.transpose()*Jaco;
	Grad=Jaco.transpose()*Res;
//	cout <<"_________________________________"<<endl;
//	cout << Hess<<endl;
//	cout <<"_________________________________"<<endl;
};

void FitLM(vector <double> u2, vector<double> u4, vector <double> u6, vector <double> lambda0,double n,double twojplusone,double &o2, double &o4, double &o6, vector <double> fexp,System::String^ &MSG)
{
MatrixXd Hessian,Hessiandiag;
MatrixXd Grad;
MatrixXd parameters(3,1);
MatrixXd newparams(3,1);
MatrixXd error(3,1);
parameters<<o2,o4,o6;
double no2,no4,no6,sumfexp,sumdfexp;
double lambda,chi2s,chi2n;
	lambda=1/1024.0;
	sumdfexp=0;
	sumfexp=0;
	chi2s=0;
	MSG+="Num.      \tChi2              \tO2                 \tO4               \tO6\r\n";
	cout <<"Beginnig fitting procedure."<<endl;
	for(int i=1;i<5;i++)
	{
	chi2s=chi2(u2,u4,u6,lambda0,n,twojplusone,o2,o4,o6,fexp);
	CalculateHessian(u2,u4,u6,lambda0,n,twojplusone,o2, o4, o6, fexp, Hessian,Grad);
	Hessiandiag=Hessian.diagonal().asDiagonal();
	newparams=parameters-((Hessian+lambda*Hessiandiag).inverse()*Grad);
	no2=newparams(0,0);
	no4=newparams(1,0);
	no6=newparams(2,0);
	chi2n=chi2(u2,u4,u6,lambda0,n,twojplusone,no2,no4,no6,fexp);
	cout<< i <<" "<< chi2s <<" " <<no2<<" "<<no4<<" "<<no6<<endl;
	MSG+=i.ToString()+"\t"+chi2s.ToString("G6")+"\t"+no2.ToString("G6")+"\t"+no4.ToString("G6")+"\t"+no6.ToString("G6")+"\r\n";
		if (chi2n<chi2s){
			parameters=newparams;
			o2=no2;
			o4=no4;
			o6=no6;
			lambda=lambda*1.1;
			}
		else
		{
			lambda=lambda/1.1;
		}
	};
	cout <<"Fitting finished"<<endl;
	MSG+="Fitting finished \r\n";
	int size=u2.size();
	error=(Hessiandiag.inverse().diagonal()*chi2n/(size-3));
	for (int i=0;i<3;i++) error(i)=sqrt(error(i));
	cout <<"Errors "<< error(0)<<" "<<error(1)<<" "<< error(2)<<endl;
	MSG+="Parameters\t o2="+o2.ToString("G4")+"\t o4="+o4.ToString("G4")+"\t o6="+o6.ToString("G4")+"\r\n";
	MSG+="Errors \t do2="+error(0).ToString("G2")+"\t do4="+error(1).ToString("G2")+"\t do6="+error(2).ToString("G2")+"\r\n";
	cout << "Relative errors " << 100*error(0)/o2 <<"% "<<100*error(1)/o4 <<"% "<<100*error(2)/o6<<"%"<<endl;
	MSG+="Relative errors \t" + (100*error(0)/o2).ToString("G3") +"%\t"+(100*error(1)/o4).ToString("G3") +"%\t"+(100*error(2)/o6).ToString("G3")+"% \r\n";
	cout << "Effective relative error "<< 100*(error(0)/o2+error(1)/o4+error(2)/o6)<<"%"<<endl;
	for (int i=0;i<size;i++){
		sumdfexp=sumdfexp+abs(pow((fexp[i]-f(u2[i], u4[i], u6[i], lambda0[i],n,twojplusone,o2, o4,o6)),2));
		sumfexp=sumfexp+fexp[i]*fexp[i];
	cout << fexp[i]<<" " << f(u2[i], u4[i], u6[i], lambda0[i],n,twojplusone,o2, o4,o6)<<"  "<< endl;
	}
	cout<<"-----------------------------------------------"<<endl;
	cout<< sqrt(sumdfexp/(size-3))<<" "<<sqrt((sumdfexp/(size-3))/sumfexp)<<endl;

}

void CalculateRates(vector <double> u2, vector<double> u4, vector <double> u6, double twojplusone, vector <double> lambda0,double n,double o2, double o4, double o6, vector <double> &a)
{
	int size;
	double rate;
	size=u2.size();
	a.clear();
	for(int i=0;i<size;i++){
		rate=((64*pow(pi,4)*qe*qe)/(3*h*pow(lambda0[i],3)*twojplusone))*(n*pow(n*n+2,2)/9)*(u2[i]*o2+u4[i]*o4+u6[i]*o6);
		cout <<1e7*lambda0[i] <<" "<< rate <<endl;
		a.push_back(rate);
	}
}