#include<bits/stdc++.h>

using namespace std;

int main(){
	int start_h, start_m, finish_h, finish_m;
	scanf("%d:%d", &start_h, &start_m);
	scanf("%d:%d", &finish_h, &finish_m);
	
	int start_to_min = (start_h * 60) + start_m;
	int finish_to_min = (finish_h * 60) + finish_m;
	
	double mid = (((double)(finish_to_min + start_to_min))/2)/60;
	double mid_hour, fractional;
	fractional = modf(mid, &mid_hour);
	fractional *= 60;
	cout << setfill('0') << setw(2) << mid_hour << ":" << setfill('0') << setw(2) << fractional;

}
