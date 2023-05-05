#pragma once
#include <iostream>
using namespace std;
template<typename T>
class clsDynamiqueArray
{

private :

	int _length = 0; // used elements
	int _size = 0;   // The real size of the array
	T* _arr = nullptr;

public :

	clsDynamiqueArray(int size) {

		_arr = new T[size];
		_size = size;
		_length = size;
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

		if (!_length) return;

		int length = _length - 1;

		for (int i = 0; i < length; i++)
			cout << _arr[i] << " ";
		cout << _arr[length] << endl;

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
		_length = 0;
	}

	bool delete_index(int index) {
		if (index < 0 || index >= _size) return false;

		for (int i = index; i < _size - 1; i++) {
			_arr[i] = _arr[i + 1];
		}

		--_length;
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
		return _binary_recursive_search(item,0,_length-1);
	}

	bool delete_item(T item) {

		return this->delete_index(this->find(item));
	}

	private:

	void _insert_if_full_arr(int index,T item) {

		_size = 1.5 * _size + 1; // Alocate More space to use the other function next time(_insert_if_empty_space)
		++_length;

		T* tmp_arr = new T[_length];

		for (int i = 0; i < index; i++)
			tmp_arr[i] = _arr[i];

		tmp_arr[index] = item;

		for (int i = index + 1; i < _length; i++)
			tmp_arr[i] = _arr[i - 1];

		delete[] _arr;
		_arr = tmp_arr;
	}

	void _insert_if_empty_space(int index, T item) {

		if (index != _length) 
			for (int i = _length; i > index; i--) _arr[i] = _arr[i - 1];

		_arr[index] = item;
		++_length;
	}

	public:

	bool insert(int index, T item) {

		if (index > _length || index < 0) return false;
		if (_size == _length) _insert_if_full_arr(index,item);
		else _insert_if_empty_space(index,item);
		return true;
	}


};

