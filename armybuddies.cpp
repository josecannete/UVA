// 12356 - Army Buddies

#include <bits/stdc++.h>
using namespace std;

#define ii pair<int,int>

int main(){
	int S, B;
	cin >> S >> B;
	
	while(S != 0 && B != 0){
		vector<ii> vec(S+1);
		vec[1] = ii(0,2);
		vec[S] = ii (S-1,0);
		for (int i = 2; i < S; i++){
			vec[i] = ii(i-1,i+1);
		}
		for (int i = 0; i < B; i++){
			int L, R;
			cin >> L >> R;
			vec[vec[L].first] = ii(vec[vec[L].first].first, vec[R].second);
			vec[vec[R].second] = ii(vec[L].first, vec[vec[R].second].second);
			if (vec[L].first == 0) cout << "*" << " ";
			else cout << vec[L].first << " ";
			if (vec[R].second == 0)	cout << "*" << endl;
			else cout << vec[R].second << endl;
			vec[L] = vec[R] = ii(0,0);
			}
		cout << "-" << endl;
		cin >> S >> B;
	}
}
