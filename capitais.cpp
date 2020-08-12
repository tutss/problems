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

const int MAX = 10005;
const int INF = INT_MAX;

vi adj[MAX];

int mxp = 0;

int bfs(int x) {
	queue<int> q;
	vi d(MAX, INF);

	q.push(x);
	d[x] = 0;

	int mx = 0;
	int nodemx;
	while(!q.empty()){
		int u = q.front(); q.pop();
		for (auto v : adj[u]){
			if (d[v] == INF){
				q.push(v);
				d[v]=d[u]+1;
				if (d[v]>mx) {
					mx = d[v];
					nodemx = v;
				}
			}
		}
	}

	mxp = max(mx, mxp);

	return nodemx;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	set<int> nodes;
	for (int i=0; i<n-1; i++){
		int a, b; cin >> a >> b;
		nodes.insert(a); nodes.insert(b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int init = *nodes.begin();
	int v = bfs(init);
	int u = bfs(v);

	cout << mxp << endl;
}


