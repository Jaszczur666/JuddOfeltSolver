#ifndef parser_h
#define parser_h
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using namespace System;
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





#endif