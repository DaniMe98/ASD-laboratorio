#ifndef _INSIEME_H
#define _INSIEME_H

#include <iostream>

const int Max=100;

using namespace std;

template<class T>
class insieme{
				
			typedef T type;	
				
			public:
				//costruttori
				insieme();
				insieme(int n);
				~insieme(){delete[]	elementi;};
				
				//operatori
				insieme<type> & operator =(const insieme<type> &);
				void creaInsieme();
				void spostaElem(int i);
				bool InsiemeVuoto();
				void InserisciIns(type elemento);
				bool appartiene(type elemento);
				void cancella(type elemento);
				void unione(const insieme<type> &a,insieme<type> &b);
				void intersezione(const insieme<type> &a, insieme<type> &b);
				void differenza(const insieme<type> &a, insieme<type> &b);
				int getLungh();
				void stampaIns();
				void SetaccioEratostene(int a,int b);
				int findMin();
	
			protected:
				int lunghezza=0;
				type *elementi;
				
};

template<class T>
int insieme<T>::findMin(){
	int min=this->elementi[0];
	for(int i=1; i<this->lunghezza; i++){
			if(min>this->elementi[i]){
					min=this->elementi[i];
			}
	}
	return min;
}

template<class T>
void insieme<T>::SetaccioEratostene(int a, int b){
	this->~insieme();
	this->lunghezza=0;
	int min,i,multiplo=0,k=0,elem[Max];
	
	for(int j=a; j<b+1; j++){
		this->InserisciIns(j);
	}
	
	do{
		
		min=this->findMin();
		elem[k]=min;
		i=2;
		multiplo=0;
		
		while(multiplo<=b){
				multiplo=i*min;
				
					if(this->appartiene(multiplo)){
										this->cancella(multiplo);
										
										}
				if(this->appartiene(min)){
							this->cancella(min);
				}
				i++;
		};
		k+=1;
		
	}while(!this->InsiemeVuoto());	
	
	cout<<"I numeri primi nell'intervallo ["<<a<<","<<b<<"]  sono: "<<endl;
	
	for(int z=0; z<=k-1; z++){
		cout<<elem[z]<<endl;
		
	}
	
}
	





template<class T>
insieme<T>::insieme(){
	creaInsieme();
	this->elementi=new T[Max];
}

template<class T>
void insieme<T>::stampaIns(){
	if(this->InsiemeVuoto()){
		cout<<"VUOTO"<<endl;
	}else{
	for(int i=0; i<insieme<T>::lunghezza; i++){
		cout<<"Elemento n."<<i<<" :"<<this->elementi[i]<<endl;
	}
 }
}

template<class T>
insieme<T>::insieme(int n){
	insieme::creaInsieme();
	this->lunghezza=n;
	this->elementi=new T[n];
}

template<class T>
insieme<T>::getLungh(){
	return this->lunghezza;
}



template<class T>
void insieme<T>::creaInsieme(){
	this->elementi= new T[Max];
	this->lunghezza=0;		
}

template<class T>
bool insieme<T>::appartiene(T elemento){
	
	bool flag=false;
	
	for(int i=0; i<this->lunghezza; i++){
		if(elemento==this->elementi[i]){
			flag=true;
		}
	}
		return flag;
}

template<class T>
void insieme<T>::cancella(T elemento){
	if(!this->appartiene(elemento)){
		cout<<"Elemento non appartenente all'insieme."<<endl;
	}else{
		
		int i=0;
		bool flag=false;
		while(!flag){
			if(this->elementi[i]==elemento){
				flag=true;
				this->spostaElem(i);
			}else{
				i++;
			}
		}
	}
}

template<class T>
void insieme<T>::InserisciIns(T elemento){
	if(!this->appartiene(elemento)){
		this->elementi[lunghezza]=elemento;
		this->lunghezza+=1;
		
	}else{
		cout<<"Questo elemento appartiene gia all insieme."<<endl;
	}
}

template<class T>
bool insieme<T>::InsiemeVuoto(){
	return(this->lunghezza==0);
}

template<class T>
void insieme<T>::spostaElem(int i){
	for(int j=i; j<this->lunghezza-1; j++){
		this->elementi[j]=this->elementi[j+1];
	}
	this->lunghezza-=1;
}

template<class T>
insieme<T> &insieme<T>::operator =(const insieme<T> &f){
	
	this->~insieme();
	
	this->elementi=new T[f.lunghezza];
	this->lunghezza=f.lunghezza;
	
	for(int i=0; i<lunghezza; i++){
		this->elementi[i]=f.elementi[i];
	}
	
}

template<class T>
void insieme<T>::unione(const insieme<T> &a, insieme<T> &b){
	this->~insieme();
	this->lunghezza=0;
	
	for(int i=0; i<a.lunghezza; i++){
		this->InserisciIns(a.elementi[i]);
	}
	
	for(int j=0; j<b.lunghezza; j++){
		if(!this->appartiene(b.elementi[j])){
				this->InserisciIns(b.elementi[j]);
		}
	}

}

template<class T>
void insieme<T>::intersezione(const insieme<T> &a, insieme<T> &b){
	this->~insieme();
	this->lunghezza=0;
	
	for(int i=0; i<a.lunghezza; i++){
		
		if(b.appartiene(a.elementi[i])){
							this->InserisciIns(a.elementi[i]);
				}
		}
	
}

template<class T>
void insieme<T>::differenza(const insieme<T> &a, insieme<T> &b){
	this->~insieme();
	this->lunghezza=0;
	
	for(int i=0; i<a.lunghezza; i++){
		
		if(!b.appartiene(a.elementi[i])){
							this->InserisciIns(a.elementi[i]);
		}
	}
			
	
}

#endif //_INSIEME_H
