#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> tupl;
typedef pair<int, pair<int, int>> tripl;

int main() {
    int n;
    scanf("%i\n", &n);

    vi v(n);
    for (int i = 0; i < n; i++) scanf("%i", &v[i]);

    for (int i = 1; i < (1 << n); ++i)
    {
    	int sum = 0;
    	for (int j = 0; j < n; ++j)
    	{
    		if (i & (1 << j)) sum += v[j];
    		else sum -= v[j];
    	}
    	if (sum % 360 == 0) {
    		printf("YES\n");
    		return 0;
    	}
    }

    printf("NO\n");
}
