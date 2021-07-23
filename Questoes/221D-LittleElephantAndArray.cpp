#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAXN = 100005;

int n, m, blocksize;
ll a[MAXN], freq[MAXN], ans[MAXN];
ll resp = 0;

struct Query{
	int l, r, index;
	bool operator<(Query other) const{
		return make_pair(l/blocksize, r) < make_pair(other.l/blocksize, other.r);
	}
};

vector<Query> queries;

void add(ll idx, ll val){

	ll num = a[idx];

	if(num < MAXN){
		if(freq[num] == num) resp--;
		freq[num] += val;
		if(freq[num] == num) resp++;
	}
}

void solve(){
	int left = 0, right = -1;

	for(int i=0; i<m; i++){
	
		Query atual = queries[i];

		while(right < atual.r)
			add(++right, 1);
		
		while(right > atual.r)
			add(right--, -1);
		
		while(left < atual.l)
			add(left++, -1);
		
		while(left > atual.l)
			add(--left, 1);

		ans[atual.index] = resp;
	}
}

int main(){
	
	cin >> n >> m;
	for(int i=0; i<n; i++)
		cin >> a[i];
	for(int i=0; i<m; i++){
		queries.push_back(Query());
		cin >> queries[i].l >> queries[i].r;
		queries[i].l--;
		queries[i].r--;
		queries[i].index = i;
	}

	blocksize = sqrt(n);
	sort(queries.begin(), queries.end());
	solve();

	for(int i=0; i<m; i++)
		cout << ans[i] << endl;
	return 0;
}