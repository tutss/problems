#include<iostream>
#include<math.h>
#include<bitset>
#include<vector>
#include<set>

using namespace std;

typedef long long ll;

bitset<10000010> bs;
vector<int> tprimes;
ll sieve_size; 
set<ll> t;

void sieve(ll n){
	sieve_size = n + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= sieve_size; i++) {
		if (bs[i]) {
			for (ll j = i * i; j <= sieve_size; j+=i) {
				bs[j] = 0;
			}
			tprimes.push_back((int)i);
		}
	}
	for (int i = 0; i < tprimes.size(); i++){
		ll sq = (ll) tprimes[i];
		ll sq2 = sq * sq;
		t.insert(sq2);
	}
}
	
bool is_Tprime(ll xi){
	if ((int)sqrt(xi) <= sieve_size) return t.find(xi) != t.end();
	return false;	
}

/* Compute the sieve of eratosthenes, then check if xi is there*/
int main(){
	int n;
	cin >> n;
	sieve(1000000);
	long long int xis [n];
	for (int i = 0; i < n; i++) {
		cin >> xis[i];
	}
	for (int i = 0; i < n; i++) {
		if (i == n - 1)  {
			is_Tprime(xis[i]) ? cout << "YES" : cout << "NO";
		}
		else {
			is_Tprime(xis[i]) ? cout << "YES\n" : cout << "NO\n";
		}
	}
}
