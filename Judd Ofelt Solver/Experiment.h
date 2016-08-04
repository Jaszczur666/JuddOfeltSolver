#ifndef parser_h
#define parser_h
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Multiplet.h"
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
	std::wstring BrDatafile;
	void LoadAbsoDataFromFile(System::String^ Filename,System::String^ &MSG);
	void LoadEmDataFromFile(System::String^ Filename);
	void LoadEmBranchFromFile(System::String^ Filename,System::String^ &MSG );
	void GetParameters(Experiment donor);
	void CalculateRates();
	void ReportRates(System::String^ &messages, System::String^ &latex);
	void FitLevMar(System::String^ &messages, System::String^ &latex);
	void FitLevMarBranching(System::String^ &messages, System::String^ &latex);
	void FitLevMarSol(System::String^ &messages, System::String^ &latex);
	void MatrixJO(System::String^ &messages);
	void DumpEmiData(System::String^ &emi);
	Experiment()
	{
		femi=1e-6;
	}
};





#endif