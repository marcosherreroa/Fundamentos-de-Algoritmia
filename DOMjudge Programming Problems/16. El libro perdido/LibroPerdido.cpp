//Marcos Herrero
//Martín Fernández
#include <iostream>
#include <vector>

/*

P:{N>0 && for all: i: 0<= i< N-1: v[i]< v[i+1] && exists i: 0<= i < N: (for all j: 0<= j < N && j!=i:( v[i] != v[j] && (exists k: 0<= k <N: v[j] = v[k])))}
fun libroFalta(v[0,....N-1] de ent)dev p:ent
Q:{ for all j: 0<= j < N && j!=p: v[p] != v[j]}

El coste en función del tamaño n del vector tratado es:
T(n) = k1 si n ==1;
T(n) = k2 + T(n/2) si n>1;

Aplicando el teorema de la división, el coste del algoritmo están en el orden de log(n)

*/



int libroFalta(std::vector<int> v, int ini, int fin){
	if (ini == fin - 1) return ini;
	else {
		int m = (ini + fin - 1) / 2;

		if (v[m] != v[m - 1] && v[m] != v[m + 1]) return m;
		else if (v[m] == v[m - 1] ) {
			if((m - 1 - ini) % 2 == 1) return libroFalta(v, ini, m - 1);
			else if ((fin - m - 1) % 2 == 1) return libroFalta(v, m + 1, fin);
		}
		else if (v[m] == v[m + 1]) {
			if ((m - ini) % 2 == 1) return libroFalta(v, ini, m);
			else if((fin - m - 2) % 2 == 1)return libroFalta(v, m + 2, fin);
		}
	}
}

void resuelveCaso() {
	int  N;
	std::cin >> N;

	std::vector<int> v(N);
	for (int i = 0; i < N; ++i) std::cin >> v[i];

	std::cout << libroFalta(v, 0, N) << '\n';


}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
	return 0;
}