#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#define MAXX 10000
using namespace std;

struct Node{
	int num;
	string name;
	vector<int> d1; // zavisimo e ot
	Node(int nm, string nme){
		num = nm;
		name = nme;
	}
};

vector<string> list;
vector<Node> nodes;
map<string, int> map4e;
bool visited[MAXX] = {};
bool check[MAXX] = {};
bool cycle = false;
int n;
int project;

void input(){
	cin >> n;
	string p;
	int tmp;
	for(int i = 0; i < n; i++){
		cin >> p;
		map4e[p] = i;
		nodes.push_back(Node(i, p)); 
	}
	cin >> p;
	project = map4e[p];
	for(int i = 0; i < n; i++){
		cin >> tmp;
		while(tmp--){
			cin >> p;
			nodes[i].d1.push_back(map4e[p]);
		}
	}
}
void dfs(int curr){
	if (cycle || visited[curr]) return;
	visited[curr] = true;
	check[curr] = true;
	for(int i = 0; i < nodes[curr].d1.size(); i++){
		int neighbor = nodes[curr].d1[i];
		if (check[neighbor]){
			cycle = true;
			return;
		}
		dfs(neighbor);
	}
	check[curr] = false;
	list.push_back(nodes[curr].name);
}

void solve(){
	dfs(project);
	if (cycle) cout << "BUILD ERROR" << endl;
	else {
		for(int i = 0; i < list.size(); i++)
			cout << list[i] << " ";
		cout << endl;
	}
}

int main(){
	input();
	solve();
	return 0;
}
