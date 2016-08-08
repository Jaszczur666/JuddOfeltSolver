#include "StdAfx.h"
#include "Multiplet.h"
#include "AuxFuncs.h"
#include <stdio.h>


Multiplet::Multiplet(void)
{
	filled=false;
}


Multiplet::~Multiplet(void)
{
}

void Multiplet::proveQuimbyToBeArchMoron(double o2,double o4,double o6){
	int size=u2.size();
	double sumdfexp;
	double sumfexp;
	sumdfexp=0;
	sumfexp=0;
	int TwoJPlusOne=9;
	for (int i=0;i<size;i++){
		double ftheor;

		double n=1.469+3927.0/pow((1e7/lambda[i]),2);
		ftheor=f(u2[i], u4[i], u6[i], lambda[i],n,TwoJPlusOne,o2, o4,o6);
		sumdfexp=sumdfexp+abs(pow((fexp[i]-ftheor),2));
		sumfexp=sumfexp+fexp[i]/size;
		std::cout << fexp[i]<<" " << ftheor<<"  "<< (fexp[i]-ftheor)/fexp[i]<<" "<<std::endl;
	}
	std::cout<<"-----------------------------------------------"<<std::endl;
	std::cout<<"RMS = " <<sqrt(sumdfexp/(size-3))<<" RMS/avg f "<<100*sqrt(sumdfexp/(size-3))/sumfexp<<"%"<<std::endl;

}
