#ifndef NODE_BST_H
#define NODE_BST_H

#include <iostream>

using namespace std;

template<class T>
class NodeBST {
	T key;
	NodeBST<T> *left, *right, *parent;
	
	public:
		NodeBST(T key) : key(key), left(NULL), right(NULL), parent(NULL){}
		NodeBST() : NodeBST(0) {}
		
		NodeBST<T> * getLeft() const{ return left;}
		NodeBST<T> * getRight() const{ return right;}
		NodeBST<T> * getParent() const{ return parent;}
		T getKey() const { return key;}
		
		void setLeft(NodeBST<T> *left){ this->left = left;}
		void setRight(NodeBST<T> *right){ this->right = right;}
		void setParent(NodeBST<T> *parent){ this->parent = parent;}
		void setKey(T key){ this->key = key;}
		
		friend ostream& operator<<(ostream& out , const NodeBST<T>& n){
			out<< "BST Node: "<<&n;
			out<<"\t key = "<<n.key<<" , left = "<<n.left<<" , right = "<<n.right<<" , parent = "<<n.parent;
			return out;
		}
};
#endif
