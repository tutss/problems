#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> tupl;
typedef pair<int, pair<int, int>> tripl;

int main() {
    char c = 'X'; 
    ll a, b;
    a = 0;
    b = 1000000001;

    while (c != '=') {
        ll mid = (a + b)/2;
        cout << "Q " << mid << endl;
        
        cin >> c;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if (c == '>') {
            a = mid;
        } else if (c == '<') {
            b = mid + 1;
        } else if (c == '=') {
            break;
        }
    }
}
