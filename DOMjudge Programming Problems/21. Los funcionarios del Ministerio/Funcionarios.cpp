//Marcos Herrero
#include <iostream>
#include <vector>

using tMatriz = std::vector<std::vector<int>>;

int estimacionInf(tMatriz const & mat, int N, int k, int suma, std::vector<bool> const & tareas) {
	int min, posmin;
	for (int i = k; i < N; ++i) {
		int r = 0;
		while (tareas[r])++r;
		min = mat[i][r];
		for (int j = r + 1; j < N; ++j) {
			if (!tareas[j] && mat[i][j] < min) {
				min = mat[i][j];
				posmin = j;
			}
		}

		suma += min;
	}

	return suma;
}


int minTiempos(tMatriz const & mat, int N, int k, std::vector<bool> & tareas, int suma, int csup) {
	if (k == N) return suma;
	else {
		int min;
		for (int i = 0; i < N; ++i) {
			if (!tareas[i]) {
				tareas[i] = true;
				suma += mat[k][i];
				if (csup > estimacionInf(mat, N, k + 1, suma, tareas)) {
					min = minTiempos(mat, N, k + 1, tareas, suma, csup);
					if (min < csup) csup = min;
				}
				suma -= mat[k][i];
				tareas[i] = false;
			}
		}

		return csup;
	}
}


bool resuelveCaso() {
	int N;
	std::cin >> N;
	
	if (N == 0) return false;

	tMatriz mat(N, std::vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cin >> mat[i][j];
		}
	}

	std::vector<bool> tareas(N, false);
	int csup = 0, min, posmin;
	for (int i = 0; i < N; ++i){
		int k = 0;
		while (tareas[k])++k;
		min = mat[i][k];
		posmin = k;
		for (int j = k+1; j < N; ++j) {
			if (!tareas[j] && mat[i][j] < min) {
				min = mat[i][j];
				posmin = j;
			}
		}
		csup += min;
		tareas[posmin] = true;
	}

	for (int i = 0; i < N; ++i)tareas[i] = false;

	std::cout << minTiempos(mat,N,0,tareas,0,csup) << '\n';
	
	return true;
}

int main() {
	while (resuelveCaso());
}