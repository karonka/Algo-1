#include <iostream>
#include <cstdlib>

using namespace std;

class Vector{
	int sz;
	int cap;
	int* vec;
	public:
	Vector(){
		sz = 0;
		cap = 16;
		vec = (int*) malloc(cap*sizeof(int));
	}
	~Vector(){
		free(vec);
	}
	void insert(int index,int value){
		if (index > sz || index < 0){
			cout<<"Out of bounds!";
			return;
		}
		if (sz + 1 > cap){
			expand();
			insert(index,value);
		}
		else{
			for (int i = sz - 1; i >= index; i--){
				vec[i+1] = vec[i];
			}
			vec[index] = value;
			sz++;
		}
	}
	void add(int value){
		if (sz + 1 > cap){
			expand();
		}
		vec[sz++] = value;
	}
	int get(int index){
		if (index < 0 || index >= sz){
			cout<<"Out of bounds!";
			return -1;
		}
		return vec[index];
	}
	int size(){
		return sz;
	}
	int capacity(){
		return cap;
	}
	void pop(){
		sz--;
	}
	void deleteV (int index){
		for (int i = index; i < sz - 1; i++){
			vec[i] = vec[i+1];
		}
		sz--;
		if (sz < cap/4){
			contract();
		}
	}
	void expand(){
		cout<<"expanding.."<<endl;
		vec = (int*)realloc(vec,(cap+(int)(0.5*cap))*sizeof(int));
		cap+=(int)(0.5*cap);
	}
	void contract(){
		cout<<"attempt to contract"<<endl;
		if(cap < 16) return; // да не остават < 8
		cout<<"contracting.. form "<<cap<<" to "<<((int)(0.5*cap))<<endl;
		vec = (int*)realloc(vec,((int)(0.5*cap))*sizeof(int));
		cap = (int)(0.5*cap);
	}
};
int main(){
	// test
	Vector v;
	for(int i = 1; i <= 16; i++) v.add(i);
	for(int i = 0; i < v.size(); i++) cout<<v.get(i)<<" ";
	cout<<endl;
	v.insert(5,5);
	for(int i = 0; i < v.size(); i++) cout<<v.get(i)<<" ";
	cout<<endl;
	for(int i = 16; i >= 2; i--){
		v.deleteV(i);
	}
	for(int i = 0; i < v.size(); i++) cout<<v.get(i)<<" ";
	cout<<endl;
	return 0;	
}
