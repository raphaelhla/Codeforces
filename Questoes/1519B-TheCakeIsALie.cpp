#include <bits/stdc++.h>

using namespace std;


void solve(){

	int n, m, k;
	cin >> n >> m >> k;

	int resp = (n-1) * 1 + (m-1) * n;

	if (resp == k)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}


int main(){

	int t;
	cin >> t;

	while (t--){
		solve();
	}

	return 0;
}