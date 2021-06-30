#include <bits/stdc++.h>

using namespace std;

void solve(){

	long long x, y, k;
	cin >> x >> y >> k;

	long long precisa = k * y + k - 1;
	long long lucro = x-1;

	long long trocas = k + precisa / lucro;
	if (precisa % lucro)
		trocas++;

	cout << trocas << endl;
}

int main(){

	int t;
	cin >> t;

	while (t--)
		solve();

	return 0;
}