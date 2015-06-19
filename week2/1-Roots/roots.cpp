#include <cstdio>
#include <cmath>

using namespace std;

double binary(double l, double r, double x){
	double t;
	while(l < r && r - l > 0.00001) {
		t = (l + (r - l)/2)*(l + (r - l)/2);
		if (abs(x-t) < 0.00000001) return l + (r - l)/2;
		if (t > x){
			r = l + (r - l)/2;
		}
		else{
			l = l + (r - l)/2;
		}
	}
	return (l + (r - l)/2);
}
class Roots {
public:
	double square_root(int x){
		return binary(0,x,x);
	}
};

int main(){
	Roots r;
	printf("%.5f", r.square_root(20));
	return 0;
}
