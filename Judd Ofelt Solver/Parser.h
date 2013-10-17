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
double n;
double o2;
double o4;
double o6;
std::vector <double> fexp;
double j;
bool filled;
void LoadAbsoDataFromFile(String^ Filename);
void LoadEmDataFromFile(String^ Filename);
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
	string name,str;
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
			this->o2=1e-20;
		this->o4=1e-20;
		this->o6=1e-20;
	while(inpfile >> pexp >> wavenumber>>u2>>u4>>u6){
		this->fexp.push_back(pexp);
		this->u2.push_back(u2);
		this->u4.push_back(u4);
		this->u6.push_back(u6);
		this->lambda.push_back(1./wavenumber);

	cout <<pexp <<" "<<1./wavenumber <<" "<<u2<<" "<<" "<<u4<<" "<< u6<<endl;
	}
}

void Experiment::LoadEmDataFromFile(String^ Filename)//, struct Experiment &experimental)
{
	double n, j,u2,u4,u6,wavenumber,pexp;
	string name,str;
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
	while(inpfile >> wavenumber>>u2>>u4>>u6){
		this->fexp.push_back(pexp);
		this->u2.push_back(u2);
		this->u4.push_back(u4);
		this->u6.push_back(u6);
		this->lambda.push_back(1./wavenumber);
		this->o2=1e-20;
		this->o4=1e-20;
		this->o6=1e-20;
	cout  <<1./wavenumber <<" "<<u2<<" "<<" "<<u4<<" "<< u6<<endl;
	}
}