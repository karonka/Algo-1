#include <cstdio>
#define MAXX 100000
#define INF 2147483647

using namespace std;

int arr[MAXX] = {};
int N;

bool check(int i, int cmp){
	static int level = 0;
	level += 1;
	int multi = -1;
	if (level%2) multi = 1;
  	bool l = true, r = true;
    if (i*2 + 1 < N && arr[i*2 + 1]){
    	if (arr[i*2 + 1]*multi > arr[i]*multi && arr[i*2 + 1]*multi < cmp*multi ){
    		l = check(i*2 + 1, arr[i]);
		}
    	else{
			level -= 1;
    		return false;
		}
    }
    if (i*2 + 2 < N && arr[i*2 + 2]){
    	if (arr[i*2 + 2]*multi > arr[i]*multi && arr[i*2 + 2]*multi < cmp*multi){
    		r = check(i*2 + 2, arr[i]);
		} 
    	else{
			level -= 1;
    		return false;
		}
    }
	level -= 1;
    return l && r;
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}
	if (check(0, INF)) {
		printf("YES");
	}
	else{
		printf("NO");
	}
	return 0;
}
