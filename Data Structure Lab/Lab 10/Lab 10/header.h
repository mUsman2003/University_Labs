#include<iostream>
using namespace std;

struct Node
{
	Node* right;
	Node* left;
	int data;
};
class BinaryTree
{
public:
	Node* root;
	int capacity;
	int Root;
	int current_index;
	BinaryTree()
	{
		root = nullptr;
		capacity = 0;
	
	}

	Node* insertRecursive(Node* node, int value) {
		if (node == nullptr) {
			node->data = value;
			cout << node->data << "-";
			return new Node;
		}

		if (value < node->data) {
			node->left = insertRecursive(node->left, value);
		}
		else if (value > node->data) {
			node->right = insertRecursive(node->right, value);
		}

		return node;
	}
	void displayInorderRecursive(Node* node) {
		if (node == nullptr) {
			return;
		}

		displayInorderRecursive(node->left);
		cout << node->data << " ";
		displayInorderRecursive(node->right);
	}

	void insert(int val)
	{
		root = insertRecursive(root, val);
	}
	void displayInorder()
	{
		displayInorderRecursive(root);
	}
};