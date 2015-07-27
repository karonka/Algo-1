#include <cstdio>
#include <cstring>
#include <set>
#define INF 2147483647
#define MAXX 10001

using namespace std;

struct cmp{
	bool operator() (const pair<int,int> a, const pair<int, int> b){
		if (a.second == b.second)
			return a.first < b.first;
		return a.second < b.second;
	}
};

bool used[MAXX] = {};
int d[MAXX], n, m, s, e;
set< pair<int,int>, cmp > SS[MAXX] = {};
int pl[MAXX] = {};

void input(){
	scanf("%d %d %d %d", &n, &m, &s, &e);
	int a,b,c;
    while(m--){
       scanf("%d %d %d", &a, &b, &c);
       SS[a].insert(make_pair(b,c));
       SS[b].insert(make_pair(a,c));
    }
}

void dijkstra (){
	for(int i = 1; i <= n; i++){ d[i] = INF; used[i] = 0;}	
	int min, cv, y;
	d[s] = 0;
	
	for(int i = 1; i <= n; i++){
		min = INF; cv = 0;
		for(int j = 1;j <= n; j++){ 
			if(!used[j] && d[j] < min){ 
				cv = j; min = d[j];
			}
		}
		//if (!cv) break;
		if (cv == e) return;
		used[cv] = 1;
		for(auto it = SS[cv].begin(); it != SS[cv].end(); ++it) { 
			y = it -> first; 
			if(!used[y] && d[cv] + it -> second < d[y]) {
				d[y] = d[cv] + it -> second; pl[y] = cv;
			} 
		}
	}
}

void print_path(unsigned dest){
	if (pl[dest]) print_path( pl[dest] );
	printf("%d ", dest);
}

int main(){
	input();
	dijkstra();
	printf("%d\n", d[e]);
	print_path(e);
	return 0;
}
