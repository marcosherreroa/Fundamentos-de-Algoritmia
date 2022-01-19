//Marcos Herrero

#include <iostream>
#include <vector>
#include <string>


std::ostream &operator<<(std::ostream & flujo, std::vector<std::string> v ) {
	for (int i = 0; i < v.size(); ++i) {
		std::cout << v[i] << ' ';
	}

	std::cout << '\n';
	return flujo;
}

void mostrarTorres(int N, int R, int A, int V, std::vector<std::string> & torre, int nrojas, int nazules, int nverdes, bool & nosol) {
	if (N == 0 && nverdes+nazules < nrojas) {
		nosol = false;
		std::cout << torre;
	}

	else {

		if (A > 0 && nverdes + nazules + 1 < nrojas + R) {
		torre.push_back("azul");
		mostrarTorres(N - 1, R, A - 1, V, torre, nrojas, nazules + 1, nverdes, nosol);
		torre.pop_back();
		}


		if (R > 0) {
			torre.push_back("rojo");
			mostrarTorres(N - 1, R - 1, A, V, torre, nrojas + 1, nazules, nverdes, nosol);
			torre.pop_back();
		}

		if (V > 0 && torre[torre.size() - 1] != "verde" && nverdes < nazules && nverdes +nazules +1 < nrojas + R) {
			torre.push_back("verde");
			mostrarTorres(N - 1, R, A, V - 1, torre, nrojas, nazules, nverdes + 1, nosol);
			torre.pop_back();
		}


	}
	
}

bool resuelveCaso() {
	int N, R, A, V;
	std::cin >> N >> A >> R >> V;
	if (N == 0 && R == 0 && A == 0 && V == 0) return false;

	if (R == 0 && R+V+A < N) std::cout << "SIN SOLUCION\n\n";
	else {
		std::vector<std::string> torre = { "rojo" };
		bool nosol = true;
		mostrarTorres(N - 1, R - 1, A, V, torre, 1, 0 ,0 , nosol);
		if (nosol)std::cout << "SIN SOLUCION\n";
		std::cout << '\n';
	}

	return true;
}

int main() {
	int n;
	while (resuelveCaso());
	return 0;
}