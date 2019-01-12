#include <iostream>
#include "insieme.h"

using namespace std;

int main(){
	  
	insieme<int> a,b,c,d,e,s;
	a.creaInsieme(); 
	b.creaInsieme();
	c.creaInsieme();
	d.creaInsieme();   
	e.creaInsieme();
	s.creaInsieme();
	
	cout<<"A e' vuoto? "<<(a.InsiemeVuoto() ? "si":"no")<<endl;
	
	a.InserisciIns(3);
	a.InserisciIns(5);

	cout<<"A e' vuoto? "<<(a.InsiemeVuoto() ? "si":"no")<<" lunghezza: "<<a.getLungh()<<endl;
	
	b.InserisciIns(1);
	b.InserisciIns(7);
	b.InserisciIns(5); 
	b.InserisciIns(2);
	a.InserisciIns(6);
	a.InserisciIns(0);
	a.InserisciIns(74);
	b.InserisciIns(17);
	
	cout<<"74 appartiene ad A? "<<(a.appartiene(74)? "si":"no")<<endl;
	cout<<"74 appartiene a B? "<<(b.appartiene(74)? "si":"no")<<endl;
	
	
	c.unione(a,b);
	cout<<"\t\tINS A:"<<endl;
	a.stampaIns();
	a.cancella(6);
	a.cancella(55);  
	a.InserisciIns(1);
	cout<<"\t\tINS A:"<<endl;
	a.stampaIns();
	
	cout<<"\t\tINS B:"<<endl;
	b.stampaIns(); 
	cout<<"\t\tINS UNIONE:"<<endl;  
	c.stampaIns();
    
 
	cout<<"\t\tINS DIFFERENZA:"<<endl;
	e.stampaIns();
	
	 
	cout<<"\t\tINS INTERSEZIONE:"<<endl;
	d.stampaIns();
	  
	cout<<"MIN B:"<<b.findMin()<<endl;
     
    s.SetaccioEratostene(2,521);      
	  
	return 0; 
	
}
