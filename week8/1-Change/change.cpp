#include <iostream>
using namespace std;

int n,coins[7] = {1,2,5,10,20,50,100};
int dp[1001][7] = {};

int res(int aim, int max){
	if (aim == 0) return 1;
	if (aim < 0) return 0;
	if (dp[aim][max]) return dp[aim][max];
	int sum = 0;
	for(int i = 0; i < 7 && coins[i] <= max; i++){
		sum += res(aim - coins[i], coins[i]);
	}
	return dp[aim][max] = sum;
}

int find_max(){
	int i = 6;
	while(coins[i] > n) i--;
	return coins[i];
}

int main(){
	cin >> n;
	cout << res(n,find_max()) << endl;
	return 0;
}
 

