#include <cstdio>
#include <cstring>
#define MAXX 32768
using namespace std;

int tree[MAXX] = {};
int n, beg, k;

void input(){
	scanf("%d %d", &n, &k);
	beg = 1;
	while (beg < n){
		beg <<= 1;
	}
	beg--;
}

int query(int num){
	if (num == n) return tree[1] + tree[2];
	int sum = 0;
	num = num + beg;
	bool right_child = false;
	while (num > 1){
		right_child = (num%2 == 0);
		if (right_child){
			sum += tree[num - 1];
			num = (num - 1)/2;
		}
		else{
			num = (num - 1)/2;
		}
	}
	return sum;
}

void add(int num){
	int pos = beg + num;
	while(pos > 0 ){
		tree[pos]++;
		pos = (pos - 1)/2;
	}
}

int solve(){
	int sum = 0, max = 0, number = 1;
	for(int i = 0; i < k; i++){
		memset(tree,0,sizeof(int)*2*beg);
		sum = 0;
		int tmp;
		for(int i = 0; i < n; i++){
			scanf("%d", &tmp);
			//printf("%d :: %d ____ i: %d q: %d\n",tmp, i - query(tmp), i, query(tmp));
			sum += i - query(tmp);
			add(tmp);
		}
		if (sum > max) {
			max = sum;
			number = i + 1;
		}
		//printf("row: %d jumps: %d\n", i + 1, sum);
	}
	return number;
}

int main(){
	input();
	printf("%d",solve());
	return 0;
}
