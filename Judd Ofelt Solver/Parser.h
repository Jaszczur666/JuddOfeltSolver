#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

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
void LoadAbsoDataFromFile(String^ Filename);
void LoadEmDataFromFile(String^ Filename);
void GetParameters(Experiment donor);
void CalculateRates();
void ReportRates(String^ &messages, String^ &latex);
void FitLevMar(String^ &messages, String^ &latex);
void FitLevMarSol(String^ &messages, String^ &latex);
 Experiment()
  {
    filled=false;
  }
};
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
void Experiment::LoadAbsoDataFromFile(String^ Filename)//, struct Experiment &experimental)
{
	double n, j,u2,u4,u6,wavenumber,pexp;
	wstring name,str;
	MarshalString(Filename,name);
	ifstream inpfile(name);
//	cout<<name<<endl;
//	getline(inpfile,str);
	inpfile>>j>>n;
	cout <<"Loading file "<<endl;
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
	cout<<"fexp \t wvlgth[nm] \t u2 \t u4 \t u6"<<endl;
	while(inpfile >> pexp >> wavenumber>>u2>>u4>>u6){
		this->fexp.push_back(pexp);
		this->u2.push_back(u2);
		this->u4.push_back(u4);
		this->u6.push_back(u6);
		this->lambda.push_back(1./wavenumber);
		cout <<pexp <<" \t"<<1.0e7/wavenumber <<"\t "<<u2<<"\t "<<"\t "<<u4<<"\t "<< u6<<endl;
	}
}

void Experiment::LoadEmDataFromFile(String^ Filename)//, struct Experiment &experimental)
{
	double n, j,u2,u4,u6,wavenumber,pexp;
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
cout<<"Wavenumber \t u2\t u4 \t u6";
	while(inpfile >> wavenumber>>u2>>u4>>u6){
		this->fexp.push_back(pexp);
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
	for (int i=0;i<size;i++)
	{
		messages+=(1./this->lambda[i]).ToString("G5")+" "+(this->Ajj[i]).ToString("F1")+" "+(100*this->Ajj[i]/this->sumrate).ToString("F1")+"%\r\n";
		latex+="&"+(1./this->lambda[i]).ToString("G5")+" & "+(this->Ajj[i]).ToString("F1")+" & "+(100*this->Ajj[i]/this->sumrate).ToString("F1")+"\\% \\\\\r\n\\hline\r\n";
	}
	latex+="\\hline\r\n\\multicolumn{3}{|l|}{Lifetime}&"+(1000./this->sumrate).ToString("G3")+"ms \\\\\r\n\\hline\r\n ";
	latex+="\\end{tabular}\r\n";
}
