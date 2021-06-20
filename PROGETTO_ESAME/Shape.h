#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape{
	
	protected:
		virtual double getPerimetro() = 0;
	    friend std::ostream& operator<<(std::ostream& out, const Shape& shape){}
};
#endif
