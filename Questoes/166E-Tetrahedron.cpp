#include <bits/stdc++.h>

using namespace std;

int n;
const int MOD = 1000000007;
int dp[2][10000007];

int main(){
    cin >> n;
    dp[1][0] = 1;
    for (int i= 1; i<=n ; i++){
        dp[1][i] = (3LL * dp[0][i-1]) % MOD;
        dp[0][i] = (2LL * dp[0][i-1] + dp[1][i-1]) % MOD;
    }

    cout << dp[1][n] << endl;
    
    return 0;
}
