#include <iostream>
using namespace std;
// start on 22:40 // complite on 23:03 // continue at 23:35

struct st_node {

	int value = 0;
	st_node* left = nullptr;
	st_node* right = nullptr;
};

void add_node(st_node*& root, char new_value) {

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

void from_arr_to_tree(st_node*& root, char arr[]) {

	root = new st_node;
	root->value = arr[0];

	for (char i = 1; i < 9; i++)
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

int main() {

	char arr[] = { 45,15,79,90,10,55,12,20,50 };

	st_node* root = nullptr;
	from_arr_to_tree(root, arr);
	//cout << is_binary_search_tree(root) << endl;
	
	for (size_t i = 0; i < 100; i++)
	{

		if (find(root, i)) {
			cout << i << endl;
		}

	}




	return 0;
}

