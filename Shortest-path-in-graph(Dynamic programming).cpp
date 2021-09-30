#include <iostream>
#include <vector>
using namespace std;

#define INF 1000000000;
#define MAX 100;
int i, j, n=0, m, V_start, V_end, weight, w, C[MAX][MAX], p[MAX], d[MAX], Min, counterr = 0;
int used[MAX];
vector <int> G[MAX];
int final_array[MAX];


void Spisuk_ot_Susedi() {
	cout << "Enter number of V: ";
	cin >> n;

	cout << "Enter number of ribs: ";
	cin >> m;

	int v1, v2;

	for (i = 1; i <= n; i++) {
		G[i].push_back(0);
	}

	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			C[i][j] = INF;


	for (i = 0; i < m; i++) {
		cout << "Enter rib number " << i + 1 << ": " << endl;
		cin >> v1;
		cin >> v2;
		cout << "Enter weight of the rib: ";
		cin >> weight;

		G[v1].push_back(v2);
		G[v1].at(0) += 1;

		C[v1][v2] = weight;
	}
}


int nai_kus_put(int v) {
	if (V_start == V_end || v == V_start - 1)
		return 0;
	else if (v == V_end) {
		for (i = v; i >= 1; i--) {
			p[i] = v; d[i] = INF;
		}
		d[v] = p[v] = 0;
		return nai_kus_put(v - 1);
	}
	else {
		for (j = 1; j <= G[v][0]; j++) {
			w = G[v][j];
			if (d[w] + C[v][w] < d[v] && G[v][0] != 0) {
				d[v] = d[w] + C[v][w]; p[v] = w;
			}
		}
		return nai_kus_put(v - 1);
	}
}



void gen(int vruh) {
	if (G[vruh][0] > 0) {
		final_array[counterr++] = vruh;
		Min = G[vruh][1];
		for (i = 1; i <= G[vruh][0]; i++) {
			if (d[G[vruh][i]] < d[Min]) {
				Min = G[vruh][i];
			}
		}
		if(Min != V_end)
			gen(Min);
		else {
			final_array[counterr++] = V_end;
		}
	}
}


int main()
{
	Spisuk_ot_Susedi();
	cout << "Enter start V: ";
	cin >> V_start;
	cout << "Enter end V: ";
	cin >> V_end;

	nai_kus_put(V_end);
	gen(V_start);

	for (i = 0; i < counterr; i++)
	{
		cout << final_array[i] << " ";
	}
	cout << endl;



	return 0;
}

