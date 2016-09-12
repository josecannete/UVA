// 11340 - Newspaper

#include <bits/stdc++.h>
using namespace std;

#define ci pair<char,int>

int main(){
	int t;
	cin >> t;
	
	for (int tests = 0; tests < t; tests++){
		int k;
		cin >> k;
		map<char, int> mapita;
		
		for (int i = 0; i < k; i++){
			char mander; int valor;
			cin >> mander >> valor;
			mapita.insert(ci(mander, valor));
			}
		int M;
		cin >> M;
		string text = "";
		cin.ignore();
		for (int i = 0; i < M; i++){
			string asd;
			getline(cin,asd);
			text += asd;
		}
		long long sum = 0;
		for (int i = 0; i < text.size(); i++){
			sum += mapita[text[i]];
		}
		int dollars = sum / 100;
		int cents = sum % 100 / 10;
		int cents2 = sum % 100 % 10;
		cout << dollars << "." << cents << cents2 <<  "$" << endl;
		
	}
}
