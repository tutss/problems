#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

int main() {
	int t; 
	scanf("%i", &t);

	for (int i = 0; i < t; ++i)
	{
		int a, b;
		scanf("%i %i", &a, &b);

		if (abs(a-b) <= 1) printf("Ok\n");
		else {
			int d = (a+b)/2;
			printf("%i %i\n", d, a+b-d);
		}
	}
}