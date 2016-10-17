// 12149 - Feynman
#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> ans(101,0);
  for (int i = 1; i < 101; i++){
    ans[i] = i*i + ans[i-1];
  }
  int n;
  cin >> n;
  while (n != 0){
    cout << ans[n] << endl;
    cin >> n;
  }
}
