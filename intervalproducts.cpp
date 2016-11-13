#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;  // Tamaño limite del arreglo
int n;  // Tamano arreglo
vector<int> t(4 * N, 1); // En teoria usar 4 * N es mas seguro

void build() {  // Construccion heap-like
  for (int i = n - 1; i > 0; --i) t[i] = t[2 * i] * t[2 * i + 1];
}

// Nota: Si p es un hijo 2*i, p^1 es 2*i + 1 y viceversa (XOR)
void modify(int p, int valor) {  // Setear valor en la posicion p
  for (t[p += n] = valor; p > 1; p /= 2) t[p / 2] = t[p] * t[p^1];
}

int query(int l, int r) {  // Suma del intervalo [l,r)
  int res = 1;
  for (l += n, r += n; l < r; l /= 2, r /= 2) {
    if (l % 2 == 1) res *= t[l++];
    if (r % 2 == 1) res *= t[--r];
  }
  return res;
}

// Ver problema Potetiometers de UVA
int main() {
  int q;
  while (cin >> n >> q){
    for (int i = 0; i < n; ++i) {
      int valor;
      cin >> valor;
      if (valor == 0) modify(i+1, 0);
      if (valor < 0) modify(i+1, -1);
      if (valor > 0) modify(i+1, 1);
      //cout << valor << endl;
    }
    build();
    //for (int i = 0; i < 4 * n; i++)
      //cout << t[i] << " ";
    for (int i = 0; i < q; i++){
      char a;
      int b, c;
      cin >> a >> b >> c;
      if (a == 'C'){
        if (c == 0) modify(b, 0);
        if (c < 0) modify(b, -1);
        if (c > 0) modify(b, 1);
      }
      else{
        if (query(b, c+1) == 0) cout << 0;
        if (query(b, c+1) < 0) cout << '-';
        if (query(b, c+1) > 0) cout << '+';
      }
    }
    cout << endl;
  }
  return 0;
}
