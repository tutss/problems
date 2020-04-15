#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> tupl;
typedef pair<int, pair<int, int>> tripl;

int main() {
    string s;
    getline(cin, s);

    istringstream iss(s);
    vector<string> phrs(istream_iterator<string>{iss}, istream_iterator<string>());

    if (s[int(s.size())-1] == '?') {
        printf("7\n");
        return 0;
    }

    for (int i = 0; i < int(phrs.size()); i++)
    {
        if (phrs[i]=="Sussu" || phrs[i]=="Sussu." || phrs[i]=="Sussu!") {
            printf("AI SUSSU!\n");
            return 0;
        }
    }

    printf("O cara é bom!\n");

}
