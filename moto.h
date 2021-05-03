#include <iostream>
#include <sstream>
#include "veicolo.h"

class Moto : public Veicolo {
	public:
		
		Moto(int velocitaMassima, double prezzo, std::string marca , std::string motorizzazione) : Veicolo(2, velocitaMassima, prezzo, marca, "benzina", motorizzazione){}
		
		std::string toString() const{
			std::stringstream stream;
			
			stream<<"Sono una moto di marca "<< marca <<", "<< motorizzazione<<" "<< carburante <<" . La mia velocita e' di "<< velocita << "km/h";
			return stream.str();
		}
		
		/*
		 friend std::ostream& operator<<(std::ostream& out, const Moto& m){
			out<<m.toString();
			return out;
		}
		*/
};
