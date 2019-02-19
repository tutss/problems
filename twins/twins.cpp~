#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

/* Max (total) sum of the coins */
int vector_sum(vector<int> vec){
	int sum = 0;
	int n = vec.size();
	for (int i = 0; i < n; i++){
		sum += vec[i];
	}
	return sum;
}

/* Split the total sum in half */
float vector_half(vector<int> vec){
	int sum = vector_sum(vec);
	float v_mean = sum/2.0;
	return v_mean;
}

int main(){
	int n;
	int coins = 0;

	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	
	int sum = vector_sum(v);
	float mean = vector_half(v);
	// Get the biggest coins first
	sort(v.rbegin(), v.rend());

	for (int j = 0; j < n; j++){
		if (sum >= mean){
			coins += 1;
			sum -= v[j];
		}
	}

	cout << coins;
}
