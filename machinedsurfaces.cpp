// 414 - Machined Surfaces

#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  cin.ignore();
  while(n != 0){
    int contador = 0;
    int mindif = 25;
    for (int j = 0; j < n; j++){
      string a;
      getline(cin, a);
      cin.ignore();
      //cout << "asdd  " << endl << a << endl;
      int primero=0, ultimo=0, flag=0;
      for (int i = 0; i < 25; i++){
        if (a[i] == ' ' && !flag){
          primero = i;
          flag = 1;
          contador++;
        }
        else if (a[i] == ' ' && flag){
          ultimo = i;
          contador++;
        }
      }
      //cout << "primero es " << primero << "y ultimo es " << ultimo << endl;
      mindif = min(mindif, abs(ultimo+1 - primero));
    }
    //cout << "contador es " << contador << " y mindif es " << mindif << endl;
    if (contador - mindif * n >= 0)
      cout << contador - mindif * n << endl;
    else cout << 0 << endl;
    cin >> n;
    cin.ignore();
  }
}
