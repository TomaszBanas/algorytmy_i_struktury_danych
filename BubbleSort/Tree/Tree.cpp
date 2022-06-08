#include <iostream>

using namespace std;

struct tree
{
	tree* up, * L, * R;
	int val;
};

struct node
{
	node* next;
	int val;
};
void show(node* H)
{
	cout << "H->";
	node* p = H;
	while (p != NULL)
	{
		cout << p->val << "->";
		p = p->next;
	}
	cout << "NULL" << endl;
}

void Addtolist(node*& H, int x)
{
	node* p = new node;
	p->val = x;
	p->next = H;
	H = p;
}

void add(tree*& root, int x, tree* up) {
	if (root == NULL) {
		tree* p = new tree;
		p->up = up;
		p->val = x;
		p->L = NULL;
		p->R = NULL;
		root = p;
	}
	else {
		if (x >= root->val) {
			add(root->R, x, root);
		}
		else {
			add(root->L, x, root);
		}
	}
}

void inOrder(tree* root) {
	if (root->L) inOrder(root->L);
	cout << root->val << " ";
	if (root->R) inOrder(root->R);
}

int main() {
	tree* root = NULL;

	add(root, 5, NULL);
	add(root, 9, NULL);
	add(root, 6, NULL);
	add(root, 6, NULL);
	add(root, 10, NULL);

	inOrder(root);

	system("pause");
	return 0;
}