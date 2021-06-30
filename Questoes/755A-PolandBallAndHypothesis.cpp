#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int n;
	cin >> n;
	
	for(int i = 1; i <= 1000; i++){
	
		int aux = n*i + 1;
		bool achou = false;
		
		for(int j = 2; j < aux; j++)
			if (aux % j == 0)
				achou = true;
		
		if (achou){
			cout << i << endl;
			break;
		}
	}
	
	return 0;
}
