//Marcos Herrero

#include <iostream>
#include <vector>

/* 
   1.Especificación:
    
   P:= {N>0}
   proc maxmin( v[0,...N-1] de ent, S min: ent, S nummin: ent, S max: ent, S nummax: ent) 
   Q:={ m= min i: 0<= i <= N-1: v[i] && nummin = # i: 0<= i <= N-1: v[i]= m && 
       M= max i: 0<= i <= N-1: v[i] && nummax = #i: 0<= i <= N-1 : v[i] = M} 
   

   2. Derivación:

   B:= n < N-1;     C:= N-n-1
   I:= 0<=n <= N-1 && min= min i: 0<= i <= n: v[i] && nummin = # i: 0<= i <= n: v[i]= min &&
        max= max i: 0<= i <= n: v[i] && nummax = #i: 0<= i <= n : v[i] = max


   A0:= 
   A2:= n = n+1

   R:= pmd(A2, I) <=> 0<= n+1 <= N-1 && min= min i: 0<= i <= n+1: v[i] && nummin = # i: 0<= i <= n+1: v[i]= min &&
        max= max i: 0<= i <= n+1: v[i] && nummax = #i: 0<= i <= n+1 : v[i] = max
*/

void maxmin(std::vector<long long int> const & v, long long int N, long long int & min, long long int & nummin,
	long long int & max, long long int & nummax) {
	int n;

	n = 0;
	min = v[0];
	nummin = 1;   //A0
	max = v[0];
	nummax = 1;

	while (n < N - 1) {
		if (v[n + 1] < min) {
			min = v[n + 1];
			nummin = 1;
		}
		else if (v[n + 1] == min) ++nummin;  //A1

		if (v[n + 1] > max) {
			max = v[n + 1];
			nummax = 1;
		}
		else if (v[n + 1] == max) ++nummax;

		n = n + 1;   //A2
	}
}

void resuelveCaso() {
	std::vector<long long int> v;

	long long int cent;
	std::cin >> cent;
	for (int i = 0; cent != 0 && i < 10000;) {
		v.push_back(cent);
		std::cin >> cent;
	}

	long long int min, nummin = 0, max, nummax;
	maxmin(v, v.size(), min, nummin, max, nummax);

	std::cout << min << ' ' << nummin << ' ' << max << ' ' << nummax << '\n';


}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) resuelveCaso();
	system("PAUSE");
}