#include<bits/stdc++.h>
using namespace std;

void solve(){
	
	string s, t;
	cin >> s >> t;

	int ls = s.length();
	int lt = t.length();

	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	
	bool resp = true;
	for(int i=0, j=0; i<lt; i++, j++){

		while(j < ls && s[j] != t[i])
			j += 2;
		
		if(j >= ls)
			resp = false;
	}

	if (resp)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

int main(){
	int q;
	cin >> q;
	while(q--) solve();
	return 0;
}