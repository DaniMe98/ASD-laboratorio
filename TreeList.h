#ifndef TREELIST_H
#define TREELIST_H

#include "list_vector.h"
#include "Tree.h"

#define MAXNODES 25

template<class I>
class TreeList : public Tree<I, int> {
 public:

	typedef I item;
	typedef int node;

	// Costruttori e distruttore
	TreeList(){
		create();
	};

	virtual void create () ;
	virtual bool empty () const ;
	virtual void insRoot (node) ;        //inserisce root =0
	virtual node root () const ;         //restituisce il nodo root
	virtual node parent (node) const ;      //restituisce il nodo padre
	virtual bool leaf (node) const ;      //true se nodo è foglia,false altrimenti
	virtual node firstChild (node) const ;   //restituisce il primo figlio del nodo node
	virtual bool lastSibling (node) const ;      //true se node non ha altri fratelli,false altrimenti
	virtual node nextSibling (node) const ;    //restituisce il nodo fratello
	
	//sottoalberi
	virtual void insFirstSubTree (node n, TreeList &t) ;      //inserisce sotto albero in primofiglio di node n
	virtual void insSubTree (node n, TreeList &t) ;    //inserisce sotto albero in fratello di node n
	virtual void removeSubTree (node) ;     //rimuove sottoalbero (node+figli)

	void insFirst(node, item);     //inserisce un figlio (diventa il primo figlio disponibile libero)
	void ins(node, item);         //inserisce un fratello al nodo node

	virtual void writeNode (node, item) ;     //serve solo per scrivere la root che all'inizio è =0
	virtual item readNode (node) const ;       //ritrona il valore del nodo node

	void print() const;         //printa a sinistra tutti i nodi disponibili e a destra di ogni nodo i suoi figli
	
	int getAltezza();        //ritorna l'altezza dell'albero
	int getAmpiezza();		//calcola l'ampiezza di un albero
	
 private:
	struct Record {
		item e;
		bool used;
		List_vector<int> childs;
		int livello=0;		
	};
	typedef List_vector<int>::position position_list;
 
	Record nodes[MAXNODES];
	node _root;
	int numNodes;

};

template<class I>
int TreeList<I>::getAmpiezza(){
	int numliv=getAltezza();
	int cont[numliv];
	
	for(int i=0; i<numliv+1; i++){
		cont[i]=0;
	}
	
	std::cout<<"\t Numero livelli: "<<numliv<<std::endl;
	for(int i=0; i<MAXNODES; i++){
		if(nodes[i].used==true){
			cont[nodes[i].livello]+=1;
		}
	}
	
	
	int max=0,m=0;
	for(int i=0; i<numliv; i++){
		if(cont[i]>max){
			max=cont[i];
			m=i;
			
		}
	}
	return (m);
		
}

template<class I>
int TreeList<I>::getAltezza(){
	int max=0;
	for(int i=0; i<MAXNODES; i++){
		if(nodes[i].used==true){
			
			if(nodes[i].livello>max){
				max=nodes[i].livello;
			}
			
		}
	}
	return max;
	
}


template<class I>
void TreeList<I>::insFirstSubTree(node n, TreeList &t){		
	//inseriamo sottoalbero

		insFirst(n,t.readNode(t.root()));
		t.nodes[0].livello=nodes[n].livello+1;
		for (int i=t.root(); i < MAXNODES;i++){
			if (t.nodes[i].used==true){
				if(!t.leaf(i)){
					position_list child = t.nodes[i].childs.begin();					
					while (!t.nodes[i].childs.end(child)){
								insFirst(firstChild(n),t.readNode(t.nodes[i].childs.read(child)));
								child=t.nodes[i].childs.next(child);
						}
					}
				}
			}

} 

template<class I>
void TreeList<I>::insSubTree(node n, TreeList &t){
	ins(n,t.readNode(t.root()));
	t.nodes[0].livello=nodes[n].livello;
	for (int i=t.root(); i < MAXNODES;i++){
			if (t.nodes[i].used==true){
				if(!t.leaf(i)){
					position_list child = t.nodes[i].childs.begin();					
					while (!t.nodes[i].childs.end(child)){
								insFirst(nextSibling(n),t.readNode(t.nodes[i].childs.read(child)));
								child=t.nodes[i].childs.next(child);
					}
				}
			}
		}
}

template <class I>
void TreeList<I>::print() const{
	cout << "\n{";
	for (int i=0; i < MAXNODES;i++){
		if (nodes[i].used==true){
			cout << "\n  " << readNode(i) <<" ";
			cout<<nodes[i].livello<< ":  ";
			if (!leaf(i)){
				position_list child = nodes[i].childs.begin();					
				while (!nodes[i].childs.end(child)){
					cout << readNode(nodes[i].childs.read(child)) << " "; 
					child = nodes[i].childs.next(child);
				}
			}
		}

	}
	cout << "\n}\n";
}

template <class I>
void TreeList<I>::create(){
	numNodes = 0;
	for (int i=0; i< MAXNODES;i++){
		nodes[i].used = false;
		nodes[i].childs.create();
	}
}

template <class I>
bool TreeList<I>::empty() const{
	return(numNodes == 0);
}

template <class I>
void TreeList<I>::insRoot (node n){
	if (empty()){
		_root = 0;
		nodes[0].used = true;
		numNodes++;
	}
}

template <class I>
typename TreeList<I>::node TreeList<I>::root () const{
	return _root;
}

template <class I>
typename TreeList<I>::node TreeList<I>::parent (node n) const{
	position_list child;		
	int p;
	for (int i=0; i < MAXNODES; i++){
		if (!nodes[i].childs.empty()){
			child = nodes[i].childs.begin();
			bool found = false;
			while (!nodes[i].childs.end(child) && !found){
				if (nodes[i].childs.read(child) == n){
					found = true;
					p = i;
				}
				child = nodes[i].childs.next(child);
			}
			if (found)
				return(i);
		}
	}
}

template <class I>
bool TreeList<I>::leaf(node n) const{
	return(nodes[n].childs.empty());
}

template <class I>
typename TreeList<I>::node TreeList<I>::firstChild (node n) const{
	if (!leaf(n)){
		return(nodes[n].childs.read(nodes[n].childs.begin()));
	}
}

template <class I>
bool TreeList<I>::lastSibling (node n) const {
	position_list c;
	node p = parent(n);
	c = nodes[p].childs.begin();
	while (!nodes[p].childs.end(c))
		c = nodes[p].childs.next(c);
	return (n == nodes[p].childs.read(c));
}

template <class I>
typename TreeList<I>::node TreeList<I>::nextSibling (node n) const{
	if (!lastSibling(n)){
		position_list c;
		node p = parent(n);
		c = nodes[p].childs.begin();
		while (!nodes[p].childs.end(c)){
			if (nodes[p].childs.read(c) == n)
				return (nodes[p].childs.read(nodes[p].childs.next(c)));
			c = nodes[p].childs.next(c);
		}
	}
}

template <class I>
void TreeList<I>::insFirst(node n, item el){
	// cerca una posizione libera
	int k;
	for (k=0; k < MAXNODES && nodes[k].used == true; k++);
	if (k<MAXNODES){
		nodes[k].used = true;
		nodes[k].e = el;
		nodes[k].livello=nodes[n].livello+1;
		nodes[n].childs.insert(k, nodes[n].childs.begin());
	}
	//assegno il livello
	
}

template <class I>
void TreeList<I>::ins(node n, item el){
	// cerca una posizione libera
	int k;
	for (k=0; k < MAXNODES && nodes[k].used == true; k++);
	if (k<MAXNODES){
		nodes[k].used = true;
		nodes[k].e = el;
		nodes[k].livello=nodes[n].livello;
		node p = parent(n);		
		position_list child = nodes[p].childs.begin();
		bool found = false;
		while (!nodes[p].childs.end(child) && !found){
			if (nodes[p].childs.read(child) == n)
					found = true;
			child = nodes[p].childs.next(child);
		}
		nodes[p].childs.insert(k, child);
	}
}

template <class I>
void TreeList<I>::removeSubTree (node n){

	position_list c;
	if (!leaf(n)){
		while (!nodes[n].childs.empty()){
			removeSubTree(nodes[n].childs.read(nodes[n].childs.begin()));
		}
	}
	node p = parent(n);
	c = nodes[p].childs.begin();	
	while(nodes[p].childs.read(c) != n)
		c = nodes[p].childs.next(c);
	nodes[p].childs.erase(c);
	nodes[n].used = false;
}

template <class I>
void TreeList<I>::writeNode (node n, item el){
	nodes[n].e = el;
}

template <class I>
typename TreeList<I>::item TreeList<I>::readNode (node n) const{
	return(nodes[n].e);
}

#endif
