//Marcos Herrero

#include <iostream>
#include <vector>

using tMatriz = std::vector<std::vector<long long int>>;

/*

P={exists M: M>= 0: N=2^M}
fun degradadoVector(v[0,...,N-1] de ent) dev b: bool
Q={ b = degrad(v,0,N)}

donde degrad(v, ini, fin)=  (sum i: 0<= i <= (ini+fin-1)/2: v[i]) < (sum j: (ini+fin-1)/2+1 <= j <= fin-1) &&
	                         degrad(v,ini, (ini+fin-1)/2+1) &&  degrad(v, (ini+fin-1)/2+1, fin)

El coste en tiempo del algoritmo viene dado en función del tamaño N del vector por:
T(N) = k1 si N<2
T(N) = K2 + 2*T(N/2) si N>=2

Por tanto, por el teorema de la división, el algoritmo pertenece al orden exacto O(N^log_2(2)) = O(N)


*/


bool degradadoVector(std::vector<long long int> const & v, long long int ini, long long int fin, long long int & suma) {
	if (ini == fin - 1) {
		suma = v[ini];
		return true;
   }

	else {
		long long int m = (ini + fin - 1) / 2, sumaizq= 0, sumaderecha= 0;
		bool degradado = degradadoVector(v, ini, m + 1, sumaizq) && degradadoVector(v, m + 1, fin, sumaderecha);
		suma = sumaizq + sumaderecha;
		return (degradado && (sumaizq < sumaderecha));
	}
}

bool degradadoMatriz(tMatriz const & matriz, long long int N, long long int M) {
	bool degradado = true; long long int suma;
	for (long long int i = 0; degradado &&  i < N; ++i) {
		degradado = degradadoVector(matriz[i], 0, M, suma);
	}

	return degradado;
}

bool resuelveCaso() {
	long long int N, M;
	std::cin >> N >> M;
	if (!std::cin) return false;

	tMatriz mat(N, std::vector<long long int>(M));
	for (long long int i = 0; i < N; ++i) {
		for (long long int j = 0; j < M; ++j) {
			std::cin >> mat[i][j];
		}
	}

	if (degradadoMatriz(mat, N, M))std::cout << "SI\n";
	else std::cout << "NO\n";

	return true;
}

int main() {
	while (resuelveCaso());
}