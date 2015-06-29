#include <iostream>
using namespace std;

class Node {
public:
  int value;
  Node* left;
  Node* right;
  Node(int val,Node* l,Node* r):value(val), left(l), right(r){};
};

class BST {
public:
  bool isBST(Node* root) {
  	bool l = true, r = true;
    if (root->left != NULL){
    	if ((root->left) -> value < root -> value)
    		l = isBST(root->left);
    	else
    		return false;
    }
    if (root->left != NULL){
    	if ((root -> right) -> value >= root -> value)
    		r = isBST(root -> right);
    	else
    		return false;
    }
    return l && r;
  }
};

int main(){
	BST bst;
	Node c(1,NULL,NULL), d(2,NULL,NULL), e(6,NULL,NULL), f(10,NULL,NULL), a(2,&c,&d), b(8,&e,&f), r(5,&a,&b);
	cout<<bst.isBST(&r);
	return 0;
}
