#include <iostream>

using namespace std;

template<class T>
class Node{
public:
	T value;
	Node<T>* next;
	Node(T val, Node<T>* next):value(val),next(next){};
};

template<class T>
class Queue {
public:
	Node<T>* begin;
	Node<T>* end;
	int sz;
	Queue(){
		begin = NULL;
		end = NULL;
		sz = 0;
	}
	void push(T value){
		Node<T>* newNode = new Node<T>(value, NULL);
		if (end != NULL ){
			end->next = newNode;
		}
		else {
			begin = newNode;
		}
		end = newNode;
		sz++;
	}
	T pop(){
		if (sz < 1) {
			cout << "Queue is empty! :: ";
			return -1;
		}
		T val = begin->value;
		Node<T>* nodetodel = begin;
		begin = begin->next;
		delete nodetodel;
		sz--;
		return val;
	}
	T peek(){
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
template<class T>
class Stack {
	Queue<T> q;
public:
	void push(T value){
		q.push(value);
	}
	T pop(){
		if (q.size() < 1){
			cout<<"Stack is empty! :: ";
			return -1;
		}
		int sz = q.size() - 1;
		Queue<T> newq;
		for (int i = 0; i < sz; i++){
			newq.push(q.pop());
		}
		T val = q.pop();
		q = newq;
		return val;
	}
	T peek(){	
		if (q.size() < 1){
			cout<<"Stack is empty! :: ";
			return -1;
		}
		T val;
		Queue<T> newq;
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
		Node<T>* n = q.begin;
		for(int i = 0; i < q.size(); i++){
			cout<< n->value<<" ";
			n = n->next;
		}
		cout<<endl;
	}
};

int main(){
	Stack<int> s;
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
