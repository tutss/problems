
#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;

int main(){
	int n, l;
	cin >> n >> l;
 	
	// Receive input	
	vector<int> a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	// Sort vector
	sort(a.begin(), a.end());
	
	// Calculate max distance between lights
	long int max_dist;
	int j;
	for (j = 0, max_dist = 0; j < n-1; j++){	
		if(a[j+1] - a[j] >= max_dist) max_dist = a[j+1] - a[j];	
	}
	
	// We're splitting the distance because we consider 2 lights
	double d = double(max_dist)/2;
	// remember error because of type len	
	if (d <= a[0]) {
		d = a[0];
	}
	if (l-a[n-1] >= d){
		d = l-a[n-1];
	}
	cout<< setprecision(9) << d;
}
