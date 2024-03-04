//Lets see the code to insert the nodes in the AVL Tree
#include<iostream>
using namespace std;

struct Node{
	int val;
	struct Node *left;
	struct Node *right;
	int height;
};

//First thing first, lets create the helper function to create a node,
struct Node* createNode(int val){
	struct Node *root = new Node;
	root->val = val;
	root->left = nullptr;
	root->right = nullptr;
	root->height = 1;
	//whenver the node attaches, it attaches as a leaf node so height will be one
	//have to change the height of the parents accordingly
	return root;
}

int getHeight(struct Node *root){
	if(root==nullptr){
		return 0;
	}
	return root->height;
}

//Writing a function to get the balance factor of the node
int getBalanceFactor(struct Node *n){
	if(n==nullptr){
		return 0;
	}
	return getHeight(n->left) - getHeight(n->right);
}

//writing the function if there is left rotation
struct Node* leftRotate(struct Node *y){
	struct Node *x = y->right;

	y->right = x->left;
	x->left = y;
	/*above are the changes in the position of the tree, just make the tree have a look, with
	respect to x we have to do.*/

	/*As the positions of the nodes are changing, the height of the some of the nodes will change*/

	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	return x;
}

struct Node* rightRotate(struct Node *x){
	struct Node *y = x->left;
	
	x->left = y->right;
	y->right = x;

	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	return y;
}

struct Node *insert(struct Node *root, int key){
	if(root==nullptr){
		return createNode(key);
	}

	if(key > root->val){
		root->right = insert(root->right, key);
	}
	else if(key < root->val){
		root->left = insert(root->left, key);
	}
	
	//have to change the height of the of the nodes as well
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

	//Now starting from leave node aagar node ka balance factor aagar disturb ho gaya ho toh
	//usko handle karte hai
	int bf = getBalanceFactor(root);
	
	if(bf>1 && key< root->left->val){
		return rightRotate(root);
	}
	//Left of left mein insertion
	
	else if(bf<-1 && key> root->right->val){
		return leftRotate(root);
	}
	//Right of Right mein insertion
	
	else if(bf>1 && key>root->right->val){
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	//Left of Right mein insertion
	
	else if(bf<-1 && key<root->right->val){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	//Right of Left mein insertion
	return root;
}

void preOrder(struct Node *root)
{
	if(root==nullptr){
		return;
	}

	cout<<root->val<<endl;
	preOrder(root->left);
	preOrder(root->right);
}

int main(){
	struct Node *root = NULL;
	root = insert(root, 1);
	root = insert(root, 2);
	root = insert(root, 3);
	root = insert(root, 4);
	root = insert(root, 5);
	root = insert(root, 6);
	preOrder(root);
	return 0;
}
