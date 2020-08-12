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

#define all(x) (x).begin(), (x).end()
#define bsearch(v, x) binary_search(all(v), x)
#define pb push_back

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;

// class from Competitive Programming 3, pg 54
class UnionFind {
    public:
        vi p, rank, sum;
        int nSets;
        map<int, int> setNumElems;
        
        UnionFind(int N) { 
            rank.assign(N, 0);
            p.assign(N, 0);
            sum.assign(N, 0);

            for (int i = 1; i <= N; i++) {
                p[i] = i;
                sum[i] = i;
                setNumElems[p[i]] = 1;
            }
        }
        
        int findSet(int i) {
            return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
        }
        
        bool isSameSet(int i, int j) {
            return findSet(i) == findSet(j); 
        }

        void unionSet(int i, int j) {
            if (!isSameSet(i, j)) {
                debug(i, j);
                int x = findSet(i), y = findSet(j);

                debug(x, y, rank[x], rank[y]);
                if (rank[x] > rank[y]) {
                    sum[p[x]] += sum[p[y]];
                    p[y] = x;
                    setNumElems[p[x]]+=setNumElems[p[y]];
                    
                    // debug(sum[p[x]], setNumElems[p[x]]);
                }
                else {
                    sum[p[y]] += sum[p[x]];
                    setNumElems[p[y]]+=setNumElems[p[x]];
                    p[x] = y;
                    // p[i] = y;
                    if (rank[x] == rank[y]) rank[y]++; 
                    
                    debug(sum[p[y]], setNumElems[p[y]]);
                }

                // debug(p[x], p[y]);
                // debug(p[3]);
            }
        }

        // i to j
        void moveElement(int i, int j) {
            if (!isSameSet(i, j)) {
                int x = findSet(i); int y = findSet(j);
                
                // debug(i, x, j, y, p[y]);
                
                setNumElems[y]+=1; setNumElems[x]-=1;
                sum[y] += i; sum[x] -= i;
                
                // debug(sum[y], sum[x]);
                // debug(setNumElems[y], setNumElems[x]);
                
                // if (rank[x] > rank[y]) {
                    // p[i] = p[y];
                // } else {
                
                // debug(p[i], p[3]);
                //     if (rank[x] == rank[y]) rank[y]++;
                // }
            }
        }

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    // while (scanf("%d %d", &n, &m)) {
        debug(n, m);
        UnionFind uf(n);
        while (m) {
            int command, i, j;
            cin >> command >> i;
            debug(command,i);
            cout << endl;
            if (command == 1 || command == 2) {
                cin >> j;
                debug(j);
                if (command == 1) {
                    uf.unionSet(i, j);
                    debug("join");
                } else {
                    uf.moveElement(i, j);
                }
            } else if (command == 3) {
                int parent = uf.findSet(i);
                cout << uf.setNumElems[parent] << " " << uf.sum[parent] << endl;
            }

            m--;
            debug(m);
        }

        debug("end");
    // }

    debug("endend");

    return 0;
}
