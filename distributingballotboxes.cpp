// 12390 - Distributing Ballot Boxes

#include <bits/stdc++.h>
using namespace std;

int main(){
  std::ios::sync_with_stdio(false);
  int n, b;
  cin >> n >> b;
  while (n != -1 && b != -1){
	  vector<int> personas(n);
	  int ini=0, fin=0, med=0; 
	  for (int i = 0; i < n; i++){
		cin >> personas[i];
		fin = max(fin,personas[i]);
	}
	int cont = 0;
	while (fin > ini){
		cont = 0;
		med = (fin + ini) / 2;
		for (int i = 0; i < n; i++){
			cont += (personas[i] + med - 1) / med;
		}
		if (cont <= b)
			fin = med;
		else ini = med+1;
	}
	cout << (fin+ini)/2 << endl;
	  
	  
	  cin >> n >> b;
  }
  
}
