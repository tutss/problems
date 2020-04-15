#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

int main() {
	int n;
	scanf("%i", &n);

	vi v(n);
	for (int i = 0; i < n; i++) scanf("%i", &v[i]);

	sort(v.begin(), v.end());

	int sum = 0;
	for (int i = 0; i < n; i+=2) {
		int a = v[i];
		int b = v[i+1];
		if (a == b) continue;
		else sum += abs(a-b);
	}

	printf("%i", sum);
}