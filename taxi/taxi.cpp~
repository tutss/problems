#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef vector<int> vi;

int main() {

	int n;
	cin >> n;
	vi v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];	
	}
	sort(v.rbegin(), v.rend());
	
	int count = 0;
	
	int i = 0;
	int j = n-1;
	while(i <= j) {
		if (i == j){
			count++;
			break;
		}
		if (v[i] == 4) {
			i++;
			count++;
		}
		else if (v[i] + v[j] == 4) {
			i++;
			j--;
			count++;
		}
		else if (v[i] + v[j] > 4) {
			i++;
			count++;
		}
		else {
			v[i] = v[i] + v[j];
			j--;
		}

	}	
	cout << count;
}







