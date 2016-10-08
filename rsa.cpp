#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll tamano;
bitset<10000010> bs;
vector<int> primos;

void criba (ll n){
	tamano = n +1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i<= tamano; i++)
		if (bs[i]) {
			for (ll j = i * i; j <= tamano; j += i) bs[j] = 0;
			primos.push_back((int) i);
		}
}

// C function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y);

// Function to find modulo inverse of a
int modInverse(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        //cout << "Inverse doesn't exist";
        return 0;
    else
    {
        // m is added to handle negative x
        int res = (x%m + m) % m;
        //cout << "Modular multiplicative inverse is " << res;
        return res;
    }
}

// C function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}



int main(){
  criba(1000000);
  ll n, e, c;
  while (cin >> n >> e >> c){
    ll p=0,q=0;
    for (int i = 0; i < primos.size(); i++){
      if (n % primos[i] == 0){
        p = primos[i];
        q = n/primos[i];
        break;
      }
    }
    ll phi = (p-1)*(q-1);
    ll d = modInverse(e, phi);

    ll result = 1;
    ll power = d;
    ll value = c;
    while(power>0){
      if(power&1){
            result = result*value;
            result = result%n;
          }
      value = (value%n)*(value%n)%n;
      value = value%n;
      power /= 2;
    //power >>= 1;
    }
    cout << result << endl;

  }
}
