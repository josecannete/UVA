// 11093 - Just Finish it up

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	int t;
	cin >> t;
	int asd = 0;
	
	while(t--){
		asd++;
		int n;
		cin >> n;
		vector<ll> uno(n+1,0), dos(n+1,0), tres(n+1,0);
		ll a;
		for (int i = 1; i <= n; i++){
			cin >> a;
			uno[i] = uno[i-1] + a;
		}
		for (int i = 1; i <= n; i++){
			cin >> a;
			dos[i] = dos[i-1] + a;
		}
		for (int i = 1; i <= n; i++)
			tres[i] = uno[i] - dos[i];
			
		if (tres[n] < 0)
			cout << "Case " << asd << ": Not possible" << endl;
		else{
			int i = 1;
			int ultimo = 0;
			for (; i <= n; i++)
				if (tres[i] < 0){
					ultimo = i;
				}
			cout << "Case " << asd << ": Possible from station " << (ultimo + 1) % n << endl;
		}		
	}
}
