#include "StdAfx.h"
#include <math.h>
#include <vector>
#include <string>
#include  <iostream>
#include "Eigen\Dense"
#include "Constants.h"
#include "AuxFuncs.h"
#include "Experiment.h"

using Eigen::MatrixXd;
double chi2(std::vector <double> u2, std::vector<double> u4, std::vector <double> u6, std::vector <double> lambda0,double n,double TwoJPlusOne,double o2, double o4, double o6, std::vector <double> fexp)
{
	int size;
	double tempchi2=0;
	size=u2.size();
	for (int i=0;i<size;i++){
		tempchi2=tempchi2+pow(f(u2[i],u4[i],u6[i],lambda0[i],n,TwoJPlusOne,o2,o4,o6)-fexp[i],2);
	};
	return tempchi2;
};
double chi2br(Experiment BExp, double o2, double o4, double o6, double femi){
	int size;
	double tempchi2=0;
	size=BExp.AbsoMulti.u2.size();
	for (int i=0;i<size;i++){
		tempchi2=tempchi2+pow(f(BExp.AbsoMulti.u2[i],BExp.AbsoMulti.u4[i],BExp.AbsoMulti.u6[i],BExp.AbsoMulti.lambda[i],BExp.n,BExp.AbsoMulti.TwoJPlusOne,BExp.o2,BExp.o4,BExp.o6)-BExp.AbsoMulti.fexp[i],2);
	};
	size=BExp.BMulti.u2.size();
	for (int i=0;i<size;i++){
		tempchi2=tempchi2+pow(f(BExp.BMulti.u2[i],BExp.BMulti.u4[i],BExp.BMulti.u6[i],BExp.BMulti.lambda[i],BExp.n,BExp.BMulti.TwoJPlusOne,o2,o4,o6)-femi*BExp.BMulti.branching[i],2);
	};
	return tempchi2;
}
double chi2Solarz(std::vector <double> u2, std::vector<double> u4, std::vector <double> u6, std::vector <double> lambda0,double n,double TwoJPlusOne,double o2, double o4, double o6, std::vector <double> fexp)
{
	int size;
	double tempchi2=0;
	size=u2.size();
	for (int i=0;i<size;i++){
		tempchi2=tempchi2+pow((f(abs(u2[i]),abs(u4[i]),abs(u6[i]),lambda0[i],n,TwoJPlusOne,o2,o4,o6)-fexp[i])/fexp[i],2);
	};
	return tempchi2;
};

double Residue(double fexp, double o2, double o4, double o6,double u2, double u4, double u6, double lambda, double n, double TwoJPlusOne)
{
	return f(u2,u4,u6,lambda, n,TwoJPlusOne,o2,o4,o6)-fexp;
};

void CalculateHessian(std::vector <double> u2, std::vector<double> u4, std::vector <double> u6, std::vector <double> lambda0,double n,double TwoJPlusOne,double o2, double o4, double o6, std::vector <double> fexp, MatrixXd &Hess, MatrixXd &Grad)
{
	int i,size;
	MatrixXd Hessian;
	double ro2,ro4,ro6,res,delta;
	size=u2.size();
	MatrixXd Res(size,1);
	delta=1e-28;
	MatrixXd Jaco(size,3);
	//cout <<"Debug " <<o2<<" "<<o4<<" "<<o6<<std::endl;
	for (i=0;i<size;i++){
		res=Residue(fexp[i], o2, o4, o6,u2[i], u4[i], u6[i], lambda0[i],n,TwoJPlusOne);
		ro2=Residue(fexp[i], o2+delta, o4, o6,u2[i], u4[i], u6[i], lambda0[i],n,TwoJPlusOne);
		ro4=Residue(fexp[i], o2, o4+delta, o6,u2[i], u4[i], u6[i], lambda0[i],n,TwoJPlusOne);
		ro6=Residue(fexp[i], o2, o4, o6+delta,u2[i], u4[i], u6[i], lambda0[i],n,TwoJPlusOne);
		Jaco(i,0)=(ro2-res)/delta;
		Jaco(i,1)=(ro4-res)/delta;
		Jaco(i,2)=(ro6-res)/delta;
		Res(i,0)=res;
	};
	Hess=Jaco.transpose()*Jaco;
	Grad=Jaco.transpose()*Res;
/*		std::cout <<"_________________________________"<<std::endl;
		std::cout << Hess<<std::endl;
		std::cout <<"_________________________________"<<std::endl;*/
};
void CalculateHessianBr(Experiment BExp, double o2,double o4, double o6,double femi, MatrixXd &Hess, MatrixXd &Grad)
{
	int i,size,size1,size2;
	MatrixXd Hessian;
	double ro2,ro4,ro6,rfemi,res,delta;
	size=BExp.AbsoMulti.u2.size()+BExp.BMulti.u2.size();
	size1=BExp.AbsoMulti.u2.size();
	size2=BExp.BMulti.u2.size();
	MatrixXd Res(size,1);
	delta=1e-23;
	MatrixXd Jaco(size,4);
	//cout <<"Debug " <<o2<<" "<<o4<<" "<<o6<<std::endl;
	for (i=0;i<size1;i++){
		res=Residue(BExp.AbsoMulti.fexp[i], o2, o4, o6,BExp.AbsoMulti.u2[i], BExp.AbsoMulti.u4[i], BExp.AbsoMulti.u6[i], BExp.AbsoMulti.lambda[i],BExp.n,BExp.AbsoMulti.TwoJPlusOne);
		ro2=Residue(BExp.AbsoMulti.fexp[i], o2+delta, o4, o6,BExp.AbsoMulti.u2[i], BExp.AbsoMulti.u4[i], BExp.AbsoMulti.u6[i], BExp.AbsoMulti.lambda[i],BExp.n,BExp.AbsoMulti.TwoJPlusOne);
		ro4=Residue(BExp.AbsoMulti.fexp[i], o2, o4+delta, o6,BExp.AbsoMulti.u2[i], BExp.AbsoMulti.u4[i], BExp.AbsoMulti.u6[i], BExp.AbsoMulti.lambda[i],BExp.n,BExp.AbsoMulti.TwoJPlusOne);
		ro6=Residue(BExp.AbsoMulti.fexp[i], o2, o4, o6+delta,BExp.AbsoMulti.u2[i], BExp.AbsoMulti.u4[i], BExp.AbsoMulti.u6[i], BExp.AbsoMulti.lambda[i],BExp.n,BExp.AbsoMulti.TwoJPlusOne);
		Jaco(i,0)=(ro2-res)/delta;
		Jaco(i,1)=(ro4-res)/delta;
		Jaco(i,2)=(ro6-res)/delta;
		Jaco(i,3)=0;
		Res(i,0)=res;
	};
	for (i=0;i<size2;i++){
		res=Residue(BExp.BMulti.branching[i]*femi, o2, o4, o6,BExp.BMulti.u2[i], BExp.BMulti.u4[i], BExp.BMulti.u6[i], BExp.BMulti.lambda[i],BExp.n,BExp.BMulti.TwoJPlusOne);
		ro2=Residue(BExp.BMulti.branching[i]*femi, o2+delta, o4, o6,BExp.BMulti.u2[i], BExp.BMulti.u4[i], BExp.BMulti.u6[i], BExp.BMulti.lambda[i],BExp.n,BExp.BMulti.TwoJPlusOne);
		ro4=Residue(BExp.BMulti.branching[i]*femi, o2, o4+delta, o6,BExp.BMulti.u2[i], BExp.BMulti.u4[i], BExp.BMulti.u6[i], BExp.BMulti.lambda[i],BExp.n,BExp.BMulti.TwoJPlusOne);
		ro6=Residue(BExp.BMulti.branching[i]*femi, o2, o4, o6+delta,BExp.BMulti.u2[i], BExp.BMulti.u4[i], BExp.BMulti.u6[i], BExp.BMulti.lambda[i],BExp.n,BExp.BMulti.TwoJPlusOne);
		rfemi=Residue(BExp.BMulti.branching[i]*(femi+delta*1e12), o2, o4, o6,BExp.BMulti.u2[i], BExp.BMulti.u4[i], BExp.BMulti.u6[i], BExp.BMulti.lambda[i],BExp.n,BExp.BMulti.TwoJPlusOne);
		Jaco(size1+i,0)=(ro2-res)/delta;
		Jaco(size1+i,1)=(ro4-res)/delta;
		Jaco(size1+i,2)=(ro6-res)/delta;
		Jaco(size1+i,3)=(rfemi-res)/(delta*1e12);
		Res(size1+i,0)=res;
		//cout<<"res="<<res<<" rfemi="<<rfemi<<" rfemi-res="<<(rfemi-res)<<std::endl;
	}
	Hess=Jaco.transpose()*Jaco;
	Grad=Jaco.transpose()*Res;
		//std::cout <<"_________________________________"<<std::endl;
		//std::cout <<	Jaco<<std::endl;
		//std::cout <<"_________________________________"<<std::endl;
};
void FitLM(std::vector <double> u2, std::vector<double> u4, std::vector <double> u6, std::vector <double> lambda0,double n,double TwoJPlusOne,double &o2, double &o4, double &o6, std::vector <double> fexp,System::String^ &MSG,System::String^ &LATEX)
{
	MatrixXd Hessian,Hessiandiag;
	MatrixXd Grad;
	MatrixXd parameters(3,1);
	MatrixXd newparams(3,1);
	MatrixXd error(3,1);
	parameters<<o2,o4,o6;
	double no2,no4,no6,sumfexp,sumdfexp;
	double lambda,chi2s,chi2n;
	lambda=1/1024.0;
	sumdfexp=0;
	sumfexp=0;
	chi2s=0;
	MSG+="Num.\tChi2\tO2\tO4\tO6\r\n";
	std::cout <<"Beginnig fitting procedure."<<std::endl;
	for(int i=1;i<10;i++)
	{
		chi2s=chi2(u2,u4,u6,lambda0,n,TwoJPlusOne,o2,o4,o6,fexp);
		CalculateHessian(u2,u4,u6,lambda0,n,TwoJPlusOne,o2, o4, o6, fexp, Hessian,Grad);
		Hessiandiag=Hessian.diagonal().asDiagonal();
		newparams=parameters-((Hessian+lambda*Hessiandiag).inverse()*Grad);
		no2=(newparams(0,0));
		no4=(newparams(1,0));
		no6=(newparams(2,0));
		chi2n=chi2(u2,u4,u6,lambda0,n,TwoJPlusOne,no2,no4,no6,fexp);
		std::cout<< i <<" "<< chi2s <<" " <<no2<<" "<<no4<<" "<<no6<<std::endl;
		MSG+=i.ToString()+"\t"+chi2s.ToString("G6")+"\t"+no2.ToString("G6")+"\t"+no4.ToString("G6")+"\t"+no6.ToString("G6")+"\r\n";
		if (chi2n<chi2s){
			parameters=newparams;
			o2=no2;
			o4=no4;
			o6=no6;
			lambda=lambda*1.1;
		}
		else
		{
			lambda=lambda/1.1;
		}
	};
	std::cout <<"Fitting finished"<<std::endl;
	MSG+="Fitting finished \r\n";
	int size=u2.size();
	error=(Hessiandiag.inverse().diagonal()*chi2n/(size-3));
	for (int i=0;i<3;i++) error(i)=abs(sqrt(error(i)));
	std::cout <<"Errors "<< error(0)<<" "<<error(1)<<" "<< error(2)<<std::endl;
	MSG+="Parameters\t o2="+o2.ToString("G4")+"\t o4="+o4.ToString("G4")+"\t o6="+o6.ToString("G4")+"\r\n";
	MSG+="Errors \t do2="+error(0).ToString("G2")+"\t do4="+error(1).ToString("G2")+"\t do6="+error(2).ToString("G2")+"\r\n";
	//LATEX+="$\\Omega_2$ ="+mantissa(o2).ToString("G4")+"$\\cdot$ 10$^{"+exponent(o2)+"}$ $\\Omega_4$ ="+mantissa(o4).ToString("G4")+"$\\cdot$ 10$^{"+exponent(o4)+"}$ $\\Omega_6$ ="+mantissa(o6).ToString("G4")+"$\\cdot$ 10$^{"+exponent(o6)+"}$ \\\\ \r\n";
	LATEX+="$\\Omega_2$ ="+lf(o2)+" $\\Omega_4$ ="+lf(o4)+" $\\Omega_6$ ="+lf(o6) +"\\\\ \r\n";
	LATEX+="$\\Delta\\Omega_2$ ="+lf(error(0))+" $\\Delta\\Omega_4$ ="+lf(error(1))+" $\\Delta\\Omega_6$ ="+lf(error(2))+" \\\\ \r\n";
	std::cout << "Relative errors " << 100*error(0)/o2 <<"% "<<100*error(1)/o4 <<"% "<<100*error(2)/o6<<"%"<<std::endl;
	MSG+="Relative errors \t" + (100*error(0)/o2).ToString("G3") +"%\t"+(100*error(1)/o4).ToString("G3") +"%\t"+(100*error(2)/o6).ToString("G3")+"% \r\n";
	LATEX+="$\\frac{\\Delta\\Omega_2}{\\Omega_2}=$"+(100*error(0)/o2).ToString("G3")+"\\% $\\frac{\\Delta\\Omega_4}{\\Omega_4}=$" +(100*error(1)/o4).ToString("G3")+"\\% $\\frac{\\Delta\\Omega_6}{\\Omega_6}=$"+(100*error(2)/o6).ToString("G3")+" \\%  \\\\\r\n";
	std::cout << "Effective relative error "<< 100*(error(0)/o2+error(1)/o4+error(2)/o6)<<"%"<<std::endl;
	LATEX+="$\\frac{\\Delta f}{f}=$ "+(100*(error(0)/o2+error(1)/o4+error(2)/o6)).ToString("G3")+"\\% \r\n";
	MSG+="Wavenumber\tPexp\tPtheor\t(Pexp-Ptheor)/Pexp \r\n";
	for (int i=0;i<size;i++){
		double ftheor;
		ftheor=f(u2[i], u4[i], u6[i], lambda0[i],n,TwoJPlusOne,o2, o4,o6);
		sumdfexp=sumdfexp+abs(pow((fexp[i]-ftheor),2));
		sumfexp=sumfexp+fexp[i]/size;
		std::cout << fexp[i]<<" " << ftheor<<"  "<< (fexp[i]-ftheor)/fexp[i]<<" "<<std::endl;
		MSG+=(1.0/lambda0[i]).ToString()+"\t"+fexp[i].ToString("G4")+"\t"+ftheor.ToString("G4")+"\t"+(abs(100*(fexp[i]-ftheor)/fexp[i])).ToString("G4")+"%\r\n";
	}
	MSG+="-----------------------------------------------\r\n";
	std::cout<<"-----------------------------------------------"<<std::endl;
	std::cout<<"RMS = " <<sqrt(sumdfexp/(size-3))<<" RMS/avg f "<<100*sqrt(sumdfexp/(size-3))/sumfexp<<"%"<<std::endl;
	LATEX+="RMS = "+lf(sqrt(sumdfexp/(size-3)))+"$\\frac{RMS}{\\underline{f}}$= "+(100*sqrt(sumdfexp/(size-3))/sumfexp).ToString("G3") +"\\%\r\n\r\n";
	MSG+="RMS = "+sqrt(sumdfexp/(size-3)).ToString("G4")+" RMS/avg f = "+ (100*sqrt(sumdfexp/(size-3))/sumfexp).ToString("G3")+"% \r\n";

}

void FitSolarz(std::vector <double> u2, std::vector<double> u4, std::vector <double> u6, std::vector <double> lambda0,double n,double TwoJPlusOne,double &o2, double &o4, double &o6, std::vector <double> fexp,System::String^ &MSG,System::String^ &LATEX)
{
	MatrixXd Hessian,Hessiandiag;
	MatrixXd Grad;
	MatrixXd parameters(3,1);
	MatrixXd newparams(3,1);
	MatrixXd error(3,1);
	parameters<<o2,o4,o6;
	double no2,no4,no6,sumfexp,sumdfexp;
	double lambda,chi2s,chi2n;
	lambda=1/1024.0;
	sumdfexp=0;
	sumfexp=0;
	chi2s=0;
	MSG+="Num.      \tChi2              \tO2                 \tO4               \tO6\r\n";
	std::cout <<"Beginnig fitting procedure."<<std::endl;
	for(int i=1;i<100;i++)
	{
		chi2s=chi2Solarz(u2,u4,u6,lambda0,n,TwoJPlusOne,o2,o4,o6,fexp);
		CalculateHessian(u2,u4,u6,lambda0,n,TwoJPlusOne,o2, o4, o6, fexp, Hessian,Grad);
		Hessiandiag=Hessian.diagonal().asDiagonal();
		newparams=parameters-((Hessian+lambda*Hessiandiag).inverse()*Grad);
		no2=abs(newparams(0,0));
		no4=abs(newparams(1,0));
		no6=abs(newparams(2,0));
		chi2n=chi2Solarz(u2,u4,u6,lambda0,n,TwoJPlusOne,no2,no4,no6,fexp);
		std::cout<< i <<" "<< chi2s <<" " <<no2<<" "<<no4<<" "<<no6<<std::endl;
		MSG+=i.ToString()+"\t"+chi2s.ToString("G6")+"\t"+no2.ToString("G6")+"\t"+no4.ToString("G6")+"\t"+no6.ToString("G6")+"\r\n";
		if (chi2n<chi2s){
			parameters=newparams;
			o2=no2;
			o4=no4;
			o6=no6;
			lambda=lambda*1.1;
		}
		else
		{
			lambda=lambda/1.1;
		}
	};
	std::cout <<"Fitting finished"<<std::endl;
	MSG+="Fitting finished \r\n";
	int size=u2.size();
	error=(Hessiandiag.inverse().diagonal()*chi2n/(size-3));
	for (int i=0;i<3;i++) error(i)=abs(sqrt(error(i)));
	std::cout <<"Errors "<< error(0)<<" "<<error(1)<<" "<< error(2)<<std::endl;
	MSG+="Parameters\t o2="+o2.ToString("G4")+"\t o4="+o4.ToString("G4")+"\t o6="+o6.ToString("G4")+"\r\n";
	MSG+="Errors \t do2="+error(0).ToString("G2")+"\t do4="+error(1).ToString("G2")+"\t do6="+error(2).ToString("G2")+"\r\n";
	//LATEX+="$\\Omega_2$ ="+mantissa(o2).ToString("G4")+"$\\cdot$ 10$^{"+exponent(o2)+"}$ $\\Omega_4$ ="+mantissa(o4).ToString("G4")+"$\\cdot$ 10$^{"+exponent(o4)+"}$ $\\Omega_6$ ="+mantissa(o6).ToString("G4")+"$\\cdot$ 10$^{"+exponent(o6)+"}$ \\\\ \r\n";
	LATEX+="$\\Omega_2$ ="+lf(o2)+" $\\Omega_4$ ="+lf(o4)+" $\\Omega_6$ ="+lf(o6) +"\\\\ \r\n";
	LATEX+="$\\Delta\\Omega_2$ ="+lf(error(0))+" $\\Delta\\Omega_4$ ="+lf(error(1))+" $\\Delta\\Omega_6$ ="+lf(error(2))+" \\\\ \r\n";
	std::cout << "Relative errors " << 100*error(0)/o2 <<"% "<<100*error(1)/o4 <<"% "<<100*error(2)/o6<<"%"<<std::endl;
	MSG+="Relative errors \t" + (100*error(0)/o2).ToString("G3") +"%\t"+(100*error(1)/o4).ToString("G3") +"%\t"+(100*error(2)/o6).ToString("G3")+"% \r\n";
	LATEX+="$\\frac{\\Delta\\Omega_2}{\\Omega_2}=$"+(100*error(0)/o2).ToString("G3")+"\\% $\\frac{\\Delta\\Omega_4}{\\Omega_4}=$" +(100*error(1)/o4).ToString("G3")+"\\% $\\frac{\\Delta\\Omega_6}{\\Omega_6}=$"+(100*error(2)/o6).ToString("G3")+" \\%  \\\\\r\n";
	std::cout << "Effective relative error "<< 100*(error(0)/o2+error(1)/o4+error(2)/o6)<<"%"<<std::endl;
	LATEX+="$\\frac{\\Delta f}{f}=$ "+(100*(error(0)/o2+error(1)/o4+error(2)/o6)).ToString("G3")+"\\% \r\n";
	MSG+="Pexp\tPtheor \r\n";
	for (int i=0;i<size;i++){
		sumdfexp=sumdfexp+abs(pow((fexp[i]-f(u2[i], u4[i], u6[i], lambda0[i],n,TwoJPlusOne,o2, o4,o6)),2));
		sumfexp=sumfexp+fexp[i]/size;
		std::cout << fexp[i]<<" " << f(u2[i], u4[i], u6[i], lambda0[i],n,TwoJPlusOne,o2, o4,o6)<<"  "<<std::endl;
		MSG+=fexp[i].ToString()+f(u2[i], u4[i], u6[i], lambda0[i],n,TwoJPlusOne,o2, o4,o6).ToString()+"\r\n";
	}
	MSG+="-----------------------------------------------\r\n";
	std::cout<<"-----------------------------------------------"<<std::endl;
	std::cout<<"RMS = " <<sqrt(sumdfexp/(size-3))<<" RMS/avg f "<<100*sqrt(sumdfexp/(size-3))/sumfexp<<"%"<<std::endl;
	LATEX+="RMS = "+lf(sqrt(sumdfexp/(size-3)))+"$\\frac{RMS}{\\underline{f}}$= "+(100*sqrt(sumdfexp/(size-3))/sumfexp).ToString("G3") +"\\%\r\n\r\n";
	MSG+="RMS = "+sqrt(sumdfexp/(size-3)).ToString("G4")+" RMS/avg f = "+ (100*sqrt(sumdfexp/(size-3))/sumfexp).ToString("G3")+"% \r\n";

}

void FitBranching(Experiment &BExp,System::String^ &MSG,System::String^ &LATEX){
	MatrixXd Hessian,Hessiandiag;
	MatrixXd Grad;
	MatrixXd parameters(4,1);
	MatrixXd newparams(4,1);
	MatrixXd error(4,1);
	double o2,o4,o6,femi;
	parameters<<BExp.o2,BExp.o4,BExp.o6,BExp.femi;
	std::cout <<parameters<<std::endl;
	o2=BExp.o2;
	o4=BExp.o4;
	o6=BExp.o6;
	femi=BExp.femi;
	double no2,no4,no6,sumfexp,sumdfexp;
	double lambda,chi2s,chi2n,nfemi;
	lambda=1/4096.0;
	sumdfexp=0;
	sumfexp=0;
	chi2s=0;
	MSG+="Num.\tChi2\tO2\tO4\tO6\r\n";
	std::cout <<"Begining fitting procedure."<<std::endl;
	for(int i=1;i<100;i++)
	{
		chi2s=chi2br(BExp,o2,o4,o6,femi);
		CalculateHessianBr(BExp,o2,o4,o6,femi,Hessian,Grad);
		Hessiandiag=Hessian.diagonal().asDiagonal();
		newparams=parameters-((Hessian+lambda*Hessiandiag).inverse()*Grad);
		no2=newparams(0,0);
		no4=newparams(1,0);
		no6=newparams(2,0);
		nfemi=newparams(3,0);
		chi2n=chi2br(BExp,no2,no4,no6,nfemi);
		std::cout<< i <<" "<< chi2n <<" " <<no2<<" "<<no4<<" "<<no6<<" "<<nfemi<<" "<<lambda<<std::endl;
		MSG+=i.ToString("G5")+"\t"+chi2n.ToString("G5")+"\t"+no2.ToString("G5")+"\t"+no4.ToString("G5")+"\t"+no6.ToString("G5")+"\t"+nfemi.ToString("G5")+"\r\n";
		if (chi2n<chi2s){
			parameters=newparams;
			o2=no2;
			o4=no4;
			o6=no6;
			femi=nfemi;
			lambda=lambda*1.1;
		}
		else
		{
			lambda=lambda/1.1;
			std::cout<<"Step failed"<<std::endl;
		}
	}
	int size,size1,size2;
	size=BExp.AbsoMulti.u2.size()+BExp.BMulti.u2.size();
	size1=BExp.AbsoMulti.u2.size();
	size2=BExp.BMulti.u2.size();
	error=(Hessiandiag.inverse().diagonal()*chi2n/(size-4));
	for (int i=0;i<4;i++) error(i)=abs(sqrt(error(i)));
	std::cout <<"Errors "<< error(0)<<" "<<error(1)<<" "<< error(2)<<" "<<error(3)<<std::endl;
//	MSG+=error(0).ToString("G5")+" "+error(1).ToString("G5")+" "+error(2).ToString("G5")+" "+error(3).ToString("G5")+" "+"\r\n";
	MSG+="Parameters\t o2="+o2.ToString("G4")+"\t o4="+o4.ToString("G4")+"\t o6="+o6.ToString("G4")+"\t Femi="+femi.ToString("G4")+"\r\n";
	MSG+="Errors \t do2="+error(0).ToString("G2")+"\t do4="+error(1).ToString("G2")+"\t do6="+error(2).ToString("G2")+"\t dFemi"+error(3).ToString("G2")+"\r\n";
	MSG+="Relative errors \t" + (100*error(0)/o2).ToString("G3") +"%\t"+(100*error(1)/o4).ToString("G3") +"%\t"+(100*error(2)/o6).ToString("G3")+"%\t"+(100*error(3)/femi).ToString("G3")+"%\r\n";
	MSG+="Pexp\tPtheor \r\n";
	MSG+="Absorption \r\n";
	for (int i=0;i<size1;i++){
		sumdfexp=sumdfexp+abs(pow(BExp.AbsoMulti.fexp[i]-f(BExp.AbsoMulti.u2[i], BExp.AbsoMulti.u4[i], BExp.AbsoMulti.u6[i], BExp.AbsoMulti.lambda[i],BExp.n,BExp.AbsoMulti.TwoJPlusOne,o2, o4,o6),2));
		sumfexp=sumfexp+BExp.AbsoMulti.fexp[i]/size;
		std::cout << BExp.AbsoMulti.fexp[i]<<" " << f(BExp.AbsoMulti.u2[i], BExp.AbsoMulti.u4[i], BExp.AbsoMulti.u6[i], BExp.AbsoMulti.lambda[i],BExp.n,BExp.AbsoMulti.TwoJPlusOne,o2, o4,o6)<<"  "<<std::endl;
		MSG+=BExp.AbsoMulti.fexp[i].ToString("G4")+" "+f(BExp.AbsoMulti.u2[i], BExp.AbsoMulti.u4[i], BExp.AbsoMulti.u6[i], BExp.AbsoMulti.lambda[i],BExp.n,BExp.AbsoMulti.TwoJPlusOne,o2, o4,o6).ToString("G4")+"\r\n";
	}
		MSG+="Emission \r\n";
	for (int i=0;i<size2;i++){
		sumdfexp=sumdfexp+abs(pow(BExp.BMulti.branching[i]*femi-f(BExp.BMulti.u2[i], BExp.BMulti.u4[i], BExp.BMulti.u6[i], BExp.BMulti.lambda[i],BExp.n,BExp.BMulti.TwoJPlusOne,o2, o4,o6),2));
		sumfexp=sumfexp+BExp.BMulti.branching[i]*femi/size;
		std::cout<<BExp.BMulti.branching[i]*femi <<" "<<f(BExp.BMulti.u2[i], BExp.BMulti.u4[i], BExp.BMulti.u6[i], BExp.BMulti.lambda[i],BExp.n,BExp.BMulti.TwoJPlusOne,o2, o4,o6)<<std::endl;
		MSG+=(BExp.BMulti.branching[i]*femi).ToString("G4")+" "+f(BExp.BMulti.u2[i], BExp.BMulti.u4[i], BExp.BMulti.u6[i], BExp.BMulti.lambda[i],BExp.n,BExp.BMulti.TwoJPlusOne,o2, o4,o6).ToString("G4")+"\r\n";
	}
	std::cout<<"RMS = " <<sqrt(sumdfexp/(size-4))<<" RMS/avg f "<<100*sqrt(sumdfexp/(size-4))/sumfexp<<"%"<<std::endl;
	LATEX+="RMS = "+lf(sqrt(sumdfexp/(size-4)))+"$\\frac{RMS}{\\underline{f}}$= "+(100*sqrt(sumdfexp/(size-4))/sumfexp).ToString("G3") +"\\%\r\n\r\n";
	MSG+="RMS = "+sqrt(sumdfexp/(size-4)).ToString("G4")+" RMS/avg f = "+ (100*sqrt(sumdfexp/(size-4))/sumfexp).ToString("G3")+"% \r\n";

	BExp.o2=o2;
	BExp.o4=o4;
	BExp.o6=o6;
}
