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
const int MAXN = 100005;

int a, b, c;

void solve(){

	cin >> a >> b >> c;
	string resp = "No";

	if(!(c % a)) resp = "Yes";
	if(!(c % b)) resp = "Yes";

	while (c > 0){
		if(!(c % a)) resp = "Yes";
		c -= b;
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

