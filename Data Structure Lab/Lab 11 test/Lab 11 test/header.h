#include <iostream>
using namespace std;

template <typename T>
class TreeNode 
{
public:
	T data;
	TreeNode<T>* left;
	TreeNode<T>* right;
	TreeNode() : data(T()), left(nullptr), right(nullptr) {}
};

template <typename T>
class BST {
public:

	TreeNode<T>* root;	
	BST():root(nullptr){}

	void insert(T val)
	{
		TreeNode<T>* temp=new TreeNode<T>;
		TreeNode<T>* newRoot = new TreeNode<T>;
		newRoot = root;

		temp->data = val;
		temp->left = NULL;
		temp->right = NULL;

		if (!root)
		{
			//cout << "Tree was Empty\n";
			root = temp;
		}
		else
		{
			while (newRoot!=NULL)
			{
				//cout << "Tree is not Empty\n";
				if (val < newRoot->data)
				{
					if (newRoot->left)
						newRoot = newRoot->left;
					else
					{
						newRoot->left = temp;
						break;
					}
				}
				else if (val > newRoot->data)
				{
					if (newRoot->right)
						newRoot = newRoot->right;
					else
					{
						newRoot->right = temp;
						break;
					}
				}
				else
				{
					cout << "Duplicate Found ! \n";
					break;
				}
			}
		}
	}

	bool search(T val)
	{
		TreeNode<T>* temp = root;
		while (temp)
		{
			if (val == temp->data)
				return true;
			else if (val < temp->data)
				temp = temp->left;
			else
				temp = temp->right;
		}
		return false;
	}

	string GetCapturedStdout()
	{
		return "";
	}

	void preOrder(TreeNode<T>* node)
	{
		if (node == nullptr)
		{
			return;
		}

		cout << node->data<<" ";
		preOrder(node->left);
		preOrder(node->right);
	}

	void postOrder(TreeNode<T>* node)
	{
		if (node == nullptr)
			return;

		postOrder(node->left);
		postOrder(node->right);

		cout << node->data << " ";
	}

	void postOrderTraversal()
	{
		TreeNode<T>* temp = root;
		postOrder(temp);
		cout << "\n";
	}

	void preOrderTraversal()
	{
		TreeNode<T>* temp = root;
		preOrder(temp);
		cout << "\n";
	}

	TreeNode<T>* findMin(TreeNode<T>* node)
	{
		while (node->left != nullptr)
		{
			node = node->left;
		}
		return node;
	}

	void delnode(TreeNode<T>*& root, T v)
	{
		if (root == nullptr)
		{
			return;
		}
		if (v < root->data)
		{
			delnode(root->left, v);
		}
		else if (v > root->data)
		{
			delnode(root->right, v);
		}
		else
		{
			if (root->left == nullptr && root->right == nullptr)
			{
				delete root;
				root = nullptr;
			}
			else if (root->left == nullptr)
			{
				TreeNode<T>* temp = root;
				root = root->right;
				delete temp;
			}
			else if (root->right == nullptr)
			{
				TreeNode<T>* temp = root;
				root = root->left;
				delete temp;
			}
			else
			{
				// Node with two children
				TreeNode<T>* minRightSubtree = findMin(root->right);
				root->data = minRightSubtree->data;
				delnode(root->right, minRightSubtree->data);
			}
		}
	}

	void remove(T val)
	{
		delnode(root, val);
	}

	int countLeafNodes(TreeNode<T>* node)
	{
		if (node == nullptr)
			return 0;

		if (node->left == nullptr && node->right == nullptr)
			return 1;

		int leftCount = countLeafNodes(node->left);
		int rightCount = countLeafNodes(node->right);

		return leftCount + rightCount;
	}

	int LeafCount()
	{
		return countLeafNodes(root);
	}

};
