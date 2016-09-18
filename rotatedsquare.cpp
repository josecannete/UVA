// 10855 - Rotated square

#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N, n;
  cin >> N >> n;
  while(N != 0 && n != 0){
    vector<vector<char> > grande(N, vector<char>(N));
    vector<vector<char> > chico(n, vector<char>(n));
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        cin >> grande[i][j];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cin >> chico[i][j];
    int contador1, contador2, contador3, contador4, ans1=0, ans2=0, ans3=0, ans4=0;
    for (int i = 0; i + n <= N; i++)
      for (int j = 0; j + n <= N; j++){
        contador1 = 0, contador2 = 0, contador3 = 0, contador4 = 0;
        for (int a = 0; a < n; a++)
          for (int b = 0; b < n; b++){
            if (chico[a][b] == grande[i+a][j+b])
              contador1++;
            if (chico[n-b-1][a] == grande[i+a][j+b])
              contador2++;
            if (chico[n-a-1][n-b-1] == grande[i+a][j+b])
              contador3++;
            if (chico[n-1-(n-b-1)][n-a-1] == grande[i+a][j+b])
              contador4++;
          }
        //cout << contador1 << " " << contador2 << " " << contador3 << " " <<contador4 << endl;
        if (contador1 == n*n)
          ans1++;
        if (contador2 == n*n)
          ans2++;
        if (contador3 == n*n)
          ans3++;
        if (contador4 == n*n)
          ans4++;
      }
    cout << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << endl;


    cin >> N >> n;
  }
}
