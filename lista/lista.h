#ifndef _LISTA_H
#define _LISTA_H

#include <iostream>

using namespace std;

const int dimensione=1000;


template<class T>
class lista{
	
	public:
		typedef T type;
		
		
		lista(); //costruttori
		lista(type t);
		~lista(){};  //distruttore
		
		//operatori
		bool listavuota() const;      //true se lungheszza=0 false altrimenti
		type leggilista(int p) const;   //leggi elemento in posizione p
		void scrivilista(type t,int p);    //scrivi t in posizione p
		void crealista();           //crea lista di lungh 0
		int primolista() const;   //posizione del primo elemento
		bool finelista(int p) const;  //ti dice se è l'ultimo elem
		int succlista(int p) const;    //posizione elemento successivo
		int predlista(int p) const; 	//posizione elemento precedente
		void inslista(type t,int p);     //inserisci nuovo elem in pos p
		void canclista(int p);		//cancella elemento in position p
		int size(lista l);   //restituisce la lunghezza della lista
		void inverti(lista l);   //inverte gli elementi della lista
		bool palindroma(lista l);   //true se lista è palindroma false altrimenti
		void stampal(lista l);
		void insListaOrd(type t);   //lista lineare ordinata
		
		
		protected:
			int lunghezza;
			type elementi[dimensione];
			
	
};

template<class T>
lista<T>::lista(){
	crealista();
}

template<class T>
void lista<T>::crealista(){
	lunghezza=0;
}

template<class T>
bool lista<T>::listavuota() const{
	return (lunghezza==0);
}

template<class T>
typename lista<T>::type lista<T>::leggilista(int p) const{
	if(p>0 && p<lunghezza+1)
	return elementi[p];
}

template<class T>
void lista<T>::scrivilista(type t, int p){
	if(p>0 && p<lunghezza+1)
	elementi[p]=t;
}


template<class T>
int lista<T>::primolista() const{
		return (1);
}
	
template<class T>
bool lista<T>::finelista(int p) const{
	if(p>0 && p<=lunghezza+1)
	 if(p==lunghezza+1){
	 		return true;
	 }
	 else return false;
}

template<class T>
int lista<T>::succlista(int p) const{
	if(p>0 && p<lunghezza+1){
		return (p+1);
	}else return p;
}

template<class T>
int lista<T>::predlista(int p) const{
	if(p>1 && p<lunghezza+1){
		return (p-1);
	}else return p;
}

template<class T>
void lista<T>::inslista(type t,int p) {
		lista::lunghezza++;
		if(p>0 && p<lunghezza+1){
		for(int i=lunghezza+1; i>=p; i--){
				elementi[i]=elementi[i-1];
		}
		elementi[p]=t;
	}

}

template<class T>
void lista<T>::canclista(int p){
	if(p>0 && p<lunghezza+1){
			for(int i=p; i<lunghezza+1; i++){
					elementi[i]=elementi[i+1];
			}
	}
	lunghezza--;
}

template<class T>
int lista<T>::size(lista l){
	int d=0;
	for(int i=l.primolista(); !l.finelista(i); i=l.succlista(i)){
			d++;
	}
	return d;
}

template<class T>
void lista<T>::inverti(lista l){
	lista::type Temp;
	int idestro=l.primolista();
	int isinistro=l.primolista();
	
	idestro=l.size(l);
	
	while(idestro!=isinistro && idestro!=l.predlista(isinistro)){
		Temp=elementi[isinistro];
		elementi[isinistro]=elementi[idestro];
		elementi[idestro]=Temp;
		isinistro=l.succlista(isinistro);
		idestro=l.predlista(idestro);
	}
	
}

template<class T>
bool lista<T>::palindroma(lista l){
	
	int idestro=l.primolista();
	int isinistro=l.primolista();
	
	idestro=l.size(l);
	
	bool pal=true;
	while(idestro!=isinistro && idestro!=l.predlista(isinistro) && pal!=false){
		if(elementi[isinistro]==elementi[idestro]){
				isinistro=l.succlista(isinistro);
				idestro=l.predlista(idestro);	
		}else{
			pal=false;
		}
	}
	return pal;
}

template<class T>
void lista<T>::stampal(lista l){
	
	cout<<"Elementi della lista: \t";
	cout<<"[";
	for(int i=l.primolista(); !l.finelista(i); i=l.succlista(i)){
				cout<<elementi[i]<<",";
		}
		cout<<"]";
		cout<<endl;
}

template<class T>
void lista<T>::insListaOrd(type t){
	int p=1;
	bool flag=false;
	while(!lista::finelista(p) && flag==false ){
				if(t>lista::elementi[p]){
					p=lista::succlista(p);
					
				}else{
						lista::inslista(t,p);
						flag=true;
				}
	}
	if(lista::finelista(p)){
		lista::inslista(t,p);
	}

}



#endif //_LISTA_H
