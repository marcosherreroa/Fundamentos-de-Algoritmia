
#include <iostream>
#include <vector>
/*
P={N>0 && exists i: 0<=i<=N-1: v[i]>D}
  fun rescate(v[0,...,N-1] de ent, D:ent) dev <p,q>: ent
Q={ 0<=p<=q<=N-1 &&   q+1-p = max i,j: 0<=i<=j<=N-1 && H(i,j): j+1-i && 
     && p= min i: 0<= i<= N-1 && (exists j: i<= j<= N-1 && H(i,j) :  j+1-i = q+1-p): i}

	donde H(i,j) = for all k: i<=k<= j: v[k] > D

I:= 0<= n <= N &&  exists i: 0<=i<=N-1: v[i]>D && 0<=p<=q+1<=n &&   (q+1-p = max i,j: 0<=i<=j+1<=n && H(i,j): j+1-i) &&
    (n-c = max i: 0<= i <=  n && H(i,n-1):n-i)  
	&& p= min i: 0<= i<= n-1 && (exists j: i<= j<= n-1 && H(i,j) :  j+1-i = q+1-p): i

B:= n < N
C= N-n

Avanzar : n = n+1;
R=: 0<= n+1 <= N &&  exists i: 0<=i<=N-1: v[i]>D && 0<=p<=q+1<=n &&   (q+1-p = max i,j: 0<=i<=j+1<=n && H(i,j): j+1-i) && 
 && (n+1-c = max i: 0<= i <=  n+1 && H(c,n):n+1-i) && p= min i: 1<= i<= n && (exists j: i<= j<= n && H(i,j) :  j+1-i = r): i

Reestablecer:
   max i: 0<= i <= n+1 && H(c,n): n+1-i=
   Si v[n] > D -> = n+1-c , c se queda como está
   cc -> = 0, c=n+1

	max i,j: 0<=i<=j+1<=n+1 && H(i,j): j+1-i
	Si v[n]> D -> = max{q+1-p , max i: 0<= i <= n+1 && H(i,n): n+1-i}= max{q+1-p, n+1-c}
	en cc -> = max i,j: 0<= i<= j+1 <= n-1 && H(i,j): j+1-i = q+1-p

---------------------------------------------------------	
Q={ 0<=p<=q<=N-1 && r = max i,j: 0<=i<=j<=N-1 && H(i,j):j+1-i && q+1-p = r &&
	q = 0min i: 0<= i <= N-1 && exists j: 0<=j<=i+1 && H(j,i):r= i+1-j: i}

I:= 0<=n<=N && exists i: 0<=i<=N-1: v[i]>D && r= max i,j: 0<=i<=j+1<=n && H(i,j-1):j+1-i &&
   s= max i:0<=i<=n && H(i,n-1): n-i  && q = min i: 0<= i <= n && exists j: 0<=j<=i+1 & H(j,i):r= i+1-j: i}

B: n<N
    max i: 0<=i<=n+1 && H(i,n):n+1-i
	Si v[n]> D -> = s+1
	cc -> = 0

    max i,j: 0<=i<=j+1<=n+1 && H(i,j): j+1-i
	= max{r, max i: 0<=i<=n+1 && H(i,n): n+1-i} = max{r,s}
	cc -> = r
*/

void ruta(std::vector<int> v , int N, int D, int & p, int & q) {
	int n, r, s;

	n = 0;
	q = 0;
	r = 0;
	s = 0;

	
	while (n < N) {
		if (v[n] > D) s = s+1;
		else s = 0;
		
		if (s > r) {
			r = s;
			q = n;
		}

		n = n + 1;
	}

	p = q + 1 - r;
}


void resuelveCaso() {
	int N, D;
	std::cin >> N >> D;

	std::vector<int> v(N);
	for (int i = 0; i < N; ++i) std::cin >> v[i];

	int p, q;
	ruta(v, N, D, p, q);
	std::cout << p <<' '<< q<<'\n';

}

int  main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) resuelveCaso();
	system("PAUSE");
}