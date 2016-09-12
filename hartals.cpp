// 10050 - Hartals

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

int main(){
	int T;
	cin >> T;
	while (T--){
		int N, P;
		cin >> N >> P;
		vi vec(N+1,0);
		for (int i = 0; i < P; i++){
			int h;
			cin >> h;
			for (int j = 0; j * h <= N; j++)
				vec[j*h] = 1;
		}
		int ans = 0;
		for (int i = 1; i <= N; i++)
			if (i % 7 != 6 && i % 7 != 0 && vec[i] == 1)
				ans++;
		cout << ans << endl;
		}
	
}
