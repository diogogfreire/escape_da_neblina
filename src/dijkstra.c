#include "../include/no.h"
#include "../include/graph.h"
#include "../include/fila_prioridade.h"
#include "../include/dijkstra.h"

#define INFINITO 0x3f3f3f3f

static void setarInfinito(double* vetor, int n)
{
	for(int i = 0; i < n; i++)
	{
		vetor[i] = INFINITO;
	}
}

static void iterarSobreVizinhos(Lista* lista, Heap* fila)
{
	No* aux = lista->primeiro;
	No* vizinho;
	double d;
	double v;

	while(aux->proximo != NULL)
	{
		d = getDistancia(aux);
		v = getVertice(aux);
		inserirNoHeap(fila, d, v);
		aux = aux->proximo;
	}
}

Caminho dijkstra(Grafo *g, int v)
{
	Heap* fila;
	Lista* vertice = vizinhosVertice(g, v);
	No* vizinho;
	No raiz;
	int tam = getTamanhoLista(vertice);
	int n = quantidadeVertices(g);
	int i, j = 0;
	int raiz_d, raiz_v;
	double* distancias = (double*) malloc(sizeof(double) * n);

	setarInfinito();

	// Adicionar os vizinhos de 'v' no Heap
	while(i < tam) //Nao é uma boa maneira de iterar
	{
		vizinho = get(vertice, i);	
		inserirNoHeap(fila, 0, vizinho);
		i++;
	}

	while(!empty(fila))
	{
		raiz = removeNoHeap(fila);
		raiz_d = getDistancia(raiz);
	       	raiz_v = getVertice(raiz);	

		if(distancias[raiz_v] <= raiz_d) continue;

		distancias[raiz_v] = raiz_d;

		vertice = vizinhosVertice(g, raiz_v);
		vizinho = get(vertice, );
		
		for()
		{

		}
	}

	get


}


