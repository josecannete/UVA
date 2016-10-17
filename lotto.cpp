// 441 - Lotto
#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > listingSubsets(int n){
  vector<vector<int> > subsets;
  int cantidad = 1 << n;
  for (int i = 0; i < cantidad; i++){
    int aux = i;
    int add = 0;
    vector<int> sub;
    while (aux != 0){
      if (aux & 1){
        sub.push_back(add);
      }
      add++;
      aux = aux >> 1;
    }
    subsets.push_back(sub);
  }
  return subsets;
}

int main(){
  int k;
  cin >> k;
  while (k != 0){
    vector<int> nums(k);
    for (int i = 0; i < k; i++){
      cin >> nums[i];
    }
    vector<vector<int> > subconjuntos = listingSubsets(k);
    vector<vector<int> > subtamseis;
    vector<vector<int> > numtamseis;
    for (int i = 0; i < subconjuntos.size(); i++){
      if (subconjuntos[i].size() == 6)
        subtamseis.push_back(subconjuntos[i]);
    }
    for (int i = 0; i < subtamseis.size(); i++){
      vector<int> actual = subtamseis[i];
      for (int j = 0; j < actual.size(); j++){
        actual[j] = nums[actual[j]];
      }
      sort(actual.begin(), actual.end());
      numtamseis.push_back(actual);
    }
    sort(numtamseis.begin(), numtamseis.end());
    for (int i = 0; i < numtamseis.size(); i++){
      for (int j = 0; j < 6; j++){
        cout << numtamseis[i][j];
        if (j != 5)
          cout << " ";
      }
      cout << endl;
    }
    cin >> k;
    if (k != 0)
      cout << endl;
  }
}
