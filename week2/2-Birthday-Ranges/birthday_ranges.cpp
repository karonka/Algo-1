#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Pair {
public:
  int start;
  int end;
  Pair(int s = 0, int e = 0):start(s),end(e){}
};

class BirthdayRanges {
public:
	vector<int> birthdays_count(vector<int> &birthdays, vector<Pair> &ranges) {
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
			int beg = ranges[i].start + 1;
			int end = ranges[i].end + 1;
			newRanges.push_back(k[end] - k[beg-1]);
		}
	  return newRanges;
	}
};

int main(){
	BirthdayRanges br;
	int n,m,a,b;
	cin >> n >> m;
	vector<int> v;
	while(n--) {
		cin >> a;
		v.push_back(a);
	}
	vector<Pair> ranges;// = {Pair(0,5),Pair(4,10), Pair(10,365)};
	while(m--){
		cin >> a >> b;
		ranges.push_back(Pair(a,b));
	}
	vector <int> result = br.birthdays_count(v,ranges);
	for (int i = 0; i < result.size(); i++) cout<<result[i]<<endl;
	return 0;
}
