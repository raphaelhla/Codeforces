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
template<class T> void debug(string msg, T x){cout << msg << x << endl;}
//-----------------------------------------------------------------
const int MAXN = 100005;
const int MAXLOG = 60;

ll a[MAXN];

struct TrieNode{

	TrieNode *filhos[2];

	TrieNode(){
		memset(filhos, 0, sizeof(filhos));
	}

} *root = new TrieNode();


void insert(ll num){

	TrieNode *atual = root;

	for(int i=MAXLOG; i>=0; i--){

		bool idx = ((1ll << i) & num) > 0;
		if(!atual->filhos[idx])
			atual->filhos[idx] = new TrieNode();
		atual = atual->filhos[idx];
	}
}

ll query(ll num){

	TrieNode *atual = root;
	ll resp = 0;

	for(int i=MAXLOG; i>=0; i--){

		bool idx = ((1ll << i) & num) > 0;

		if(atual->filhos[idx^1]){
			resp += (1ll << i);
			atual = atual->filhos[idx^1];
		}
		else
			atual = atual->filhos[idx];				
	}

	return resp;
}

void solve(){

	ll xorprefix = 0;
	ll xorsufix = 0;
	ll resp = 0;

	int n;
	cin >> n;

	for(int i=0; i<n; i++){
		
		cin >> a[i];
		xorprefix ^= a[i];

		resp = max(resp, xorprefix);
	}	

	for(int i=n-1; i>=0; i--){
		
		xorsufix ^= a[i];
		xorprefix ^= a[i];

		insert(xorsufix);

		resp = max(resp, query(xorprefix));
	}

	cout << resp << endl;
}

int main(){
	IO
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}

