#include<iostream>

using namespace std;

int main(){
	int n;
	cin >> n;

	int capacity = 0;
	int passagers = 0;
	int entered;
	int left;

	for(int i = 0; i < n; i++) {
		cin >> left >> entered;
		passagers += entered - left;
		if (capacity < passagers) {
			capacity = passagers;
		}
	}
	cout << capacity;
}
