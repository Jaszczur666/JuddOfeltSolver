#ifndef parser_h
#define parser_h
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Constants.h"
using namespace System;
using namespace std;
class Experiment{
	public:
std::vector <double> u2;
std::vector <double> u4;
std::vector <double> u6;
std::vector <double> lambda;
std::vector <double> Ajj;
double n;
double o2;
double o4;
double o6;
std::vector <double> fexp;
double j;
bool filled;
double sumrate;
wstring AbsoDatafile;
void LoadAbsoDataFromFile(String^ Filename,String^ &MSG);
void LoadEmDataFromFile(String^ Filename);
void GetParameters(Experiment donor);
void CalculateRates();
void ReportRates(String^ &messages, String^ &latex);
void FitLevMar(String^ &messages, String^ &latex);
void FitLevMarSol(String^ &messages, String^ &latex);
void MatrixJO(String^ &messages);
void DumpEmiData(String^ &emi);
 Experiment()
  {
    filled=false;
  }
};
double KFunction(double u2, double u4, double u6, double lambda0,double n,double twojplusone);
void MarshalString ( String ^ s, string& os ) {
	using namespace Runtime::InteropServices;
	const char* chars = 
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

void MarshalString ( String ^ s, wstring& os ) {
	using namespace Runtime::InteropServices;
	const wchar_t* chars = 
		(const wchar_t*)(Marshal::StringToHGlobalUni(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}
void Experiment::LoadAbsoDataFromFile(String^ Filename,String^ &MSG)//, struct Experiment &experimental)
{
	double n, j,u2,u4,u6,wavenumber,pexp;
	wstring name,str;
	MarshalString(Filename,name);
	ifstream inpfile(name);
	this->AbsoDatafile=name;
//	cout<<name<<endl;
//	getline(inpfile,str);
	inpfile>>j>>n;
	MSG+="Loading file "+Filename+"\r\n";
	cout <<"Loading file "<<endl;
	MSG+="n= "+n.ToString("G3")+" 2J+1= "+j.ToString()+"\r\n";
	cout <<"n= "<< n <<" 2J+1= "<<j<<endl;
	this->lambda.clear();
	this->u2.clear();
	this->u4.clear();
	this->u6.clear();
	this->fexp.clear();
	this->n=n;
	this->j=j;
	this->o2=1e-20;
	this->o4=1e-20;
	this->o6=1e-20;
	MSG+="fexp \t wvnmb[cm^-1] \t u2 \t u4 \t u6\r\n";
	cout<<"fexp \t wvlgth[nm] \t u2 \t u4 \t u6"<<endl;
	while(inpfile >> pexp >> wavenumber>>u2>>u4>>u6){
		this->fexp.push_back(pexp);
		this->u2.push_back(u2);
		this->u4.push_back(u4);
		this->u6.push_back(u6);
		this->lambda.push_back(1./wavenumber);
		cout <<pexp <<" \t"<<1.0e7/wavenumber <<"\t "<<u2<<"\t "<<"\t "<<u4<<"\t "<< u6<<endl;
		MSG+=pexp.ToString("G5")+"\t"+wavenumber.ToString("G5")+"\t"+u2.ToString("G5")+"\t"+u4.ToString("G5")+"\t"+u6.ToString("G5")+"\r\n";
	}
}

void Experiment::LoadEmDataFromFile(String^ Filename)//, struct Experiment &experimental)
{
	double n, j,u2,u4,u6,wavenumber;
	wstring name,str;
	MarshalString(Filename,name);
	ifstream inpfile(name);
//	getline(inpfile,str);
	inpfile>>j>>n;
	cout << n <<" "<<j<<endl;
	this->lambda.clear();
	this->u2.clear();
	this->u4.clear();
	this->u6.clear();
	this->fexp.clear();
	this->n=n;
	this->j=j;
cout <<"Loading file "<<endl;
cout<<"Wavenumber \t u2\t u4 \t u6"<<endl;
	while(inpfile >> wavenumber>>u2>>u4>>u6){
		//this->fexp.push_back(pexp);
		this->u2.push_back(u2);
		this->u4.push_back(u4);
		this->u6.push_back(u6);
		this->lambda.push_back(1./wavenumber);
		this->o2=1e-20;
		this->o4=1e-20;
		this->o6=1e-20;
	cout  <<1.0e7/wavenumber <<" "<<u2<<" "<<" "<<u4<<" "<< u6<<endl;
	}
}

void Experiment::CalculateRates()//vector <double> u2, vector<double> u4, vector <double> u6, double twojplusone, vector <double> lambda0,double n,double o2, double o4, double o6, vector <double> &a)
{
	int size;
	double rate,sumrate;
	size=u2.size();
	this->Ajj.clear();
	sumrate=0;
	for(int i=0;i<size;i++){
		//rate=((64*pow(pi,4)*qe*qe)/(3*h*pow(lambda0[i],3)*twojplusone))*(n*pow(n*n+2,2)/9)*(u2[i]*o2+u4[i]*o4+u6[i]*o6);
		rate=((64*pow(pi,4)*qe*qe)/(3*h*pow(this->lambda[i],3)*this->j))*(this->n*pow(this->n*this->n+2,2)/9)*(this->u2[i]*this->o2+this->u4[i]*this->o4+this->u6[i]*this->o6);
		cout <<1e7*this->lambda[i] <<" "<< rate <<endl;
		this->Ajj.push_back(rate);
		sumrate+=rate;
	}
	this->sumrate=sumrate;
	cout << "Effective rate = "<<sumrate<<" which amounts to lifetime of "<<1e3/sumrate<<" ms"<<endl;
}

void Experiment::GetParameters(Experiment donor)
{
this->o2=donor.o2;
this->o4=donor.o4;
this->o6=donor.o6;
}

void Experiment::FitLevMar(System::String^ &messages,System::String^ &latex)
{
FitLM(this->u2, this->u4, this->u6, this->lambda,this->n,this->j,this->o2,this->o4, this->o6, this->fexp,messages,latex);
}
void Experiment::FitLevMarSol(System::String^ &messages,System::String^ &latex)
{
FitSolarz(this->u2, this->u4, this->u6, this->lambda,this->n,this->j,this->o2,this->o4, this->o6, this->fexp,messages,latex);
}

void Experiment::ReportRates(System::String^ &messages,System::String^ &latex)
{
	int size;
	size=this->u2.size();
	if (size>0) {
		latex+="\\begin{tabular}{|l|l|l|l|}\r\n";
		latex+="\\hline\r\n";
		latex+="Multiplet&Wavenumber&Rate&Branching ratio\\\\\r\n";
		latex+="\\hline\r\n";

	}
	cout <<"Rates of radiative transmition calculated"<<endl;
	messages+="Wavenumber\t Transition rate\tBranching ratio\r\n";
	for (int i=0;i<size;i++)
	{
		messages+=(1./this->lambda[i]).ToString("G5")+"\t"+(this->Ajj[i]).ToString("F1")+"\t"+(100*this->Ajj[i]/this->sumrate).ToString("F1")+"%\r\n";
		latex+="&"+(1./this->lambda[i]).ToString("G5")+" & "+(this->Ajj[i]).ToString("F1")+" & "+(100*this->Ajj[i]/this->sumrate).ToString("F1")+"\\% \\\\\r\n\\hline\r\n";
	}
	messages+="Summary rate ="+(this->sumrate).ToString("G5")+" which amounts to lifetime "+(1000./this->sumrate).ToString("G5")+"ms\r\n";
	latex+="\\hline\r\n\\multicolumn{3}{|l|}{Lifetime}&"+(1000./this->sumrate).ToString("G3")+"ms \\\\\r\n\\hline\r\n ";
	latex+="\\end{tabular}\r\n";
}
void Experiment::DumpEmiData(String^ &emi)
{
	int size;
	emi="";
	size=this->u2.size();
	if (size>0) {
		emi+="2J+1= "+this->j+" n= "+this->n+"\r\n";
		for (int i=0;i<size;i++){
			emi+=(1/this->lambda[i]).ToString("G5")+"\t"+this->u2[i]+"\t"+this->u4[i]+"\t"+this->u6[i]+"\r\n";

		}
	emi+="";
	}

}
void Experiment::MatrixJO(String^ &msg){
	double XF=0.0,YF=0.0,ZF=0.0,XX=0.0,XY=0.0,XZ=0.0,YY=0.0,YZ=0.0,ZZ=0.0,K=0.0;
	double x=0.0,y=0.0,z=0.0;
	MatrixXd Dmat(3,3),Om2(3,3),Om4(3,3),Om6(3,3);
	for (int i=0;i<this->u2.size();i++){
		K=KFunction(this->u2[i],this->u4[i],this->u6[i],this->lambda[i],this->n,this->j);
			x=K*this->u2[i];
		y=K*this->u4[i];
		z=K*this->u6[i];
		XF+=x*fexp[i];
		YF+=y*fexp[i];
		ZF+=z*fexp[i];
		XX+=x*x;
		XY+=x*y;
		XZ+=x*z;
		YY+=y*y;
		YZ+=y*z;
		ZZ+=z*z;
		//cout<<K<<endl;
}
	Dmat<<XX,XY,XZ,XY,YY,YZ,XZ,YZ,ZZ;
	cout<<Dmat<<endl;
	Om2<<XF,XY,XZ,YF,YY,YZ,ZF,YZ,ZZ;
	Om4<<XX,XF,XZ,XY,YF,YZ,XZ,ZF,ZZ;
	Om6<<XX,XY,XF,XY,YY,YF,XZ,YZ,ZF;
	double d;
	d=Dmat.determinant();
	cout<<d<<" "<<1/d*Om2.determinant()<<" "<<1/d*Om4.determinant()<<" "<<1/d*Om6.determinant()<<endl;
}
double KFunction(double u2, double u4, double u6, double lambda0,double n,double twojplusone){
	return ((pow(n*n+2,2)/(9*n))*(8*pi*pi*m*c))/(3*h*twojplusone*lambda0);
};
#endif