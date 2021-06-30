#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;

	int xs[n], ys[n];
	for(int i = 0; i<n; i++)
		cin >> xs[i] >> ys[i];
		
	int resp = -1;
		
	for (int i =0; i<n; i++){
		bool entrou = false;
		for(int j = 0; j<n; j++){
			if (abs(xs[i] - xs[j]) + abs(ys[i] - ys[j]) > k)
				entrou = true;
		}
		
		if (!entrou)
			resp = 1;
	}
	
	cout << resp << endl;
}

int main(){
	
	int t;
	cin >> t;
	
	while (t--) solve();
	
	return 0;
}
