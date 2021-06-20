#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include "Shape.h"

using namespace std;

class Triangle : public Shape{
	double A,B,C;
	
	public:
		Triangle(): Triangle(0,0,0){}
		Triangle(double A, double B, double C): A(A), B(B), C(C) {}
		
		double getPerimetro(){
			return A+B+C;
		}
		
		double getBase(){
			return B;
		}
		
		double getLatoA(){
			return A;
		}
		
		double getLatoC(){
			return C;
		}
		
		void setLatoA(double A){this->A = A;}
		void setBase(double B){this->B = B;}
		void setLatoC(double C){this->C = C;}
		
		friend ostream& operator<<(ostream& out,Triangle& t){
			out<<"Sono un Triangolo con Base: "<<t.B<<"  lato A : "<<t.A<<" lato C : "<<t.C<<endl;
			return out;
		}
};
#endif
