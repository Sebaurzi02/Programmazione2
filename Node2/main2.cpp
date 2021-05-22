#include "list_dls.h"

using namespace std;

int main(){
	ListDLS<int> list1;
	list1.insertHead(10);
	list1.insertTail(22);
	list1.insert(8);
	list1.insert(30);
	list1.insert(15);
	
	cout<<list1<<endl;
}
