#include <cstdio>
#define INF 2147483647
#define MAXX 501

int mat[MAXX][MAXX] = {};
int dp[MAXX][MAXX] = {};
int d[MAXX] = {};
bool used[MAXX] = {};
int n,m;

void input(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", &mat[i][j]);
		}
	}
}

void dijkstra(int a, int b){
	if (dp[a][b] > 0){
		printf("%d\n",dp[a][b]);
		return;
	}
	if (dp[a][b] == -1){
		printf("NO WAY\n");
		return;
	}
	
	for(int i = 1; i <= n; i++){ 
		d[i] = INF;
		used[i] = 0;
	}
		
	int min, cv;
	d[a] = 0;
	
	for(int i = 1; i <= n; i++){
		min = INF; cv = 0;
		for(int j = 1; j <= n; j++){ 
			if(!used[j] && d[j] < min){ 
				cv = j; min = d[j];
			}
		}
		if (!cv) {
			break;
		}
		used[cv] = 1;
		for(int k = 1; k <= n; k++){
			if(!used[k] && mat[cv][k] && d[k] > d[cv] + mat[cv][k]){
				d[k] = d[cv] + mat[cv][k];
				dp[a][k] = d[k];
			}
		}
	}
	if (!dp[a][b]){
		dp[a][b] = -1;
	}
	dijkstra(a,b);
}

void solve(){
	scanf("%d", &m);
	int a,b;
	while(m--){
		scanf("%d %d", &a, &b);
		dijkstra(a + 1,b + 1);
	}
}

int main(){
	input();
	solve();
	return 0;
}
