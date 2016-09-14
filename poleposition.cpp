// 12150 - Pole Position

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	while( n != 0 ){
		vector<int> vec(n+1,0), pos(n+1,0), fin(n+1,0);
		int contador = 0;
		int suma = 0;
		for (int i = 1; i <= n; i++){
			cin >> vec[i] >> pos[i];
			suma += pos[i];
			if (suma != 0) contador++;
		}
		//cout << suma << endl;
		if (suma != 0) {cout << -1 << endl;}
		else{
			for (int i = 1; i <= n; i++){
				fin[i + pos[i] ] = vec[i];
			}
			vector<int> fin2(n+1,0);
			fin2 = fin;
			sort(vec.begin(), vec.end());
			sort(fin2.begin(), fin2.end());
			int flag = 0;
			for (int i = 0; i <= n; i++){
				//cout << vec[i] << "     " << fin2[i] << endl;
				if (vec[i] != fin2[i]){
					//cout << vec[i] << "   " << fin2[i] << endl;
					cout << -1 << endl;
					flag = 1;
					break;
				}
			}
			if (!flag){
			for (int i = 1; i <= n; i++){
				cout << fin[i];
				if (i != n) cout << " ";
			}
			cout << endl;
		}
		}
		cin >> n;
	}

}
