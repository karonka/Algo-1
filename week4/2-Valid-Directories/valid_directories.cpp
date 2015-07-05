#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

class ValidDirectories {
public:
	bool dfs(int** graph, bool* visited, int i, int size){
		if (visited[i]) return false;
		visited[i] = true;
		for(int j = 0; j < size; j++){
			if (graph[i][j] == 1){
				if (!dfs(graph, visited, j, size)) return false;
			}
		}
		visited[i] = false;
		return true;
	}
	bool isValid(int** graph, int size) {
		bool* visited = new bool[size];
		memset(visited, 0, sizeof(bool)*size);
		return dfs(graph, visited, 0, size);
	}
};


int main(){
	ValidDirectories vd;
	
	int** graph = new int*[6]{ 
		new int[6] {0, 1, 0, 1, 0, 2}, 
		new int[6] {0, 0, 2, 0, 0, 0}, 
		new int[6] {0, 0, 0, 0, 0, 0}, 
		new int[6] {0, 0, 0, 0, 2, 0}, 
		new int[6] {0, 0, 0, 0, 0, 0},
		new int[6] {0, 0, 0, 0, 0, 0}
	};
	
	cout<<vd.isValid(graph,6)<<endl;
	
	return 0;
}
