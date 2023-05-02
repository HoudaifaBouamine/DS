#pragma once
#include "clsMyQueue.h"

template <typename T>
class clsMyStack : public clsMyQueue<T>
{

public :

	void push(T value) {

		this->insert_front(value);

	}


};

