#ifndef GARA_H
#define GARA_H
#include "veicolo.h"
#include <cstdlib>


class Gara {
	int durata;
	int numeroPartecipanti;
	int numeroIscritti;
	void controlla(int t);
	Veicolo ** veicoli;
	
	public:
		
		Gara(int durata, int partecipanti) : durata(durata), numeroPartecipanti(partecipanti){
			veicoli = new Veicolo*[numeroPartecipanti];
			numeroIscritti=0;
		}
		
		~Gara() {
			delete [] veicoli;
		}
		
		void partenza();
		void stampaClassifica();
		void aggiungiPartecipante(Veicolo& v);
		
};

#endif

void Gara::aggiungiPartecipante(Veicolo& v) {
	veicoli[numeroIscritti++] = &v;
}


void Gara::controlla(int t) {
	int massimo_temporaneo = veicoli[0]->getVelocita();
	int indice_massimo = 0;
	
	//std::cout << "Riga 42 file Gara - metodo controlla" << std::endl;
	
	for(int i=1; i < numeroIscritti; i++){
		//estrarre la velocita di ogni veicolo
		//e verificare chi è più avanti
		//RICERCA se vogliamo solo trovare il massimo
		//ORDINAMENTO se vogliamo la classifica completo
		if(veicoli[i]->getVelocita() > massimo_temporaneo){
			massimo_temporaneo = veicoli[i]->getVelocita();
			indice_massimo = i;
		}
	}
	
	std::cout<<"Il veicolo piu' veloce e' "<< *veicoli[indice_massimo]<<" e ha velocita' "<<massimo_temporaneo<<" nell'istante: "<<t<<std::endl;
	
}


void Gara::partenza() {
	srand(42);
	for(int i=0;i<durata;i++){
		
		for(int j=0;j<numeroIscritti;j++){
			
			//std::cout << "Riga 66 file Gara - metodo partenza" << std::endl;
			
			int scelta = rand()%2;
			if(scelta==1){
				veicoli[j]->accelera();
			}
			else
			  veicoli[j]->decelera();
		}
		
		this->controlla(i);
	}
	
	this->stampaClassifica();
}


void Gara::stampaClassifica() {
	std::cout << "Da stampare dopo aver implementato l'ordinamento "<<std::endl;
}





