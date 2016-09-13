#include <bits/stdc++.h>
using namespace std;

#define si pair<char, int>

int main(){
	string s;
	map<char, int> mapita;
	mapita.insert(si('B', 1));
	mapita.insert(si('F', 1));
	mapita.insert(si('P', 1));
	mapita.insert(si('V', 1));
	
	mapita.insert(si('C', 2));
	mapita.insert(si('G', 2));
	mapita.insert(si('J', 2));
	mapita.insert(si('K', 2));
	mapita.insert(si('Q', 2));
	mapita.insert(si('S', 2));
	mapita.insert(si('X', 2));
	mapita.insert(si('Z', 2));
	
	mapita.insert(si('D', 3));
	mapita.insert(si('T', 3));
	
	mapita.insert(si('L', 4));
	
	mapita.insert(si('M', 5));
	mapita.insert(si('N', 5));
	
	mapita.insert(si('R', 6));
	
	while (cin >> s){
		vector<int> dev;
		vector<int> arreglo(25,0);
		for (int i = 0; i < s.size(); i++)
			arreglo[i] = mapita[s[i]];
		for (int i = 0; i < arreglo.size(); i++)
			if (arreglo[i] != 0 && arreglo[i-1] != arreglo[i])
				dev.push_back(arreglo[i]);
		for (int i = 0; i < dev.size(); i++)
			cout << dev[i];
		cout << endl;
	}
	
}
