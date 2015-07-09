#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Median {
	vector<int> min;
	vector<int> max;
public:
	//inserts the number and returns the median
	int insert(int number){
		if( min.size() == max.size()){
			min.push_back(number);
			go_up(min, 1, min.size() - 1);
			if (max.size() && min[0] < max[0]){
				swap(min[0], max[0]);
				heapify(max, -1, 0);
			}
		}
		else{ //min.size > max.size
			if(number <= min[0]){
				max.push_back(number);
				go_up(max, -1, max.size() - 1);
			}
			else{ // number > min[0]
				max.push_back(min[0]);
				go_up(max, -1, max.size() - 1);
				min[0] = number;
				heapify(min, 1, 0);
			}
		}
		return min[0];
	}
	void heapify(vector<int>& seq, int mult, int i){
		int size = seq.size();
		int m = i;
		while(i*2 + 1 < size){
			if (i*2 + 1 < size && mult*seq[i*2 + 1] < mult*seq[m]) m = i*2 + 1;
			if (i*2 + 2 < size && mult*seq[i*2 + 2] < mult*seq[m]) m = i*2 + 2;
			if (seq[m]*mult < seq[i]*mult){
				swap(seq[m],seq[i]);
				i = m;
			}
			else return;
		}
	}
	void go_up(vector<int>& seq, int mult, int i){
		while (i >= 1 && seq[i]*mult < seq[(i-1)/2]*mult){
			swap(seq[i],seq[(i-1)/2]);
			i = (i-1)/2;
		}
	}
};

int main(){
	Median med;
	int n, tmp;
	cin >> n;
	while(n--){
		cin>>tmp;
		cout<<med.insert(tmp)<<endl;
	}
	return 0;
}
