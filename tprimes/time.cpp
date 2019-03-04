#include<iostream>
#include<time.h>
#include<math.h>

using namespace std;
/* Improvements used to avoid TLE:
 *	as seen in CP3, test only if N is divisible by a divisor in [2, sqrt(N)]
 *	second improvement, check only odd numbers up to sqrt(N)
 * */
int main(){
	long long int n;

	cin >> n;
 	clock_t t = clock();	
	int t_p = 1;
	cout << "started" << endl;
	long double s = sqrt(n);
   	cout << "long double " << s << endl;	
	long long int ns = (long long int) s; 
   	cout << "long long int " << ns << endl;	
	for (int i = 3; i < ns; i += 2){
		if (n % i == 0) t_p++;
	}
	t = clock() - t;
	printf("Tempo: %3f\n", ((float) t)/CLOCKS_PER_SEC);
	cout << t_p;
}
