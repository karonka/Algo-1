#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

class ClosestCoffeeStore {
public:
	int closestCoffeeStore(bool** graph, bool* isCoffeStore, int size, int startingPoint){
		bool* visited = new bool[size];
		memset(visited, 0, sizeof(bool)*size);
		queue<int> q;
		q.push(startingPoint);
		while( q.size() > 0 && !isCoffeStore[q.front()] ){
			startingPoint = q.front();
			visited[startingPoint] = true;
			q.pop();
			for(int i = 0; i < size; i++){
				if (graph[startingPoint][i] && !visited[i]){
					q.push(i);
				}
			}
		}
		delete [] visited;
		if (q.size() > 0) return q.front();
		return -1;
	}
};

int main(){
	ClosestCoffeeStore ccs;
	
	bool isCoffeStore [6] = {
		0, 0, 1, 0, 0, 1
	};
	bool** graph = new bool*[6]{ 
		new bool[6] {0, 1, 0, 1, 0, 0}, 
		new bool[6] {1, 0, 1, 0, 0, 0}, 
		new bool[6] {0, 1, 0, 0, 1, 0}, 
		new bool[6] {1, 0, 0, 0, 0, 0}, 
		new bool[6] {0, 0, 1, 0, 0, 1},
		new bool[6] {0, 0, 0, 0, 1, 0}
	};

	cout<<ccs.closestCoffeeStore(graph,isCoffeStore,6,0);
	
	return 0;
}
