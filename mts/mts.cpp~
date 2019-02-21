#include<iostream>
#include<vector>

using namespace std;

int main(){
	string s;
	cin >> s;
	vector<char> v;

	int n = s.size();
	
	int shift = 0;
	for (int i = 0; i < n; i++){
		if (s[i] == '1') {
			shift++;
		}
		else {
			v.push_back(s[i]);
		}
	}
	
	int m = v.size();
	int k;
	for (k = 0; k < m; k++) {
		if (v[k] == '2') {
			while (shift > 0){
				cout << '1';
				shift--;
			}
			break;
		}
		cout << v[k];
	}
	for (int j = k; j < m; j++){
		cout << v[j];
	}
	while (shift > 0){
		cout << '1';
		shift--;
	}
}
