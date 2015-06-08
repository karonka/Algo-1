#include <iostream>

using namespace std;

class Node{
	public:
	int value;
	Node* next;
	Node(int val, Node* next):value(val),next(next){};
};

class Queue{
public:
	Node* begin;
	Node* end;
	int sz;
	Queue(){
		begin = 0;
		end = 0;
		sz = 0;
	}
	void push(int value){
		Node* newNode = new Node(value, 0);
		if (end){
			end->next = newNode;
		}
		else {
			begin = newNode;
		}
		end = newNode;
		sz++;
	}
	int pop(){
		if (sz < 1) {
			cout << "Queue is empty! :: ";
			return -1;
		}
		int val = begin->value;
		begin = begin->next;
		sz--;
		return val;
	}
	int peek(){
		if (sz < 1) {
			cout << "Queue is empty! :: ";
			return -1;
		}
		return begin->value;
	}
	int size(){
		return sz;
	}
};

class Stack{
	Queue q;
public:
	void push(int value){
		q.push(value);
	}
	int pop(){
		if (q.size() < 1){
			cout<<"Stack is empty! :: ";
			return -1;
		}
		int sz = q.size() - 1;
		Queue newq;
		for (int i = 0; i < sz; i++){
			newq.push(q.pop());
		}
		int val = q.pop();
		q = newq;
		return val;
	}
	int peek(){	
		if (q.size() < 1){
			cout<<"Stack is empty! :: ";
			return -1;
		}
		int val;
		Queue newq;
		int sz = q.size();
		for (int i = 0; i < sz; i++){
			newq.push(val = q.pop());
		}
		q = newq;
		return val;
	}
	int size(){
		return q.size();
	}
	void printAll(){
		Node* n = q.begin;
		for(int i = 0; i < q.size(); i++){
			cout<< n->value<<" ";
			n = n->next;
		}
		cout<<endl;
	}
};
int main(){
	Stack s;
	cout<<"size:: "<<s.size()<<endl;
	s.push(5);s.push(8);s.push(13);s.push(3);s.push(1);
	cout<<"size:: "<<s.size()<<endl;
	s.printAll();
	cout<<s.pop()<<endl;
	s.printAll();
	cout<<"size:: "<<s.size()<<endl;
	cout<<s.peek()<<endl;
	s.printAll();
	cout<<"size:: "<<s.size()<<endl;
	int sz = s.size();
	for(int i = 0; i <= sz; i++) cout<<s.pop()<<" ";
	return 0;
}
