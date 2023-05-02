#pragma once

template<typename T>
class clsDynamiqueArray
{

private :

	int _size = 0;
	T* _ptr = nullptr;

public :

	clsDynamiqueArray(int size) {

		_ptr = new T[size];
		_size = size;
	}

	~clsDynamiqueArray() {

		delete[] _ptr;
	}

	bool set(int index, T value) {

		if (index >= _size || index < 0)
			return false;

		_ptr[index] = value;
		return true;
	}

	T get(int index) {

		if (index >= _size || index < 0)
			return NULL;

		return _ptr[index];
	}

	int size() {

		return _size;
	}

	bool is_empty() {

		return !_size;
	}

	void print(char sep) {

		int size = _size - 1;

		for (int i = 0; i < size; i++)
			cout << _ptr[i] << sep;

		cout << _ptr[size];
	}

	void print(string sep) {

		int size = _size - 1;

		for (int i = 0; i < size; i++)
			cout << _ptr[i] << sep;
		cout << _ptr[size];

	}

	void print() {

		int size = _size - 1;

		for (int i = 0; i < size; i++)
			cout << _ptr[i] << " ";
		cout << _ptr[size];

	}
};

