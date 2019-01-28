#ifndef _HISTOGRAM_H
#define _HISTOGRAM_H

#include "dictionary.h"

using namespace std;

class histogram{
	
	public:
		//costruttori
		histogram(){};
		~histogram(){};
		
		//operatori
		void create();
		void add(int v);   //incrementa di 1 la frequenza del bin v
		void remove(int v);  //decrementa di 1 la frequenza del bin v
		int mode();    //restituisce la moda dell'istogramma(bin con frequenza massima)
		double mean();   //restituisce la media dell'istogramma
		void print(); //stampa l'istogramma
		
	private:
		dictionary<int,int> t;
	
};























#endif //_HISTOGRAM_H
