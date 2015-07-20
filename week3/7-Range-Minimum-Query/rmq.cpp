#include <iostream>
#include <string>
#define INF 2147483647
#define MAXX 2097152
using namespace std;

int arr[MAXX] = {};
int beg,sz,n,k,minn,s,e;
//beg - index of first el of the sequence
//sz - last index ot the tree
//n - last index of the sequence

void init(){
	int d = 1;
	while (d < n) d <<= 1;
	sz = 2*d - 1;
	beg = d - 1;
	for(int i = 0; i < sz; i++) arr[i] = INF;
}

void re(int i){
	int sib = i%2 ? i+1 : i-1;
	int par = (i - 1)/2;
	while (i > 0 && arr[par] != min(arr[i],arr[sib])) {
		arr[par] = min(arr[i],arr[sib]);
		i = par;
		sib = i%2 ? i+1 : i-1;
		par = (i - 1)/2;
	}
}

void set(int index, int value) {
	index = index + beg;
	arr[index] = value;
	re(index);
}

void q(int curr, int left, int right){
	if (curr >= sz || left > e || right < s) return;
	if((left >= s && left <= e) && (right >= s && right <= e)){
		if (minn > arr[curr]) minn = arr[curr];
	}
	else{
		q(curr*2 + 1, left, (left+right)/2);
		q(curr*2 + 2, (left+right)/2 + 1, right);
	}
}

void input(){
	int tmp;
	cin >> n >> k;
	init();
	for(int i = 0; i < n; i++){
		cin >> tmp;
		set(i,tmp);
	}
	n--;
}

void solve(){
	string cmd;
	while(k--){
		cin >> cmd >> s >> e;
		if (cmd == "set"){
			set(s,e);
		}
		else{
			minn = INF;
			q(0,0,sz-beg -1);
			cout << minn << endl;
		}
	}
}

int main(){
	cin.sync_with_stdio(false);
	input();
	solve();
	return 0;
}
