// 10986 - Sending email

#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define inf 1e9

vector<int> d;
vector<vector<ii> > adj; // Lista de adyacencia con pesos
int n;

void dijkstra(int nodo){
  d.assign(n+1,inf);
  priority_queue<ii> cola;

  cola.push(ii(0, nodo));
  d[nodo] = 0;

  while(!cola.empty()){
    ii u = cola.top(); cola.pop();
    int nodoActual = u.second;
    for (int i = 0; i < adj[nodoActual].size(); i++){
      ii parVecino = adj[nodoActual][i];
      int nodoVecino = parVecino.second;
      int pesoVecino = parVecino.first;
      if (d[nodoActual] + pesoVecino < d[nodoVecino]){
        d[nodoVecino] = d[nodoActual] + pesoVecino;
        cola.push(ii(d[nodoVecino],nodoVecino));
      }
    }
  }
}


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  int asd = 0;
  while(t--){
    asd++;
    int m, S, T;
    cin >> n >> m >> S >> T;
    S++; T++;
    adj.assign(n+1, vector<ii>(0));
    for (int i = 0; i < m; i++){
      int primer, segundo, peso;
      cin >> primer >> segundo >> peso;
      primer++; segundo++;
      adj[primer].push_back(ii(peso,segundo));
      adj[segundo].push_back(ii(peso,primer));
    }
    dijkstra(S);
    if (d[T] == 1e9) cout << "Case #" << asd << ": unreachable" << endl;
    else cout << "Case #" << asd << ": " << d[T] << endl;
  }
}
