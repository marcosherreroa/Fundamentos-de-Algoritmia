//Marcos Herrero
#include <iostream>
#include <vector>

/*
P={exists M:M>= 0: N= 2^M}
fun parcOrd(v[0,...,N-1] de ent, ini:ent, fin:ent) dev b:bool
Q={b= parcOrd(v, 0, N)}

donde  maxl(v,ini, fin) = max i: ini<= i <= (ini+fin-1)/2: v[i] 
       minl(v,ini, fin) = min i: ini<= i <= (ini+fin-1)/2: v[i]     (definidos para ini > fin - 1)
	   maxr(v,ini,fin) = max i: (ini+fin-1)/2 < i < fin-1
	   minr (v,ini,fin) = min i: (ini+fin-1/2

      parcOrd(v, ini, fin)= maxr(v,ini,fin)>= maxl(v,ini,fin) && minl(v,ini,fin) <= minr(v,ini,fin)
	                        parcOrd(v, ini, (ini+fin-1)/2+1) && parcOrd(v, (ini+fin-1)/2+1, fin)  si ini > fin-1
                          = true si ini == fin-1

La función que da el coste en tiempo del algoritmo en función del tamaño N del vector:
T(N) = k1 si N < 2;
T(N) = K2 + 2*T(N/2) si n>=2;

Entonces por el teorema de la division el algoritmo está en el orden exacto O(N^log_2(2))= O(N)
*/

bool parcOrd(std::vector<int> v, int ini, int fin, int & minl, int & maxr) {
	if (ini == fin - 1) {
		minl = v[ini];
		maxr = v[ini];
		return true;
	}

	else {
		int m = (ini + fin - 1) / 2, maxl, minr;
		if (!parcOrd(v, ini, m + 1, minl, maxl) || !parcOrd(v, m + 1, fin, minr, maxr)) return false;
		else if (maxl > maxr)return false;
		else if (minr < minl) return false;
		else return true;
	}
}

bool resuelveCaso() {
	std::vector<int> v;
	int aux ;
	std::cin >> aux;
	while (aux != 0){
		v.push_back(aux);
		std::cin >> aux;
	}

	if (v.size() == 0) return false;

	int aux1 = 0, aux2 = 0;
	if (parcOrd(v,0, v.size(), aux1, aux2))std::cout << "SI\n";
	else std::cout << "NO\n";

	return true;
}

int main() {
	while (resuelveCaso());
	system("PAUSE");
}