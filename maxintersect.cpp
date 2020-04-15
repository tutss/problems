#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%i", &n);

    vector<pair<int,pair<int,int>>> segment(n);
    for (int i = 0; i < n; i++)
    {
        int l, r;
        scanf("%i %i", &l, &r);
        segment[i] = make_pair(max(l,r) - min(l,r) + 1, make_pair(l, r));
    }

    sort(segment.begin(), segment.end());
    
    for (int i = 0; i < n; i++)
    {
        printf("triple: %i %i %i\n", segment[i].first, segment[i].second.first, segment[i].second.second);
    }
    

    int maxSeg = 0;
    
    if (int(segment.size()) == 2) {
        int dist = segment[1].second.second - segment[1].second.first;
        maxSeg = max(dist, maxSeg);
    }

    for (int i = 1; i < n-1; i++)
    {
        int minI = min(segment[i].second.first, segment[i+1].second.first);
        int maxI = max(segment[i].second.second, segment[i+1].second.second);

        int whichLeft = 0;
        int whichRight = 0;
        if (minI == segment[i].second.first) {
            whichLeft = segment[i+1].second.first;
        } else {
            whichLeft = segment[i].second.first;
        }

        if (maxI == segment[i].second.second) {
            whichRight = segment[i+1].second.second;
        } else {
            whichRight = segment[i].second.second;
        }

        printf("maxI: %i, minI: %i, whichRight: %i, whichLeft: %i\n", maxI, minI, whichRight, whichLeft);
        if (segment[i+1].second.first < segment[i].second.second) {
            int dist = whichRight - whichLeft - 1;
            maxSeg = max(dist, maxSeg);
        } else {
            break;
        }
    }
    
    printf("%i", maxSeg);
}