#ifndef AREA_H
#define AREA_H

#include <iostream>
#include <utility>


class Area{
public:
	Area();
	double squareArea(std::pair<double,double> posLast, std::pair<double,double> posCur,std::pair<double,double> camLast,std::pair<double,double> camCur);
private:
	typedef struct linecoe{
		double a;
		double b;
		double c;
	} LineCoe;

	LineCoe _lineCoe(std::pair<double,double> A,std::pair<double,double> B);
	double _areaProduct(std::pair<double,double> A,std::pair<double,double> B,std::pair<double,double> C);
};

#endif
