#include <bits/stdc++.h>

using namespace std;


int main(){

	int n, q;
	cin >> n >> q;
	int a[n];
	int t[q];
	for(int i=0; i < n; i++)
		cin >> a[i];
	for(int i=0; i < q; i++)
		cin >> t[i];

	vector<int> pos(51, -1);
	for(int i=0; i < n; i++){
		if (pos[a[i]] == -1) 
			pos[a[i]] = i + 1;
	}

	for(int i=0; i< q ;i++){
		
		cout << pos[t[i]] << " ";
		int aux = pos[t[i]];
		for(int j = 0; j < 51; j++){
			if (pos[j] < aux) 
				pos[j]++;
		}
		pos[t[i]] = 1;
	}

	cout << endl;
	return 0;
}
