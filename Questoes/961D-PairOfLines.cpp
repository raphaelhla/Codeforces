#include<bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------
#define ll long long
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define IO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
// #define IO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//-----------------------------------------------------------------
const int MAXN = 100005;
const int MAXLOG = 32;
const int MOD = 1000000007;

int n;

struct ponto{
	ll x, y;
}pontos[MAXN];

bool inLine(ponto a, ponto b, ponto c){
	
	ll p1 = a.x*b.y + a.y*c.x + b.x*c.y;
	ll p2 = b.y*c.x + a.x*c.y + a.y*b.x;
	
	return p1 == p2;
}

bool check(ponto a, ponto b){

	bool resp = true;
	vector<ponto> linha2;

	for(int i = 0; i<n; i++){
		if(!inLine(a, b, pontos[i]))
			linha2.pb(pontos[i]);
	}

	for(int i=2; i<linha2.size(); i++){
		if(!inLine(linha2[0], linha2[1], linha2[i]))
			resp = false;
	}

	return resp;
}

void solve(){

	cin >> n;
	for(int i=0; i<n; i++)
		cin >> pontos[i].x >> pontos[i].y;

	if (n <= 4)
		cout << "YES";
	else{
		bool resp = check(pontos[0],pontos[1]) || check(pontos[0],pontos[2]) || check(pontos[1],pontos[2]);
		cout << (resp ? "YES" : "NO");	
	}
}

int main(){
	IO
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}

