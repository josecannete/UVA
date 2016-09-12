// 591 - Box of Bricks

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

int main(){
	int sets = 0;
	int n;
	cin >> n;
	vi vec(n);
	while (n != 0){
		sets++;
		vec.assign(n,0);
		int sum = 0;
		for (int i = 0; i < n; i++){
			cin >> vec[i];
			sum += vec[i];
		}
		int stacks = sum / n;
		int ans = 0;
		for (int i = 0; i < n; i++)
			if (vec[i] > stacks)
				ans += vec[i] - stacks;
		cout << "Set #" << sets << endl << "The minimum number of moves is "
		<< ans << "." << endl << endl;
		cin >> n;
	}	
	
}
