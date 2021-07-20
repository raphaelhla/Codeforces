#include<bits/stdc++.h>
using namespace std;
const int MAXN= 100005;
 
int stree[4*MAXN][30], lazy[4*MAXN][30], cont[30];
char s[MAXN];

void propagate(int node, int left, int right, int idLetra){

	if(lazy[node][idLetra] != -1){

		if(left != right){
			lazy[2*node][idLetra] = lazy[node][idLetra];
			lazy[2*node+1][idLetra] = lazy[node][idLetra];
		}

		stree[node][idLetra] = (right - left + 1) * lazy[node][idLetra];
		lazy[node][idLetra] = -1;
	}
}

void build(int node, int left,int right){
  
	if(left == right){

		stree[node][s[left] - 'a'] = 1;

		for(int i=0; i<26; i++)
			lazy[node][i] = -1;

	} else if (left < right){

		int mid = (right + left) / 2;

		build(2*node, left, mid);
		build(2*node+1, mid+1, right);

		for(int i=0; i<26; i++){
			lazy[node][i] = -1;
			stree[node][i] = stree[2*node][i] + stree[2*node+1][i];
		}	
	}
}

void update(int node, int left, int right, int A, int B, int value, int idLetra){
  
	propagate(node, left, right, idLetra);

	if(left >= A && right <= B){

		lazy[node][idLetra] = value;
		stree[node][idLetra] = (right - left + 1) * lazy[node][idLetra];

		if(left != right){
			lazy[2*node][idLetra] = lazy[node][idLetra];
			lazy[2*node+1][idLetra] = lazy[node][idLetra];
		}

		lazy[node][idLetra] = -1;

	} else if(left <= B && right >= A){
		int mid = (right + left) / 2;

		update(2*node, left, mid, A, B, value, idLetra);
		update(2*node+1, mid+1, right, A, B, value, idLetra);

		stree[node][idLetra] = stree[2*node][idLetra] + stree[2*node+1][idLetra];
	}
}

int query(int node, int left, int right, int A, int B, int idLetra){

	propagate(node, left, right, idLetra);

	if(left > B || right < A)
		return 0;
	if(left >= A && right <= B)
		return stree[node][idLetra];

	int mid = (right + left) / 2;

	int p1 = query(2*node, left, mid, A, B, idLetra);
	int p2 = query(2*node+1, mid+1, right, A, B, idLetra);

	return p1 + p2;
}

void getStr(int node, int left, int right, int idLetra){

	propagate(node, left, right, idLetra);

	if(stree[node][idLetra]){

		if(left == right){
			s[left] = idLetra + 'a';

		}else if (left < right){
			int mid = (right + left) / 2;

			getStr(2*node, left, mid, idLetra);
		 	getStr(2*node+1, mid + 1, right, idLetra);
		}
	}
}

int main(){

	int n, q;
	cin >> n >> q;
	cin >> s;
	build(1, 0, n-1);

	while(q--){

		int A, B, crescente;
		cin >> A >> B >> crescente;
		A--, B--;

		for(int i=0;i<26;i++)
      		cont[i] = query(1, 0, n-1, A, B, i);

    	int aux;
    	if (crescente) 	aux = A;
    	else	   		aux = B;

    	for(int i=0;i<26;i++){

      		if(cont[i]){
        		update(1, 0, n-1, A, B, 0, i);

        		if(crescente){
          			update(1, 0, n-1, aux, aux + cont[i] - 1, 1, i);
          			aux += cont[i];
        		} else{
          			update(1, 0, n-1, aux - cont[i] + 1, aux, 1, i);
					aux -= cont[i];
				}
			}
		}
	}

	for(int i=0;i<26;i++)
		getStr(1, 0, n - 1, i);
	cout << s << endl;
	return 0;
}