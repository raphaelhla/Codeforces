#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
 
void solve(){
	int s;
	cin >> s;

	int cont = 1;
	int i = 1;
	int soma = 1;
	while (soma < s){
		i += 2;
		cont += 1;
		soma += i;
	}

	cout << cont << endl;
}
 
int main(){
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}