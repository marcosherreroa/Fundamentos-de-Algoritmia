//Belén Sánchez
//Marcos Herrero

#include <iostream>
#include <vector>

using tMatriz = std::vector<std::vector<bool>>;

int reinasTorres(int N, int T, int R, int suma, tMatriz const & matriz, std::vector<bool> & cols,
	std::vector<bool> & diagasc, std::vector<bool> & diagdesc, std::vector<bool> & diagtasc, std::vector<bool> & diagtdesc) {
	if (suma == 0) return 1;
	else {
		int formas = 0;

		for (int i = 0; i < N; ++i) {
			if (!cols[i] && !diagasc[i + N - suma] && !diagdesc[2 * N - suma - i - 1] && matriz[N - suma][i] && 
				   !diagtasc[i + N - suma] && !diagtdesc[2 * N - suma - i - 1] && R > 0) {
				cols[i] = true;
				diagasc[i + N - suma] = true;
				diagdesc[2 * N - suma - i - 1] = true;
				formas += reinasTorres(N, T, R - 1, suma - 1, matriz, cols, diagasc, diagdesc, diagtasc, diagtdesc);
				cols[i] = false;
				diagasc[i + N - suma] = false;
				diagdesc[2 * N - suma - i - 1] = false;
			}

			if (!cols[i] && !diagasc[i + N - suma] && !diagdesc[2 * N - suma - i - 1] && matriz[N - suma][i] && T > 0) {
				cols[i] = true;
				bool cambiadoAsc = false, cambiadoDesc = false;
				if (!diagtasc[i + N - suma]) {
					diagtasc[i + N - suma] = true;
					cambiadoAsc = true;
				}

				if (!diagtdesc[2 * N - suma - i - 1]) {
					diagtdesc[2 * N - suma - i - 1] = true;
					cambiadoDesc = true;
				}

				formas += reinasTorres(N, T - 1, R, suma - 1, matriz, cols, diagasc, diagdesc, diagtasc, diagtdesc);
				cols[i] = false;
				if(cambiadoAsc) diagtasc[i + N - suma] = false;
				if(cambiadoDesc) diagtdesc[2 * N - suma - i - 1] = false;
			}
		}

		return formas;
	}
}

bool resuelveCaso() {
	int T, R, N;
	std::cin >> T >> R >> N;

	if (!std::cin) return false;
	
	tMatriz matriz(T + R, std::vector<bool>(T + R, true));
	int x, y;
	for (int i = 0; i < N; ++i) {
		std::cin >> x >> y;
		matriz[x-1][y-1] = false;
	}
	std::vector<bool> cols(T + R);
	std::vector<bool> diagasc(2 * (T + R) - 1);
	std::vector<bool> diagdesc(2 * (T + R) - 1);
	std::vector<bool> diagtasc(2 * (T + R) - 1);
	std::vector<bool> diagtdesc(2 * (T + R) - 1);
	std::cout << reinasTorres(T+R, T, R, T+R, matriz, cols, diagasc, diagdesc, diagtasc, diagtdesc)<<'\n' ;

	return true;
}

int main() {
	while (resuelveCaso());
}