//Marcos Herrero
#include <iostream>
#include <vector>


/* 
   1.Especificación:
   {N>0}
   fun picos(v[0,...,N-1] de ent)dev: picos: ent
   {picos= #i: 1<= i <= N-2: v[i-1]<v[i] && v[i+1]<v[i]}

   2. Derivación:
   B:= n < N-2
   I:= 0 <= n <= max{0, N-2} && picos= #i: 1<= i <= n: v[i-1]<v[i] && v[i+1]<v[i]
   C:= N-n-1

   R:= pmd(A2, I)<-> 0 <= n+1 <=N-2 && picos= #i: 1<= i <= n+1: v[i-1]<v[i] && v[i+1]<v[i]
*/

int picos(std::vector<int> const & v, int N) {
	int n, picos;

	n = 0;
	picos = 0;    //A0

	while (n < N - 2) {
		if (v[n] < v[n + 1] && v[n + 2] < v[n + 1]) ++picos;

		n = n + 1;    //A2
	}

	return picos;
}

/*
   1.Especificación:
   {N>0}
   fun valles(v[0,...,N-1] de ent)dev: valles: ent
   {valles= #i: 1<= i <= N-2: v[i-1]>v[i] && v[i+1]>v[i]}

   2. Derivación:
   B:= n < N-2
   I:= 0 <= n <= max{0, N-2} && valles= #i: 1<= i <= n: v[i-1]>v[i] && v[i+1]>v[i]
   C:= N-n-1

   R:= pmd(A2, I)<-> 0 <= n+1 <=N-2 && picos= #i: 1<= i <= n+1: v[i-1]>v[i] && v[i+1]>v[i]
*/

int valles(std::vector<int> const & v, int N) {
	int n, valles;

	n = 0;
	valles = 0;    //A0

	while (n < N - 2) {
		if (v[n] > v[n + 1] && v[n + 2] > v[n + 1]) ++valles;

		n = n + 1;    //A2
	}

	return valles;
}

void resuelveCaso() {
	int N;
	std::cin >> N;

	std::vector<int> v(N);;

	for (int i = 0; i < N; ++i) std::cin >> v[i];

	std::cout << picos(v,v.size()) << ' ' << valles(v,v.size()) << '\n';


}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) resuelveCaso();
	system("PAUSE");
}