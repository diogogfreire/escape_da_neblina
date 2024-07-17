#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios::sync_with_stdio(0);cin.tie(0);

#include <iostream>
#include <algorithm> 
#include <queue>
#include <utility>

using namespace std;

const int INF = 0x3f3f3f3f;
int n, m, q;

typedef pair<int, int> Aresta;
typedef vector< vector<Aresta> > Grafo;

vector<int> dijkstra(Grafo &g, vector<int> vertices)
{
	priority_queue< Aresta > fila;

	for(int v : vertices)
	{
		fila.push({-0, v - 1}); // Caso dele onde os vertices sao dados de 1 ate n ?				
	}

	vector<int> dist(n, INF);

	while(fila.empty() != 1) //Enquanto a fila nao estiver vazia
	{
		int w = -fila.top().f;
		int u = fila.top().s;
		fila.pop();

		if(dist[u] <= w) continue;

		/*
		if(u == destino) 
		{
			dist[0] = w;
			return dist; // Distancia ate um vertice especifico
		}
		*/

		dist[u] = w;
		for(auto [v, n_w]: g[u])
		{
			if(dist[v] > w + n_w) fila.push({-(w + n_w), v});
		}
	}

	return dist;
}

void insereAresta(Grafo &g, int a, int b, int w) // a e b são vertices, w distancia
{
	a--; b--; // caso dele onde os vertices sao dados de 1 ate n
	g[a].push_back({b, w}); // insere ab
	g[b].push_back({a, w}); // insere ba
}

void solveAmb() // Funcao que resolve o problema das ambulancias
{
	Grafo grp = Grafo(n, vector<Aresta>());

	for(int i = 0; i < m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		insereAresta(grp, a, b, w);
	}

	vector<int> hospitais(q);

	for(int &i : hospitais) cin >> i;

	vector<int> dist = dijkstra(grp, hospitais);

	int ans = -1;
	for(int x : dist) ans = max(ans, x);
	cout << ans << endl;
}

int main()
{_
	while(cin >> n >> m >> q)
	{
		solveAmb();
	}

}







