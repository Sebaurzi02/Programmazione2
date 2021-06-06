#include "Giocatore.h"
#include "ListDL.h"
#include <fstream>
#include <sstream>

using namespace std;

static void Caricamento(ListDL<Giocatore>& list){
	ifstream ifs("Punteggi.txt",ifstream::in);
	int i=1;
	
	while(ifs.eof() == false){
		Giocatore g;
		ifs>>g;
		//cout << "Giocatore caricato #" << i++ << ": " << g << endl;
		list.insert(g);
	}
	ifs.close();
}

int main(){
	ListDL<Giocatore> list(true);
	Caricamento(list);
	cout<<list;
}

