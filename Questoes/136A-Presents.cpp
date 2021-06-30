#include<bits/stdc++.h>

using namespace std;

int main(){

	int n;
	cin >> n;

	int array[n], ans[n];
	for(int i =0; i<n; i++) 
	{
		cin >> array[i];
		ans[array[i]-1] = i+1;
	}

	for (int i = 0; i < n; ++i)
	{
		cout << ans[i] << " " ;
	}
	cout << endl;

	return 0;
}