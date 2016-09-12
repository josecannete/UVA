// 10038 - Jolly Jumpers

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	
	while(cin >> n){
		vector<int> vec(n,0);
		int dif = 0;
		int a=0, b=0;
		cin >> a;
		b = a;
		for (int i = 1; i < n; i++){
			cin >> a;
			dif = abs(a-b);
			//cout << dif << endl;
			if (dif < n)
				vec[dif]++;
			b = a;
		}
		bool flag = true;
		for (int i = 1; i < n; i++)
			if (vec[i] == 0)
				flag = false;
		if (flag) cout << "Jolly" << endl;
		else cout << "Not jolly" << endl;
	}	
	
	
}
