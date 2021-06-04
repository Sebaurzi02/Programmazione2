#include "NodeBST.h"
#include "BST.h"
#include <cstdlib>

int main(){
	NodeBST<int> n1(10);
	NodeBST<int> n2(107);
	NodeBST<int> n3(120);
	
	cout<< n1 <<endl;
	cout<< n2 <<endl;
	cout<< n3 <<endl;
	
	BST<int> tree;
	srand(0);
	for(int i=0; i < 20 ; i++){
		tree.insert(rand()%201);
	}
	tree.inorder();
	
}
