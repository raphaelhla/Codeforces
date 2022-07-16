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
const int MAXN = 2000005;
const int MAXLOG = 32;
const int MOD = 1000000007;

char letras[2005][2005];
int n, m, ans[2005][2005];

int menor(int a, int b, int c, int d){
	vector<int> vec;
	vec.pb(a);
	vec.pb(b);
	vec.pb(c);
	vec.pb(d);
	sort(all(vec));
	return vec[0] + 1;
}

void solve(){

	cin >> n >> m;
	for(int i=0; i<n; i++)
		cin >> letras[i];

	int resp = 0;

	for(int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			
			ans[i][j] = 1;

			if (i-2 >= 0 && j-1 >= 0 && j+1 < m){
				if (letras[i][j] == letras[i-1][j] && 
					letras[i][j] == letras[i-2][j] && 
					letras[i][j] == letras[i-1][j-1] && 
					letras[i][j] == letras[i-1][j+1] ){

					ans[i][j] = menor(ans[i-1][j], ans[i-2][j], ans[i-1][j-1], ans[i-1][j+1]);
				}
			}
			resp += ans[i][j];
		}
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