#include<iostream>
#include <cstring>
using namespace std;

int is_lucky_t1(string n){
	int a_check = 0;
	for (char& c : n) {
		if ( c != '4' && c != '7') {
			a_check = 1;
		}
	}
	return a_check;
}

int is_lucky_t2(int n){
	int b_check = 0;
	if (n % 4 != 0 && n % 7 != 0) {
		b_check = 1;
	}
	return b_check;
}

int main(){
	string n;
	cin >> n;

	int n_int = atoi(n.c_str());
	
	for (int i = 1; i <= n_int; i++) {
		int t1 = is_lucky_t1(to_string(i));
		int t2 = is_lucky_t2(i);
		if (t1 + t2 < 2) {
			if (n_int % i == 0) {
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
}
