// 11093 - Just Finish it up

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	int t;
	cin >> t;
	int asd = 0;

	while(t--){
		asd++;
		int n;
		cin >> n;
		vector<ll> uno(2*n,0), dos(2*n,0), tres(2*n,0);
		ll suma = 0;
		for (int i = 0; i < n; i++)
			cin >> uno[i], suma += uno[i];
		for (int i = 0; i < n; i++)
			cin >> dos[i], suma -= dos[i];
		if (suma < 0) { cout << "Case " << asd << ": Not possible" << endl; continue; }
		for (int i = 0; i < n; i++){
			uno[i+n] = uno[i];
			dos[i+n] = dos[i];
		}
		suma = 0;
		int marcador = 0;
		for (int i = 0; i < 2*n; i++){
			suma += (uno[i] - dos[i]);
			if (suma < 0){
				suma = 0;
				marcador = i;
			}
			else{
				tres[i] = marcador;
			}
		}
		cout << "Case " << asd << ": Possible from station " <<  tres[n] + 2 << endl;
	}
}
