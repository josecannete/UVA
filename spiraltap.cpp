// 10920 - Spiral Tap

#include <iostream>
#include <vector>
using namespace std;

int main(){
  int s, p;
  cin >> s >> p;
  while(s != 0 && p != 0){
    long long num = 1;
    for (; num * num < p; num+= 2){
    }
    vector<long long> pos(2,0); // arriba, der
    pos[0] = num/2;
    pos[1] = num/2;
    //cout << pos[0] << 1%2  << num << endl;
    int restador = 0;
    int a = -1;
    int cambio = 1;
    for (int i = num * num - 1; i >= p; i--){
      pos[restador] += a;
      if (i % num == cambio){
        if (restador == 0) restador = 1;
        else restador = 0;
        cambio++;
        if (cambio == num)
          cambio = 0;
      }
      if ( pos[0] == -num/2 && pos[1] == -num/2) a *= -1;
    }
    cout << "Line = "<< (s/2 + pos[0] + 1) << ", column = " << (s/2 + pos[1] + 1) << "."<<  endl;

    cin >> s >> p;
  }
}
