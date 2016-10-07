// 1263 - Mines

#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>


vector<bool> visited;
vector<vector<int> > adj;

vector<int> topo;

void toposort(int nodo){
  visited[nodo] = 1;
  for (int i = 0; i < adj[nodo].size(); i++){
    if (!visited[adj[nodo][i]])
      toposort(adj[nodo][i]);
  }
  topo.push_back(nodo);
}

void dfs(int nodo){
  visited[nodo] = 1;
  for (int i = 0; i < adj[nodo].size(); i++){
    if (!visited[adj[nodo][i]])
      dfs(adj[nodo][i]);
  }
}

int main(){
  ::ios::sync_with_stdio(0);
  int T;
  cin >> T;
  for (int test = 0; test < T; test++){
    int n;
    cin >> n;
    vector<int> diametro(n,0);
    vector<ii> pos;
    adj.assign(n, vector<int>(0));
    visited.assign(n,0);
    topo.clear();
    
    for (int i = 0; i < n; i++){
      int x, y, diam;
      cin >> x >> y >> diam;
      diametro[i] = diam;
      pos.push_back(ii(x,y));
    }


    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        if (i != j){
          ii bomb1 = pos[i];
          int diam = diametro[i];
          ii bomb2 = pos[j];
          if (2 * max(abs(bomb1.first-bomb2.first), abs(bomb1.second-bomb2.second)) <= diam)
              adj[i].push_back(j);
              //UF.unionSet(i, j);
        }
      }
    }
    int componentesconexas = 0;
    //cout << componentesconexas << endl;

    for (int i = 0; i < n; i++){
      if (!visited[i]){
        toposort(i);
      }
    }
    
    reverse(topo.begin(), topo.end());

    visited.assign(n,0);
    
    for (int i = 0; i < n; i++){
      if (!visited[topo[i]]){
        dfs(topo[i]);
        componentesconexas++;
      }
    }

    cout << componentesconexas << endl;


  }
}
