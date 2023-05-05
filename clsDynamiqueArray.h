#pragma once
#include <iostream>
using namespace std;
template<typename T>
class clsDynamiqueArray
{

private :

	int _size = 0;
	T* _arr = nullptr;

public :

	clsDynamiqueArray(int size) {

		_arr = new T[size];
		_size = size;
	}

	~clsDynamiqueArray() {

		delete[] _arr;
	}

	bool set(int index, T value) {

		if (index >= _size || index < 0)
			return false;

		_arr[index] = value;
		return true;
	}

	T get(int index) {

		if (index >= _size || index < 0)
			return NULL;

		return _arr[index];
	}

	int size() {

		return _size;
	}

	bool is_empty() {

		return !_size;
	}

	void print(char sep) {
		if (!_size) return;

		int size = _size - 1;

		for (int i = 0; i < size; i++)
			cout << _arr[i] << sep;

		cout << _arr[size];
	}

	void print(string sep) {
		if (!_size) return;

		int size = _size - 1;

		for (int i = 0; i < size; i++)
			cout << _arr[i] << sep;
		cout << _arr[size];

	}

	void print() {

		if (!_size) return;

		int size = _size - 1;

		for (int i = 0; i < size; i++)
			cout << _arr[i] << " ";
		cout << _arr[size] << endl;

	}

	void resize(int new_size) {

		if (new_size < 0) {
			new_size = 0;
		}

		T* tmp = new T[new_size];

		int min_size = min(new_size, _size);

		for (int i = 0; i < min_size; i++)
		{
			tmp[i] = _arr[i];
		}

		delete[] _arr;
		_arr = tmp;
		_size = new_size;
	}

	void reverce() {

		T tmp;
		int limit = _size / 2 + 1;

		for (int i = 0; i < limit; i++) {

			tmp = _arr[i];
			_arr[i] = _arr[_size - i - 1];
			_arr[_size - i - 1] = tmp;
		}
	}

	void clear() {

		delete[] _arr;
		_arr = NULL;
		_size = 0;
	}

	bool delete_index(int index) {
		if (index < 0 || index >= _size) return false;

		for (int i = index; i < _size - 1; i++) {
			_arr[i] = _arr[i + 1];
		}

		--_size;
		return true;
	}

	private:
	int _binary_recursive_search(T item, int min,int max) {

		int mid = (min + max) / 2;

		if (min > max) {
			return -1;
		}

		if (item == _arr[mid]) {
			return mid;
		}
		
		if (item > _arr[mid]) {
			return _binary_recursive_search(item, mid + 1, max);
		}
		else {
			return _binary_recursive_search(item, min, mid - 1);
		}


	}

	public :
	int find(T item) {	
		return _binary_recursive_search(item,0,_size-1);
	}

	bool delete_item(T item) {

		return this->delete_index(this->find(item));
	}

	bool insert(int index, T item) {

		if (index > _size || index < 0) return false;

		++_size;

		T* tmp_arr = new T[_size];

		for (int i = 0; i < index; i++)
			tmp_arr[i] = _arr[i];

		tmp_arr[index] = item;

		for (int i = index + 1; i < _size; i++)
			tmp_arr[i] = _arr[i-1];

		delete[] _arr;
		_arr = tmp_arr;

		return true;
	}
};

