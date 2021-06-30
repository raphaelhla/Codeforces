#include <bits/stdc++.h>

using namespace std;

int fun(int a, int b){

	int n = 0;

	while (a != 0){
		
		if (b == a)
			b += 1;
		else
			a /= b;
		
		n++;
	}

	return n;

}

void solve(){

	int a, b;
	cin >> a >> b;

	int n1 = 0;
	int resp = 99999;
	
	if (b == 1){
		b++;
		n1++;
	}

	for(int i = b; i<b+5; i++){
		int aux = fun(a, i) + (i-b);
		resp = min(resp, aux);
	}
	
	cout << resp + n1 << endl;

}

int main(){
	
	int t;
	cin >> t;

	while (t--){
		solve();
	}

	return 0;
}