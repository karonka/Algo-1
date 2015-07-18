#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*string toL(string s){
	for (int i = 0; i < s.size(); i++ ){
		s[i] = tolower(s[i]);
	}
	return s;
}*/

class Contact {
public:
  string name;
  int number;
  Contact(string name, int number):name(name),number(number){}
};

class Node{
public:
	Contact contact;
	Node* left;
	Node* right;
	Node(Contact ct, Node* l, Node* r):contact(ct),left(l),right(r){};
};

class PhoneBook {
	Node* beg;
public:
	PhoneBook():beg(NULL){}
	
	void insert(Contact contact){
		Node* currNode = beg;
		Node* parent = NULL;
		while(currNode != NULL){
			if (currNode -> contact.name == contact.name){
				currNode -> contact.number = contact.number;
				return;
			}
			else if (currNode -> contact.name > contact.name){
				parent = currNode;
				currNode = currNode -> left;
			}
			else {// currNode -> contact.name < contact.name
				parent = currNode;
				currNode = currNode -> right;
			}
		}
		if (beg != NULL){
			if(contact.name < parent -> contact.name){
				parent -> left = new Node(contact, NULL, NULL);
			}
			else{
				parent -> right = new Node(contact, NULL, NULL);
			}
		}
		else{
			beg = new Node(contact, NULL, NULL);
		}
	}

	void lookup(string name){
		Node* n = beg;
		if (n == NULL) {
			cout << "NOT FOUND!"<<endl;
			return;
		}
		while(n -> contact.name != name){
			if (name > n -> contact.name){
				if(n -> right == NULL){
					cout << "NOT FOUND!"<<endl;
					return;
				}
				n = n -> right;
			}
			else{
				if(n -> left == NULL) {
					cout << "NOT FOUND!"<<endl;
					return;
				}
				n = n -> left;
			}
		}
		cout << n -> contact.number << endl; 
	}

	void list() {
		show(beg);
	}

	void remove(string name) {
		if (beg == NULL) return;
		Node* toRemove = beg;
		Node* parent = NULL;
		while(toRemove -> contact.name != name){
			parent = toRemove;
			if (name > toRemove -> contact.name){
				if(toRemove -> right == NULL) return;
				toRemove = toRemove -> right;
			}
			else{
				if(toRemove -> left == NULL) return;
				toRemove = toRemove -> left;
			}
		}
		if (toRemove -> right != NULL){
			parent = toRemove;
			Node* leftmost = toRemove -> right;
			while (leftmost -> left != NULL){
				parent = leftmost;
				leftmost = leftmost -> left;
			}
			toRemove -> contact = leftmost -> contact;
			if (parent -> right == leftmost)//
				parent -> right = leftmost -> right;
			else
				parent -> left = leftmost -> right;
		}
		else{
			if (toRemove == beg) {
				beg = beg -> left;
				return;
			}
			if (parent -> contact.name < toRemove -> contact.name)
				parent -> right = toRemove -> left;
			else 
				parent -> left = toRemove -> left;
		}
	}
	void show(Node* node){
		if (node == NULL) return;
		show(node -> left);
		cout << node->contact.name << " " << node->contact.number << endl;
		show(node -> right);
	}
};

int main(){
	PhoneBook pb;
	int n,tmp;
	string s;
	cin >> n;
	while(n--){
		cin >> s;
		if (s == "insert"){
			cin >> tmp >> s;
			pb.insert(Contact(s,tmp));
		}
		else if (s == "lookup"){
			cin >> s;
			pb.lookup(s);
		}
		else if(s == "remove"){
			cin >> s;
			pb.remove(s);
		}
		else {
			pb.list();
		}
	}
	return 0;
}
