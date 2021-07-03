typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int arr[205];

void solve(){

	int n, s[2] = {0,0};
	cin >> n;

	for(int i=0; i<2*n;i++){
		cin >> arr[i];
		s[arr[i] & 1]++;
	}

	if (s[0] == s[1])
		cout << "Yes" << endl;
	else 
		cout << "No" << endl;
}

int main(){

	int t;
	cin >> t;

	while (t--)
		solve();
	
	return 0;
}