// 10611 - The Playboy Chimp

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> num(n,0);
  for (int i = 0; i < n; i++)
    cin >> num[i];
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    int ini = 0, fin = n, med = (ini + fin)/2;
    int buscado;
    cin >> buscado;
    int primero=0, segundo=0;
    while (fin > ini){
      if (num[med] >= buscado)
        fin = med;
      else
        ini = med+1;
      med = (ini+fin) / 2;
    }

    primero = med;
    if (primero - 1 < 0)
      cout << "X ";
    else
      cout << num[primero-1] << " ";

    ini = 0, fin = n, med = (ini + fin)/2;
    while (fin > ini){
      if (num[med] <= buscado)
        ini = med+1;
      else
        fin = med;
      med = (ini+fin) / 2;
    }

    segundo = med;
    if (segundo >= n)
      cout << "X" << endl;
    else
      cout << num[segundo] << endl;
  }
}
