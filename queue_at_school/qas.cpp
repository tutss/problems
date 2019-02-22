/*boy -> girl -> girl -> boy -> girl
1       2       3       4      5

girl -> boy -> girl -> boy -> girl
1        2      3       4      5

*/
#include<iostream>
#include<vector>

using namespace std;

int main(){
	int n;
	int t;
	cin >> n >> t;
	
	vector<char> v(n);
	for (int i = 0; i < n; i++){
		cin >> v[i]; 
	}
	
	for (int j = 0; j < t; j++){
		for (int k = 0; k < n; k++){

			if (v[k] == 'B' && v[k+1] == 'G'){
				
				char tmp = v[k];
				v[k] = v[k+1];
				v[k+1] = tmp;
				k++;
			}
		}
	}

	for (int i = 0; i < n; i++){
		cout << v[i];
	}
}
