// 12393 - Non-negative Partial Sums

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;  // Tamaño limite del arreglo
int n;  // Tamano arreglo
vector<int> t(2*N, 1e9+5); // En teoria usar 4 * N es mas seguro

void build() {  // Construccion heap-like
  for (int i = n - 1; i > 0; --i) t[i] = min(t[2 * i],t[2 * i + 1]);
}

// Nota: Si p es un hijo 2*i, p^1 es 2*i + 1 y viceversa (XOR)
void modify(int p, int valor) {  // Setear valor en la posicion p
  for (t[p += n] = valor; p > 1; p /= 2) t[p / 2] = min(t[p], t[p^1]);
}

int query(int l, int r) {  // Suma del intervalo [l,r)
  int res = 1e9+20;
  for (l += n, r += n; l < r; l /= 2, r /= 2) {
    if (l % 2 == 1) res = min(res, t[l++]);
    if (r % 2 == 1) res = min(res,t[--r]);
  }
  return res;
}

// Ver problema Potetiometers de UVA
int main() {
  cin >> n;
  while(n != 0){
	t.assign(4*n + 20, 1e9+5);
	cin >> t[2*n];
	vector<int> a(n+1);
	a[0] = t[2*n];
	for (int i = 1; i < n; ++i){
		cin >> a[i];
		 t[2*n+i] = t[2*n+i-1] + a[i];
	 }
	for (int i = 3*n; i < 4*n; i++) t[i] = t[i-1] + a[i%n];
	n = 2*n;
	build();
	/*
	for (int i = 0; i < t.size(); i++)
		cout << t[i] << " ";
	*/
	int ans = 0;
	for (int i = 0; i < n/2; i++){
		//cout << "la query es " << query(i,i+n/2) << endl;
		//cout << "t de n+i es " << t[n+i-1] << endl;
		if ( query(i,i+n/2) - t[n+i-1] >= 0 && n+i-1 >= n)
			ans++;
		else if ( query(i,i+n/2) >= 0 && i == 0) ans++;
		
	}
	cout << ans << endl;
	cin >> n;
  }
  return 0;
}
