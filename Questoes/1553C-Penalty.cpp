#include<bits/stdc++.h>
using namespace std;

void solve(){

	string s;
	cin >> s;
	
	int n = s.size();

	int resp = 100;

	for(int i=0, golsT1 = 0, golsT2 = 0; i<n; i++){
		if(!(i&1)){

			if(s[i] != '0')	golsT1++;

		}else{

			if(s[i] == '1')	golsT2++;

		}

		if(golsT1 - golsT2 > (n-i)/2 || i == n-1){
			resp = min(resp, i+1);
			break;
		}
	}

	for(int i=0, golsT1 = 0, golsT2 = 0; i<n; i++){
		if(!(i&1)){

			if(s[i] == '1')	golsT1++;

		}else{
		
			if(s[i] != '0')	golsT2++;

		}

		if(golsT2 - golsT1 > (n-i-1)/2 || i == n-1){
			resp = min(resp, i+1);
			break;
		}
	}

	cout << resp << endl;
}

int main(){
	int q;
	cin >> q;
	while(q--) solve();
	return 0;
}
