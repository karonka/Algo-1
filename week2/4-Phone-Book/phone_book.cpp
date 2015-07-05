#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Contact {
public:
  string name;
  int number;
  Contact(string name, int num):name(name),number(num){};
};

vector<Contact> phone_book;
int size;
bool cmp (Contact i,Contact j) { return (i.number < j.number); }
void binary(int num){
	int l = 0; 
	int r = size;
	int mid;
	while(l < r) {
		mid = l + (r - l)/2;
		if (phone_book[mid].number == num) {
			cout << phone_book[mid].name << endl;
			return;
		}
		if (phone_book[mid].number > num){
			r = l + (r - l)/2 - 1;
		}
		else{
			l = l + (r - l)/2 + 1;
		}
	}
	cout << phone_book[l].name << endl;
}

int main(){
	int n,m,tmp;
	string s;
	cin >> n >> m;
	while (n--){
		cin >> tmp >> s;
		phone_book.push_back(Contact(s,tmp));
	}
	sort(phone_book.begin(),phone_book.end(),cmp);
	size = phone_book.size();
	while (m--){
		cin >> tmp;
		binary(tmp);
	}
	return 0;
}
