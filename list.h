#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>

#include "node.h"

using namespace std;


template <typename T>
class List{
private:
	Node<T> *first;

public:
	List();
	~List();

	Node<T>* getFirst();
	void setFirst(Node<T> *);
	void addNodeEnd(Node <T> node);
	Node<T> getLastNode();
	void destroy();

	void print() const;
	bool isEmpty() const;
};


template <typename T> List<T>::List(){
	first = 0;
}


template <typename T> List<T>::~List(){
	Node<T> *aux = first;

	while (!isEmpty()){
		first = first->next;
		delete aux;
		aux = first;
	}
}


template <typename T> Node <T>* List<T>::getFirst(){
	return first;
}


template <typename T> void List<T>::setFirst(Node<T> * node){
	first = node;
}


template <typename T> void List<T>::addNodeEnd(Node <T> node){
	Node<T> *aux1;
	Node<T> *aux2;
	aux1 = new Node<T>(node);

	if(isEmpty()){             //si la lista está vacia, lo agrega al comienzo 
 		first = aux1;
 		first->next = 0;
		first->prev = 0;
 	} else{
		aux2 = first;
		while(aux2->next)
			aux2 = aux2->next;
		aux2->next = aux1;
		aux1->prev = aux2;
		aux1->next = 0;
	}
}

template <typename T> Node<T> List<T>::getLastNode(){
	Node<T> *aux = first;
	
	while(aux->next)
		aux = aux->next;
	return (*aux);
}

template <typename T> void List<T>::destroy(){
	
	while(!isEmpty()){
		first->removeAll();
		first = 0;
	}
	
	return;
}

template <typename T> bool List<T>:: isEmpty() const{
	return (first == 0);
}

template <typename T> void List<T>::print() const{
	Node<T> * aux = first;

	if(!isEmpty()){
		while(aux != 0){
			cout << aux->data << '\n';
			aux = aux->next;
		}
		cout << endl;
	}
	//else cout << "lista vacia";
}



#endif