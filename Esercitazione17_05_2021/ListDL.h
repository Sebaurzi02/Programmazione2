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
			
		}
};
#endif

