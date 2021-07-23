#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAXN = 200005;
int n, t;
ll a[MAXN], ans[MAXN], blocksize, freq[1000006];

struct Query{
	int l, r, index;
	bool operator<(Query other) const{
		return make_pair(l / blocksize, r) < make_pair(other.l / blocksize, other.r);
	}
};

vector<Query> queries;

void solve(){
	ll resp = 0;
	int left = 0, right = -1;

	for(int i=0; i<t; i++){

		Query atual = queries[i];

		while(right < atual.r){ // add
			right++;
			freq[a[right]]++;
			resp += (freq[a[right]]*2 - 1) * a[right];
		}
		while(left < atual.l){ // remove
			resp -= (freq[a[left]]*2 - 1) * a[left];
			freq[a[left]]--;
			left++;
		}
		while(right > atual.r){ // remove
			resp -= (freq[a[right]]*2 - 1) * a[right];
			freq[a[right]]--;
			right--;
		}
		while(left > atual.l){ // add
			left--;
			freq[a[left]]++;
			resp += (freq[a[left]]*2 - 1) * a[left];
		}

		ans[atual.index] = resp;
	}
}

int main(){
	
	cin >> n >> t;
	for(int i=0; i<n; i++)
		cin >> a[i];
	for(int i=0; i<t; i++){
		queries.push_back(Query());
		cin >> queries[i].l >> queries[i].r;	
		queries[i].l--;
		queries[i].r--;	
		queries[i].index = i;
	}

	blocksize = sqrt(n);
	sort(queries.begin(), queries.end());
	solve();	

	for(int i=0; i<t; i++)
		cout << ans[i] << endl;

	return 0;
}