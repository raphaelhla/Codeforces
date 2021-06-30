#include<bits/stdc++.h>

using namespace std;

void solve(){
	
	string p, h;
	cin >> p >> h;
	
	string resp = "NO";
	vector<int> cntp(26);
	
	for(int i =0; i< (int)p.size(); i++)
		cntp[p[i] - 'a']++;
	
	for(int i =0; i<=(int)(h.size() - p.size()); i++){
		
		vector<int> cnth(26);
		for(int j = i; j < (int) h.size(); j++){
			cnth[h[j] - 'a']++;
			if(cntp == cnth) resp = "YES";
		}
	}
	
	cout << resp << endl;
}

int main(){
		
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}
