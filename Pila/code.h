#ifndef _CODA_H
#define _CODA_H
#include <iostream>

using namespace std;

template<class ele>
class coda{
	
		typedef ele types;
		
		public:
			//costruttori
			coda();
			coda(int i);
			~coda(){delete element;};
			
			//operatori
			void creacoda();
			void pop();
			bool codaVuota();
			void push(types elee);
			void stampaCoda();
			types leggiCoda();
			int getTesta();
			int getFondo();
	
		protected:
			int testa;
			types *element;
			int MAXLUNG=10;
			int fondo;
			
	
};

template<class ele>
int coda<ele>::getTesta(){
	return coda::testa;
}

template<class ele>
int coda<ele>::getFondo(){
	return coda::fondo-1;
}

template<class ele>
coda<ele>::coda(){
	coda::creacoda();
	coda::element= new types[coda::MAXLUNG];
}

template<class ele>
coda<ele>::coda(int i){
	coda::creacoda();
	coda::MAXLUNG=i;
	coda::element= new types[i];
}

template<class ele>
bool coda<ele>::codaVuota(){
	return(coda::fondo==0);
}

template<class ele>
void coda<ele>::creacoda(){
	coda::testa=0;
	coda::fondo=coda::testa;
	
}

template<class ele>
typename coda<ele>::types coda<ele>::leggiCoda(){
	if(!coda::codaVuota()){
	return element[testa];
			}else{
					cout<<"Nessun elemento da visualizzare"<<endl;
				}
}

template<class ele>
void coda<ele>::pop(){
	
	if(!coda::codaVuota()){
		coda::testa=coda::testa+1;
		}else{
			cout<<"Coda gia' vuota."<<endl;
		}
}

template<class ele>
void coda<ele>::push(types elee){
	if(fondo-testa==coda::MAXLUNG){
			cout<<"Capienza massima coda raggiunta."<<endl;
			}else{
					
					element[fondo]=elee;
					fondo++;
					
			}
}

template<class ele>
void coda<ele>::stampaCoda(){

	if(!coda::codaVuota()){
		for(int i=coda::testa; i<coda::fondo; i++){
				cout<<"Elemento coda n. ("<<i<<") : "<<coda::element[i]<<endl;
				}
		}else{
			cout<<"Coda Vuota"<<endl;
		}
}

#endif //_CODA_H
