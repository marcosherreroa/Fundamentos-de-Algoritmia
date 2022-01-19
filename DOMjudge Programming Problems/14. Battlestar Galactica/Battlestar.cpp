//Marcos Herrero

#include <iostream>
#include <vector>

long long int mezcla(std::vector<long long int> & v, long long int ini, long long int fin, long long int m) {
	long long int r = 0;
	std::vector<long long int> w(fin - ini);
	long long int i = ini, j = m + 1, k = 0;
	while (i <= m && j < fin) {
		if (v[i] <= v[j]) {
			w[k] = v[i];
			++i;
		}
		else {
			w[k] = v[j];
			r += abs(ini + k - j);
			++j;
		}
		++k;
	}

	while (i <= m) {
		w[k] = v[i];
		++k;
		++i;
	}

	while (j < fin) {
		w[k] = v[j];
		++k;
		++j;
	}

	for (int t = 0; t < fin - ini; ++t)  v[t + ini] = w[t];
	return r;
}

/*
P={N>0}
fun permut(v[0,...,N-1] de ent) dev p:ent
Q={sum i: 0<= i<= N-1: (#j: i < j <= N-1: v[j] < v[i])} 

El coste de la funcion permut viene dado en función del tamaño N del vector y de la función de coste de mezcla por:
T(N) = k1 si N<2
T(N) = k2 + 2*T(N/2) + cost_mezcla(N)     
Como la función mezcla tiene coste lineal ( realiza N iteraciones y todas las operaciones tiene coste constante)
una función de coste en el mismo orden que la anterior sería:
T'(N) = k1 si N<2
T'(N) = k2 + 2*T'(N/2) + N si N>=2
Por el teorema de la división, con a=2, b=2 y k =1, como a = 2 = b^k, el algoritmo está en el orden exacto de 
O(n^k*log(n))=O (nlog(n))

*/

long long int permut(std::vector<long long int> & v, long long int ini, long long int fin) {
	long long int r = 0;
	if (ini >= fin - 1) return 0;

	else {
		long long int m = (ini + fin - 1) / 2;
		r += permut(v, ini, m + 1);
		r += permut(v, m + 1, fin);
		r += mezcla(v, ini, fin, m);

		return r;
	}
}

bool resuelveCaso() {
	long long int N;
	std::cin >> N;
	if (!std::cin) return false;

	std::vector<long long int> v(N);
	for (long long int i = 0; i < N; ++i) std::cin >> v[i];

	std::cout << permut(v, 0, N) << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
}