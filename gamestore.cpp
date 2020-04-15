#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    pair<int, pair<int, int>> p;
    pair<int, pair<int, int>> q;

    int h, e, a; cin >> h >> e >> a;
    
    p = make_pair(h, make_pair(e, a));
    q = make_pair(h, make_pair(e, a));
    
    int index_p = 0;
    int index_q = 0;

    for (int i = 1; i < n; i++) {
        int hi, ei, ai; cin >> hi >> ei >> ai;

        int hp, ep, ap, hq, eq, aq; 
        
        hp = p.first; ep = p.second.first; ap = p.second.second;
        hq = q.first; eq = q.second.first; aq = q.second.second;
        
        if (hi > hp) {
            p = make_pair(hi, make_pair(ei, ai));
            index_p = i;
        } else if (hi == hp) {
            if (ei < ep) {
                p = make_pair(hi, make_pair(ei, ai));
                index_p = i;
            } else if (ei == ep) {
                if (ai > ap) {
                    p = make_pair(hi, make_pair(ei, ai));  
                    index_p = i;
                }  
            }
        }

        if (hi < hq) {
            q = make_pair(hi, make_pair(ei, ai));
            index_q = i;
        } else if (hi == hq) {
            if (ei > eq) {
                q = make_pair(hi, make_pair(ei, ai));
                index_q = i;
            } else if (ei == eq) {
                if (ai < aq) {
                    q = make_pair(hi, make_pair(ei, ai));
                    index_q = i;
                }
            }
        }
    }
    
    if (p.first == q.first && p.second.first == q.second.first && p.second.second == q.second.second) {
        printf("Easiest and Hardest is level %d\n", ++index_p);    
    } else {
        printf("Easiest is level %d\n", ++index_p);
        printf("Hardest is level %d\n", ++index_q);
    }
}