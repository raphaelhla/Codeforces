#include<bits/stdc++.h>

using namespace std;

void solve(){

	int n, k;
	cin >> n >> k;

	string resp = "";
	int cont = 0, aux = 0;

	for (int i=0; i<n; i++){
		if (cont == k){
			cont = 0;
			aux += 1;
		}
		
		resp += char((aux % 3) + 'a');
	 	cont++;
	}

	cout << resp << endl;
}

int main(){

	int t;
	cin >> t;

	while (t--) solve();

	return 0;
}