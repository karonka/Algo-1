#include <cstdio>
#include <set>
#include <cmath>
#define INF 2147483647
#define MAXX 251

using namespace std;

class Square{
public:
	int i;
	int j;
	int dist;
	Square(int i = 0, int j = 0, int d = 0):i(i),j(j),dist(d){};
	bool operator<(const Square ob)const{
		return dist < ob.dist;
	}	
};

int map[MAXX][MAXX] = {};
int d[MAXX][MAXX] = {};
bool used[MAXX][MAXX] = {};
set<Square> s;
int n, sX, sY, fX, fY;

void input(){
	scanf("%d", &n);
	scanf("%d %d %d %d", &sX, &sY, &fX, &fY);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &map[i][j]);
		}
	}
}

void dijkstra(){
	for(int i = 0; i < n; i++){ 
		for(int j = 0; j < n; j++){ 
			d[i][j] = INF;
		}
	}
		
	int cvX, cvY;
	Square curr;
	d[sX][sY] = 0;
	s.insert(Square(sX,sY,0));
	
	for(int i = 1; i <= n*n; i++){
		if (!s.size()) return;
		curr = *s.begin();
		s.erase(s.begin());
		cvX = curr.i;
		cvY = curr.j;
		if(used[cvX][cvY]) continue;
		if (cvX == fX && cvY == fY) {
			break;
		}
		used[cvX][cvY] = 1;
		
		if(cvX > 0 && !used[cvX-1][cvY]){
			if(d[cvX-1][cvY] > d[cvX][cvY] + abs(map[cvX][cvY] - map[cvX-1][cvY]) + 1){
				d[cvX-1][cvY] = d[cvX][cvY] + abs(map[cvX][cvY] - map[cvX-1][cvY]) + 1;
			}
			s.insert(Square(cvX-1, cvY, d[cvX-1][cvY]));
		}
		if(cvY > 0 && !used[cvX][cvY-1]){
			if (d[cvX][cvY-1] > d[cvX][cvY] + abs(map[cvX][cvY] - map[cvX][cvY-1]) + 1){
				d[cvX][cvY-1] = d[cvX][cvY] + abs(map[cvX][cvY] - map[cvX][cvY-1]) + 1;
			}
			s.insert(Square(cvX, cvY-1, d[cvX][cvY-1]));
		}
		if(cvX > 0 && cvY > 0 && !used[cvX-1][cvY-1]){
			if(d[cvX-1][cvY-1] > d[cvX][cvY] + abs(map[cvX][cvY] - map[cvX-1][cvY-1]) + 1){
				d[cvX-1][cvY-1] = d[cvX][cvY] + abs(map[cvX][cvY] - map[cvX-1][cvY-1]) + 1;
			}
			s.insert(Square(cvX-1, cvY-1, d[cvX-1][cvY-1]));
		}
		if(cvX > 0 && cvY < n-1 && !used[cvX-1][cvY+1]){
			if(d[cvX-1][cvY+1] > d[cvX][cvY] + abs(map[cvX][cvY] - map[cvX-1][cvY+1]) + 1){
				d[cvX-1][cvY+1] = d[cvX][cvY] + abs(map[cvX][cvY] - map[cvX-1][cvY+1]) + 1;
			}
			s.insert(Square(cvX-1, cvY+1, d[cvX-1][cvY+1]));
		}
		if(cvY < n-1 && !used[cvX][cvY+1]){
			if(d[cvX][cvY+1] > d[cvX][cvY] + abs(map[cvX][cvY] - map[cvX][cvY+1]) + 1){
				d[cvX][cvY+1] = d[cvX][cvY] + abs(map[cvX][cvY] - map[cvX][cvY+1]) + 1;
			}
			s.insert(Square(cvX, cvY+1, d[cvX][cvY+1]));
		}
		if(cvX < n-1 && cvY > 0 && !used[cvX+1][cvY-1]){
			if(d[cvX+1][cvY-1] > d[cvX][cvY] + abs(map[cvX][cvY] - map[cvX+1][cvY-1]) + 1){
				d[cvX+1][cvY-1] = d[cvX][cvY] + abs(map[cvX][cvY] - map[cvX+1][cvY-1]) + 1;
			}
			s.insert(Square(cvX+1, cvY-1, d[cvX+1][cvY-1]));
		}
		if(cvX < n-1 && !used[cvX+1][cvY]){
			if(d[cvX+1][cvY] > d[cvX][cvY] + abs(map[cvX][cvY] - map[cvX+1][cvY]) + 1){
				d[cvX+1][cvY] = d[cvX][cvY] + abs(map[cvX][cvY] - map[cvX+1][cvY]) + 1;
			}
			s.insert(Square(cvX+1, cvY, d[cvX+1][cvY]));
		}
		if(cvX < n-1 && cvY < n-1 && !used[cvX+1][cvY+1]){
			if(d[cvX+1][cvY+1] > d[cvX][cvY] + abs(map[cvX][cvY] - map[cvX+1][cvY+1]) + 1){
				d[cvX+1][cvY+1] = d[cvX][cvY] + abs(map[cvX][cvY] - map[cvX+1][cvY+1]) + 1;
			}
			s.insert(Square(cvX+1, cvY+1, d[cvX+1][cvY+1]));
		}
	}
	printf("%d\n", d[fX][fY]);
}

int main(){
	input();
	dijkstra();
	return 0;
}
