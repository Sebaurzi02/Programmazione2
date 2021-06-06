#ifndef LISTDL_H
#define LISTDL_H

#include "NodeDL.h"
#include <iostream>

using namespace std;

template<class S>
class ListDL{
	protected:
	     NodeDL<S> *head, *tail;
	     int length;
	     bool ascend;
	     
	    void insertAscending(S value){
		   NodeDL<S> * temp = new NodeDL<S>(value);
		   if(head == NULL && tail == NULL){ // in caso lista vuota
			  this->insertHead(value);
		      return;
	    	}
	    	
		   if(head->getValue() > value) {
			  this->insertHead(value);
			  return;
		    }
		    
		   if(tail->getValue() <= value){
			  this->insertTail(value);
			  return;
		    }
		    
		   NodeDL<S> * current = head;
		   //condizione arresto = nodo corrente minore di value e nodo successivo maggiore o uguale
		   while(current->getValue() < value) { // arrivo tra i due nodi dove inserire quello nuovo
			  current = current->getNext();
		    }
		
		   temp->setPrev(current->getPrev());
		   temp->setNext(current);
		   current->getPrev()->setNext(temp);
		   current->setPrev(temp);
		   length++;
	    }
	
	public:
		ListDL() : ListDL(true) {}
		ListDL(bool ascend) : head(NULL), tail(NULL), length(0), ascend(ascend){}
		
		void setAscendingOrder(){ ascend = true;}
		void setDescendingOrder(){ ascend = false;}
		
		NodeDL<S> *getHead() const{return this->head;}
		NodeDL<S> *getTail() const{return this->tail;}
		bool isAscending() const {return this->ascend; }
		int getLength() const{return this->length;}
		
		void insertHead(S value){
			NodeDL<S> * temp = new NodeDL<S>(value);
			
			if(head == NULL && tail == NULL){
				head = temp;
				tail = temp;
			}
			else{
				temp->setNext(head);
				head->setPrev(temp);
				head = temp;
			}
			length++;
		}
		
		void insertTail(S value){
			NodeDL<S> * temp = new NodeDL<S>(value);
			
			if(head == NULL && tail == NULL){
				head = temp;
				tail = temp;
			}
			else{
				temp->setPrev(tail);
				tail->setNext(temp);
				tail = temp;
			}
			
			length++;
		}
		
		void insert(S value){
			if(this->isAscending()){
				this->insertAscending(value);
			}
			else{
				cout<<"to be implemented "<<endl;
			}
			return;
		}
		
		void deleteValue(S value){
			if(head == NULL && tail == NULL){
				cout<< "Errore: empty list "<<endl;
				return;
			}
			NodeDL<S> * cur = head;
			while(cur != NULL && cur->getValue() != value){
				cur = cur->getNext();
			}
			if(cur == NULL) {
				cout<< "Errore: value "<< value << " not found." <<endl;
				return;
			}
			if(cur != head) {
				cur->getPrev()->setNext(cur->getNext());
			}
			if(cur != tail) {
				cur->getNext()->setPrev(cur->getPrev());
			}
			
			length--;
			
			if(cur == head) {
				head = head->getNext();
			}
			
			if(cur == tail) {
				tail = tail->getPrev();
			}
			
			delete cur;
		}
		
		friend ostream& operator<<(ostream& out, const ListDL<S> list){
			out << "Lista di lunghezza " <<list.length << ", head = "<< list.head << " ,tail = " << list.tail <<endl;
			NodeDL<S> * cur = list.head;
			while(cur != NULL){
				out<< " \t " << *cur <<endl;
				cur = cur->getNext();
			}
			return out;
		}
};
#endif

