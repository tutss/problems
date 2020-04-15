#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> tupl;
typedef pair<int, pair<int, int>> tripl;


// class from Competitive Programming 3, pg 54
class UnionFind {
    public:
        vi p, rank;
        map<int, int> set_numElem;
        
        UnionFind(int N) { 
            rank.assign(N, 0);
            p.assign(N, 0); 
            for (int i = 0; i < N; i++) p[i] = i; 
        }
        
        int findSet(int i) {
            return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
        }
        
        bool isSameSet(int i, int j) {
            return findSet(i) == findSet(j); 
        }

        void unionSet(int i, int j) {
            if (!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) p[y] = x;
            else {
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++; 
            }
        } 
    } 
};


int main() {
    int n, m; scanf("%i %i", &n, &m);
    UnionFind uf(n);

    // no teams
    if (m == 0) {
        int j = 0;
        for (int i = 1; i <= n; i++) {
            if (j % 3 == 0 && j != 0) printf("\n");
            printf("%i ", i);
            j++;
        }
        return 0;
    }

    // at least one team
    for (int j = 0; j < m; j++) {
        int ai, bi; scanf("%i %i", &ai, &bi);
        uf.unionSet(ai-1, bi-1);
    }

    map<int, int> set_numElem; map<int, vi> set_elem;
    for (int k = 0; k < n; k++) {
        int fset = uf.findSet(k);
        
        set_numElem[fset]++; // fset contains one more elem
        set_elem[fset].push_back(k); // added k to the fset
        
        if (set_numElem[fset] > 3) {
            printf("-1\n");
            return 0;
        }
    }

    int twos = 0; 
    int ones = 0;
    queue<int> q;
    
    for (auto it : set_numElem) {
        if (it.second == 2) {
            twos++;
        } else if (it.second == 1) {
            ones++;
            q.push(it.first);
        }
    }
    if (twos > ones) {
        printf("-1\n");
        return 0;
    }
    
    for (auto it : set_numElem) {
        if (it.second == 2) {
            set_elem[it.first].push_back(q.front());
            q.pop();
        }
    }

    if (int(q.size())%3 != 0) {
        printf("-1\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        vi elems = set_elem[i];
        if (int(elems.size()) == 3) {
            for (int j = 0; j < 3; j++)
            {
                printf("%i ", ++elems[j]);
            }
            printf("\n");
        }
    }
    
    if (!q.empty()) {
        int sz = int(q.size());
        for (int i = 0; i < sz/3; i++) {
            for (int j = 0; j < 3; j++) {
                if (!q.empty()) {
                    printf("%i ", ++q.front());
                    q.pop();
                }
            }
            printf("\n");
        }
        
    }
    
}
