// 10107 - What is the Median?

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  vector<int> numeros;
  int n;
  while(cin >> n){
    numeros.push_back(n);
    sort(numeros.begin(), numeros.end());
    if (numeros.size() % 2 == 1)
      cout << numeros[numeros.size()/2] << endl;
    else cout << (numeros[numeros.size()/2 - 1] + numeros[numeros.size()/2])/2 << endl;
  }
}
