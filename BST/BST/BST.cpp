#include<iostream>
using namespace std;

struct Node {
	Node*P = NULL , *L = NULL, *R = NULL ;
	int key;
};

class BST {
private:
	Node* root = nullptr;
	
	void TRANSPLANT(Node* u, Node* v) {
		if (u->P == NULL)
			root = v;
		else if (u == u->P->L)
			u->P->L = v;
		else
			u->P->R = v;
		if (v != NULL)
		{
			v->P = u->P;
		}
	}

public:
	Node* TREE_MINIMUM(Node* n) {
		while (n->L != NULL)
		{
			n = n->L;
		}
		return n;
	}

	Node* TREE_MAXIMUM(Node* n) {
		while (n->R != NULL)
		{
			n = n->R;
		}
		return n;
	}

	Node* TREE_SUCCESSOR(Node* n) {
		if (n->R != NULL)
		{
			return TREE_MINIMUM(n->R);
		}
		Node* y = n->P;
		while (y!=NULL && n == y->R)
		{
			n = y;
			y = y->P;
		}
		return y;
	}

	void TREE_INSERT(Node* z) {
		Node* y = NULL;
		Node* x = root;
		while (x!=NULL)
		{
			y = x;
			if (z->key < x->key)
				x = x->L;
			else
				x = x->R;
		}
		z->P = y;
		if (y == NULL)
			root = z;
		else if (z->key < y->key)
			y->L = z;
		else
			y->R = z;
		}
	
	void TREE_DELETE(Node* z) {
		if (z->L == NULL)
		{
			TRANSPLANT(z, z->R);
		}
		else if (z->R == NULL)
			TRANSPLANT(z, z->L);
		else
		{
			Node* y = TREE_MINIMUM(z->R);
			if (y->P != z) {
				TRANSPLANT(y, y->R);
				y->R = z->R;
				y->R->P = y;
			}
			TRANSPLANT(z, y);
			y->L = z->L;
			y->L->P = y;
		}
	}

	Node* TREE_SEARCH(Node* x, int key) {
		while ( x != NULL && key!=x->key )
		{
			if (key < x->key)
				x = x->L;
			else
				x = x->R;
		}
		return x;
	}

	void INORDER_TREE_WALK(Node* x) {
		if (x == NULL) return; 
		INORDER_TREE_WALK(x->L);
		cout << x->key << " " ;
		INORDER_TREE_WALK(x->R);
	}

	void RootSetter(Node* k) {
		root = k;
	}

	Node* rootgetter() {
		return root;
	}
};

int main() {
	BST T = BST();
	
	Node *a = new Node();
	Node* b = new Node();
	Node* c = new Node();
	Node* d = new Node();
	Node* e = new Node();
	Node* f = new Node();
	Node* g = new Node();
	Node* h = new Node();
	Node* i = new Node();
	Node* j = new Node();
	g->key = 10;
	a->key = 9;
	b->key = 8;
	c->key = 7;
	d->key = 6;
	e->key = 5;
	f->key = 4;
	h->key = 3;
	i->key = 2;
	j->key = 1;

	T.TREE_INSERT(c);
	T.TREE_INSERT(a);
	T.TREE_INSERT(b);
	T.TREE_INSERT(d);
	T.TREE_INSERT(e);
	T.TREE_INSERT(f);
	T.TREE_INSERT(g);
	T.TREE_INSERT(h);
	T.TREE_INSERT(i);
	T.TREE_INSERT(j);
	//T.TREE_DELETE(c);
	//cout << T.TREE_SEARCH(g,10)->key << endl;

	T.INORDER_TREE_WALK(T.rootgetter());
	cout << endl;
	system("pause");
	return 0;
}