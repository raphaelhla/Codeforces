#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int BLOCKSIZE = 320;

int n, m, power[MAXN], prox[MAXN], cont[MAXN], ult[MAXN];

void update(int i){
	
	int blocoAtual = i/BLOCKSIZE;

	if(i + power[i] >= n || (i + power[i]) / BLOCKSIZE != blocoAtual){
		prox[i] = i + power[i];
		cont[i] = 1;
		ult[i] = i+1;
	}else {
		prox[i] = prox[i + power[i]];
		cont[i] = cont[i + power[i]] + 1;
		ult[i] =   ult[i + power[i]];
	}
}

void solve(){
	
	int type, a, b;
	scanf("%d", &type);

	if(type){

		scanf("%d", &a);
		a--;

		int resp = cont[a];

		while(prox[a] < n){
			a = prox[a];
			resp += cont[a];
		}

		printf("%d %d\n", ult[a], resp);

	}else{

		scanf("%d %d", &a, &b);
		a--;

		power[a] = b;
		for(int i=a; i >= 0 && i/BLOCKSIZE == a/BLOCKSIZE; i--)
			update(i);		
	}
}

int main(){
	
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++)
		scanf("%d", &power[i]);

	for(int i=n-1; i>=0; i--)
		update(i);

	while(m--) solve();	
	return 0;
}
