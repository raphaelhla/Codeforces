#include <bits/stdc++.h>

using namespace std;

const int MAX = 100001;

int main(){

	int n, k;
	int id[MAX];

	cin >> n >> k;
	for(int i=0; i<n; i++)
		cin >> id[i];

	int a = 1, b = 0;

	while(a <= k)
		a += ++b;

	int aux = k - (a - b);
	cout << id[aux] << endl;

	return 0;
}
