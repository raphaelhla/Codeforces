#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;
	cin >> n;

	int a[n], b[n], removidos[n+1];

	for(int i=0; i<n; i++){
		cin >> a[i];
		removidos[i+1] = 1;
	}
	for(int i=0; i<n; i++)
		cin >> b[i];
	
	int prox = 0;
	int cont = 0;
	for(int i=0; i<n; i++){
		
		cont++;
		removidos[a[i]] = 0;

		if (b[prox] == a[i]){
			cout << cont << " ";
			cont = 0;
			prox++;
		}

		while(prox < n && !removidos[b[prox]]){
			cout << cont << " ";
			prox++;
		}
	}
	cout << endl;

	return 0;
}