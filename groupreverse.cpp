// 11192 - Group Reverse
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  string dev = "";
  while(n != 0){
    string s;
    cin >> s;
    int groups = (s.size()) / n;
    string aux = "";
    for (int i = 0; i < s.size(); i++){
      aux += s[i];
      if (i % groups == groups - 1){
        reverse(aux.begin(), aux.end());
        dev += aux;
        aux = "";
      }
    }
    cin >> n;
    if (n != 0) dev += "\n";
  }
  cout << dev;
  cout << endl;
}
