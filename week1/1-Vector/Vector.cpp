#include <iostream>
#include <cstdlib>

using namespace std;

class Vector{
	int size;
	int capacity;
	int* vec;
	public:
	Vector(){
		size = 0;
		capacity = 16;
		vec = (int*) malloc(capacity*sizeof(int));
	}
	void insert(int index,int value){
		if (index > size || index < 0){
			cout<<"Out of bounds!";
		}
		if (size + 1 > capacity){
			expand();
		}
		else{
			for (int i = size + 1; i >= index; i--){
				vec[i+1] = vec[i];
			}
			vec[index] = value;
			size++;
		}
	}
	void add(int value){
		if (size + 1 > capacity){
			expand();
		}
		vec[size++] = value;
	}
	int get(int index){
		if (index < 0 || index >= size){
			cout<<"Out of bounds!";
			return -1;
		}
		return vec[index];
	}
	int getSize(){
		return size;
	}
	int getCapacity(){
		return capacity;
	}
	void pop(){
		size--;
	}
	void deleteV (int index){
		for (int i = index; i < size - 1; i++){
			vec[i] = vec[i+1];
		}
		size--;
		if (size < capacity/4){
			contract();
		}
	}
	void expand(){
		cout<<"expanding.."<<endl;
		vec = (int*)realloc(vec,(capacity+(int)(0.5*capacity))*sizeof(int));
		capacity+=(int)(0.5*capacity);
	}
	void contract(){
		cout<<"contracting.. form "<<capacity <<" to "<<((int)(0.5*capacity))<<endl;
		vec = (int*)realloc(vec,((int)(0.5*capacity))*sizeof(int));
		capacity = (int)(0.5*capacity);
	}
};
int main(){
	// test
	Vector v;
	for(int i = 1; i <= 16; i++) v.add(i);
	for(int i = 0; i < v.getSize(); i++) cout<<v.get(i)<<" ";
	v.insert(5,5);
	for(int i = 0; i < v.getSize(); i++) cout<<v.get(i)<<" ";
	cout<<endl;
	for(int i = 16; i >= 2; i--){
		v.deleteV(i);
	}
	for(int i = 0; i < v.getSize(); i++) cout<<v.get(i)<<" ";
	cout<<endl;
	return 0;	
}
