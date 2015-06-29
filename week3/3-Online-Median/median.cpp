#include <iostream>
#include <string>
#include <vector>

using namespace std;

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

class Median {
	vector<int> min;
	vector<int> max;
public:
	//inserts the number and returns the median
	int insert(int number){
		if( min.size() == max.size()){
			if(!min.size() || number >= min[0]){
				min.push_back(number);
				go_up(min, 1, min.size() - 1);
			}
			else{
				min.push_back(number);
				go_up(min, 1, min.size() - 1);
				if (min[0] < max[0]){
					swap(min[0], max[0]);
					heapify(max, 1, 0);
				}
			}
		}
		else{ //min.size > max.size
			if(number <= min[0]){
				max.push_back(number);
				go_up(max, -1, max.size() - 1);
			}
			else{// number > min[0]
				max.push_back(min[0]);
				go_up(max, -1, max.size() - 1);
				min[0] = number;
				heapify(min, -1, 0);
			}
		}
		return min[0];
	}
	void heapify(vector<int>& seq, bool mult, int i){
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
		while (i >= 1 && seq[i]*mult < seq[i/2]*mult){
			swap(seq[i],seq[i/2]);
			i = i/2;
		}
	}
};

int main(){
	Median med;/*
	cout<<med.insert(4)<<" ";
	cout<<med.insert(14)<<" ";
	cout<<med.insert(1)<<" ";
	cout<<med.insert(5)<<" ";
	cout<<med.insert(40)<<" ";
	cout<<med.insert(14)<<" ";
	cout<<med.insert(8)<<" ";
	cout<<med.insert(3)<<" ";
	cout<<med.insert(0)<<" ";
	cout<<med.insert(2)<<" ";
	*/
	cout<<med.insert(1)<<" ";
	cout<<med.insert(2)<<" ";
	cout<<med.insert(3)<<" ";
	cout<<med.insert(3)<<" ";
	cout<<med.insert(4)<<" ";
	cout<<med.insert(5)<<" ";
	cout<<med.insert(6)<<" ";
	cout<<med.insert(6)<<" ";
	cout<<med.insert(7)<<" ";
	cout<<med.insert(8)<<" ";
	return 0;
}
