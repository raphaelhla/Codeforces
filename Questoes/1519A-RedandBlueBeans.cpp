#include <bits/stdc++.h>

using namespace std;


void solve(){

	int r, b, d;
	cin >> r >> b >> d;

	int maior = max(r,b);
	int menor = min(r,b);

	int div = maior / menor;
	int resto = maior % menor;

	if (resto > 0)
		div++;


	if (div <= ++d)
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