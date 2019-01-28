#include <iostream>
#include "dictionary.h"
#include <string>

using namespace std;

int main(){ 
	dictionary<int,int> t;
	t.create();
	cout<<"Empty ?"<<(t.empty() ? "yes":"no")<<endl;
	t.insert(15);
	t.insert(22);
	t.insert(36);
	t.insert(1);
	t.insert(400);
	t.insert(2);
	cout<<"Size? "<<t.size()<<endl;
    t.stampa();

	
	
	return 0;
}
