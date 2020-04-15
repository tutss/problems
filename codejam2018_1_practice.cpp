#include <bits/stdc++.h>

using namespace std;

int main() {
    int nTests; cin >> nTests;
    for (int i = 0; i < nTests; i++) {
        int a, b, n;
        cin >> a >> b;
        cin >> n;
        
        bool correctAnswer = false;
        while (!correctAnswer) {
            string answer;
            int guess = (a+b)/2+1;
            cout << guess;
            cin >> answer;
            if (answer == "CORRECT") {
                correctAnswer = true;
            } else if (answer == "TOO_SMALL") {
                a = guess;
            } else {
                b = guess;
            }
        }
    }
    
    return 0;
}