#include <iostream>

using namespace std;

class Node{
	public:
	int value;
	Node* next;
	Node(int val, Node* next):value(val),next(next){};
};

class Queue{
	Node* begin;
	Node* end;
	int sz;
public:
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

int main(){
	Queue q;
	cout<<q.size()<<endl;
	q.push(5);
	cout<<q.peek()<<endl;
	q.push(8);q.push(13);
	//извеждаме всички + проверка какво става ако е празна опашката 
	int sz = q.size();
	for(int i = 0; i <= sz; i++) cout<<q.pop()<<" ";
	return 0;
}
