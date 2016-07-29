#ifndef multiplet_h
#define multiplet_h
#include <vector>
class Multiplet
{
public:
	std::vector <double> u2;
	std::vector <double> u4;
	std::vector <double> u6;
	std::vector <double> lambda;
	std::vector <double> Ajj;
	std::vector <double> fexp;
	std::vector <double> branching;
	double twojplusone;
	bool filled;
	Multiplet(void);
	~Multiplet(void);
};
#endif