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

bool cmp (Contact i,Contact j) { return (i.number < j.number); }
string binary(int num, vector<Contact> &book){
	int l = 0; 
	int r = book.size();
	int mid;
	while(l < r) {
		mid = l + (r - l)/2;
		if (book[mid].number == num) return book[mid].name;
		if (book[mid].number > num){
			r = l + (r - l)/2 - 1;
		}
		else{
			l = l + (r - l)/2 + 1;
		}
	}
	return book[l].name;
}

class PhoneBook {
public:

  // Find the names of people based on their phone numbers.
  vector<string> lookupNames(vector<Contact> &phoneBook, vector<int> &numbers) {
    	vector<string> names;
		sort(phoneBook.begin(),phoneBook.end(),cmp);
		for(unsigned i = 0; i < numbers.size(); i++){
			names.push_back(binary(numbers[i], phoneBook));
		}
		return names;
  }
};

int main(){
	PhoneBook pb;
	vector<Contact> phone_book = {Contact("a",6),Contact("i",65),Contact("el",13),
		Contact("a",2432423),Contact("dje",3),Contact("fr",101)};
	vector<int> numbers = {65,6,101,3,13,2432423};
	vector<string> result = pb.lookupNames(phone_book,numbers);
	for(unsigned i = 0; i < result.size(); i++){
		cout<<result[i]<<" ";
	}
	cout<<"\nCOMPARE\ni a fr dje el a"<<endl;
	return 0;
}
