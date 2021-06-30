typedef long long ll;
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
const int MAXK = 12;

int ar[MAXN];
ll bit[MAXK][MAXN];
int n, k;

ll sum(int k, int r){
    ll soma = 0;

    while (r > 0){
        soma += bit[k][r];
        r-= (r & -r);
    }

    return soma;
}

ll sum(int k, int l, int r){
    return sum(k, r) - sum(k, l - 1);
}

void add(int k, int index, ll val){

    while(index <= n){
        bit[k][index]+= val;
        index += (index & -index);
    }
}

int main(){

	cin >> n >> k;
	memset(bit, 0, sizeof(bit));

	for (int i=0; i<n; i++){
		cin >> ar[i];
    }

    for(int i =0; i<n; i++){
        
        int atual = ar[i];
        add(0, atual, 1);

        for(int w=1; w<=k;w++){
            ll qtd = sum(w-1, atual-1);
            add(w, atual, qtd);
        }
    }

    cout << sum(k, n) << endl;

	return 0;
}

