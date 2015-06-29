#include <iostream>
#include <string>
#include <vector>

using namespace std;

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
	void deleteNode(Node* node){
		if (node == NULL) return;
		deleteNode (node -> left);
		deleteNode (node -> right);
		delete node;
	}
public:
	PhoneBook():beg(NULL){}
	~PhoneBook(){
		deleteNode(beg);
	}

	//inserts a new contact
	void insert(Contact contact){
		Node* currNode = beg;
		Node* father = NULL;
		while(currNode != NULL){
			if (currNode -> contact.name == contact.name){
				currNode -> contact.number = contact.number;
				return;
			}
			else if (currNode -> contact.name > contact.name){
				father = currNode;
				currNode = currNode -> left;
			}
			else {// currNode -> contact.name < contact.name
				father = currNode;
				currNode = currNode -> right;
			}
		}
		if (beg != NULL){
			if(contact.name < father -> contact.name){
				father -> left = new Node(contact, NULL, NULL);
			}
			else{
				father -> right = new Node(contact, NULL, NULL);
			}
		}
		else{
			beg = new Node(contact, NULL, NULL);
		}
	}

	//lookup a name and print its phone number
	void lookup(string name){
		Node* n = beg;
		if (n == NULL) return;
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
		cout << n -> contact.number <<endl; 
	}

	//list all records in an alphabetical order
	void list() {
		show(beg);
	}

	//remove a record for a given name
	void remove(string name) {
		if (beg == NULL) return;
		Node* toRemove = beg;
		Node* father = NULL;
		while(toRemove -> contact.name != name){
			father = toRemove;
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
			father = toRemove;
			Node* leftmost = toRemove -> right;
			while (leftmost -> left != NULL){
				father = leftmost;
				leftmost = leftmost -> left;
			}
			toRemove -> contact = leftmost -> contact;
			if (father -> right == leftmost)//
				father -> right = leftmost -> right;
			else
				father -> left = leftmost -> right;
		}
		else{
			if (father -> contact.name < toRemove -> contact.name)
				father -> right = toRemove -> left;
			else 
				father -> left = toRemove -> left;
		}
	}
	void show(Node* node){
		if (node == NULL) return;
		show(node -> left);
		cout << node->contact.name << " ";
		show(node -> right);
	}
};

int main(){
	PhoneBook pb;
	pb.insert(Contact("Kari",134));
	pb.insert(Contact("Mara",153));
	pb.insert(Contact("Pesho",166));
	pb.list();cout<<endl;
	pb.remove("Kari");
	pb.list();cout<<endl;
	pb.insert(Contact("Dani",5761));
	pb.lookup("Pesho");
	pb.insert(Contact("Carrie",17777));
	pb.insert(Contact("Zack",4641));
	pb.list();cout<<endl;
	pb.remove("Mara");
	pb.list();cout<<endl;
	pb.lookup("Dani");
	pb.insert(Contact("Kari",1));
	pb.list();cout<<endl;
	pb.lookup("Kari");
	pb.lookup("Carrie");
	pb.lookup("Zack");
	pb.remove("Kari");
	pb.lookup("Carrie");
	pb.list();cout<<endl;
	pb.remove("Zack");
	pb.list();cout<<endl;
}
