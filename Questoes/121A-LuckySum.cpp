#include<bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------
#define ll long long
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define IO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
// #define IO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//-----------------------------------------------------------------
const ll MAXN = 90000000000;

ll l, r;
vector<ll> numeros;

void getNumeros(ll num){
	
	if(num < MAXN){
		numeros.pb(num);
		getNumeros(num * 10 + 4);
		getNumeros(num * 10 + 7);
	}
}

void solve(){

	cin >> l >> r;

	numeros.pb(0);
	getNumeros(4);
	getNumeros(7);
	sort(all(numeros));

	ll resp = 0;
	for(int i=1; i<numeros.size(); i++){
		ll left = max(l, numeros[i-1] + 1);
		ll right = min(r, numeros[i]);

		if(left <= right)
			resp += (right - left + 1) * numeros[i];
	}

	cout << resp << endl;
}

int main(){
	IO
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}