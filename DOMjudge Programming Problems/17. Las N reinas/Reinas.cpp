//Marcos Herrero

#include <iostream>
#include <vector>

int reinas(int N, int r, std::vector<bool> & cols, std::vector<bool> & diagasc, std::vector<bool> & diagdesc) {
	if (r == 0) return 1;
	else {

		int formas = 0;

		for (int i = 0; i < N; ++i) {
			if (!cols[i] && !diagasc[i + N- r] && !diagdesc[2*N - r -i -1]) {
				cols[i] = true;
				diagasc[i + N - r] = true;
				diagdesc[2*N - r - i - 1] = true;
				formas += reinas(N, r - 1, cols, diagasc, diagdesc);
				cols[i] = false;
				diagasc[i + N - r] = false;
				diagdesc[2*N - r- i - 1] = false;
			}
		}

		return formas;
	}
}

void resuelveCaso() {
	int N;
	std::cin >> N;

	std::vector<bool> cols(N, false);
	std::vector<bool> diagasc(2 * N - 1, false);
	std::vector<bool> diagdesc(2 * N - 1, false);
	std::cout << reinas(N, N, cols, diagasc, diagdesc)<<'\n';
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
	return 0;
}