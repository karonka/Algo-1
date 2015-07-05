#include <cstdio>
#define MAXX 1001
using namespace std;

int mat[MAXX][MAXX] = {};
int visited[MAXX] = {};
int n;

void input(){
	scanf("%d", &n);
	int* nums = new int[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &nums[i]);
		visited[nums[i]] = 1;
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &mat[nums[i]][0]);
		for (int j = 1; j <= mat[nums[i]][0]; j++)
			scanf("%d", &mat[nums[i]][j]);
	}
	delete [] nums;
}
void dfs(int i){
	visited[i] = 2;
	for (int j = 1; j <= mat[i][0]; j++){
		if(visited[mat[i][j]] == 1)
			dfs(mat[i][j]);
	}
}

int main(){
	input();
	int k = 0;
	for(int i = 0; i < MAXX; i++){
		if(visited[i] == 1){
			k++;
			dfs(i);
		}
	}
	printf("%d", k);
	return 0;
}
