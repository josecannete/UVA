#include<bits/stdc++.h>
using namespace std;


template<class node> class ST {
    vector<node> t;
    int n;


public:
    ST(vector<node> &arr) {
        n = arr.size();
        t.resize(n*2);
        copy(arr.begin(), arr.end(), t.begin() + n);
        for (int i = n-1; i > 0; --i)
            t[i] = node(t[i<<1], t[i<<1|1]);
    }


    // 0-indexed
    void set_point(int p, const node &value) {
        for (t[p += n] = value; p > 1; p >>= 1)
            t[p>>1] = node(t[p], t[p^1]);
    }


    // inclusive exclusive, 0-indexed
    node query(int l, int r) {
        node ansl, ansr;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) ansl = node(ansl, t[l++]);
            if (r&1) ansr = node(t[--r], ansr);
        }
        return node(ansl, ansr);
    }
};


struct rmaxq {
    int value;
    rmaxq() {value = -1e9;}
    rmaxq(int x) {value = x;}
    rmaxq(const rmaxq &a,
          const rmaxq &b) {
        value = max(a.value,
                    b.value);
    }
};



int main(){
	int n, q;
	while(cin >> n){
		if (n == 0) {
			//cout << endl;
			break;
		}
		cin >> q;
		vector<int> frecuencias(n+1,0);
		vector<int> valores(n+1,0);
		vector<int> termina(n+1,0);
		int cont = 1;
		int valor = 1e7;
		int valorant = 1e7;
		for (int i = 1; i <= n; i++){
			cin >> valor;
			valores[i] = valor;
			//cout << valor << endl;
		}
		//cout << "hola" << endl;
		valores[0] = 1e7;
		for (int i = 1; i <= n; i++){
			frecuencias[i] = cont;
			if (valores[i] == valores[i+1])
				cont++;
			else cont = 1;
			//cout << frecuencias[i] << " ";
		}
		//cout << endl;
		cont = n;
		//valores[n] = n;
		termina[n] = n;
		for (int i = n-1; i >= 1; i--){
			if (valores[i] == valores[i+1])
				termina[i] = cont;
			else{
				cont = i;
				termina[i] = i;
			}
		}
		
		//for (int i = 1; i <= n; i++)
			//cout << termina[i] << " ";
		
		//cout << endl;
		
		vector<rmaxq> t;
		for (int i = 1; i<= n; i++)
			t.push_back(rmaxq(frecuencias[i]));
		
		ST<rmaxq> SST(t);
		
		for (int i = 0; i < q; i++){
			int x, y;
			cin >> x >> y;
			int primer = 0;
			int segundo = 0;
			if (termina[x] <= y){
				primer = termina[x] - x + 1;
				segundo = SST.query(termina[x]+1, y).value;
			}
			else{
				primer = y - x + 1;
			}
			//cout << segundo << endl;
			cout << max(primer, segundo) << endl;
		}
	}
}
