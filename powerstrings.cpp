// 455 - Periodic Strings
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

int B = 33;

ull fast_pow(int a,int n)
{
    ull result = 1;
    ull power = n;
    ull value = a;
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

void hashear(vector<ull>& h, string s){
  h.assign(s.size()+1,0);

  for (int i = s.size() - 1; i >= 0; i--){
    h[i] = (ull)s[i] + h[i+1] * B;
  }
}

ull hashval(vector<ull>& h, int i, int j){
  return h[i] - h[j+1] * fast_pow(B, j+1-i);
}


int main(){
  string s;
  cin >> s;
  while (s[0] != '.'){
    string sub = "";
    vector<ull> h;
    //cout << "pase por 0" << endl;
    hashear(h, s);
    //cout << "pase por 1" << endl;
    for (int i = 1; i < s.size() + 1; i++){
      sub += s[i-1];
      //cout << "el sub es " << sub << endl;
      //vector<ull> p;
      //hashear(p, sub);
      int index = 0;
      //cout << hashval(h, 0, i-1) << endl;
      //cout << hashval(h, 0, i-1) << endl;
      //cout << p[0 << endl;
      //cout << i << endl;
      do{
        index += sub.size();
      } while ( index + sub.size() - 1 < s.size() && hashval(h, index, index + sub.size() - 1) == hashval(h,0,sub.size() - 1)) ;

      //cout << i << endl;
      //cout << hashval(h, 0, sub.size()-1) << endl;
      //cout << hashval(h, index, index + sub.size() - 1) << endl;

      //cout << "el indice es " << index << endl;
      if (index == s.size()){
        //cout << sub << endl;
        cout << s.size()/sub.size() << endl;
        break;
      }
    }
    cin >> s;
  }
}
