#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAXN = 200005;
ll a[MAXN];

int main(){

	int n, q;
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> a[i];
	cin >> q;

	ll blocosize = sqrt(n);
	ll blocos[(n/blocosize)+1];
	memset(blocos, -1, sizeof(blocos));

	while(q--){
		ll type, p, x;
		cin >> type;

		if (type == 1){
			cin >> p >> x;
			int bloconum = (p-1) / blocosize;
			for(int i = bloconum*blocosize; i<(bloconum*blocosize + blocosize); i++)
				a[i] = max(a[i], blocos[bloconum]);
			

			a[p-1] = x;
			blocos[bloconum] = -1;

		} else {
			cin >> x;
			for(int i=0; i<(n/blocosize)+1; i++)
				blocos[i] = max(blocos[i], x);
		}
	}

	for(int i=0; i<n; i++){
		int bloconum = i/blocosize;
		a[i] = max(a[i], blocos[bloconum]);
	}

	for(int i=0; i<n; i++)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}