#include<bits/stdc++.h>
using namespace std;

void solve(){

	string s, t;
	cin >> s >> t;
	
	int ls = s.size();
	int lt = t.size();

	bool resp = false;

	for(int i=0; i<ls; i++){
		for(int j=1; (i+j)<=ls; j++){

			string str1 = s.substr(i, j);
			string str2 = s.substr(0, i+j-1);
			
			reverse(str2.begin(), str2.end());
			
			string str3 = str1 + str2.substr(0, lt - j);

			if (str3 == t)
				resp = true;
		}
	}

	cout << (resp ? "YES" : "NO") << endl;
}

int main(){
	int q;
	cin >> q;
	while(q--) solve();
	return 0;
}
