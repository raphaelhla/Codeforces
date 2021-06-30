#include <iostream>

using namespace std;

int main(){
	
	int t;
	cin >> t;
	
	while (t--){
		
		int a, b, n;
		cin >> a >> b >> n;
		int cont = 0;
		
		while (a <= n && b <= n){
			if (a <= b)
				a += b;
			else
				b += a;
			cont += 1;
		}
		
		cout << cont << endl;
		
	}

	return 0;
}
