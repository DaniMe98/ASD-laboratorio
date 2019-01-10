#include <iostream>
#include "lista.h"
#include <string.h>

using namespace std;

int main(){
	lista<int> l;
	l.crealista();
	l.inslista(1,l.primolista());
	l.inslista(2,l.succlista(l.primolista()));
	l.inslista(3,l.succlista(l.succlista(l.primolista())));
	l.inslista(5,l.succlista(l.succlista(l.succlista(l.primolista()))));
	
	l.insListaOrd(4);
	
	l.stampal(l);
	
	cout<<"Palindroma "<<(l.palindroma(l) ? "si":"no")<<endl;
	
	l.inverti(l); 
	l.stampal(l); 
	 
	cout<<"Dimensione lista \t"<<l.size(l)<<endl;
	l.canclista(2);
	
	l.stampal(l);
	cout<<"Dimensione lista \t"<<l.size(l)<<endl;
	
	cout<<"Palindroma "<<(l.palindroma(l) ? "si":"no")<<endl;
	
	lista<string> c;
	
	c.crealista();
	c.inslista("arianna",c.primolista());
	c.inslista("cassiopea",c.succlista(c.primolista()));
	c.inslista("davide",c.succlista(c.succlista(c.primolista())));
	c.insListaOrd("casa");
	c.insListaOrd("cesium");
	
	c.stampal(c); 
	
	
	return 0;
	
}
