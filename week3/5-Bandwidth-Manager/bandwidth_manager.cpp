#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Packet{
public:
	int priority;
	string data;
	Packet(int p, string d):priority(p),data(d){}
	
	bool operator<(const Packet& ob){
		return priority < ob.priority;
	}
	bool operator<=(const Packet& ob){
		return priority <= ob.priority;
	}
};

class BandwidthManager {
	
	vector<Packet> queue;
	void go_up(int i){
		while (i >= 1 && queue[(i-1)/2] < queue[i]){
			swap(queue[i],queue[(i-1)/2]);
			i = (i-1)/2;
		}
	}
	void heapify(int i){
		int size = queue.size();
		int m = i;
		while(i*2 + 1 < size){
			if (i*2 + 1 < size && queue[m] <= queue[i*2 + 1]) m = i*2 + 1;
			if (i*2 + 2 < size && queue[m] <= queue[i*2 + 2]) m = i*2 + 2;
			if (queue[i] <= queue[m] && i != m){
				swap(queue[m],queue[i]);
				i = m;
			}
			else return;
		}
	}
	
public:

	//receives a packet with specified protocol and payload
	void rcv(string protocol, string payload){
		int priority = 0;
		if (protocol == "ICMP") priority = 5;
		else if (protocol == "UDP") priority = 4;
		else if (protocol == "RTM") priority = 3;
		else if (protocol == "IGMP") priority = 2;
		else if (protocol == "DNS") priority = 1;
		queue.push_back(Packet(priority,payload));
		go_up(queue.size()-1);
	}

	//returns the payload of the packet which should be sent
	string send(){
		if (queue.size() < 1) return "Nothing to send!";
		string result = queue[0].data;
		queue[0] = queue.back();
		queue.pop_back();
		heapify(0);
		return result;
	}
};

int main(){
	BandwidthManager bm;
	int n;
	string cmd,p,s;
	cin >> n;
	while(n--){
		cin >> cmd;
		if (cmd == "rcv"){
			cin >> p >> s;
			bm.rcv(p,s);
		}
		else if (cmd == "send"){
			cout << bm.send() << endl;
		}
	}
	
	return 0;
}
