#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
vector<long long> first;
vector<long long> second;
int n;

int bounds(int pos){
	int x = second[pos];
	int l = 0; 
	int r = pos;
	int mid, min = pos, max = pos;
	while(l <= r) {
		mid = l + (r - l)/2;
		if (second[mid] == x){
			min = mid;
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	l = pos, r = second.size() - 1;
	while(l <= r) {
		mid = l + (r - l)/2;
		if (second[mid] == x){
			max = mid;
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	return max - min + 1;
}

int binary(int num){
	int l = 0; 
	int r = second.size();
	int mid;
	while(l < r) {
		mid = l + (r - l)/2;
		if (second[mid] == num) {
			break;
		}
		if (second[mid] > num){
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	mid = l + (r - l)/2;
	if (second[mid] == num){
		return bounds(mid);
	}
	return 0;
}

int zero_quadruplets_count(int* a, int* b, int* c, int* d) {
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			first.push_back(a[i] + b[j]);
			second.push_back(c[i] + d[j]);
		}
	}
	int count = 0;
	sort(second.begin(),second.end());
	for(int i = 0; i < first.size(); i++){
			count += binary(-first[i]);
	}
	return count;
}

int main(){
	scanf("%d", &n);
	int a[n];
	int b[n];
	int c[n];
	int d[n];
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i < n; i++) scanf("%d", &b[i]);
	for(int i = 0; i < n; i++) scanf("%d", &c[i]);
	for(int i = 0; i < n; i++) scanf("%d", &d[i]);
	
	printf("%d", zero_quadruplets_count(a,b,c,d));
	
	return 0;
}
