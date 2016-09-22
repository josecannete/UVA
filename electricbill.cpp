// 12190 - Electric Bill

#include <bits/stdc++.h>
using namespace std;

int foo(int cantidad){
	int valor = 0;
    valor += min(max(0, cantidad*2), 2*100); cantidad -= 100;
    valor += min(max(0, cantidad*3), 3*9900); cantidad -= 9900;
    valor += min(max(0, cantidad*5), 5*990000); cantidad -= 990000;
    valor += max(0, cantidad*7);
	return valor;
}

int fooinversa(int valor){
	int cantidad = 0;
    cantidad += min(max(0, valor/2), 100); valor -= 2*100;
    cantidad += min(max(0, valor/3), 9900); valor -= 3*9900;
    cantidad += min(max(0, valor/5), 990000); valor -= 5*990000;
    cantidad += max(0, valor/7);
	return cantidad;
}


int main(){
	int A, B;
	cin >> A >> B;
	while (A != 0 && B != 0){
		int sumacantidades = fooinversa(A);
		int ini=0, fin=sumacantidades, med;
		while (fin > ini){
			med = (ini + fin)/2;
			if ( (foo(sumacantidades - med) - foo(med)) > B)
				ini = med+1;
			else
				fin = med;
		}
		cout << foo((ini+fin)/2) << endl;
		cin >> A >> B;
	}
}
