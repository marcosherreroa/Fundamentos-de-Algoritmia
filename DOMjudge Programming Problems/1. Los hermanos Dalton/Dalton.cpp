//Marcos Herrero

#include <iostream>
#include <vector>

/* 1.Especificación:
     {N>0}
	 fun Dalton(v[0,...,N-1] de ent) dev b: bool
	 {b= (for all i,j: 0<=i < j <=N-1 : v[i]<v[j]) || ( for all i,j: 0<=i<j<=N-1: v[i] > v[j])}
   
   2.Verificación:
	 I:= {0<= n <= N-1 && crec = (for all i,j: 0<=i < j <=n : v[i]<v[j]) && decrec = ( for all i,j: 0<=i<j<=n: v[i] > v[j])}
	 C= N-1-n
     

*/



bool Dalton(std::vector<int> const & v, int N) {
	bool b , crec, decrec;
	int n;

	n = 0;          //E1
	crec = true;
	decrec = true;  

	while (n < N-1) {
		crec = crec && v[n] < v[n+1];     //A1
		decrec = decrec && v[n] > v[n+1];

		n = n + 1;       //A2
	}

	b = crec || decrec;  //E2

	return b;
}

bool resuelveCaso() {
	int N;
	std::cin >> N;

	if (N == 0) return false;

	std::vector<int> v(N);
	for (int i = 0; i < N; ++i) std::cin >> v[i];

	if (Dalton(v,N)) std::cout << "DALTON\n";
	else std::cout << "DESCONOCIDOS\n";

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}