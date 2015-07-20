#include <cstdio>
#include <set>
#define MAXX 1001
using namespace std;

struct cmp{
	bool operator()(const pair< pair<int,int>, int > a,const pair< pair<int,int>, int > b)const{
		return a.second < b.second; 
	}
};

int n = 0,m;
int visited[MAXX] = {};
multiset<pair< pair<int,int>, int >, cmp > edges;

void input(){
	int a,b,c;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &a, &b, &c);
		if (a > n) n = a;
		if (b > n) n = b;
		edges.insert(make_pair(make_pair(a,b),c));
	}
}

bool ready(int a, int b){
	bool rdy = true;
	//for(int i = 1; i <= n; i++) printf("%d ",visited[i]);printf("\n");
	for(int i = 1; i <= n; i++){
		if (visited[i] == a) visited[i] = b;
		if(visited[i] != 1) rdy = false;
	}
	return rdy;
}

int solve(){
	int sum = 0;
	int tree_cnt = 0;
	int min, max, cnt;
	do{
		//printf("sum :: %d\n",sum);
		int a = (edges.begin() -> first).first;
		int b = (edges.begin() -> first).second;
		if ( (!visited[a] || !visited[b]) ||
			( visited[a] != visited[b])
			 ){
			sum += edges.begin() -> second;
			min = visited[a] < visited[b] ? 
				visited[a] : visited[b];
			max = visited[a] > visited[b] ? 
				visited[a] : visited[b];
				
			cnt = min == 0? max : min;
			
			if (!cnt) cnt = ++tree_cnt;
			visited[a] = cnt;
			visited[b] = cnt;
			if (!max) max = cnt;
			//printf("%d-%d __ %d\n", a, b, edges.begin() -> second);
		}
		edges.erase(edges.begin());
	}while (!ready(max, cnt) && edges.size() > 0);
	return sum;
}

int main(){
	input();
	printf("\n");
	printf("%d",solve());
	return 0;
}
