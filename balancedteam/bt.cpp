#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vl;

int main() {
	int n;
	cin >> n;
	
	vl members(n);
	for (int i = 0; i < n; i++) cin >> members[i];

	sort(members.begin(), members.end());
	
	int team_size = 0;
	int j = 0;

	for (int i = 0; i < n; ++i){
		while (j < n && members[j] - members[i] <= 5) {
			++j;
			team_size = max(team_size, j - i);
		}		
	}

	cout << team_size << endl;
}
