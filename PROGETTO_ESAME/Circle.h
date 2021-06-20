#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <cmath>
#include "Shape.h"

using namespace std;

class Circle : public Shape{
	double R;
	
	public:
		Circle() : Circle(0){}
		Circle(double R) : R(R){}
		
		double getPerimetro(){
			return 2*M_PI*R;
		}
		
		double getRaggio(){
			return R;
		}
		
		double getDiametro(){
			return 2*R;
		}
		
		void setRaggio(double R){ this->R = R;}
		
		friend ostream& operator<<(ostream& out,Circle& c){
			out<<"Sono un Cerchio con raggio: "<<c.R<<" e diametro: "<<c.getDiametro()<<endl;
			return out;
		}
};
#endif
