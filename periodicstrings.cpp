// 455 - Periodic Strings
#include <bits/stdc++.h>
using namespace std;

int B = 33;

long long fast_pow(int a,int n)
{
    long long result = 1;
    long long power = n;
    long long value = a;
    while(power>0)
    {
        if(power&1)
            {result = result*value;
            }
        value = value*value;
        power /= 2;
        //power >>= 1;
    }
    return result;
}

void hashear(vector<long long>& h, string s){
  h.assign(s.size()+1,0);

  for (int i = s.size() - 1; i >= 0; i--){
    h[i] = (long long)s[i] + h[i+1] * B;
  }
}

long long hashval(vector<long long>& h, int i, int j){
  return h[i] - h[j+1] * fast_pow(B, j+1-i);
}


int main(){
  int n;
  cin >> n;
  while (n--){
    string s;
    cin >> s;
    string sub = "";
    vector<long long> h;
    hashear(h, s);

    for (int i = 1; i < s.size() + 1; i++){
      sub += s[i-1];
      //cout << "el sub es " << sub << endl;
      //vector<long long> p;
      //hashear(p, sub);
      int index = 0;
      //cout << hashval(h, 0, i-1) << endl;
      //cout << hashval(h, 0, i-1) << endl;
      //cout << p[0 << endl;
      do{
        index += sub.size();
      } while (hashval(h, index, index + sub.size() - 1) == hashval(h,0,sub.size() - 1)) ;

      //cout << hashval(h, 0, sub.size()-1) << endl;
      //cout << hashval(h, index, index + sub.size() - 1) << endl;

      //cout << "el indice es " << index << endl;
      if (index == s.size()){
        //cout << sub << endl;
        cout << sub.size() << endl;
        break;
      }
    }
    if (n != 0)
      cout << endl;

  }
}
