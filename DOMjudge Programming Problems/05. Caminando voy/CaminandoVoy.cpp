//Marcos Herrero
#include <iostream>
#include <vector>

/*
Precondición = {0<=D<=1000000 && 0<N<200000 && for all i:0<= i <= N-1: 0 < v[i] < 1000000  0 && N > 0}
                fun apto(v[0,..,N-1] de ent, D: ent) dev b: bool
Postcondición = {b= (D >= max i,j: 0<= i <= j <= N-1 && crec (i,j) : v[j] - v[i])}
 donde crec(i,j) = for all k: i<= k <= j-1: v[k] < v[k+1]

I:= 0 <= n <= N &&  m =  max i,j: 0<= i <= j <= n-1 && crec(i,j): v[j] - v[i] &&
    ini = min i: 0 <= i <= n-1: crec(i, n-1)
B:= n < N
C= N-n

El orden de complejidad es lineal porque el bucle da N iteraciones y todas las instrucciones tienen coste constante.
*/


bool apto(std::vector<int> & v, int N, int D) {
	int n, m, ini,b;

	n = 1;
	m = 0;
	ini = 0;

	while (n < N) {
		if (v[n - 1] >= v[n]) ini = n;
		else if (v[n]-v[ini] > m) m = v[n]-v[ini];
	
		n = n + 1;
	}

	b = D >= m;

	return b;
}

bool resuelveCaso() {
	int D, N;
	
	std::cin >> D >> N;

	if (!std::cin) return false;

	std::vector<int> v(N);
	for (int i = 0; i < N; ++i) std::cin >> v[i];

	if (apto(v, N, D)) std::cout << "APTA\n";
	else std::cout << "NO APTA\n";
	return true;
}

int main() {
	while (resuelveCaso());

	return 0;
}