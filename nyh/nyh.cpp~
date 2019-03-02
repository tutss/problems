#include<iostream>

using namespace std;

int main(){
	int n_problems, k_time;
	cin >> n_problems >> k_time;

	int remaining_time = 240 - k_time;
	if (remaining_time == 0 || k_time > 240) {
		cout << 0;
		return 0;
	}
		
	int i;
	for (i = 0; i < n_problems; i++){
		int problem_cost = 5 * (i+1);
		if (remaining_time < problem_cost) {
			break;
		}
		remaining_time -= problem_cost;
	}
	cout << i;

}
