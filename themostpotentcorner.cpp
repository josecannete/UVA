// 10264 - The Most Potent Corner

#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n;
  while(cin >> n){
    //cout << (unsigned)0 << endl;
    //cout << (2 << 31) << endl;
    vector<int> vec((1 << n),0);
    vector<int> pot((1<<n), 0);
    for (int i = 0; i < (1 << n); i++)
      cin >> vec[i];
    int maxsum = 0;
    int sum = 0;
    for (int i = 0; i < (1 << n); i++){
      sum = 0;
      for (int j = 0; j < n; j++){
        int asd = 1 << j;
        //cout << ~(~asd ^ i) << endl;
        sum += 	vec[~(~asd ^ i)];
      }
      pot[i] = sum;
    }
    for (int i = 0; i < (1 << n); i++){
      for (int j = 0; j < n; j++){
        int asd = 1 << j;
        maxsum = max(maxsum, pot[i] + pot[~(~asd ^ i)]);
      }
    }
    cout << maxsum << endl;
  }
}
