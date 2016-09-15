// 434 - Matty's Blocks

#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int k;
    cin >> k;
    vector<int> izq(k+1,0), frente(k+1,0);
    int suma1 = 0, suma3 = 0;
    for (int i = 1; i <= k; i++){
      cin >> izq[i];
    }
    for (int i = 1; i <= k; i++){
      cin >> frente[i];
    }
    vector<int> izq2 = izq, frente2 = frente;
    for (int i = 1; i <= k; i++)
      for (int j = 1; j <= k; j++){
        if (izq2[i] == frente2[j]){
          suma3 += izq2[i];
          izq2[i] = frente2[j] = 0;
        }
      }
    for (int i = 1; i <= k; i++)
      suma3 += izq2[i] + frente2[i];

    suma1 = 0;

    for (int i = 1; i <= k; i++)
      for (int j = 1; j <= k; j++)
        suma1 += min(izq[i], frente[j]);

    cout << "Matty needs at least " << suma3 << " blocks, and can add at most "
    << suma1 - suma3 << " extra blocks."  << endl;

  }
}
