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
	int sz;
	scanf("%d", &sz);
	vector<Node> lists;
	for(int i = 0; i < sz; i++){
		
		int tmp = 0;
		Node* prev;
		scanf("%d", &tmp);
		Node beg(tmp, NULL);
		prev = &beg;
		Node curr;
		while(scanf("%d", &tmp) && tmp != -1){
			Node* curr = new Node(tmp, NULL);
			prev->next = curr;
			prev = curr;
		};
		
		lists.push_back(beg);
	}
	KLists ob;
	Node node = ob.merge(lists);
	Node* n = &node;
	while(n != NULL){
		printf("%d ",n->value);
		n = n->next;
	}
	return 0;
}
