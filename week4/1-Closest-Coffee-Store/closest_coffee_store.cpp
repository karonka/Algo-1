#include <cstdio>
#include <cstring>
#include <queue>
#define MAXX 1001
using namespace std;

int isCoffeStore[MAXX] = {};
int mat[MAXX][MAXX] = {};
bool visited[MAXX] = {};
int pl[MAXX] = {};
int size, startingPoint;

int closestCoffeeStore(){
	int curr = startingPoint;
	queue<int> q;
	q.push(curr);
	while( q.size() > 0 && !isCoffeStore[q.front()]){
		curr = q.front();
		visited[curr] = true;
		q.pop();
		for(int i = 1; i <= size; i++){
			if (mat[curr][i] && !visited[i]){
				if (!pl[i]) pl[i] = curr;
				q.push(i);
			}
		}
	}
	if (q.size() > 0){
		int x = 0;
		int i = q.front();
		while(i != startingPoint) {
			x++;
			i = pl[i];
		}
		return x;
	}
	return -1;
}

int main(){
	scanf("%d", &size);
	for(int i = 1; i <= size; i++){
		for(int j = 1; j <= size; j++){
			scanf("%d", &mat[i][j]);
		}
	}
	scanf("%d", &startingPoint);
	startingPoint++;
	for(int i = 1; i <= size; i++){
		scanf("%d", &isCoffeStore[i]);
	}
	
	printf("%d\n",closestCoffeeStore());
	
	return 0;
}
