#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;

struct No {
	int a, f, c;

	No(int aa = 0, int ff = 0, int cc = 0) : f(ff), a(aa), c(cc) {}
};

int n, m;
char s[MAXN];
No stree[4*MAXN];
No neutro;

No combine(No node1, No node2){

	int novos = min(node1.a, node2.f);

	No resp = No();
	resp.a = node1.a + node2.a - novos;
	resp.f = node1.f + node2.f - novos;
	resp.c = node1.c + node2.c + novos;
	
	return resp;
}

void build(int node, int left, int right){

	if (left == right){

		if (s[left] == '(')
			stree[node] = No(1, 0, 0);
		else
			stree[node] = No(0, 1, 0);

	}
	if (left < right){

		int mid = (right + left) / 2;

		build(2*node, left, mid);
		build(2*node+1, mid+1, right);

		stree[node] = combine(stree[2*node], stree[2*node+1]);
	}
}

No getSequences(int node, int left, int right, int A, int B){

	if (right < A || left > B)
		return neutro;
	if (left >= A && right <= B)
		return stree[node];

	int mid = (left + right) / 2;
	
	No p1 = getSequences(2*node, left, mid, A, B);
	No p2 = getSequences(2*node+1, mid+1, right, A, B);

	return combine(p1, p2);
}

void solve(){

	int x, y;
	cin >> x >> y;

	No resp = getSequences(1, 0, n-1, x-1, y-1);
	cout << 2 * resp.c << endl;
}

int main(){

	cin >> s >> m;
	n = strlen(s);

	build(1, 0, n-1);

	while(m--)
		solve();

	return 0;
}