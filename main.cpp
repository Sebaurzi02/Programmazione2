#include "moto.h"
#include "Automobile.h"
#include "gara.h"

int main(){
	
	Moto m(120, 10000, "Ducati", "1000cc");
	Auto a(160, 8000, "Fiat Punto", "diesel", "1.300 MTJ");
	std::cout<<m<<std::endl;
	std::cout<<a<<std::endl;
	
	Gara gara(10,10);
	gara.aggiungiPartecipante(m);
	gara.aggiungiPartecipante(a);
	gara.partenza();
}
