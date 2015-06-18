#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> birthdays_count(vector<int> &birthdays, vector<pair<int,int>> &ranges) {
	vector<int> newRanges;
	int k[367] = {0};
	sort(birthdays.begin(),birthdays.end());
	int cnt = 0;
	for(int i = 1,j = 0; i <= 366;){
		if (j < birthdays.size() && birthdays[j] + 1 == i) {cnt++;j++;}
		if (birthdays[j] + 1 > i) {
			k[i] = cnt;
			i++;
		}
		if (j >= birthdays.size()){
			k[i] = cnt;
			i++;
		}
	}
	for(int i = 0; i < ranges.size(); i++){
		int beg = ranges[i].first + 1;
		int end = ranges[i].second + 1;
		newRanges.push_back(k[end] - k[beg-1]);
	}
  return newRanges;
}
int main(){
	vector<int> v = {1,1,1,1,4,6,6,3,3,7,2,1,20,55,5,5,300};
	vector<pair<int,int>> ranges = {make_pair(0,5),make_pair(4,10), make_pair(10,365)};
	vector <int> result = birthdays_count(v,ranges);
	for (int i = 0; i < result.size(); i++) cout<<result[i]<<" ";
	return 0;
}
