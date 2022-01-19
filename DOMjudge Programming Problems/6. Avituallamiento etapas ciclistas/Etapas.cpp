//Marcos Herrero

#include <iostream>
#include <vector>
/*
P:{N > 1 && sum i: 0<= i <= N-1: v[i] < 100000}
  fun maxkilometrosLlanos(v[0,...,N-1]) de ent) dev m: ent
Q:{m = (max i,j: (0<=i<=j<=N-1 && (for all k: i<=k <= j-1: v[k] = v[k+1]) ) : j-i)}

I:= 0 <= n <= N && m = (max i,j: (0<=i<=j<=n-1 && (for all k: i<=k <= j-1: v[k] = v[k+1]) ) : j-i) &&
    ini = min i: 0<= i <=n-1 && (for all k: i<=k <= n-2): n-1-i
B:= n < N
C = N-n
R:= 0 <= n <= N && m = (max i,j: (0<=i<=j<=n-1 && (for all k: i<=k <= j-1: v[k] = v[k+1]) ) : j-i)

*/

int maxkilometrosLlanos(std::vector <int> & v, int N) {
	int n, m, ini;

	n = 1;
	m = 0;
	ini = 0;

	while (n < N) {
		if (v[n] != v[n - 1]) ini = n;
		if (n - ini > m ) m = n -ini;

		n = n + 1;
	  }

	return m;
}

bool resuelveCaso() {
	std::vector<int> v;

	int read;
	std::cin >> read;
	while (read != -1) {
		v.push_back(read);
		std::cin >> read;
	}

	if (v.size() == 0) return false;
	
	int sol = maxkilometrosLlanos(v, v.size());
	if (sol == 0) std::cout << "HOY NO COMEN\n";
	else std::cout << sol <<'\n';

	return true;
}

int main() {
	while (resuelveCaso());
}
