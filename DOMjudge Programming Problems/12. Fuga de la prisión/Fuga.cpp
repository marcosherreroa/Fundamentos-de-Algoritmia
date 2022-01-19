//Marcos Herrero

#include <iostream>
#include <vector>

/*
P={ N > 0 && for all i: 0<= i < N-1: v[i] < v[i+1] && 
   exists i: 0 <= i <= N-1:(for all j: 0<=j <= N-1 && j!=i :(1= #k:0<=k<=N-1: v[j] = v[k])) && 0= #j:0<=j<=N-1: v[j]=v[i]}
fun letraFalta (v[0,...,N-1] de char, a:char, z:char) dev p:char
Q={ 0 = #i: 0<=i<= N-1: v[i]= v[p]}

El coste en tiempo del algoritmo viene dado en función del tamaño N del vector por:
T(N)= k1 si n<2
T(N) = k2 + T(N/2) si n>=2
Por tanto, por el teorema de la division el algoritmo esta en el orden exacto O(log(n))

*/


char letraFalta(std::vector<char> & v, int N, int ini, int fin) {
	if (fin < N && v[fin - 1] + 1 != v[fin]) return v[fin - 1] + 1;
	else if (ini >= fin - 1) return v[ini] + 1;
	else if (ini == fin - 2 && v[ini]+1 == v[fin - 1]) return v[fin - 1] + 1;
	else if (ini == fin - 2) return v[ini] + 1;
	
	else {
		int m = (ini + fin - 1) / 2;

		if ((ini +fin-1)% 2 == 1 && v[m] - v[ini] >= v[fin-1] - v[m+1]) return letraFalta(v, N, ini, m+1);
		else if ((ini + fin - 1) % 2 == 0 && v[m] - v[ini] > v[fin - 1] - v[m + 1]) return letraFalta(v, N, ini, m + 1);
		else return letraFalta(v, N, m + 1, fin);
	}
}

void resuelveCaso() {
	char x1, x2;
	std::cin >> x1 >> x2;
	int N = x2 - x1;

	std::vector<char> v(N);
	for (int i = 0; i < N; ++i) std::cin >> v[i];

	if (v[0] != x1) std::cout << x1 << '\n';
	else if (v[N - 1] != x2) std::cout << x2 <<'\n';
	else std::cout << letraFalta(v, N, 0, N) << '\n';
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) resuelveCaso();
	system("PAUSE");
}