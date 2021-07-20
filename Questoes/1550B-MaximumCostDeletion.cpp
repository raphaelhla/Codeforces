#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;

	int cont = 1;
	for (int i=1; i<n; i++)
		cont += s[i] != s[i-1];

	int q1 = b * n;
	int q2 = b * ((cont + 2) / 2);

	int resp = a * n + max(q1, q2);
	cout << resp << endl;
}
 
int main(){
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}