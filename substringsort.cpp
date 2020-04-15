#include <bits/stdc++.h>

using namespace std;

struct compare {
    bool operator()(const std::string& first, const std::string& second) {
        return first.size() < second.size();
    }
};

int main() {
    int n; cin >> n;
    vector<string> strs(n);

    for (size_t i = 0; i < n; i++) {
        cin >> strs[i];
    }

    compare c;  
    sort(strs.begin(), strs.end(), c);

    for (size_t i = 0; i < n; i++) {
        for (size_t j = i; j < n; j++) {
            bool exists = strs[j].find(strs[i]) != std::string::npos;
            if (!exists) {
                printf("NO\n");
                return 0;
            }
        }
    }

    printf("YES\n");
    for (size_t i = 0; i < n; i++) {
        cout << strs[i] << endl;
    }
    

}
