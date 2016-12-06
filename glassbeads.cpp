// 719 - Glass Beads
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int B = 33;

ull fast_pow(int a,int n) {
  ull result = 1, power = n, value = a;
  while (power>0) {
    if (power&1) result = result * value;
    value = value * value;
    power >>= 1;
  }
  return result;
}

void construirHash(vector<ull>& h, string s) {
  h.assign(s.size()+1,0);
  for (int i = s.size() - 1; i >= 0; i--)
    h[i] = (ull)s[i] + h[i+1] * B;
}

ull hashval(vector<ull>& h, int i, int j) {
  return h[i] - h[j+1] * fast_pow(B, j+1-i);
}

int menorlex(vector<ull>& h, int index1, int index2, int sufijo){
  int mitad1 = (index1 + sufijo)/2, mitad2 = (index2 + sufijo)/2;
  while (hashval(index1 + mitad1) != hashval(index2 + mitad2)) {
    
  }
}

int main(){
  int n;
  cin >> n;

  for (int test = 0; test < n; test++) {
    string s;
    cin >> s;
    string menor = s;
    s = s + s;
    vector<ull> h;
    construirHash(h, s);
    for (int i = 0; i < menor.size(); i++) {
      menor = menorlex(menor, )
    }
  }
}
