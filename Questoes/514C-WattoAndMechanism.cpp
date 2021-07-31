#include<bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------
#define ll long long
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
//-----------------------------------------------------------------
template<class T> void debug(string msg, T x){cout << msg << x << endl;}
//-----------------------------------------------------------------
const int MAXN = 600005;
const int MAXLOG = 32;
 
struct TrieNode{
 
	TrieNode *filhos[3];
	bool endOfString;
 
	TrieNode(){
		memset(filhos, 0, sizeof(filhos));
		endOfString = false;
	}
} *raiz = new TrieNode();
 
void insertNode(TrieNode *node, string &word){
	
	TrieNode *atual = node;
 
	for(int i=0; i< word.size(); i++){
		
		int idx = word[i] - 'a';
		if(atual->filhos[idx] == 0)
			atual->filhos[idx] = new TrieNode();
		atual = atual->filhos[idx];
	}
 
	atual->endOfString = true;
}
 
bool query(TrieNode *node, string &word, int index, bool flag){
 
	if(index == word.size()){
		if(flag && node->endOfString)
			return true;
		else
			return false;
	}
	else{
 
		bool resp = false;
		int idx = word[index] - 'a';		
 
		for(int i=0; i<3; i++){
			
			if (node->filhos[i] != 0){
 
				if(i == idx)
					resp |= query(node->filhos[i], word, index+1, flag);
				else if(!flag)
					resp |= query(node->filhos[i], word, index+1, true);
 
			}
		}
 
		return resp;
	}
}
 
char s[MAXN];
string str;
 
void solve(){
 
	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> s;
		str = s;
		insertNode(raiz, str);
	}
 
	for(int i=0; i<m; i++){
		cin >> s;
		str = s;
		bool resp = query(raiz, str, 0, false);
		cout << (resp?"YES":"NO") << endl;
	}
}
 
int main(){
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t = 1;
	while(t--) solve();
	return 0;
}