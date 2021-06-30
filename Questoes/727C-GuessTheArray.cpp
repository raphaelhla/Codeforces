#include <bits/stdc++.h>

using namespace std;

int ask(int i, int j){
	cout << "? " << i << " " << j << endl;
	fflush(stdout);

	int resp;
	cin >> resp;

	return resp;
}


int main(){

	int n; 
	cin >> n;
	
	int arr[n+1];
		
	int a = ask(1, 2);
	int b = ask(2, 3);
	int c = ask(1, 3);

	arr[3] = (c - a + b) / 2;
	arr[2] = b - arr[3];
	arr[1] = c - arr[3];

	for(int i=4; i<=n; i++){
		int aux = ask(1, i);
		arr[i] = aux - arr[1];
	}

	cout << "! ";
	for (int i=1; i<= n; i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}
