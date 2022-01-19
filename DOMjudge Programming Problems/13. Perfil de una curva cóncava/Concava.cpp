//Marcos Herrero

#include <iostream>
#include <vector>

/*
P={N>0 && exists i: 0<=i <= N-1:((for all j: 0<=j<i: v[j] > v[j+1]) && (for all j:i<=j<N-1: v[j] < v[j+1))}
fun minimo(v[0,...,N-1] de ent) dev m:ent
Q={exists i: 0<=i<=N-1: (v[i] = m && (for all j: 0<=j<i: v[j] > v[j+1]) && (for all j:i<=j<N-1: v[j] < v[j+1))}

El coste en tiempo del algoritmo viene dado en función del tamaño N del vector por:
T(N) = k1 si N<2
T(N) = k2+ T(N/2) si N>=2
Por el teorema de la division, el algoritmo esta en el orden O(log(n))


*/

int minimo(std::vector<int> const & v, int ini, int fin) {
	if (ini == fin - 1) return v[ini];
	else if (ini == fin - 2 && v[ini] < v[fin - 1]) return v[ini];
	else if (ini == fin - 2) return v[fin - 1];

	else {
		int m = (ini + fin - 1) / 2;
		if (v[m - 1] > v[m] && v[m + 1] > v[m]) return v[m];
		else if (v[m] < v[m+1]) return minimo(v, ini, m + 1);
		else return minimo(v, m + 1, fin);
	}
}

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (!std::cin) return false;

	std::vector<int> v(N);
	for (int i = 0; i < N; ++i)std::cin >> v[i];

	std::cout<< minimo(v, 0, N) << '\n';
	return true;
}

int main() {
	while (resuelveCaso());
}