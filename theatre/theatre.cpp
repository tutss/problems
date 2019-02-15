#include<iostream>
#include<math.h>

using namespace std;

int main(){
	double n;
	double m;
	double a;
	long long int n_flagstones;
	cin >> n;
	cin >> m;
	cin >> a;
	n_flagstones = ceil(n/a) * ceil(m/a);
	cout << n_flagstones;
}
