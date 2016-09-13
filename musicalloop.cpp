// 11496 - Musical Loop

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	while (n != 0){
		int vec[3*n];
		int contador = 0;
		for (int i = 0; i < n; i++)
			cin >> vec[i];
		for (int i = n; i < 3*n; i++)
			vec[i] = vec[i%n];
		for (int i = n; i < 2*n ; i++)
			if (vec[i] > vec[i-1] && vec[i] > vec[i+1] || vec[i] < vec[i+1] && vec[i] < vec[i-1])
				contador++;
		cout << contador << endl;
		cin >> n;
			
	}
	
}
