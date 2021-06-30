#include <iostream>

using namespace std;

int main(){
	
	int q, l, r, d;
	cin >> q;
	
	while (q--){
		cin >> l >> r >> d;
		
		if (d < l)
			cout << d << endl;
		else 
			cout << (r-r%d) + d << endl;
		
		
	}
	
	return 0;

}
