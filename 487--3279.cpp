// 755 - 487--3279

#include <bits/stdc++.h>
using namespace std;

#define si pair<string,int>

int main(){
  int t;
  cin >> t;
  string dev = "";

  while(t--){
    int n;
    cin >> n;
    map<string, int> mapita;
    for (int i = 0; i < n; i++){
      string s;
      cin >> s;
      string aux = "";
      //cout << "el size de s es " << s.size() << endl;
      for (int j = 0; j < s.size(); j++){
        if (s[j] == 'A' || s[j] == 'B' || s[j] == 'C')
          aux += '2';
        if (s[j] == 'D' || s[j] == 'E' || s[j] == 'F')
          aux += '3';
        if (s[j] == 'G' || s[j] == 'H' || s[j] == 'I')
          aux += '4';
        if (s[j] == 'J' || s[j] == 'K' || s[j] == 'L')
          aux += '5';
        if (s[j] == 'M' || s[j] == 'N' || s[j] == 'O')
          aux += '6';
        if (s[j] == 'P' || s[j] == 'R' || s[j] == 'S')
          aux += '7';
        if (s[j] == 'T' || s[j] == 'U' || s[j] == 'V')
          aux += '8';
        if (s[j] == 'W' || s[j] == 'X' || s[j] == 'Y')
          aux += '9';
        if (s[j] >= '0' && s[j] <= '9')
          aux += s[j];
        if (aux.size() == 3)
          aux += '-';
      }
      //cout << "aux es " << aux << endl;
      mapita[aux]++;
    }
    int flag = 0;
    for (auto str : mapita){
      //cout << str.first << "    " << str.second << endl;
      if (mapita[str.first] > 1){
        //cout << str.first << " " << str.second << endl;
        dev += str.first; dev += " "; dev += to_string(str.second); dev += "\n";
        flag = 1;
      }
    }
    if (!flag) //cout << "No duplicates" << endl;
      dev += "No duplicates.\n";
    //cout << endl;
    if (t != 0)
      dev += "\n";
  }
  cout << dev;
}
