#include<bits/stdc++.h>

using namespace std;

int main(){
	
	char s[101];
	cin >> s;
	int tam = strlen(s);
	sort(s, s+tam);
	
	int cont = 1;

	for(int i = 0; i < tam-1; i++){
		if (s[i] != s[i+1])
			cont++;
	}
	
	if(cont % 2 == 0)
		cout << "CHAT WITH HER!" << endl;
	else
		cout << "IGNORE HIM!" << endl;	
	
	return 0;
}
