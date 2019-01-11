#include <iostream>
#include "pila.h"
#include "code.h"

using namespace std;

int main(){
	
	coda<int> c;
	Pila<int> p;
	p.creaPila(); 
	c.creacoda();

	cout<<"\t\tPILA"<<endl;
	cout<<"P e' vuota? "<<(p.pilaVuota() ? "si":"no")<<endl;
	
	p.push(5);
	p.push(7); 
	p.push(9);
	p.push(5);
	 
	p.stampaPila(p);

	cout<<p.leggiPila()<<endl;
	cout<<p.leggiPila()<<endl;
	
	p.pop();   
	cout<<p.leggiPila()<<endl;
	cout<<"P e' vuota? "<<(p.pilaVuota() ? "si":"no")<<endl;
	p.pop();
	cout<<p.leggiPila()<<endl; 
		p.pop();
		p.push(14);
		p.pop();
	cout<<p.leggiPila()<<endl;  
	
	p.stampaPila(p); 
	 
	cout<<endl; 
	cout<<"\t\tCODA"<<endl;
	cout<<"C e' vuota? "<<(c.codaVuota() ? "si":"no")<<endl;
	
	cout<<"Testa Coda: "<<c.getTesta()<<"\tFondo Coda: "<<c.getFondo()<<endl;
    c.push(31);
    c.push(5);
    c.push(7);
    c.push(1);
    
    cout<<"Testa Coda: "<<c.getTesta()<<"\tFondo Coda: "<<c.getFondo()<<endl;
    cout<<"Primo elem: "<<c.leggiCoda()<<endl;   
  	  
	c.stampaCoda();  
	c.pop();
	
	cout<<"Testa Coda: "<<c.getTesta()<<"\tFondo Coda: "<<c.getFondo()<<endl;
	c.stampaCoda(); 
	c.pop();
	c.push(6);
	
	cout<<"Testa Coda: "<<c.getTesta()<<"\tFondo Coda: "<<c.getFondo()<<endl;
	c.stampaCoda();
	return 0; 
	
}
