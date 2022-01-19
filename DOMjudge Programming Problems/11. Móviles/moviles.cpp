//Marcos Herrero y María Juberías

#include <iostream>

/*

El coste de todas las instrucciones, salvo llamadas, es constante. En el caso peor, se hacen dos llamadas recursivas,
pero la suma de los tamaños de los subproblemas es menor o igual que el tamaño del problema. Por tanto, 
el coste del algoritmo es lineal


*/

bool equilibrado(int & peso) {
	int pi, di, pd, dd;
	std::cin >> pi >> di >> pd >> dd;

	peso = pi + pd;
	if (pi != 0 && pd != 0 && pi * di != pd * dd) return false;
	else if (pi != 0 && pd != 0 && pi*di == pd * dd) return true;

	else if (pi == 0 && pd != 0 ) {
		bool OK = equilibrado(pi);
		peso += pi;
		return OK && pi*di == pd * dd;
	}

	else if (pi != 0 && pd == 0) {
		bool OK = equilibrado(pd);
		peso += pd;
		return OK && pi*di == pd * dd;
	}

	else {
		bool OK1 = equilibrado(pi);
		bool OK2 = equilibrado(pd);
		peso = peso + pd + pi;
		return OK1 && OK2 && pi*di == pd * dd;
	}
}

void resuelveCaso() {
	int peso;
	if(equilibrado(peso)) std::cout << "SI\n";
	else std::cout << "NO\n";
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) resuelveCaso();
	system("PAUSE");
	return 0;
}