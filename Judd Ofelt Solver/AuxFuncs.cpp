#include "StdAfx.h"
#include <math.h>
#include "Constants.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

double f(double u2, double u4, double u6, double lambda0,double n,double TwoJPlusOne ,double o2, double o4, double o6)
{
	//n=1.469+3927.0/pow((1e7/lambda0),2);//test
	return (((pow(n*n+2,2)/(9*n))*(8*pi*pi*m*c))/(3*h*TwoJPlusOne*lambda0))*(u2*o2+u4*o4+u6*o6);
};

double exponent(double x)
{
return	floor(log10(x));
};
double mantissa(double x)
{
	return x/pow(10.0,exponent(x));
};
System::String ^lf(double x) // Latex format
{
	return mantissa(x).ToString("G3")+"$ \\cdot 10 ^{"+exponent(x)+"}$";
};

double sellmeier(double a, double b, double c, double d, double lambda)
{
return sqrt(a+b/(lambda*lambda-c)-d*lambda*lambda);
};
double KFunction(double u2, double u4, double u6, double lambda0,double n,double TwoJPlusOne){
	//n=1.469+3927.0/pow((1e7/lambda0),2);//test
	return ((pow(n*n+2,2)/(9*n))*(8*pi*pi*m*c))/(3*h*TwoJPlusOne*lambda0);
};
void MarshalString ( System::String ^ s, std::string& os ) {
	using namespace System::Runtime::InteropServices;
	const char* chars = 
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(System::IntPtr((void*)chars));
}

void MarshalString ( System::String ^ s, std::wstring& os ) {
	using namespace System::Runtime::InteropServices;
	const wchar_t* chars = 
		(const wchar_t*)(Marshal::StringToHGlobalUni(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(System::IntPtr((void*)chars));
}