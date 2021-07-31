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
const int MAXLOG = 32;

struct TrieNode{

	TrieNode *filhos[26];
	bool canWin;
	bool canLose;

	TrieNode(){
		memset(filhos, 0, sizeof(filhos));
		canWin = false;
		canLose = false;
	}

} * root = new TrieNode();

void insert(TrieNode *node, string s, int index){

	if(index == s.size()){

		if(index&1)
			node->canWin = true;
		else
			node->canLose = true;
		
	}
	else if(index < s.size()){

		int idx = s[index] - 'a';

		if(!node->filhos[idx])
			node->filhos[idx] = new TrieNode();

		insert(node->filhos[idx], s, index+1);
		
	}
}

void query(TrieNode *node, int index){
	

	for(int i=0; i<26; i++){

		if(node->filhos[i]){
			
			query(node->filhos[i], index + 1);
			
			int winAux = 0;
			int loseAux = 0;
			int cnt = 0;

			for(int j=0; j<26; j++){
				
				if(node->filhos[j])
				{
					cnt++;
					winAux += node->filhos[j]->canWin;
					loseAux += node->filhos[j]->canLose;
				}
			} 

			if (index&1 && (winAux && loseAux || winAux + loseAux < cnt))
			{
				node->canWin = false;
				node->canLose = false;
			}
			else
			{
				node->canWin = winAux;
				node->canLose = loseAux;
			}
		}
	}
}

void solve(){

	int n, k;
	cin >> n >> k;

	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		insert(root, s, 0);	
	}

	query(root, 0);

	if(root->canWin && root->canLose)
		cout << "First" << endl;
	else if(root->canWin)
		cout << ((k&1) ? "First" : "Second") << endl;
	else
		cout << "Second" << endl;
}

int main(){
	IO
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}