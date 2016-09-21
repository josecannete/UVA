// 12390 - Distributing Ballot Boxes

#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>

int main(){
  std::ios::sync_with_stdio(false);
  int n, b;
  cin >> n >> b;
  while (n != -1 && b != -1){
    map<int,ii> mapa;
    priority_queue<ii> cola;
    for (int i = 0; i < n; i++){
      int a; cin >> a;
      mapa[i] = ii(a, 1);
      cola.push(ii(a, i));
    }
    b -= n;
    for (int i = 0; i < b; i++){
      ii tope = cola.top(); cola.pop();
      ii enmapa = mapa[tope.second];
      //cout << enmapa.first << "   "  << enmapa.second << endl;
      //cout << " asd es  " << enmapa.first / (enmapa.second+1) << endl;
      mapa[tope.second] = ii(enmapa.first, enmapa.second + 1);
      cola.push(ii(enmapa.first / (enmapa.second+1), tope.second));
    }
    ii ultimo = cola.top();
    cout << ultimo.first << endl;


    cin >> n >> b;
  }
}
