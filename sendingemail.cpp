// 10986 - Sending email

#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
typedef pair<int, int> ii;

// Vector que contiene las distancias desde el nodo
// en que partimos el BFS hasta el resto de los nodos
vector<int> d;
vector<int> visited;
vector<vector<ii> > adj; // Lista de adyacencia con pesos
int n; // Cantidad de nodos

void dijkstra(int nodo){
  d.assign(n+1,inf);
  visited.assign(n+1,0);
  priority_queue<ii, vector<ii>, greater<ii> > cola;

  cola.push(ii(0, nodo));
  d[nodo] = 0;

  while(!cola.empty()){
    ii u = cola.top(); cola.pop();
    int Actual = u.second;
    visited[Actual] = 1;
    for (int i = 0; i < adj[Actual].size(); i++){
      ii Vecino = adj[Actual][i];
      int nodoVecino = Vecino.second;
      int pesoVecino = Vecino.first;
      if (!visited[nodoVecino]){
        if (d[Actual] + pesoVecino < d[nodoVecino]){
          d[nodoVecino] = d[Actual] + pesoVecino;
          cola.push(ii(d[nodoVecino],nodoVecino));
        }
      }
    }
  }
}


int main(){
  //ios_base::sync_with_stdio(0);
  //cin.tie(0);
  int t;
  cin >> t;
  int asd = 0;
  while(t--){
    asd++;
    int m, S, T;
    cin >> n >> m >> S >> T;
    //scanf("%d %d %d %d",&n,&m,&S,&T);
    S++; T++; n++;
    adj.assign(n+1, vector<ii>(0));
    int primer, segundo, peso;
    for (int i = 0; i < m; i++){
      cin >> primer >> segundo >> peso;
      //scanf("%d %d %d", &primer, &segundo, &peso);
      primer++; segundo++;
      adj[primer].push_back(ii(peso,segundo));
      adj[segundo].push_back(ii(peso,primer));
    }
    dijkstra(S);
    if (d[T] == 1e9) cout << "Case #" << asd << ": unreachable" << endl;
      //printf("Case #%d: unreachable\n",asd);
    else
    cout << "Case #" << asd << ": " << d[T] << endl;
    //printf("Case #%d: %d\n",asd,d[T]);
  }
  return 0;
}
