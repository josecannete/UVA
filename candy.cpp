#include <bits/stdc++.h>
using namespace std;

int main(){
  int m, n;
  cin >> m >> n;
  vector<vector<int> > mat;
  while (m != 0 && n != 0){

    mat.assign(m+1, vector<int>(n+1));
    vector<int> ans;

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        cin >> mat[i][j];
    //cout << "hola" << endl;
    for (int i = 0; i < m; i++){
      if (n > 1)
        mat[i][1] = max(mat[i][0], mat[i][1]);
      for (int j = 2; j < n; j++){
        mat[i][j] = max(mat[i][j-1], mat[i][j-2] + mat[i][j]);
      }
      ans.push_back(mat[i][n-1]);
      //cout << mat[m][i] << endl;
    }
    if (m > 1)
      ans[1] = max(ans[0], ans[1]);
    for (int i = 2; i < m; i++)
      ans[i] = max(ans[i-1], ans[i-2]+ans[i]);

    cout << ans[m-1] << endl;

    cin >> m >> n;
  }
}
