#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int log_2[MAXN];
int st[5][17][MAXN];

void log_2_init(){
	log_2[1] = 0;
	for (int i = 2; i < MAXN; ++i){
		log_2[i] = log_2[i/2] + 1;
	}
}

int getMax(int w, int l, int r){

	int maior = 0;

	if(l > -1 && r > -1){
		int i = log_2[r - l + 1];
		maior = max(st[w][i][l], st[w][i][r - (1 << i) + 1]);	
	}
	
	return maior;
}

int main(){

	int n, m, tiros;
	cin >> n >> m >> tiros;

	log_2_init();
	int K = log_2[n];

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> st[j][0][i];

	for(int i=1; i<=K; i++){
		for(int j=0; j + (1 << i) - 1 < n; j++){
			for(int w = 0; w < m; w++)
				st[w][i][j] = max(st[w][i-1][j], st[w][i-1][j + (1 << (i-1))]);
		}
	}

	int maior = 0;
	int l = -1, r = -1;
	int i = 0, j = 0;
	while(i < n && j < n){

		int soma = 0;
		for(int w=0; w<m; w++)
			soma += getMax(w, i, j);
		
		if (soma <= tiros){
			if ((j - i + 1) > maior){
				l = i;
				r = j;
				maior = (r - l + 1);
			}
			j++;
		}else{
			i++;
			if (i > j) j = i;
		}
	}

	for(int w=0; w<m; w++)
		cout << getMax(w, l, r) << " ";
	cout << endl;

	return 0;
}