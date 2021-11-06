#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

#include "list.h"

template <typename T> class List;

template<typename T>
class Node {
	friend class List <T>;

private:
	T data;
	Node <T> *next;
	Node <T> *prev;

public:
	Node(T &value);
	T & getData();
    Node <T>* getNext();

	void remove(List<T> *);
	void removeAll();
    void print() const;
};



template <typename N> Node<N> ::Node(N &value){
	data = value; 
	next = 0; 
}

template <typename T> T & Node<T>::getData(){
	return data;
}

template <typename T> Node <T>* Node<T>::getNext(){
	return next;
}

template <typename T> void Node<T>::remove(List<T> * list){
	if(prev && next){
		prev->next = next;
		delete this;
	}else if(prev){
		prev->next = 0;
		delete this;
	}else if(next){
		next->prev = 0;
		list->setFirst(next);
		delete this;
	}else{
		next = 0;
		list->destroy();
	}
}

#endif