#include<iostream>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;

	int grades [n];
	int kth_grade = 0;
	int participants = 0;

	for (int i = 0; i < n; i++) {
		cin >> grades[i];
		if (i == k-1) {
			kth_grade = grades[i];
		}
	}
	int j = 0;
	while (grades[j] > 0 && grades[j] >= kth_grade && j < n) {
		participants++;
		j++;
	}
	cout << participants;
}


