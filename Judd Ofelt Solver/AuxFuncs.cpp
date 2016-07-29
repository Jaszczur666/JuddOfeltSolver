#include "StdAfx.h"
#include <math.h>
#include "Constants.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace System;
using namespace std;
double f(double u2, double u4, double u6, double lambda0,double n,double twojplusone ,double o2, double o4, double o6)
{
	return (((pow(n*n+2,2)/(9*n))*(8*pi*pi*m*c))/(3*h*twojplusone*lambda0))*(u2*o2+u4*o4+u6*o6);
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
double KFunction(double u2, double u4, double u6, double lambda0,double n,double twojplusone){
	return ((pow(n*n+2,2)/(9*n))*(8*pi*pi*m*c))/(3*h*twojplusone*lambda0);
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