#include<bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------
#define ll long long
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define IO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
// #define IO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//-----------------------------------------------------------------
const int MAXN = 100005;

int n, a[MAXN], menor, maior, menorIdx, maiorIdx;

void solve(){

    maior = menorIdx = maiorIdx = 0;
    menor = 101;
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i] < menor){
            menor = a[i];
            menorIdx = i;
        }
        if(a[i] > maior){
            maior = a[i];
            maiorIdx = i;
        }
    }

    if(menorIdx > maiorIdx)
        swap(menorIdx, maiorIdx);

    int resp = abs(maiorIdx - menorIdx) + max(menorIdx, n-1 - maiorIdx);
    cout << resp << endl;
}

int main(){
    IO
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}

