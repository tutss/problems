#include <iostream>

using namespace std;

int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	
	if (a != d || (c > 0 && a == 0)) {
		cout << 0;
		return 0;
	}
	
	
	cout << 1;
}
