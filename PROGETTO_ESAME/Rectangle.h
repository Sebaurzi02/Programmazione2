#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "Shape.h"

using namespace std;

class Rectangle : public Shape{
	double H,B;
	
	public:
		Rectangle() : Rectangle(0,0){}
		Rectangle(double H, double B): H(H), B(B){}
		
		double getPerimetro(){
			return (2*H)+(2*B);
		}
		
		double getAltezza(){
			return H;
		}
		
		double getBase(){
			return B;
		}
		
		void setAltezza(double H){this->H = H;}
		void setBase(double B){this->B = B;}
		
		friend ostream& operator<<(ostream& out,Rectangle& r){
			out<<"Sono un rettangolo con altezza: "<<r.H<<" e base : "<<r.B<<endl;
			return out;
		}
};
#endif
