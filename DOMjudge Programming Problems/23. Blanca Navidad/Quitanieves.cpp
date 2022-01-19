//Marcos Herrero
#include <iostream>
#include <vector>

using tMatriz= std::vector<std::vector<int>>;


int estimacionSup(std::vector<int> const & anchMaquinas, std::vector<int> const & anchCarreteras, tMatriz const & mat, std::vector<bool> const & carreteras, int m, int n, int k, int suma) {
	std::vector<bool> aux = carreteras;
	int max, posmax;

	for (int i = k; i < m; ++i) {
		max = 0, posmax = 0;
		for (int j = 0; j < n; ++j) {
			if (!aux[j] && mat[i][j] > max) {
				max = mat[i][j];
				posmax = j;
			}	
			}

		suma += max;
		aux[posmax] = true;
		}

	return suma;
}

int calMax(std::vector<int> const & anchMaquinas, std::vector<int> const & anchCarreteras, tMatriz const & mat, std::vector<bool> & carreteras, int m, int n, int k, int suma, int cinf ) {
	if (k == m) return suma;
	else {
		int max;  bool sol;
		for (int i = 0; i < n; ++i) {
			if (!carreteras[i] && anchMaquinas[k] <= anchCarreteras[i]) {
				carreteras[i] = true;
				suma += mat[k][i];
				if (cinf < estimacionSup(anchMaquinas, anchCarreteras, mat, carreteras, m, n, k+1, suma)) {
					max = calMax(anchMaquinas, anchCarreteras, mat, carreteras, m, n, k + 1, suma, cinf);
					if (max > cinf) cinf = max;
				}
				carreteras[i] = false;
				suma -= mat[k][i];
			}
		}

		if (cinf < estimacionSup(anchMaquinas, anchCarreteras, mat, carreteras, m, n, k+1, suma)) {
			max = calMax(anchMaquinas, anchCarreteras, mat, carreteras, m, n, k + 1, suma, cinf);
			if (max > cinf) cinf = max;
		}

		return cinf;
	}
}

void resuelveCaso() {
	int m, n;
	std::cin >> m >> n;

	std::vector<int> anchMaquinas(m);
	for (int i = 0; i < m; ++i) std::cin >> anchMaquinas[i];

	std::vector<int> anchCarreteras(n);
	for (int i = 0; i < n; ++i) std::cin >> anchCarreteras[i];

	tMatriz calidades(m, std::vector<int>(n));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cin >> calidades[i][j];
		}
	}
	std::vector<bool> carreteras(n, false);

	std::cout << calMax(anchMaquinas, anchCarreteras, calidades, carreteras,m,n, 0, 0, 0) << '\n';
	
}

int main() {
	int n; 
	std::cin >> n;
	for (int i = 0; i < n; ++i) resuelveCaso();
	system("PAUSE");
}