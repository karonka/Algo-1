#include <iostream>
#include <vector>
#define INF 2147483647

using namespace std;

class Node {
public:
  int value;
  Node* next;
  Node(int val = 0, Node* nxt = NULL):value(val),next(nxt){};
};

void swap(Node& a, Node& b){
	Node tmp = a;
	a = b;
	b = tmp;
}

class KLists {
public:
	void make_heap(Node** seq, int size){
		for(int i = size/2 - 1; i >= 0; i--){
			heapify(seq, size, i);
		}
	}
	void heapify(Node** seq, int size, int i){
		int a,b;
		while(i*2 + 1 < size){
			if (i*2 + 1 < size) a = seq[i*2 + 1]->value;
			if (i*2 + 2 < size) b = seq[i*2 + 2]->value;
			else b = INF;
			int min = a < b? i*2+1 : i*2+2;
			if (seq[min]->value < seq[i]->value){
				swap(seq[min],seq[i]);
				i = min;
			}
			else return;
		}
	}

  // Merge K sorted lists.
	Node merge(vector<Node>& lists) {
		Node* heap[lists.size()];
		Node* begin; 
		Node* currNode; 
		for(int i = 0; i < lists.size(); i++){
			heap[i] = &lists[i];
		}
		make_heap(heap, lists.size());
		currNode = begin = heap[0];
		int hasMore = lists.size();
		if(heap[0]->next != NULL){
			heap[0] = heap[0]->next;
		}else{
			hasMore--;
			swap(heap[0],heap[hasMore]);
		}
		while(hasMore){
			heapify(heap, hasMore, 0);
			currNode->next = heap[0];
			currNode = heap[0];
			if(heap[0]->next != NULL){
				heap[0] = heap[0]->next;
			}else{
				hasMore--;
				swap(heap[0],heap[hasMore]);
			}
		}
		currNode->next = NULL;
		return *begin;
	}
};

int main(){
	Node a5(1665,NULL),a4(233,&a5),a3(46,&a4),a2(3,&a3),a1(2,&a2);
	Node b4(300,NULL),b3(234,&b4),b2(5,&b3),b1(0,&b2);
	Node c5(111,NULL),c4(23,&c5),c3(22,&c4),c2(15,&c3),c1(2,&c2);
	KLists ob;
	vector<Node> lists = {a1,b1,c1};
	Node node = ob.merge(lists);
	Node* n = &node;
	while(n != NULL){
		cout<<n->value<<" ";
		n = n->next;
	}
	return 0;
}
