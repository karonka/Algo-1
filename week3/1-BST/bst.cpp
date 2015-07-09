#include <cstdio>
#define MAXX 100000
#define INF 2147483647

using namespace std;

int arr[MAXX] = {};
int N;

bool check(int i, int min, int max){
	bool l = true, r = true;
    if (i*2 + 1 < N && arr[i*2 + 1]){
    	if (arr[i*2 + 1] < arr[i] && arr[i*2 + 1] < max && arr[i*2 + 1] > min)
    		l = check(i*2 + 1, min, arr[i]);
    	else
    		return false;
    }
    if (i*2 + 2 < N && arr[i*2 + 2]){
    	if (arr[i*2 + 2] > arr[i] && arr[i*2 + 2] > min && arr[i*2 + 2] < max)
    		r = check(i*2 + 2, arr[i], max);
    	else
    		return false;
    }
    return l && r;
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}
	if (check(0, -INF, INF)) {
		printf("YES");
	}
	else{
		printf("NO");
	}
	return 0;
}
