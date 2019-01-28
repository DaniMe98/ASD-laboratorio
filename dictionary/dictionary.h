
/* A dictionary is a collection of entries of the form (k,v), where k is a key and v is the value
 * associated with the key k (equivalently, v is the value whose key is k).
 */



#ifndef _DICTIONARY_H
#define _DICTIONARY_H
#include "insieme.h"
#include <string>

using namespace std;

template <class K, class E>
class dictionary
{
		typedef E tipoelem;
		typedef K tipo;
  public:
   ~dictionary() {} //constructor

   void create(); // create an empty dictionary
   bool empty() ; // return true if the dictionary is empty
   int size() ;	// return the number of entries in the dictionary
   tipoelem find(const tipo k); // return the entry with key k
   void insert(tipoelem e); // insert the entry e into the dictionary
   void erase(const tipo k);	// delete the entry with key k
   void modify(const tipo k,tipoelem e); // modify the value of the entry with key k to e
   void stampa();
  
  protected:
  	insieme<tipoelem> vettOrd;
	int ultimo;   

};

template<class K, class E>
void dictionary<K,E>::stampa(){
	vettOrd.stampaIns();
}


template<class K, class E>
void dictionary<K,E>::create(){
	this->vettOrd.creaInsieme();
	this->ultimo=vettOrd.getLungh();	
}

template<class K, class E>
bool dictionary<K,E>::empty(){
	return (vettOrd.InsiemeVuoto());	
}

template<class K, class E>
int dictionary<K,E>::size(){
	return vettOrd.getLungh();
}

template<class K, class E>
typename dictionary<K,E>::tipoelem dictionary<K,E>::find(const tipo k){
	if(k>=0 && k<vettOrd.getLungh()+1){
		return vettOrd.getelem(k);
	}else{
		cout<<"Key not found"<<endl;
	}
	
}

template<class K, class E>
void dictionary<K,E>::insert(tipoelem e){
	bool flag=true;
	int i=0;
	int h=vettOrd.getLungh();
	if(h==0){
		vettOrd.spostaAvanti(0);
		vettOrd.inserisci(e,0);
	}else if(h==1){
		if(vettOrd.getelem(0)<=e){
				vettOrd.spostaAvanti(1);
				vettOrd.inserisci(e,1);	
		}
	}else{
		do{
		
			if(vettOrd.getelem(i)>=e || i==h){
				flag=false;
				vettOrd.spostaAvanti(i);
				vettOrd.inserisci(e,i);
			
			}else{
				i++;
			}
		
	}while(flag==true && i<=h);

  }
}

template<class K, class E>
void dictionary<K,E>::erase(const tipo k){
	vettOrd.cancelladiz(k);	
}

template<class K, class E>
void dictionary<K,E>::modify(const tipo k,tipoelem e){
	vettOrd.inserisci(e,k);
}





#endif
