#ifndef GIOCATORE_H
#define GIOCATORE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Giocatore{
	string nome, cognome, circolo, anno_nascita;
	double punteggio;
	
	public:
		Giocatore(string nome, string cognome, string circolo, string anno_nascita, double punteggio) : nome(nome), cognome(cognome),circolo(circolo), anno_nascita(anno_nascita), punteggio(punteggio){}
		
		Giocatore() : Giocatore("","","","",0){}
		
		friend istream& operator>>(istream& in,Giocatore& g){
			string punteggio_string;
			stringstream A;
			
			getline(in,g.cognome,';');
			getline(in,g.nome,';');
			getline(in,g.circolo,';');
			getline(in,punteggio_string,';');
			getline(in,g.anno_nascita,'\n');
			
			A<<punteggio_string;
			A>>g.punteggio;
			A.clear();
			
			return in;
		}
		
		friend ostream& operator<<(ostream& out, const Giocatore& g){
			out<<"Giocatore -> Nome: "<<g.nome<<" Cognome: "<<g.cognome<<" Circolo: "<<g.circolo<<" Classe: "<<g.anno_nascita<<"  PUNTEGGIO-> "<<g.punteggio;
			return out;
		}
		
		bool operator>(const Giocatore& g) const{
			return this->punteggio > g.punteggio;
		}
		
		bool operator<(const Giocatore& g) const{
			return this->punteggio < g.punteggio;
		}
		
		bool operator>=(const Giocatore& g) const{
			return this->punteggio >= g.punteggio;
		}
		
		bool operator<=(const Giocatore& g) const{
			return this->punteggio <= g.punteggio;
		}
		
		bool operator==(const Giocatore& g) const{
			return this->punteggio == g.punteggio;
		}
	
	
};
#endif
