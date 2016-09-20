// 11933 - Splitting Numbers

#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  while (n != 0){
    int a = 0;
    int b = 0;
    int indice = 0;
    for (int i = 0; i < 31; i++){
      if (n & (1 << i)){
        indice++;
        if (indice % 2 == 1)
          a += 1 << i;
        else b += 1 << i;
      }
    }
    cout << a << " " << b << endl;
    cin >> n;
  }
}
