#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> tupl;
typedef pair<int, pair<int, int>> tripl;

bool compare(string &s1,string &s2) { 
    return s1.size() < s2.size(); 
} 

int main() {
	int t;
	scanf("%i\n", &t);


    for (int j = 0; j < t; j++)
    {
        int n; scanf("%i\n", &n);
        vector<string> v(n);
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            // int k = s.find('*');
            // s.erase(k, k+1);
            cout << s << endl << endl;
            v[i] = s;
        }


        sort(v.begin(), v.end(), compare);

        int big = -1;
        for (int i = 0; i<n-1; i++) {
            int k = v[i].find('*');
            string a = v[i].substr(0, k); string b = v[i].substr(k+1, int(v[i+1].size()));
            cout << a << " | " << b << endl;
            cout << v[i+1] <<endl;
            bool fA = true; bool fB = true;
            if (int(a.size())>0) {
                if (v[i+1].find(a) == std::string::npos) {
                    fA = false;
                }
            }

            if (int(b.size())>0) {
                if (v[i+1].find(b) == std::string::npos) {
                    fB = false;
                }
            }

            cout << fA << " | " << fB << endl;
            if (fA && fB) big = i+1;
        
        }
        if (big > 0) printf("Case #%i: %s\n", j+1, v[big].c_str());
        else printf("Case #%i: *\n", j+1);
    }
    
}