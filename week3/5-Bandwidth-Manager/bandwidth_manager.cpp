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
};

class BandwidthManager {
	
	vector<Packet> queue;
	void swap(Packet &a, Packet &b){
		Packet tmp = a;
		a = b;
		b = tmp;
	}
	void go_up(int i){
		while (i >= 1 && queue[i/2] < queue[i]){
			swap(queue[i],queue[i/2]);
			i = i/2;
		}
	}
	void heapify(int i){
		int size = queue.size();
		int m = i;
		while(i*2 + 1 < size){
			if (i*2 + 1 < size && queue[m] < queue[i*2 + 1]) m = i*2 + 1;
			if (i*2 + 2 < size && queue[m] < queue[i*2 + 2]) m = i*2 + 2;
			if (queue[i] < queue[m]){
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
	bm.rcv ("UDP", "zxchzrkljhklzrjlkhklzr");
	bm.rcv ("TCP", "ghljkajklhgjklare");
	bm.rcv ("ICMP", "ping87.129.54.123");
	cout << bm.send() << endl;
	cout << bm.send() << endl;
	bm.rcv ("DNS", "maps.google.com");
	cout << bm.send() << endl;
	bm.rcv ("TCP", "aejkgjkaegaegae");
	cout << bm.send() << endl;
	cout << bm.send() << endl;
	cout << bm.send() << endl;
	
	return 0;
}
