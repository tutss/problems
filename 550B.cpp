#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> tupl;
typedef pair<int, pair<int, int>> tripl;

string printf_binary(int n) {
	string b;
	while (n) {
    	if (n & 1)
        	b += '1';
    	else
        	b += '0';

    	n >>= 1;
    }
    reverse(b.begin(), b.end());
    return b;
}


int main() {
	int n, l, r, x;
	scanf("%i %i %i %i\n", &n, &l, &r, &x);

	vi p(n);
	for (int i = 0; i < n; i++) scanf("%i", &p[i]);

	int n_ways = 0;
	for (int i = 1; i < (1 << n); i++)
	{
		int sum = 0;
		int max_v = 0;
		int min_v = INT_MAX;
		for (int j = 0; j < n; j++)
		{

			// cout << "(j = " << j << ") " << "bits i: " << printf_binary(i) << " | ";
			// cout << "bits 2^j: " << printf_binary(1<<j) << endl;
			// cout << "bits: " << printf_binary(i & (1<<j)) << endl;
			if (i & (1 << j)) {
				sum += p[j];
				if (p[j] > max_v) max_v = p[j];
				if (p[j] < min_v) min_v = p[j];
			}
		}
		// printf("sum: %i | i: %i | min: %i | max: %i\n\n", sum, i, min_v, max_v);
		if (sum >= l && sum <= r && max_v - min_v >= x) {
			n_ways++;
		}
	}
	
	printf("%i\n", n_ways);
}