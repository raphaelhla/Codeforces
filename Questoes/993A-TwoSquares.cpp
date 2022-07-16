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
int n;
int XAmax, XAmin, YAmax, YAmin;
int centroX, centroY, distanciaAux;

bool inA(int a, int b){
	return a >= XAmin && a <= XAmax && b >= YAmin && b <= YAmax;
}

bool inB(int a, int b){
	return abs(a - centroX) + abs(b - centroY) <= distanciaAux;
}

void solve(){

	XAmax = YAmax = -1000;
	XAmin = YAmin = 1000;

	int x, y;
	for(int i=0; i<4; i++){
		cin >> x >> y;
		XAmax = max(XAmax, x);
		XAmin = min(XAmin, x);
		YAmax = max(YAmax, y);
		YAmin = min(YAmin, y);
	}
	for(int i=0; i<4; i++){
		cin >> x >> y;
		centroX += x;
		centroY += y;
	}

	centroX /= 4;
	centroY /= 4;
	distanciaAux = abs(x - centroX) + abs(y - centroY);

	bool resp = false;

	for(int i = -100; i <= 100; i++){
		for(int j = -100; j <= 100; j++){
			
			if(inA(i, j) && inB(i, j))	resp = true;
		}
	}
			
	cout << (resp ? "YES" : "NO") << endl;
}

int main(){
	IO
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}

