#include "Coda.h"
#include "Stack.h"

using namespace std;

class AAA {
	string nome , cognome;
	public:
		AAA(string n, string c) : nome(n), cognome(c){}
		AAA() : AAA("",""){}
		
		friend ostream& operator<<(ostream& out, const AAA& a){
		    out<<a.nome<<" "<<a.cognome<<endl;
			return out;
		}
};

int main(){
	Queue<int> q;
	Stack<int> s;
	cout<<q<<endl;
	cout<<s<<endl;
	//cout<<q.isEmpty()<<endl;
	//cout<<q.isFull()<<endl;
	
	for(int i=0;i<10;i++){
		q.enqueue(i);
		//cout<<"size = "<<q.size()<<endl;
		s.push(i);
	}
	
    //cout<<q.isEmpty()<<endl;
	//cout<<q.isFull()<<endl;
	cout<<q<<endl;
	cout<<s<<endl;
	
	int a = q.dequeue();
	int a1 = s.pop();
	int b = q.dequeue();
	int b1 = s.pop();
	cout<<q<<endl;
	cout<<s<<endl;
	
}
