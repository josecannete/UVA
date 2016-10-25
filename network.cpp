// 315 - Network
#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;
vector<int> parent;
vector<int> level;
vector<int> low;
set<int> puntosArticulacion;
int hijosRaiz = 0;
int n;


vector<string> tokenizer(char delim, string s){
  vector<string> ans;
  string parcial = "";
  int i = 0;
  while (i < s.size()){
    if (s[i] == delim){
      ans.push_back(parcial);
      parcial = "";
    }
    else{
      parcial += s[i];
    }
    i++;
  }
  if (parcial != "")
    ans.push_back(parcial);
  return ans;
}

vector<int> transformar(vector<string> original){
  vector<int> ans;
  for (int i = 0; i < original.size(); i++)
    ans.push_back(stoi(original[i]));
  return ans;
}



// dfs(nodo, level, padre)
void dfs_aux(int u, int l, int p){
  level[u] = low[u] = l;
  parent[u] = p;

  for (int i = 0; i < adj[u].size(); i++){
    int v = adj[u][i];
    // Ignorar al padre
    if (v == parent[u]) continue;
    if (level[v] == -1){
      dfs_aux(v, l+1, u);
      low[u] = min(low[u], low[v]);

      // Contamos los hijos de la raiz
      if (parent[u] == -1)
        hijosRaiz++;

      // Si no es la raiz y el low del hijo alcanza un nivel mas bajo
      if (parent[u] != -1 && low[v] >= level[u])
        puntosArticulacion.insert(u);
    }
    else if (level[v] < level[u]){
      low[u] = min(low[u], level[v]);
    }
  }
}

void dfs(){
  // aca los nodos van desde 1 hasta n
  for (int i = 1; i <= n; i++){
    if (level[i] == -1){
      hijosRaiz = 0;
      dfs_aux(i, 0, -1);
      if (hijosRaiz > 1)
        puntosArticulacion.insert(i);
    }
  }
}




int main(){
  cin >> n;
  while (n != 0){
    string s;
    adj.assign(n+1, vector<int>(0));
    parent.assign(n+1, 0);
    level.assign(n+1, -1);
    low.assign(n+1, -1);
    puntosArticulacion.clear();
    while (getline(cin, s)){
      if (s[0] == '0') break;
      vector<string> original = tokenizer(' ', s);
      vector<int> transformado = transformar(original);

      for (int i = 1; i < transformado.size(); i++){
        adj[transformado[0]].push_back(transformado[i]);
        adj[transformado[i]].push_back(transformado[0]);
      }
    }


     dfs();

    cout << puntosArticulacion.size() << endl;

    //for (int i = 0; i < puntosArticulacion.size(); i++)
      //cout << puntosArticulacion[i] << endl;

    cin >> n;
  }
}
