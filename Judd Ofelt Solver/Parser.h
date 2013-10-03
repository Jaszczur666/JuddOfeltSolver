#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace System;
using namespace std;
struct Experiment{
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
void LoadAbsoDataFromFile(String^ Filename, struct Experiment &experimental)
{
	double n, j,u2,u4,u6,wavenumber,pexp;
	string name,str;
	MarshalString(Filename,name);
	ifstream inpfile(name);
//	getline(inpfile,str);
	inpfile>>j>>n;
	cout << n <<" "<<j<<endl;
	experimental.lambda.clear();
	experimental.u2.clear();
	experimental.u4.clear();
	experimental.u6.clear();
	experimental.fexp.clear();
	experimental.n=n;
	experimental.j=j;
	while(inpfile >> pexp >> wavenumber>>u2>>u4>>u6){
		experimental.fexp.push_back(pexp);
		experimental.u2.push_back(u2);
		experimental.u4.push_back(u4);
		experimental.u6.push_back(u6);
		experimental.lambda.push_back(1./wavenumber);
		experimental.o2=1e-20;
		experimental.o4=1e-20;
		experimental.o6=1e-20;
	cout <<pexp <<" "<<1./wavenumber <<" "<<u2<<" "<<" "<<u4<<" "<< u6<<endl;
	}
}

void LoadEmDataFromFile(String^ Filename, struct Experiment &experimental)
{
	double n, j,u2,u4,u6,wavenumber,pexp;
	string name,str;
	MarshalString(Filename,name);
	ifstream inpfile(name);
//	getline(inpfile,str);
	inpfile>>j>>n;
	cout << n <<" "<<j<<endl;
	experimental.lambda.clear();
	experimental.u2.clear();
	experimental.u4.clear();
	experimental.u6.clear();
	experimental.fexp.clear();
	experimental.n=n;
	experimental.j=j;
	while(inpfile >> wavenumber>>u2>>u4>>u6){
		experimental.fexp.push_back(pexp);
		experimental.u2.push_back(u2);
		experimental.u4.push_back(u4);
		experimental.u6.push_back(u6);
		experimental.lambda.push_back(1./wavenumber);
		experimental.o2=1e-20;
		experimental.o4=1e-20;
		experimental.o6=1e-20;
	cout  <<1./wavenumber <<" "<<u2<<" "<<" "<<u4<<" "<< u6<<endl;
	}
}