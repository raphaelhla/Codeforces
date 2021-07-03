typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

ll n, a, b;

void solve(){

	cin >> n >> a >> b;
	bool tmp = false;

	if(n % b == 1 % b){
		tmp = true;
	}

	ll aux = 1;
	while (aux <= n && a > 1){

		if((n - aux) % b == 0){
			tmp = true;
		}
		aux *= a;
	}

	string resp = tmp ? "Yes" : "No";
	cout << resp << endl;
}

int main(){

	int t;
	cin >> t;

	while (t--)
		solve();
	
	return 0;
}