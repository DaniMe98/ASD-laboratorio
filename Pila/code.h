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
			coda<ele> & operator =(const coda<ele> & );
			void creacoda();
			void pop();
			bool codaVuota();
			void push(types elee);
			void stampaCoda();
			types leggiCoda();
			int getTesta();
			int getFondo();
			coda<ele> & positivi(const coda<ele>& c);
	
		protected:
			int testa;
			types *element;
			int MAXLUNG=100;
			int fondo;
			
	
}; 

template<class ele>
coda<ele> &coda<ele>::operator=(const coda<ele> &c){
	
	this->~coda();
	 
	coda::fondo=c.fondo;
	coda::testa=c.testa;
	this->element=new types[c.MAXLUNG];
	
	for(int i=testa; i<fondo; i++){
			coda::element[i]=c.element[i];
	}
}


template<class ele>
coda<ele> & coda<ele>::positivi(const coda<ele> &c){
		
		this->~coda();
		this->MAXLUNG=c.MAXLUNG;			
			for(int i=c.testa; i<c.fondo; i++){
				if(c.element[i]>=0){
							this->push(c.element[i]);
							cout<<"c: "<<c.element[i]<<"this: "<<this->element[i]<<endl;
					}					
			}
				
	return *this;
}

template<class ele>
int coda<ele>::getTesta(){
	return coda::testa;
}

template<class ele>
int coda<ele>::getFondo(){
	if(fondo==0){
					return coda::fondo;
						}else{
									return coda::fondo-1;
						}
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
	if(!this->codaVuota()){
	return this->element[this->testa];
			}else{
					cout<<"Nessun elemento da visualizzare"<<endl;
				}
}

template<class ele>
void coda<ele>::pop(){
	
	if(!this->codaVuota()){
		this->testa=this->testa+1;
		}else{
			cout<<"Coda gia' vuota."<<endl;
		}
}

template<class ele>
void coda<ele>::push(types elee){
	if(this->fondo-this->testa==this->MAXLUNG){
			cout<<"Capienza massima coda raggiunta."<<endl;
			}else{
					
					this->element[this->fondo]=elee;
					this->fondo++;
					
			}
}

template<class ele>
void coda<ele>::stampaCoda(){
		int j=1;
	if(!this->codaVuota()){
		for(int i=this->testa; i<this->fondo; i++){
				
				cout<<"Elemento coda n. ("<<j<<") : "<<this->element[i]<<endl;
				j++;
				}
		}else{
			cout<<"Coda Vuota"<<endl;
		}
}

#endif //_CODA_H
