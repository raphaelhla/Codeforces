#include<bits/stdc++.h>

using namespace std;

void solve(){

	int n;
	cin >> n;
	
	int array[n], cnt[n+1];
	set<int> s;
	int ans[n];
	memset(cnt, 0, sizeof(cnt));
	
	for(int i =0; i<n; i++){
		cin >> array[i];
		cnt[array[i]]++;
		s.insert(array[i]);
		ans[i] = 0;
	}
	
	bool flag = true;
	int l = 0;
	int r = n-1;
	
	for(int i =1; i<=n; i++){
		if(flag && cnt[i] > 0)
			ans[i-1] = 1;
			
		if(cnt[i] != 1)
			flag = false;
		else if(array[l] == i)
			l++;
		else if(array[r] == i)
			r--;
		else
			flag = false;
	}
	
	if((int)s.size() == n)
		ans[n-1] = 1;
	
	for(int i=n-1; i>=0; i--)
		cout << ans[i];
	cout << endl;
	
}

int main(){
	
	int t;
	cin >> t;
	
	while (t--) solve();

	return 0;
}
