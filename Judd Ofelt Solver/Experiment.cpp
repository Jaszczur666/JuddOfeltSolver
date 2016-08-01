#include "StdAfx.h"
#include "Experiment.h"
#include "AuxFuncs.h"
#include "Constants.h"
#include "SolvingAlgorithms.h"
void Experiment::LoadEmDataFromFile(String^ Filename)//, struct Experiment &experimental)
{
	double n, twojplusone,u2,u4,u6,wavenumber;
	wstring name,str;
	MarshalString(Filename,name);
	ifstream inpfile(name);
	//	getline(inpfile,str);
	inpfile>>twojplusone>>n;
	cout << n <<" "<<twojplusone<<endl;
	this->EmiMulti.lambda.clear();
	this->EmiMulti.u2.clear();
	this->EmiMulti.u4.clear();
	this->EmiMulti.u6.clear();
	this->EmiMulti.fexp.clear();
	this->n=n;
	this->EmiMulti.twojplusone=twojplusone;
	cout <<"Loading file "<<endl;
	cout<<"Wavenumber \t u2\t u4 \t u6"<<endl;
	while(inpfile >> wavenumber>>u2>>u4>>u6){
		//this->fexp.push_back(pexp);
		this->EmiMulti.u2.push_back(u2);
		this->EmiMulti.u4.push_back(u4);
		this->EmiMulti.u6.push_back(u6);
		this->EmiMulti.lambda.push_back(1./wavenumber);
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
	size=EmiMulti.u2.size();
	this->EmiMulti.Ajj.clear();
	sumrate=0;
	for(int i=0;i<size;i++){
		//rate=((64*pow(pi,4)*qe*qe)/(3*h*pow(lambda0[i],3)*twojplusone))*(n*pow(n*n+2,2)/9)*(u2[i]*o2+u4[i]*o4+u6[i]*o6);
		rate=((64*pow(pi,4)*qe*qe)/(3*h*pow(this->EmiMulti.lambda[i],3)*this->EmiMulti.twojplusone))*(this->n*pow(this->n*this->n+2,2)/9)*(this->EmiMulti.u2[i]*this->o2+this->EmiMulti.u4[i]*this->o4+this->EmiMulti.u6[i]*this->o6);
		cout <<1e7*this->EmiMulti.lambda[i] <<" "<< rate <<endl;
		this->EmiMulti.Ajj.push_back(rate);
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
	FitLM(this->AbsoMulti.u2, this->AbsoMulti.u4, this->AbsoMulti.u6, this->AbsoMulti.lambda,this->n,this->AbsoMulti.twojplusone,this->o2,this->o4, this->o6, this->AbsoMulti.fexp,messages,latex);
}
void Experiment::FitLevMarSol(System::String^ &messages,System::String^ &latex)
{
	FitSolarz(this->AbsoMulti.u2, this->AbsoMulti.u4, this->AbsoMulti.u6, this->AbsoMulti.lambda,this->n,this->AbsoMulti.twojplusone,this->o2,this->o4, this->o6, this->AbsoMulti.fexp,messages,latex);
}

void Experiment::ReportRates(System::String^ &messages,System::String^ &latex)
{
	int size;
	size=this->EmiMulti.u2.size();
	if (size>0) {
		latex+="\\begin{tabular}{|l|l|l|l|}\r\n";
		latex+="\\hline\r\n";
		latex+="Multiplet&Wavenumber&Rate&Branching ratio\\\\\r\n";
		latex+="\\hline\r\n";

	}
	cout <<"Rates of radiative transmition calculated"<<endl;
	messages+="Wavenumber\t Transition rate\tBranching ratio\r\n";
	for (int i=0;i<size;i++)
	{
		messages+=(1./this->EmiMulti.lambda[i]).ToString("G5")+"\t"+(this->EmiMulti.Ajj[i]).ToString("F1")+"\t"+(100*this->EmiMulti.Ajj[i]/this->sumrate).ToString("F1")+"%\r\n";
		latex+="&"+(1./this->EmiMulti.lambda[i]).ToString("G5")+" & "+(this->EmiMulti.Ajj[i]).ToString("F1")+" & "+(100*this->EmiMulti.Ajj[i]/this->sumrate).ToString("F1")+"\\% \\\\\r\n\\hline\r\n";
	}
	messages+="Summary rate ="+(this->sumrate).ToString("G5")+" which amounts to lifetime "+(1000./this->sumrate).ToString("G5")+"ms\r\n";
	latex+="\\hline\r\n\\multicolumn{3}{|l|}{Lifetime}&"+(1000./this->sumrate).ToString("G3")+"ms \\\\\r\n\\hline\r\n ";
	latex+="\\end{tabular}\r\n";
}
void Experiment::DumpEmiData(String^ &emi)
{
	int size;
	emi="";
	size=this->EmiMulti.u2.size();
	if (size>0) {
		emi+="2J+1= "+this->EmiMulti.twojplusone+" n= "+this->n+"\r\n";
		for (int i=0;i<size;i++){
			emi+=(1/this->EmiMulti.lambda[i]).ToString("G5")+"\t"+this->EmiMulti.u2[i]+"\t"+this->EmiMulti.u4[i]+"\t"+this->EmiMulti.u6[i]+"\r\n";

		}
		emi+="";
	}

}
void Experiment::MatrixJO(String^ &msg){
	double XF=0.0,YF=0.0,ZF=0.0,XX=0.0,XY=0.0,XZ=0.0,YY=0.0,YZ=0.0,ZZ=0.0,K=0.0;
	double x=0.0,y=0.0,z=0.0;
	MatrixXd Dmat(3,3),Om2(3,3),Om4(3,3),Om6(3,3);
	for (int i=0;i<this->AbsoMulti.u2.size();i++){
		K=KFunction(this->AbsoMulti.u2[i],this->AbsoMulti.u4[i],this->AbsoMulti.u6[i],this->AbsoMulti.lambda[i],this->n,this->AbsoMulti.twojplusone);
		x=K*this->AbsoMulti.u2[i];
		y=K*this->AbsoMulti.u4[i];
		z=K*this->AbsoMulti.u6[i];
		XF+=x*AbsoMulti.fexp[i];
		YF+=y*AbsoMulti.fexp[i];
		ZF+=z*AbsoMulti.fexp[i];
		XX+=x*x;
		XY+=x*y;
		XZ+=x*z;
		YY+=y*y;
		YZ+=y*z;
		ZZ+=z*z;
		//cout<<K<<endl;
	}
	Dmat<<XX,XY,XZ,XY,YY,YZ,XZ,YZ,ZZ;
	cout<<Dmat<<endl;
	Om2<<XF,XY,XZ,YF,YY,YZ,ZF,YZ,ZZ;
	Om4<<XX,XF,XZ,XY,YF,YZ,XZ,ZF,ZZ;
	Om6<<XX,XY,XF,XY,YY,YF,XZ,YZ,ZF;
	double d;
	d=Dmat.determinant();
	cout<<d<<" "<<1/d*Om2.determinant()<<" "<<1/d*Om4.determinant()<<" "<<1/d*Om6.determinant()<<endl;
}
void Experiment::LoadAbsoDataFromFile(String^ Filename,String^ &MSG)//, struct Experiment &experimental)
{
	double n, j,u2,u4,u6,wavenumber,pexp;
	wstring name,str;
	MarshalString(Filename,name);
	ifstream inpfile(name);
	this->AbsoDatafile=name;
	//	cout<<name<<endl;
	//	getline(inpfile,str);
	inpfile>>j>>n;
	MSG+="Loading file "+Filename+"\r\n";
	cout <<"Loading file "<<endl;
	MSG+="n= "+n.ToString("G3")+" 2J+1= "+j.ToString()+"\r\n";
	cout <<"n= "<< n <<" 2J+1= "<<j<<endl;
	this->AbsoMulti.lambda.clear();
	this->AbsoMulti.u2.clear();
	this->AbsoMulti.u4.clear();
	this->AbsoMulti.u6.clear();
	this->AbsoMulti.fexp.clear();
	this->n=n;
	this->AbsoMulti.twojplusone=j;
	this->o2=1e-20;
	this->o4=1e-20;
	this->o6=1e-20;
	MSG+="fexp \t wvnmb[cm^-1] \t u2 \t u4 \t u6\r\n";
	cout<<"fexp \t wvlgth[nm] \t u2 \t u4 \t u6"<<endl;
	while(inpfile >> pexp >> wavenumber>>u2>>u4>>u6){
		this->AbsoMulti.fexp.push_back(pexp);
		this->AbsoMulti.u2.push_back(u2);
		this->AbsoMulti.u4.push_back(u4);
		this->AbsoMulti.u6.push_back(u6);
		this->AbsoMulti.lambda.push_back(1./wavenumber);
		cout <<pexp <<" \t"<<1.0e7/wavenumber <<"\t "<<u2<<"\t "<<"\t "<<u4<<"\t "<< u6<<endl;
		MSG+=pexp.ToString("G5")+"\t"+wavenumber.ToString("G5")+"\t"+u2.ToString("G5")+"\t"+u4.ToString("G5")+"\t"+u6.ToString("G5")+"\r\n";
	}
}
void Experiment::LoadEmBranchFromFile(String^ Filename ,String^ &MSG){
	wstring name,str;
	double branching,wavenumber,u2,u4,u6,twojplusone;
	int size;
	double branchsum,branchnorm;
	MarshalString(Filename,name);
	ifstream inpfile(name);
	MSG+="Loading file "+Filename+"\r\n";
	cout <<"Loading file "<<endl;
	inpfile>>twojplusone;
	this->BMulti.twojplusone=twojplusone;
	this->BMulti.u2.clear();
	this->BMulti.u4.clear();
	this->BMulti.u6.clear();
	this->BMulti.branching.clear();
	this->BMulti.lambda.clear();
	while(inpfile >> branching >> wavenumber>>u2>>u4>>u6){
		cout<<branching<<" "<<wavenumber<<" "<<u2<<" "<<u4<<" "<<u6<<std::endl;
		this->BMulti.branching.push_back(branching);
		this->BMulti.u2.push_back(u2);
		this->BMulti.u4.push_back(u4);
		this->BMulti.u6.push_back(u6);
		this->BMulti.lambda.push_back(1./wavenumber);
	}
	size=BMulti.u2.size();
	branchsum=0.0;
	branchnorm=BMulti.branching[0];
	for (int i=0;i<size;i++){
	branchsum+=BMulti.branching[i];
	BMulti.branching[i]*=(1/branchnorm);
	cout<<i<<" "<<BMulti.branching[i]<<std::endl;
	}
	cout<<branchsum<<std::endl;
	for (int i=0;i<size;i++){
		cout <<i<<" "<<BMulti.branching[i]<<" "<<std::endl;
	}
}
void Experiment::FitLevMarBranching(String^ &messages, String^ &latex){
	FitBranching(*this,messages,latex);
}