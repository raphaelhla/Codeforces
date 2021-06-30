#include<bits/stdc++.h>

using namespace std;

int ans[30];

void solve(){
	string s;
	cin >> s;
	
	memset(ans, 0, sizeof(ans));
	
	int tam = s.size();
	for(int i = 0; i < tam; i++){

		int j = i;

		while (j < tam-1 && s[j] == s[j+1])
			j++;
		
		if ((j-i+1) % 2 != 0)
			ans[s[i] - 'a']++;
		
		i = j;
	}
	
	for(int i = 0; i < 26; i++)
		if(ans[i])
			cout << char('a' + i);
	
	cout << endl;
	
}

int main(){
	
	int t;
	cin >> t;
	
	while (t--){
		solve();
	}
	return 0;
}
