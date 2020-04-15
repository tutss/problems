#include <bits/stdc++.h>

using namespace std;

bool IsZero(int i) {
    return i == 0;
}

int main() {
    vector<int> in = {1, 2, 3, 0, 0};

    // vector<int>::iterator zero_pos = find_if_not(in.begin(), in.end(), [](int i){return i!=0;} );
    // int pos_zero = zero_pos - in.begin();

    auto it = find_if(in.begin(), in.end(), IsZero);
    int first_nonzero_idx = distance(in.begin(), it);

    cout << "pos: " << first_nonzero_idx << endl;

    for (auto it = in.begin(); it != in.end(); ++it) 
        cout << *it << " "; 
    
    cout << endl;
}