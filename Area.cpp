#include "Area.h"

Area::Area(){

}

double Area::squareArea(std::pair<double,double> posLast, std::pair<double,double> posCur,std::pair<double,double> camLast,std::pair<double,double> camCur){
	LineCoe line1,line2;
	line1 = _lineCoe(posLast,posCur);
	line2 = _lineCoe(camLast,camCur);
	if((line1.a*line2.b - line2.a*line1.b) == 0){
		return this->_areaProduct(posLast,posCur,camLast) + this->_areaProduct(camLast,camCur,posCur);
	}
	else{
		std::pair <double,double> middlePoint;
		middlePoint.first = (line2.c*line1.b - line1.c*line2.b)/(line1.a*line2.b - line2.a*line1.b);
		middlePoint.second = (line2.c*line1.c - line1.a*line2.c)/(line1.a*line2.b - line2.a*line1.b);
		return this->_areaProduct(posLast,camLast,middlePoint) + this->_areaProduct(camCur,posCur,middlePoint);
	}
}

double Area::_areaProduct(std::pair<double,double> A,std::pair<double,double> B,std::pair<double,double> C){
	double product = ((A.first*B.second - A.second*B.first + A.second*C.first - A.first*C.second + B.first*C.second - C.first*B.second)/2.0);
	if(product < 0){
		return product*(-1);
	}
	return product;
}

Area::LineCoe Area::_lineCoe(std::pair<double,double> A,std::pair<double,double> B){
	LineCoe ret;
	ret.a = (A.second - B.second);
	ret.b = (B.first - A.first);
	ret.c = (A.first*B.second - B.first*A.second);
	return ret;
}

int main() {
  	Area area;
  	std::pair <double,double> A,B,C,D;

  	A.first	 = 0; 	//A1
  	A.second = 0;
	B.first  = 3;	//B1 C2
	B.second = 3;
	C.first  = 3;	//C1 A2
	C.second = 0;
	D.first  = 0;	//B2
	D.second = 3;

  	std::cout << area.squareArea(A,B,C,D) << '\n';

  	return 0;
}
