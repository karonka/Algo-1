#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp (pair<string,int> i,pair<string,int> j) { return (i.second < j.second); }
string binary(int num, vector< pair<string,int> > &book){
	int l = 0; 
	int r = book.size();
	int mid;
	while(l < r) {
		mid = l + (r - l)/2;
		if (book[mid].second == num) return book[mid].first;
		if (book[mid].second > num){
			r = l + (r - l)/2 - 1;
		}
		else{
			l = l + (r - l)/2 + 1;
		}
	}
	return book[l].first;
}
vector<string> lookup_names(vector< pair<string, int> >& phone_book,vector<int>& numbers) {
	vector<string> names;
	sort(phone_book.begin(),phone_book.end(),cmp);
	for(unsigned i = 0; i < numbers.size(); i++){
		names.push_back(binary(numbers[i], phone_book));
	}
	return names;
}

int main(){
	vector< pair<string, int> > phone_book = {make_pair("a",6),make_pair("i",65),make_pair("el",13),
		make_pair("a",2432423),make_pair("dje",3),make_pair("fr",101)};
	vector<int> numbers = {65,6,101,3,13,2432423};
	vector<string> result = lookup_names(phone_book,numbers);
	for(unsigned i = 0; i < result.size(); i++){
		cout<<result[i]<<" ";
	}
	cout<<"\nCOMPARE\ni a fr dje el a"<<endl;
	return 0;
}
