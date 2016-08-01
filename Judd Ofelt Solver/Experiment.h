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
	Multiplet BMulti;
	double n;
	double o2;
	double o4;
	double o6;
	double sumrate;
	double femi;
	std::wstring AbsoDatafile;
	void LoadAbsoDataFromFile(String^ Filename,String^ &MSG);
	void LoadEmDataFromFile(String^ Filename);
	void LoadEmBranchFromFile(String^ Filename,String^ &MSG );
	void GetParameters(Experiment donor);
	void CalculateRates();
	void ReportRates(String^ &messages, String^ &latex);
	void FitLevMar(String^ &messages, String^ &latex);
	void FitLevMarBranching(String^ &messages, String^ &latex);
	void FitLevMarSol(String^ &messages, String^ &latex);
	void MatrixJO(String^ &messages);
	void DumpEmiData(String^ &emi);
	Experiment()
	{
		femi=1e-6;
	}
};





#endif