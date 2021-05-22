#ifndef LIST_DLS_H
#define LIST_DLS_H

#include <iostream>
#include "node_dl.h"

using namespace std;

template<class T>

class ListDLS{
	NodeDL<T> *head,*tail,*nil;
	int length;
	bool ascend;
	
	public:
		
		ListDLS(bool ascend) : head(NULL) , tail(NULL) ,length(0), ascend(ascend){
			nil = new NodeDL<T>;
		}
		ListDLS() : ListDLS(true){}
		
		bool isEmpty(){ //verifica se la lista è vuota
			return (head == NULL) && (tail == NULL);
		}
		
		//getter, non implementiamo setter per evitare di avere situazioni di memoria non consistente
		NodeDL<T> *getHead() const {return head;}
		NodeDL<T> *getTail() const {return tail;}
		NodeDL<T> *getNil() const {return nil;}
		int getLength() const {return length;}
		bool isAscend() const{return ascend;}
		
		void insertHead(T value){
			NodeDL<T> * n = new NodeDL<T>(value);
			
			if(this->isEmpty()){
				n->setNext(nil); // aggiorno i riferimenti a precedente e successivo per il nuovo nodo
				n->setPrev(nil);
				head = n;
				tail = n;
				nil->setNext(head);
				nil->setPrev(tail);
				length++;
				return;
			}
			else {
				 n->setNext(head);
				 head->setPrev(n);
				 n->setPrev(nil);
				 nil->setNext(n);
				 head = n;
				 length++;
				 return;
			}
		}
		
		void insertTail(T value){
			
			if(this->isEmpty()) {
				this->insertHead(value);
				return;
			}
			
			NodeDL<T> * n = new NodeDL<T>(value);
			n->setPrev(tail);
			tail->setNext(n);
			n->setNext(nil);
			nil->setPrev(n);	
			tail = n;
			
			length++;
			return;	
		}
		
		
		void insert(T value){
			
			if((ascend && (value < head->getValue())) || (!ascend && (value >= head->getValue()))){
				this->insertHead(value);
				return;
			}
			
			if((ascend && (value >= tail->getValue())) || (!ascend && (value < tail->getValue()))){
				this->insertTail(value);
				return;
			}
			
			NodeDL<T> * cur = head;
			NodeDL<T> * n = new NodeDL<T>(value);
			if(ascend){
				while((*cur < *n) && cur->getNext() != nil) {
					cur = cur->getNext();
				}
				n->setPrev(cur->getPrev());
				n->setNext(cur);
				cur->getPrev()->setNext(n);
				cur->setPrev(n);
				length++;
				return;
			}
			else {
				while((*cur >= *n) && cur->getNext() != nil) {
					cur = cur->getNext();
				}
				n->setPrev(cur->getPrev());
				n->setNext(cur);
				cur->getPrev()->setNext(n);
				cur->setPrev(n);
				length++;
				return;
			}
		}
		
		void deleteHead(){
			if(this->isEmpty()){
				return;
			}
			head->getNext()->setPrev(nil);
			nil->setNext(head->getNext());
			NodeDL<T> * tmp = head;
			head = head->getNext();
			
			length--;
			delete tmp;
			return;
			
		}
		
		void deleteTail(){
			if(this->isEmpty()){
				return;
			}
			
			tail->getPrev()->setNext(nil);
			nil->setPrev(tail->getPrev());
			NodeDL<T> * tmp = tail;
			tail = tail->getPrev();
			
			length--;
			delete tmp;
			return;
		}
		
		NodeDL<T> * search(T value){
			NodeDL<T> * tmp = new NodeDL<T>(value);
			
			if((ascend && (*tmp < *head)) || (!ascend && (*tmp < *tail)) || (ascend && (*tmp >= *tail)) || (!ascend && (*tmp >= *head))){return NULL;}
			
			NodeDL<T> * cur = head;
			
			while(*cur != *tmp && cur != nil){
				cur = cur->getNext();
			}
			
			if(cur == nil){
				return NULL;
			}
			else{
				return cur;
			}
		}
		
		friend ostream& operator<<(ostream& out, const ListDLS<T> list) {
			out << "Lista di lunghezza " <<list.length << ", head = "<< list.head << " ,tail = " << list.tail <<endl;
			NodeDL<T> * cur = list.head;
			while(cur != list.nil){
				out<< " \t " << *cur <<endl;
				cur = cur->getNext();
			}
			return out;
		}
};
#endif
