#ifndef auxfunc_h
#define auxfunc_h
double f(double u2, double u4, double u6, double lambda0,double n,double TwoJPlusOne ,double o2, double o4, double o6);
double exponent(double x);
double mantissa(double x);
System::String ^lf(double x);
double sellmeier(double a, double b, double c, double d, double lambda);
double KFunction(double u2, double u4, double u6, double lambda0,double n,double TwoJPlusOne);
void MarshalString ( System::String ^ s, std::string& os);
void MarshalString ( System::String ^ s, std::wstring& os);
#endif