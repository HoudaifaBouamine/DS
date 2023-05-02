#pragma once
#include <iostream>
#include "clsDblLinkedList.h"
#include <queue>
using namespace std;

template <typename T> 
class clsMyQueue 
{
	
private:

	clsDblLinkedList<T> _list;

public :

	void push(T value) {

		_list.InsertAtEnd(value);
	}

	void pop() {

		_list.DeleteFirstNode();
	}

	T front() {

		return _list.GetItem(0);
	}

	T back() {

		return _list.GetItem(size() - 1);
	}

	void print() {
		_list.PrintList();
	}

	int size() {

		return _list.Size();
	}

	bool is_empty() {

		return _list.IsEmpty();
	}

	T get_item(short index) {

		return _list.GetItem();
	}

	void reverce() {

		_list->Reverce();
	}

	void updateitem(short index, T value) {

		_list->UpdateItem(index, value);
	}


	void insert_after(short index, T value) {

		_list->InsertAfter(index, value);
	}

	void insert_front(T value) {

		_list.InsertAtBeginning(value);
	}

	void insert_back(T value) {
		_list->InsertAtEnd(value);
	}

	void clear() {

		_list->Clear();
	}

};

