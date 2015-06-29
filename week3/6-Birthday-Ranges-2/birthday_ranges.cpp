#include <iostream>
#include <cstring>

using namespace std;

class BirthdayRanges {
public:
	int arr[1024];
	BirthdayRanges(){
		memset(arr,0,sizeof(int)*1024);
	}
	// adds people who are born on a specific day
	void add(int day, int numberOfPeople) {
		day = day + 510;
		while(day > 0 ){
			arr[day] += numberOfPeople;
			day = (day - 1)/2;
		}
	}

	// removes people who are born on a specific day
	void remove(int day, int numberOfPeople) {
		day = day + 510;
		numberOfPeople = arr[day] > numberOfPeople ? numberOfPeople : arr[day];
		while(day > 0){
			arr[day] -= numberOfPeople;
			day = (day - 1)/2;
		}
	}

	// returns the number of people born in a range
	int count(int startDay, int endDay) {
		return all(endDay + 1) - all(startDay);
	}
	
	int all (int endDay){
		if (endDay == 367) return arr[1]+arr[2];
		
		int sum = 0;
		endDay = endDay + 510;
		bool right_child = false;
		while (endDay > 1){
			right_child = (endDay%2 == 0);
			if (right_child){
				sum += arr[endDay - 1];
				endDay = (endDay - 1)/2;
			}
			else{
				endDay = (endDay - 1)/2;
			}
		}
		return sum;
	}
};

int main(){
	BirthdayRanges br;
	int n,m,tmp,a,b;
	string cmd;
	
	cin>>n>>m;
	
	while(n--){
		cin>>tmp;
		br.add(tmp,1);
	}
	while (m--){
		cin>>cmd>>a>>b;
		if(cmd == "add"){
			br.add(a,b);
		}
		else if(cmd == "remove"){
			br.remove(a,b);
		}
		else if(cmd == "count"){
			cout<<br.count(a,b)<<endl;
		}
	}
	return 0;
}
