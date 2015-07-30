#include <iostream>
using namespace std;

int n,coins[7] = {1,2,5,10,20,50,100};
int dp[1001][7] = {};

int res(int aim, int max_i){
	if (aim == 0) return 1;
	if (aim < 0) return 0;
	if (dp[aim][max_i]) return dp[aim][max_i];
	int sum = 0;
	for(int i = max_i; i >= 0; i--){
		sum += res(aim - coins[i], i);
	}
	return dp[aim][max_i] = sum;
}

int find_max(){
	int i = 6;
	while(coins[i] > n) i--;
	return i;
}

int main(){
	cin >> n;
	cout << res(n,find_max()) << endl;
	return 0;
}
 

