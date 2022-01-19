//Marcos Herrero
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

struct tPar {
	float duracion;
	float puntuacion;
};

std::istream &operator>>(std::istream & flujo, tPar & par) {
	flujo >> par.duracion >> par.puntuacion;
	return flujo;
}

struct ord {
	bool operator()(tPar par1, tPar par2) {
		return par1.puntuacion / par1.duracion > par2.puntuacion / par2.duracion;
	}
};

float estimacionSup(std::vector<tPar> const & cancion, int N, int k, float puntuacion, float cint1, float cint2) {
	while (cint1 > 0 && k < N) {
		if (cancion[k].duracion <= cint1) {
			cint1 -= cancion[k].duracion;
			puntuacion += cancion[k].puntuacion;
			++k;
		}

		else if (cint2 >= (cancion[k].duracion - cint1)) {
			cint2 -= (cancion[k].duracion - cint1);
			cint1 = 0;
			puntuacion += cancion[k].puntuacion;
			++k;
		}
		else {
			puntuacion += cancion[k].puntuacion * (cint1 + cint2) / cancion[k].duracion;
			cint1 = 0;
			cint2 = 0;
		}
	}

	while (cint2 > 0 && k < N) {
		if (cancion[k].duracion <= cint2) {
			cint2 -= cancion[k].duracion;
			puntuacion += cancion[k].puntuacion;
			++k;
		}
		else {
			puntuacion += cancion[k].puntuacion * cint2 / cancion[k].duracion;
			cint2 = 0;
		}

	}

	return puntuacion;
}


int puntMax(std::vector<tPar> const & cancion, int N, int k, int puntuacion, float cint1, float cint2, int cinf) {
	if (k == N) return puntuacion;
	else {
		int max;

		if (cancion[k].duracion <= cint1) {
			puntuacion += cancion[k].puntuacion;
			cint1 -= cancion[k].duracion;
			max = puntMax(cancion, N, k + 1, puntuacion, cint1, cint2, cinf);
			if (max > cinf) cinf = max;
			puntuacion -= cancion[k].puntuacion;
			cint1 += cancion[k].duracion;
		}

		if (cancion[k].duracion <= cint2) {
			puntuacion += cancion[k].puntuacion;
			cint2 -= cancion[k].duracion;
			max = puntMax(cancion, N, k + 1, puntuacion, cint1, cint2, cinf);
			if (max > cinf) cinf = max;
			puntuacion -= cancion[k].puntuacion;
			cint2 += cancion[k].duracion;
		}

		if (cinf < estimacionSup(cancion, N, k + 1, puntuacion, cint1, cint2)) {
			max = puntMax(cancion, N, k + 1, puntuacion, cint1, cint2, cinf);
			if (max > cinf) cinf = max;
		}

		return cinf;
	}
}

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N == 0) return false;
	int cint1, cint2;
	std::cin >> cint1;
	cint2 = cint1;
	std::vector<tPar> cancion(N);

	for (int i = 0; i < N; ++i) {
		std::cin >> cancion[i];
	}

	std::sort(cancion.begin(), cancion.end(), ord());
	std::cout << puntMax(cancion, N, 0, 0.0 , cint1, cint2, 0) << '\n';
	

	return true;
}

int main() {
	while (resuelveCaso());
}