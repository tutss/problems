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

struct point {
    int l, r, c;

    bool operator<(const point p) const {
        if (this->l < p.l) {
            return true;
        } else if (this->l == p.l) {
            if (this->r < p.r) {
                return true;
            } else if (this->r == p.r) {
                if (this->c < p.c) {
                    return true;
                }
            }
        }
        return false;
    }

};
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> pii;

const int MAX = 33;

point operator+(const point &p1, const point &p2) {
    point p;
    p.l = p1.l + p2.l;
    p.r = p1.r + p2.r;
    p.c = p1.c + p2.c;
    return p;
}

bool operator==(const point &p1, const point &p2) {
    if ((p1.l == p2.l) && (p1.r == p2.r) && (p1.c == p2.c)) {
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    point moves[] = {
        {0, 0, -1},
        {0, 0, 1},
        {1, 0, 0},
        {-1, 0, 0},
        {0, 1, 0},
        {0, -1, 0}
    };

    while (true) {
        int l, r, c;
        cin >> l >> r >> c >> ws;
        
        if (l == 0 && r == 0 && c == 0) break;
        
        map<point, char> pos;
        
        point start; point end;
        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < r; j++)
            {
                for (int k = 0; k < c; k++)
                {
                    point p; char b;
                    p.l = i; p.r = j; p.c = k;
                    cin >> b; 
                    if (b == 'S') start = p;
                    if (b == 'E') end = p;
                    pos[p] = b;
                }
            }
        }

        queue<point> q;
        map<point, int> dist;
        dist[start] = 0;
        q.push(start);
        while(!q.empty()) {
            point u = q.front();
            q.pop();

            if (u == end) break;
            for (int i = 0; i < 6; i++) {
                point mv = u + moves[i];
                if (pos.count(mv) && dist.count(mv) == 0 && pos[mv] != '#') {
                    dist[mv] = dist[u] + 1;
                    q.push(mv);
                }
            }
        }
        
        if (dist.count(end)) {
            cout <<"Escaped in " << dist[end] << " minute(s)." << endl;
        } else {
            cout << "Trapped!" << endl;
        }
    }

}
