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
	Node<T>* begin;
	Node<T>* end;
	int sz;
public:
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

int main(){
	Queue<int> q;
	cout<<"sz: "<<q.size()<<endl;
	q.push(5);
	cout<<"peek: "<<q.peek()<<endl;
	q.push(8);q.push(13);
	//извеждаме всички + проверка какво става ако е празна опашката 
	int sz = q.size();
	for(int i = 0; i < sz; i++) cout<<q.pop()<<" ";
	return 0;
}
