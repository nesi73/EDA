//Inés Prieto Centeno

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100000
using lli = long long int;

lli merge(int V[], int W[], int A[], int N, int M)
{
	int n = 0, m = 0, i = 0;

	lli inversiones = 0;

	while (i < N + M)
	{
		if (n >= N)
		{
			A[i] = W[m];
			m++;
		}
		else if (m >= M || V[n] <= W[m])
		{
			A[i] = V[n];
			n++;
		}
		else
		{
			inversiones += m + N - i;
			A[i] = W[m];
			m++;
		}


		i++;
	}

	return inversiones;
}

lli mergesortG(int V[], int ini, int fin)
{
	if (fin - ini <= 1)
	{
		return 0;
	}

	int m = (ini + fin) / 2;
	int V1[MAX], V2[MAX];
	lli inversiones = 0;
	for (int i = 0; i < m - ini; i++)
	{
		V1[i] = V[ini + i];
	}
	for (int i = 0; i < fin - m; i++)
	{
		V2[i] = V[m + i];
	}
	inversiones = mergesortG(V1, 0, m - ini);
	inversiones += mergesortG(V2, 0, fin - m);

	inversiones += merge(V1, V2, V, m - ini, fin - m);

	return inversiones;
}//O(n/2) + O(n/2) + 2 llamadas recursivas por la mitad + O(n) = O(nlogn)

lli mergesort(int V[], int N)
{
	return mergesortG(V, 0, N);
}

int main(int argc, char **args)
{
	int V[MAX];
	int N, C;
	cin >> C;

	for (int c = 0; c < C; c++)
	{
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			cin >> V[i];
		}

		cout << mergesort(V, N) << endl;

	}

	return 0;
}
