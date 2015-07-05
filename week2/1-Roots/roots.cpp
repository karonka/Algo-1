#include <cstdio>
#include <cmath>

using namespace std;

double binary(double l, double r, double x){
	double t;
	while(l < r && r - l >= 0.000001) {
		t = (l + (r - l)/2)*(l + (r - l)/2);
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
		return binary(1,x,x);
	}
};

int main(){
	Roots r;
	int k;
	scanf("%d", &k);
	printf("%.5f", (double)roundl(r.square_root(k)*1000000.)/1000000.);
	return 0;
}
