// adski ne4etliv kod...

#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

bool visited[31][31] = {};
pair<int,int> path[31][31] = {};
int how[31][31] = {};
int aim,quantity;
pair<int,int> startingPoint;
int cap[3];

pair< pair<int,int>,pair<int,int> > find_next(int a, int b, int c, int pb, int pc){
	pair< pair<int,int>,pair<int,int> > ans;
	if (!a) {
		return make_pair(make_pair(a,b),make_pair(a,c));
	}
	if (cap[pb] - b){
		if(a > cap[pb] - b){
			ans.first = make_pair(a - (cap[pb] - b), cap[pb]);
		}
		else{
			ans.first = make_pair(0, b + a);
		}
	}
	else 
		ans.first = make_pair(a,b);
		
	if (cap[pc] - c){
		if(a > cap[pc] - c){
			ans.second = make_pair(a - (cap[pc] - c), cap[pc]);
		}
		else{
			ans.second = make_pair(0,c + a);
		}
	}
	else 
		ans.second = make_pair(a,c);
	
	return ans;
}

void print_path(stack<int> s){
	int i;
	while(!s.empty()){
		i = s.top();
		s.pop();
		switch(i){
			case 1: printf("1 2\n");break;
			case 2: printf("1 3\n");break;
			case 3: printf("2 1\n");break;
			case 4: printf("2 3\n");break;
			case 5: printf("3 1\n");break;
			case 6: printf("3 2\n");break;
		}
	}
}

void solve(){
	pair<int,int> curr = startingPoint;
	queue<pair<int,int> > q;
	q.push(curr);
	int a,b,c,x,y;
	while( q.size() > 0){
		curr = q.front();
		a = curr.first;
		b = curr.second;
		c = quantity - a - b; 
		if (a == aim || b == aim || c == aim) break; 
		visited[a][b] = true;
		q.pop();
		
		pair< pair<int,int>,pair<int,int> > result;
		pair<int,int> parent = make_pair(a,b);
		
		result = find_next(a,b,c,1,2);
		if(result.first != parent) {
			x = result.first.first;
			y = result.first.second;
			if (!visited[x][y]){
				q.push(result.first);
				if (path[x][y].first == -1){
					path[x][y] = parent;
					how[x][y] = 1;
				}
			}
		}
		pair<int,int> k = make_pair(a,c);
		if(result.second != k){
			x = result.second.first;
			y = quantity - result.second.first - result.second.second;
			if (!visited[x][y]){
				q.push(make_pair(x,y));
				if (path[x][y].first == -1){
					path[x][y] = parent;
					how[x][y] = 2;
				}
			}
		}
		
		result = find_next(b,a,c,0,2);
		k = make_pair(b,a);
		if(result.first != k) {
			x = result.first.second;
			y = result.first.first;
			if (!visited[x][y]){
				q.push(make_pair(x,y));
				if (path[x][y].first == -1){
					path[x][y] = parent;
					how[x][y] = 3;
				}
			}
		}
		
		k = make_pair(b,c);
		if(result.second != k){
			x = quantity - result.second.first - result.second.second;
			y = result.second.first;
			if (!visited[x][y]){
				q.push(make_pair(x,y));
				if (path[x][y].first == -1){
					path[x][y] = parent;
					how[x][y] = 4;
				}
			}
		}
		
		result = find_next(c,a,b,0,1);
		k = make_pair(c,a);
		if(result.first != k) {
			x = result.first.second;
			y = quantity - result.first.first - result.first.second;
			if (!visited[x][y]){
				q.push(make_pair(x,y));
				if (path[x][y].first == -1){
					path[x][y] = parent;
					how[x][y] = 5;
				}
			}
		}
		k = make_pair(c,b);
		if(result.second != k){
			x = quantity - result.second.first - result.second.second;
			y = result.second.second;
			if (!visited[x][y]){
				q.push(make_pair(x,y));
				if (path[x][y].first == -1){
					path[x][y] = parent;
					how[x][y] = 6;
				}
			}
		}
	}
	if (q.size() > 0){
		stack<int> st;
		pair<int,int> i = q.front();
		while(i != startingPoint) {
			st.push(how[i.first][i.second]);
			i = path[i.first][i.second];
		}
		printf("%d\n",(int)st.size());
		print_path(st);
	}
	else
		printf( "IMPOSSIBLE\n");
}

void input(){
	scanf("%d %d %d", &cap[0], &cap[1], &cap[2]);
	int x,y,z;
	scanf("%d %d %d", &x, &y, &z);
	quantity = x + y + z;
	startingPoint = make_pair(x,y);
	scanf("%d", &aim);
	for(int i = 0; i < 31; i++){
		for(int j = 0 ; j < 31; j++){
			path[i][j].first = -1;
		}
	}
}

int main(){
	input();
	solve();
	return 0;
}
