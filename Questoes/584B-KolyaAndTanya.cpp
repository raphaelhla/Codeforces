#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;

long long bin_pow(int a, int b){
	if (b == 0)	
		return 1;
	else if (b % 2 == 1) 
		return (a * bin_pow(a, b-1)) % MOD;
	
	long long tmp = bin_pow(a, b/2);
	return (tmp * tmp) % MOD;
}

int main(){
	
	int n;
	cin >> n;

	long long a = bin_pow(3, n*3);
	long long b = bin_pow(7, n);
	
	cout << (a - b + MOD) % MOD << endl;

	return 0;
}