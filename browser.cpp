#include <bits/stdc++.h>

using namespace std;

int main() {
    int numTabs, cursorPos, rangeBegin, rangeEnd;
    scanf("%i %i %i %i", &numTabs, &cursorPos, &rangeBegin, &rangeEnd);

    int rightDist = numTabs - rangeEnd;
    int leftDist = rangeBegin - 1;

    if (rangeBegin == 1 && rangeEnd == numTabs) {
        cout << 0 << endl;
        return 0;
    }
    
    if (!leftDist) {
        cout << abs(rangeEnd - cursorPos) + 1 << endl;
    } else if (!rightDist) {
        cout << abs(cursorPos - rangeBegin) + 1;
    } else {
        int rangeDist = rangeEnd - rangeBegin + 2;
        int minDist = min(abs(rangeEnd-cursorPos), abs(cursorPos-rangeBegin));
        cout << rangeDist + minDist << endl;
    }
    return 0;

} 