//Marcos Herrero
#include <iostream>
#include <vector>

/*1.Especificación:
    {0<=p<=N-1}
	fun bienDividido(v[0,...,N-1] de ent, p:ent) dev b:bool
	{b= (for all j: p+1 <= j <= N-1 : (max i: 0<= i <= p : v[i]) < v[j]) }

  2.Verificación:
    I1:= 0<= n <= p && maxl = (max i: 0<= i <= n : v[i]) 
	C1:= p-n

	I2:= p<= n <= N-1 && maxl = (max i: 0<= i <= p : v[i]) && b= (for all j: p+1 <= j <= n : maxl < v[j])
	C2= N-1-n

     

*/

bool bienDividido(std::vector<int> const & v, int N, int p) {
	int n, maxl; bool b;

	n = 0;             //E1
	maxl = v[0];

	while (n < p) {
		if (v[n + 1] > maxl) maxl = v[n + 1];    //A1

		n = n + 1;                               //A2
	}

	b = true;             //E2

	while (n < N - 1) {
		b = b && maxl < v[n + 1];       //B1
		
		n = n + 1;                     //B2
	}

	return b;
}

void resuelveCaso(){
	int N, p;
	std::cin >> N >> p;

	std::vector<int> v(N);
	for (int i = 0; i < N; ++i) std::cin >> v[i];

	if (bienDividido(v,N, p))std::cout << "SI\n";
	else std::cout << "NO\n";
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) resuelveCaso();

	return 0;
}