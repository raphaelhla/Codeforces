#include<bits/stdc++.h>
 
using namespace std;
 
struct FenwickTree {
    int n;
    vector<int> bit;  // arvore de indexaçao binaria
    
    FenwickTree(int n) {
        this->n = n+1;
        bit.assign(n+1, 0);  //{0,0,0,0..}
    }
 
    int sum(int r) {
        int sum = 0;
 
        while(r > 0){
        	sum += bit[r];
        	r -= (r & -r);
        }
 
        return sum;
    }
 
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
 
    void add(int index, int val) {
 
        while(index < n){
        	bit[index] += val;
        	index += (index & -index);
        }
    }
 
    int getNum(int index) {
    	return sum(index, index);
    }
};
 
int main(){
 
	int n, k, a, b, q;
	cin >> n >> k >> a >> b >> q;
	
	FenwickTree antes = FenwickTree(n);
	FenwickTree depois = FenwickTree(n);
	
	while (q--){
 
		int type, d, val;
		cin >> type >> d;
 
		if (type == 1) {
			cin >> val;
			
			int aux1 = min(b - antes.getNum(d), val);
			int aux2 = min(a - depois.getNum(d), val);
			
			antes.add(d, aux1);
			depois.add(d, aux2);
			
		} else {
			int resp = 0;
			resp += antes.sum(d-1);
			resp += depois.sum(d+k, n);
 
			cout << resp << endl;
		}
	}
 
	return 0;
}