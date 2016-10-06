// 12032 - The Monkey and the Oiled Bamboo

#include <bits/stdc++.h>
using namespace std;

int main(){
  string dev = "";
  cin.tie(0);
  int T;
  cin >> T;
  for (int test = 0; test < T; test++){
    int n;
    cin >> n;
    vector<int> num;
    num.assign(n+1,0);
    for (int i = 1; i <= n; i++)
      cin >> num[i];
    int ini = 0, fin = 1e7, med = (ini+fin) / 2;
    while (fin > ini){
      bool flag = 0;
      int posible = med;
      for (int i = 0; i < n; i++){
        if (num[i] + posible < num[i+1]){
          flag = 1;
          break;
        }
        else if (num[i] + posible == num[i+1]){
          posible--;
        }
      }
      if (!flag)
        fin = med;
      else
        ini = med+1;
      med = (ini+fin)/2;
    }
    //cout << "Case " << test+1  << ": " << med << endl;
    dev += "Case " + to_string(test+1) + ": " + to_string(med) + "\n";
  }
  cout << dev;
}
