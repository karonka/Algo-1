#include <iostream>
using namespace std;

class Node {
public:
  int value;
  Node* left;
  Node* right;
  Node(int val,Node* l,Node* r):value(val), left(l), right(r){};
};

class MinMaxHeap {
public:
  // Checks if a binary tree is a min/max heap.
  bool isMinMax(Node* root) {
	static int level = 0;
	level += 1;
	int multi = 1;
	if (level%2) multi = -1;
  	bool l = true, r = true;
    if (root->left != NULL){
    	if (((root->left) -> value)*multi >= (root -> value)*multi )
    		l = isMinMax(root->left);
    	else{
			level -= 1;
    		return false;
		}
    }
    if (root->left != NULL){
    	if (((root -> right) -> value)*multi >= (root -> value)*multi )
    		r = isMinMax(root -> right);
    	else{
			level -= 1;
    		return false;
		}
    }
	level -= 1;
    return l && r;
  }
};

int main(){
	MinMaxHeap bst;
	Node N(6,NULL,NULL), N1(5,NULL,NULL), N2(9,NULL,NULL), N3(8,NULL,NULL), N4(4,&N,&N1), N5(7,&N2,&N3), N6(10,&N4,&N5);
	//Node c(1,NULL,NULL), d(2,NULL,NULL), e(6,NULL,NULL), f(10,NULL,NULL), a(2,&c,&d), b(8,&e,&f), r(5,&a,&b);
	cout<<bst.isMinMax(&N6);
	return 0;
}

