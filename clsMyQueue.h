#pragma once
#include <iostream>
#include "clsDblLinkedList.h"
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



};

