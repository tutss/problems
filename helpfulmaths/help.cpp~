#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef vector<int> vi;
int main(){
	string s;
	vi v;

	cin >> s;
	for (char& c : s) {
		if (c != '+') {
			v.push_back(c-'0');
		}
	}
	sort(v.begin(), v.end());
	int n = v.size();
	for (int i = 0; i < n; i++){
		if (i == n-1) {
			cout << v[i];
		} else {
			cout << v[i] << '+';
		}
	}
}
