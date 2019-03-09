#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vl;

int main() {
	int n;
	cin >> n;
	
	vl members(n);
	for (int i = 0; i < n; i++) cin >> members[i];

<<<<<<< HEAD
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
=======
	sort(members.rbegin(), members.rend());
	
	int team_size = 1;
	ll biggest_possible = members[0];
	
	vector<int> maxs;
	for (int j = 0; j < n-1; j++){
		if (biggest_possible - members[j+1] <= 5) {
			team_size++;
		} else {
			maxs.push_back(team_size);
			biggest_possible = members[j+1];
			team_size = 1;
		}
	}
	maxs.push_back(team_size);
	cout << *max_element(maxs.begin(), maxs.end());
>>>>>>> b637d886c46c3e466d034bc13a30d9316c8096ab
}
