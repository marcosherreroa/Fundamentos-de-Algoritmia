//Marcos Herrero
// Ángeles Plaza
#include <iostream>
#include <vector>

/*

P:{N > 0 && for all i,j: 0<= i <j <= N-1: v[i] < v[j]}
fun tachar(v[0,...,N-1] de ent, c: ent) dev p: ent
Q:{ p = v[i] && c + i = v[i]} 

El tamaño n del problema es la longitud del vector considerado

T(n) = k1 si n=0;
T(n) = k2 + T(n/2) si n> 1;

Aplicando el teorema de la division, como k = 0, a=1 y b = 2, a = b^k y por tanto el coste del algoritmo 
es n^k*log(n) = log (n)

*/

int tachar(std::vector<int> & v, int c, int ini, int fin) {
	if (ini >= fin) return -1;


	else {
		int m = (ini + fin - 1) / 2;

		if (c + m == v[m]) return v[m];
		else if (c + m < v[m]) return tachar(v, c, ini, m);
		else return tachar(v, c, m + 1, fin);
	}

}


void resuelveCaso() {
	int N, c;
	std::cin >> N >> c;

	std::vector<int> v(N);
	for (int i = 0; i < N; ++i) std::cin >> v[i];

	int sol = tachar(v, c, 0 , N);
	if (sol == -1) std::cout << "NO\n";
	else std::cout << sol << '\n';

}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) resuelveCaso();
	system("PAUSE");
}