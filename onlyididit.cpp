// 11222 - Only I did it!

#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  int asd = 0;
  string dev = "";
  while(t--){
    asd++;
    //cout << "Case #" << asd << ":" << endl;
    dev += "Case #";
    dev += to_string(asd);
    dev += ":\n";
    vector<int> uno(10001,0), dos(10001,0), tres(10001,0);
    vector<int> suno, sdos, stres;
    int s, p;
    cin >> s;
    for (int i = 0; i < s; i++)
      cin >> p, uno[p] = 1;
    cin >> s;
    for (int i = 0; i < s; i++)
      cin >> p, dos[p] = 1;
    cin >> s;
    for (int i = 0; i < s; i++)
      cin >> p, tres[p] = 1;
    int sum1 = 0, sum2 = 0, sum3 = 0;
    for (int i = 0; i < 10001; i++){
      if (uno[i] && !dos[i] && !tres[i])
        sum1++, suno.push_back(i);
      else if (!uno[i] && dos[i] && !tres[i])
          sum2++, sdos.push_back(i);
      else if (!uno[i] && !dos[i] && tres[i])
            sum3++, stres.push_back(i);
    }
    int maximo = max(sum1, max(sum2, sum3));
    if (maximo == sum1){
      //cout << 1 << " " << suno.size() << " ";
      dev += "1";
      dev += " ";
      dev += to_string(suno.size());
      sort(suno.begin(), suno.end());
      for (int i = 0; i < suno.size(); i++){
        //cout << suno[i] << " ";
        dev += " ";
        dev += to_string(suno[i]);
      }
      //cout << endl;
      dev += "\n";
    }
    if (maximo == sum2){
      //cout << 2 << " " << sdos.size() << " ";
      dev += "2";
      dev += " ";
      dev += to_string(sdos.size());
      sort(sdos.begin(), sdos.end());
      for (int i = 0; i < sdos.size(); i++){
        //cout << sdos[i] << " ";
        dev += " ";
        dev += to_string(sdos[i]);
      }
      //cout << endl;
      dev += "\n";
    }
    if (maximo == sum3){
      //cout << 3 << " " << stres.size() << " ";
      dev += "3";
      dev += " ";
      dev += to_string(stres.size());
      sort(stres.begin(), stres.end());
      for (int i = 0; i < stres.size(); i++){
        //cout << stres[i] << " ";
        dev += " ";
        dev += to_string(stres[i]);
      }
      //cout << endl;
      dev += "\n";
    }
  }
  dev.erase(dev.size());
  cout << dev;

}
