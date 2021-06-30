#include <bits/stdc++.h>

using namespace std;

void solve(){

	int n;
	cin >> n;
	int array[n];
	int cont = 0;

	for (int i=0; i<n; i++){
		cin >> array[i];
		if (array[i] == 1 || array[i] == 3)	
			cont++;
	}

	cout << cont << endl;
}


int main(){

	int t;
	cin >> t;

	while (t--){
		solve();
	}

	return 0;
}
