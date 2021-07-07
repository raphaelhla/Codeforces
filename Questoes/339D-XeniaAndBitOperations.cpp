#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll MAXN = 140000;

int n, m;
ll a[MAXN], stree[4*MAXN];

void build(ll node, ll left, ll right, ll altura){
	
	if (left == right)
		stree[node] = a[left];
	if (left < right){
		ll mid = (right + left) / 2;

		build(2*node, left, mid, altura+1);
		build(2*node+1, mid+1, right, altura+1);

		if ((n - altura) & 1)
			stree[node] = stree[2*node] | stree[2*node+1];
		else
			stree[node] = stree[2*node] ^ stree[2*node+1];
	}
}

void update(ll node, ll left, ll right, ll index, ll new_value, ll altura){

	if (left == right){
		stree[node] = new_value;
		a[index] = new_value;
	} else {
		ll mid = (right + left) / 2;

		if (index <= mid)
			update(2*node, left, mid, index, new_value, altura+1);
		else
			update(2*node+1, mid+1, right, index, new_value, altura+1);


		if ((n - altura) & 1)
			stree[node] = stree[2*node] | stree[2*node+1];
		else
			stree[node] = stree[2*node] ^ stree[2*node+1];
	}
}

void solve(int n){
	ll p, b;
	cin >> p >> b;

	update(1, 1, (1 << n), p, b, 0);

	cout << stree[1] << endl;
}

int main(){

	cin >> n >> m;
	for(ll i=1; i<=(1 << n); i++)
		cin >> a[i];

	build(1, 1, (1 << n), 0);

	while(m--)
		solve(n);

	return 0;
}