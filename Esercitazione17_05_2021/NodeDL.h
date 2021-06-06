#ifndef NODEDL_H
#define NODEDL_H

#include <iostream>
#include <sstream>

using namespace std;

template<class S>
class NodeDL{
	S value;
	NodeDL<S> * prev;
	NodeDL<S> * next;
	
	int compareTo(const NodeDL<S>& n) const{
		if(this->value < n.value){ return -1;}
		if(this->value == n.value){ return 0;}
		if(this->value > n.value){ return 1;}
		
		return 0;
	}
	
	public:
		NodeDL(S value, NodeDL<S> *prev, NodeDL<S> *next) : value(value), prev(prev), next(next){}
		NodeDL(S value) : NodeDL(value,NULL,NULL){}
		NodeDL() : NodeDL(0,NULL,NULL){}
		
		void setValue(S value){this->value = value;}
		void setNext(NodeDL<S> *next){this->next = next;}
		void setPrev(NodeDL<S> *prev){this->prev = prev;}
		
		S getValue() const{ return value;}
		NodeDL<S> *getNext() const{ return next;}
		NodeDL<S> *getPrev() const{ return prev;}
		
		string toString() const {
			stringstream stream;
			stream<<" NodeDL value = "<<value<<", prev = "<<prev<<", next = "<<next;
			return stream.str();
		}
		
		friend ostream& operator<<(ostream& out,const NodeDL<S>& n){
			out<<n.toString();
			return out;
		}
		
		bool operator<(NodeDL<S>& n){
			return this->compareTo(n) < 0;
		}
		
		bool operator<=(NodeDL<S>& n){
			return this->compareTo(n) <= 0;
		}
		
		bool operator>(NodeDL<S>& n){
			return this->compareTo(n) > 0;
		}
		
		bool operator>=(NodeDL<S>& n){
			return this->compareTo(n) >= 0;
		}
		
		bool operator==(NodeDL<S>& n){
			return this->compareTo(n) == 0;
		}
		
		
	
};
#endif
