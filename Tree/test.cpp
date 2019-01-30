#include "TreeList.h"

int main(){
    
	TreeList<char> Tree;
	TreeList<char> t;
	std::cout<<"Node,Liv:     Figli"<<std::endl;
	TreeList<char>::node n;
	TreeList<char>::node f;
	Tree.insRoot(n);
	Tree.writeNode(Tree.root(),'a');

	Tree.insFirst(Tree.root(), 'b');
	Tree.insFirst(Tree.root(), 'c');

	n = Tree.root();
	n = Tree.firstChild(n);

	Tree.ins(n, 'd');

	n = Tree.root();
	n = Tree.nextSibling(Tree.firstChild(n));
	Tree.insFirst(n, 'e');
	Tree.insFirst(n, 'f');

	Tree.print();	

	n = Tree.root();
	n = Tree.firstChild(Tree.nextSibling(Tree.firstChild(n)));
	Tree.insFirst(n,'k');
	Tree.insFirst(n,'l');
	
	n=Tree.nextSibling(Tree.nextSibling(Tree.firstChild(Tree.root())));
	Tree.insFirst(n,'z');
	Tree.print();	
	
	t.insRoot(f);
	t.writeNode(t.root(),'n');
	t.insFirst(t.root(),'u');                          
	t.ins(t.firstChild(t.root()),'v');
	t.print(); 
	Tree.insFirst(Tree.root(),'w');
	Tree.insFirst(Tree.root(),'y');      
	Tree.insFirstSubTree(Tree.firstChild(Tree.root()),t);
	std::cout<<"\tOra insFirst "<<std::endl;    
	Tree.print();   
	Tree.removeSubTree(Tree.firstChild(Tree.firstChild(Tree.root())));
	std::cout<<"\tOra remove "<<std::endl;
	Tree.print();  
	Tree.insSubTree(Tree.firstChild(Tree.root()),t);
	std::cout<<"\tOra ins "<<std::endl;
	Tree.print(); 
	
	
	
	std::cout<<"Altezza albero: "<<Tree.getAltezza(); 
	std::cout<<"Livello con maggior numero di nodi: "<<Tree.getAmpiezza();      
     
	return 0;  
}
