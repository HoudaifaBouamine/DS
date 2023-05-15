#include <iostream>
#include <algorithm>
using namespace std;
// start on 22:40 // complite on 23:03 // continue at 23:35

struct st_node {

	int value = 0;
	st_node* left = nullptr;
	st_node* right = nullptr;
};

void add_node(st_node*& root, int new_value) {

	if (root == NULL) {
		root = new st_node;
		root->value = new_value;
		return;
	}

	if (root->value > new_value) {
		add_node(root->left, new_value);
		return;
	}

	add_node(root->right, new_value);
}

void from_arr_to_binary_search_tree(st_node*& root, int arr[],char length) {

	root = new st_node;
	root->value = arr[0];

	for (short i = 1; i < length; i++)
	{
		st_node* tmp = root;
		add_node(tmp, arr[i]);
	}

}

int get_max(st_node* root) {

	if (root == NULL)
		return -1;

	if (root->left == NULL && root->right == NULL)
		return root->value;

	if (root->left == NULL)
		return max(root->value, get_max(root->right));

	if (root->right == NULL)
		return max(root->value, get_max(root->left));

	return max(max(root->value, get_max(root->left)), get_max(root->right));

}

int get_min(st_node* root) {

	if (root == NULL)
		return 1000;

	if (root->left == NULL && root->right == NULL)
		return root->value;

	if (root->left == NULL)
		return min(root->value, get_min(root->right));

	if (root->right == NULL)
		return min(root->value, get_min(root->left));

	return min(min(root->value, get_min(root->left)), get_min(root->right));

}

bool is_binary_search_tree(st_node* root) {

	if (root == NULL)
		return true;

	return (get_max(root->left) < root->value && get_min(root->right) >= root->value) && is_binary_search_tree(root->left) && is_binary_search_tree(root->right);

}

bool find(st_node* root,int value) {

	if (root == NULL) {
		return false;
	}

	if (root->value == value) {
		return true;
	}

	if (value < root->value) {
		return find(root->left, value);
	}
	
	return find(root->right, value);
}

void fill(st_node* root,int v[],int& index) {

	if (!root)
		return;

	v[index++] = root->value;

	if (root->left)
		fill(root->left, v, index);

	if (root->right)
		fill(root->right, v, index);
}

void from_tree_to_arr(st_node* root, int v[]) {

	int counter = 0;

	fill(root, v, counter);
}

void _delete_tree(st_node*& root) {

	if (root->left != NULL)
		_delete_tree(root->left);

	if (root->right != NULL)
		_delete_tree(root->right);

	delete root;
}

void delete_tree(st_node*& root) {

	_delete_tree(root);
	root = NULL;
}

void _sort_arr_binary(int arrSource[],int arrDestination[],int& index,int min,int max) {

	if (min > max)
		return;

	int mid = (min + max) / 2;
	arrDestination[index++] = arrSource[mid];
	_sort_arr_binary(arrSource, arrDestination,index, mid + 1, max);
	_sort_arr_binary(arrSource, arrDestination,index, min, mid-1);
}

void sort_arr_binary(int arr[],const int length) {

	sort(arr, arr + length - 1);

	int* arr2 = new int [length];
	int tmp = 0;
	_sort_arr_binary(arr,arr2,tmp,0,length-1);

	arr = arr2;
}

void balanced(st_node*& root) {
	
	const int length = 16;
	int v[length];
	from_tree_to_arr(root, v);
	sort_arr_binary(v,length);
	delete_tree(root);
	from_arr_to_binary_search_tree(root,v,length);

}

int main() {

	//char arr[] = { 45,15,79,90,10,55,12,20,50 };
	int arr[] = { 20,7,4,2,15,18,11,53,46,80,29,37,86,69,74,75 };
	st_node* root = nullptr;
	from_arr_to_binary_search_tree(root, arr,16);
	//cout << is_binary_search_tree(root) << endl;
	balanced(root);
	
	return 0;
}


