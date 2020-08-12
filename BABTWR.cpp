#include <bits/stdc++.h>

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	while (cin >> t, t != 0) {
		
		vector<pair<int, pair<int, int>>> v;
		int blocks[32][3];
		int dp[100];

		for (int i = 0; i < t; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> blocks[i][j];
			}
		}

		for (int i = 0; i < t; i++) {
			for (int j = 0; j < 3; j++) {
				int a = blocks[i][j];
				int b = blocks[i][(j+1)%3];
				int c = blocks[i][(j+2)%3];
				if (a>b) swap(a,b);
				v.push_back({a, {b, c}});
			}
		}

		sort(v.begin(), v.end());

		dp[0] = v[0].second.second;
		
		int ans = 0;
		for (int i=1;i<int(v.size());i++){
			int h = v[i].first; int w = v[i].second.first;
			dp[i]=0;
			for (int j=i-1; j>=0;j--){
				int hh=v[j].first; int ww=v[j].second.first;
				if (hh < h && ww < w) dp[i]=max(dp[i],dp[j]);
			}
			dp[i]+=v[i].second.second;
			ans = max(ans, dp[i]);
		}

		cout << ans << endl;
	}	

}


