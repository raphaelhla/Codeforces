#include <bits/stdc++.h>

using namespace std;

int n, q, k;
int ar[100000];

void solve(){

	int l, r;
	cin >> l >> r;

	int aux = 2 * (ar[r-1] - ar[l-1] - 1 - (r-l-1));

	int resp = 0;
	resp += ar[l-1] -1;
	resp += k - ar[r-1];
	resp += aux;		

	cout << resp << endl;
}

int main(){

	cin >> n >> q >> k;
	for (int i = 0; i < n; i++)
		cin >> ar[i];

	while (q--)
		solve();

	return 0;
}
