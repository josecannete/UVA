//7207 - Exposing corruption
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

vector<int> visited;
vector<vector<int> > adj;
int peso;
int compA, compB;

vector<int> ka,kb;

void bfs(int nodo){
  queue<int> cola;
  cola.push(nodo);
  while(!cola.empty()){
    int u = cola.front(); cola.pop();
    if (u <= 100) peso += ka[u];
    else peso += kb[u-100];
    if (visited[u] == 1) compA++;
    else if (visited[u] == -1) compB++;
    for (int i = 0; i < adj[u].size(); i++){
      int v = adj[u][i];
      if (visited[v] == 0){
        cola.push(v);
        visited[v] = -1 * visited[u];
      }
    }
  }
}

int main(){
  int a, b, m, k;
  while (cin >> a >> b >> m >> k){
    ka.assign(a+1,0);
    kb.assign(b+1,0);
    vector<int> partir(101, 0);
    adj.assign(201, vector<int>(0));
    visited.assign(201, 0);

    for (int i = 1; i <= a; i++)
      cin >> ka[i];
    for (int i = 1; i <= b; i++)
      cin >> kb[i];
    for (int i = 0; i < m; i++){
      int uno, dos;
      cin >> uno >> dos;
      dos += 100;
      partir[uno] = 1;
      adj[uno].push_back(dos);
      adj[dos].push_back(uno);
    }
    vector<ii> CBA, CBB;
    for (int i = 1; i <= a; i++){
      if (partir[i] && visited[i] == 0){
        peso = 0;
        visited[i] = 1;
        compA = 0;
        compB = 0;
        bfs(i);
        //cout << compA << " asd " << compB << endl;
        if (compA > compB)
          CBB.push_back(ii(compA - compB, peso));
        else if (compB > compA)
          CBA.push_back(ii(compB - compA, peso));
      }
    }
    //cout << "hola" << endl;
    for (int i = 1; i <= a; i++)
      if (visited[i] == 0)
        CBB.push_back(ii(1, ka[i]));
    for (int i = 1; i <= b; i++)
      if (visited[i+100] == 0)
        CBA.push_back(ii(1, kb[i]));
    //cout << "hola2" << endl;

    vector<vector<int> > DPA(CBA.size()+1, vector<int>(k+1, 0)), DPB(CBB.size()+1, vector<int>(k+1,0));

    for (int i = 0; i <= CBA.size(); i++){
      for (int j = 0; j <= k; j++){
        if (i == 0 || j == 0)
          DPA[i][j] = 0;
        else if (CBA[i-1].second <= j)
          DPA[i][j] = max(DPA[i-1][j], DPA[i-1][j - CBA[i-1].second] + CBA[i-1].first);
        else
          DPA[i][j] = DPA[i-1][j];
      }
    }
    for (int i = 0; i <= CBB.size(); i++){
      for (int j = 0; j <= k; j++){
        if (i == 0 || j == 0)
          DPB[i][j] = 0;
        else if (CBB[i-1].second <= j)
          DPB[i][j] = max(DPB[i-1][j], DPB[i-1][j - CBB[i-1].second] + CBB[i-1].first);
        else
          DPB[i][j] = DPB[i-1][j];
      }
    }


    int cantA = a + DPA[CBA.size()][k];
    int cantB = b + DPB[CBB.size()][k];

    cout << cantA << " " << cantB << endl;
  }
}
