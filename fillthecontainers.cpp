// 11413 - Fill the Containers

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	while (cin >> n >> m){
		vector<int> vasels(n+1,0);
		for (int i = 0; i < n; i++)
			cin >> vasels[i];
		bool sepuede;

		int fin = 1e9, ini = 0, med;
		while (fin - ini > 1){
			sepuede = 1;
			med = (ini + fin) / 2;
			int cont = 1;
			int cantidad = 0;
			for (int i = 0; i < n; i++){
				if (vasels[i] > med){
					sepuede = 0;
					break;
				}
				else{
					if (cantidad + vasels[i] > med){
						cantidad = 0;
						cont++;
					}
					if (cont > m){
						sepuede = 0;
						break;
					}
					cantidad += vasels[i];
				}
			}
			if (sepuede) fin = med;
			else ini = med;
		}
		cout << fin << endl;

	}
}
