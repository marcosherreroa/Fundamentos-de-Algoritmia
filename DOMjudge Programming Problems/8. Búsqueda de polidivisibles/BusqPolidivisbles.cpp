//Marcos Herrero

#include <iostream>
#include <vector>

/*
P:{0<N<10^18 && 0<D<=18 && es_polidivisible(N) && D >= numDigitos(N)}
fun polidivisible(N: ent, D: ent) dev v[0,...,M-1] de ent
Q:{ for all i: 0<= i <= M-1: pol(v[i], N , D) && for all i:( i>= 0 && pol(i, N ,D)): (exists j: 0<=j<=M-1: v[j]= i)} 

donde  numDigitos(N) = max i: i>= 1 && N/(10^(i-1)) > 0: i 
       es_polidivisible(N) = N>0 && for all i: 1<= i <= numDigitos(N) : (exists j: j>=1: N/10^(numdigitos(N)-i) = i*j)
	   pol(p, N, D) = es_polidivisible(p) && exists i: i>=0: p/10^N = q && numDigitos(p) <= D

En todos los casos recursivos con numdigits >= 9 se realizará, como mucho, una llamada recursiva, y todos los casos anteriores tienen coste constante, ya que este no aumenta al aumentar el tamaño del problema D-numdigits(N) . Además,
todas las instrucciones tienen coste constante y  el bucle realiza también un número constante de iteraciones. Por
tanto, podemos concluir que el coste del algoritmo es lineal.

*/

void polidivisible(std::vector<long long int> & v, long long int N, long long int D, long long int numdigits) {
	v.push_back(N);

	if(D-numdigits > 0) {
		for (int i = 0; i < 10; ++i){
			if ((10 * N + i) % (numdigits + 1) == 0) polidivisible(v, 10 * N + i , D, numdigits + 1);
		}
	}
}

bool resuelveCaso() {
	long long int N, D;
	std::cin >> N >> D;
	if (!std::cin) return false;

	long long int aux = N, numdigits = 0;
	while (aux != 0) {
		aux /= 10;
		++numdigits;
	}

	std::vector<long long int> v;
	polidivisible(v,N, D, numdigits);
	for (int i = 0; i < v.size(); ++i)std::cout << v[i] << '\n';
	std::cout << "---\n";
	return true;
}

int main() {
	while (resuelveCaso());
}