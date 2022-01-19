//Marcos Herrero

#include <iostream>
#include <vector>

using tMatriz = std::vector<std::vector<int>>;

int estimacionInf(tMatriz const & mat, int m, int n, int k, std::vector<int> const & sup, int suma) {
	int min;
	for (int i = k; i < n; ++i) {
		int k = 0;
		while (sup[k] >= 3)++k;
		min = mat[k][i];
		for (int j = 0; j < m; ++j) {
			if (mat[j][i] < min && sup[j] < 3) min = mat[j][i];
		}
		suma += min;
	}

	return suma;
}

int  minPrecio(tMatriz const & mat, int m, int n, int k, std::vector<int> & sup, int suma, int csup) {
	if (k == n) return suma;
	else {
		bool sol = false; int min;
		for (int i = 0; i < m; ++i) {
			if (sup[i] < 3) {
				++sup[i];
				suma += mat[i][k];
				if (csup > estimacionInf(mat,m,n,k+1,sup,suma) ) {
					min = minPrecio(mat, m, n, k + 1, sup, suma, csup);
					if (min < csup) csup = min;
				}
				suma -= mat[i][k];
				--sup[i];
			}
		}

		return csup;
	}
}

void resuelveCaso() {
	int m, n;
	std::cin >> m >> n;

	tMatriz mat(m, std::vector<int>(n));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cin >> mat[i][j];
		}
	}

	std::vector<int> sup(m,0);
	int min, posmin, csup= 0;
	for (int i = 0; i < n; ++i) {
		int k = 0;
		while (sup[k] >= 3)++k;
		min = mat[k][i];
		posmin = k;
		for (int j = k+1; j < m; ++j) {
			if (sup[j] < 3 && mat[j][i] < min) {
				min = mat[j][i];
				posmin = j;
			}
		}

		csup += min;
		++sup[posmin];
	}
	
	for (int i = 0; i < m; ++i) sup[i] = 0;
	std::cout<< minPrecio(mat,m,n,0,sup,0 , csup)<< '\n';
	
}
  

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)resuelveCaso();
	system("PAUSE");
}