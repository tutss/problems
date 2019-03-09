#include <iostream>

using namespace std;
/* 
 * BST implementation strongly based on https://gist.github.com/harish-r/a7df7ce576dda35c9660
 * My main goal was just to play a little with a BST structure, transversing it in preorder, postorder
 * and inorder.
 *
 * */
class BST {
	
	struct Node {
		int data;
		Node* left;
		Node* right;
	};

	Node* root;

	/* Methods */
	Node* insert(int x, Node* t) {
		if (t == NULL) {
			t = new Node;
			t->data = x;
			t->left = t->right = NULL;
		} else if (x < t->data) {
			t->left = insert(x, t->left);
		} else if (x > t->data) {
			t->right = insert(x, t->right);
		}
		return t;
	}

	Node* find(Node* t, int x) {
		if (t == NULL) {
			return NULL;
		} else if (x < t->data) {
			return find(t->left, x);
		} else if (x > t->data) {
			return find(t->right, x);
		} else {
			return t;
		}
	}

	Node* findMin(Node* t) {
		if (t == NULL) {
			return NULL;
		} else if (t->left == NULL) {
			return t;
		} else {
			return findMin(t->left);
		}
	}

	Node* findMax(Node* t) {
		if (t == NULL) {
			return NULL;
		} else if (t->right == NULL) {
			return t;
		} else { 
			return findMax(t->right);
		}
	}

	Node* remove(int x, Node* t) {
		Node* tmp;
		if (t == NULL) {
			return NULL;
		} else if (x < t->data) {
			t->left = remove(x, t->left);
		} else if (x > t->data) {
			t->right = remove(x, t->right);
		} else if (t->left && t->right) {
			tmp = findMin(t->right);
			t->data = tmp->data;
			t->right = remove(t->data, t->right);
		} else {
			tmp = t;
			if (t->left == NULL) {
				t = t->right;
			} else if (t->right == NULL) {
				t = t->left;
			}
			delete tmp;
		}
		return t;
	}

	void inorder(Node* t) {
		if (t == NULL) {
			return;
		}
		inorder(t->left);
		cout << t->data << " ";
		inorder(t->right);
	}

	void preorder(Node* t) {
		if (t == NULL)
			return;
		cout << t->data << " ";
		preorder(t->left);
		preorder(t->right);
	}

	void postorder(Node* t) {
		if (t == NULL)
			return;
		postorder(t->left);
		postorder(t->right);
		cout << t->data << " ";
	}

	// Public BST Functions
	public:

		BST() {
			root = NULL;
		}

		void insert(int key) {
			root = insert(key, root);
		}

		void remove(int key) {
			root = remove(key, root);
		}

		void display(int mode) {
			if (mode == 1) {
				inorder(root);
				cout << endl;
			} else if (mode == 2) {
				postorder(root);
				cout << endl;
			} else {
				preorder(root);
				cout << endl;
			}
		}

		void search(int key) {
			root = find(root, key);
		}
};


int main() {
	BST t;

	t.insert(20);
     	t.insert(25);
    	t.insert(15);
        t.insert(10);
        t.insert(30);
	// preorder
        cout << "Preorder: " << endl;
	t.display(0);
	// inorder
        cout << "Inorder: " << endl;
	t.display(1);
	// postorder
        cout << "Postorder: " << endl;
 	t.display(2);	
}
