#include <cstdio>
#include <cstring>
#include <stack>
#define MAXX 1001
using namespace std;

int graph[MAXX][MAXX] = {};
int visited[MAXX] = {};
int n;

void input(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
				scanf("%d", &graph[i][j]);
		}
	}
}

class ValidDirectories {
public:
	bool dfs(int i, int size){
		if (visited[i] == 2) return false;
		visited[i] = 2;
		for(int j = 0; j < size; j++){
			if (graph[i][j] == 1 && visited[j] != 1){
				if (!dfs(j, size)) return false;
			}
		}
		visited[i] = 1;
		return true;
	}
	bool isValid() {
		return dfs(0, n);
	}
};


int main(){
	ValidDirectories vd;
	input();
	if(vd.isValid())
		printf("true\n");
	else
		printf("false\n");
	return 0;
}
