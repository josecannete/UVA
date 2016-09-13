// 12150 - Pole Position

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	while( n != 0 ){
		vector<int> vec(n+1,0);
		int contador = 0;
		int suma = 0;
		for (int i = 0; i < n; i++){
			int c, p;
			cin >> c >> p;
			suma += p;
			if (p != 0) contador++;
		}
		if (suma == 0 && contador % 2 == 0)
			cout <<
	} 

}
