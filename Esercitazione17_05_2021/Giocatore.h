#ifndef GIOCATORE_H
#define GIOCATORE_H

#include <iostream>

using namespace std;

class Giocatore{
	string nome, cognome, circolo, anno_nascita;
	double punteggio;
	
	public:
		Giocatore(string nome, string cognome, string circolo, string anno_nascita, double punteggio) : nome(nome), cognome(cognome), anno_nascita(anno_nascita), punteggio(punteggio){}
		
		Giocatore() : Giocatore("","","","",0){}
		
		string getNome() const { return nome;}
		string getCognome() const { return cognome;}
		string getCircolo() const { return circolo;}
		string getAnno_nascita() const { return anno_nascita;}
		double getPunteggio() const { return punteggio;}
		
		
		friend ostream& operator<<(ostream& out, const Giocatore g){
			out<<"Giocatore -> Nome: "<<g.nome<<" Cognome: "<<g.cognome<<" Circolo: "<<g.circolo<<" Classe: "<<g.anno_nascita;
			out<<"\t PUNTEGGIO-> "<<g.punteggio;
			return out;
		}
	
	
};
#endif
