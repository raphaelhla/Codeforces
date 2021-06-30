#include<bits/stdc++.h>

using namespace std;

int main(){

	int t;
	cin >> t;

	while(t--){
		string x;
		cin >> x;
		int tam = x.size();
		
		int aux = x[0] - '0' - 1;
		int soma = aux * 10 + tam * (tam+1) / 2; 

		cout << soma << endl;
	}

	return 0;
}