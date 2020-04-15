#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;


// Checked the editorial
int main() {
	ll a1, a2, k1, k2, n;
	scanf("%lld\n%lld\n%lld\n%lld\n%lld\n",&a1,&a2,&k1,&k2,&n);

	ll min = 0; ll maxx = 0;
	if (k1 > k2) {
		ll tmp1; ll tmp2;
		tmp1 = k1; tmp2 = a1;
		k1 = k2; k2 = tmp1;
		a1 = a2; a2 = tmp2;
	}

	ll count = a1*(k1-1)+ a2*(k2-1);
	if (count < 0)
		min = 0;
	else 
		min = max(0LL,n - count);

	if (n <= a1*k1) maxx = n/k1;
	else maxx = a1 + (n - a1*k1)/k2;

	printf("%lld %lld", min, maxx);

}