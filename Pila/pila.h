#ifndef _PILA_H
#define _PILA_H

#include <iostream>

const int MAX=100;

using namespace std;

template<class elem>
class Pila{

		
	typedef elem type;

	public:
		//costruttori
		Pila();
		Pila(int t);
		~Pila(){delete elementi;};
		
		//operatori
		void creaPila();
		type leggiPila();
		void push(type eleem);
		void pop();
		bool pilaVuota();
		void stampaPila(Pila<elem> &p);
	
	protected:
		type *elementi;
		int testa;
	
	
};

template<class elem>
void Pila<elem>::stampaPila(Pila<elem> &p){
		if(Pila::pilaVuota()){
			cout<<"Nessun elemento da stampare";
		}else{	
			for(int i=0; i<p.testa; i++){
				cout<<"Posizione : ("<<i<<")"<<"elemento: "<<p.elementi[i]<<endl;
			}
		}
}

template<class elem>
Pila<elem>::Pila(){
	Pila::elementi=new type[100];
	Pila::creaPila();
}

template<class elem>
Pila<elem>::Pila(int t){
	Pila::elementi= new type[t];
	MAX=t;
	Pila::creaPila();
}

template<class elem>
void Pila<elem>::creaPila(){
	Pila::testa=0;
}

template<class elem>
typename Pila<elem>::type Pila<elem>::leggiPila(){
	if(Pila::pilaVuota()){
			cout<<"Pila vuota";
		}else{
		return Pila::elementi[testa-1];
		}
}

template<class elem>
bool Pila<elem>::pilaVuota(){
		return(testa==0);	
}

template<class elem>
void Pila<elem>::pop(){
	if(!Pila::pilaVuota()){
			Pila::testa-=1;
	}else{
		cout<<"Pila gia vuota"<<endl;
	}
}

template<class elem>
void Pila<elem>::push(type eleem){
	if(Pila::testa==MAX){
		cout<<"La pila ha raggiunto la capienza massima"<<endl;
	}else{
		bool flag=false;
		for(int i=0; i<Pila::testa; i++){
				if(eleem==Pila::elementi[i]){
					flag=true;
				}
		}
		if(flag){
				cout<<"Elemento gia' in pila"<<endl;
		}else{
			Pila::elementi[testa]=eleem;
			testa++;
		}
	}
	
}


#endif //_PILA_H
