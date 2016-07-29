#ifndef parser_h
#define parser_h
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Multiplet.h"
using namespace System;
class Experiment{
public:
	Multiplet AbsoMulti;
	Multiplet EmiMulti;

	double n;
	double o2;
	double o4;
	double o6;
	double sumrate;
	std::wstring AbsoDatafile;
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
		
	}
};





#endif