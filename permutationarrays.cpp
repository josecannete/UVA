// 482 - Permutation Arrays

#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  string s = "";
  getline(cin, s);
  t = stoi(s);
  while(t--){
    vector<int> uno;
    vector<string> dos, tres;
    s = "";
    getline(cin, s);
    string aux = "";
    for (int i = 0; i < s.size(); i++){
      if (s[i] == ' '){
        uno.push_back(stoi(aux));
      }
      else aux += s[i];
    }
    for (int i = 0; i < uno.size(); i++){
      string asd;
      cin >> asd;
      dos.push_back(asd);
    }
    tres.assign(uno.size()+1, "");
    for (int i = 0; i < uno.size(); i++){
      tres[uno[i]] = dos[i];
    }
    for (int i = 1; i <= uno.size(); i++)
      cout << tres[i] << endl;

  }
}
