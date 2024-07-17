#include "../include/no.h"
#include "../include/lista_encadeada.h"
#include "../include/graph.h"
#include "../include/fila_prioridade.h"

#include "math.h"
#include "stdio.h"
#include "stdlib.h"

#define MAX 100000
#define ENDL "\n"

void testeHeap()
{
	int n = 0;
	printf("Teste no heap\n");

	printf("Insira a quantidade de elementos no Heap: ");
	scanf("%d", &n);
	n = 5;

	Heap* heap = criarHeap(n);
	inserirNoHeap(heap, 10, 5);
	inserirNoHeap(heap, 2, 6);
	inserirNoHeap(heap, 1, 1);
	inserirNoHeap(heap, 10, 6);
	inserirNoHeap(heap, -1, 48);

	Heap* heap2 = criarHeap(7);
	inserirNoHeap(heap2, 23, 0);
	inserirNoHeap(heap2, 21, 0);
	inserirNoHeap(heap2, 9, 0);
	inserirNoHeap(heap2, 13, 0);
	inserirNoHeap(heap2, 15, 0);
	inserirNoHeap(heap2, 8, 0);
	inserirNoHeap(heap2, 2, 0);

	Heap* heap3 = criarHeap(3);
	inserirNoHeap(heap3, 5, 10);
	inserirNoHeap(heap3, 10, 3);
	inserirNoHeap(heap3, 5, -1);

	Heap* heap4 = criarHeap(3);
	inserirNoHeap(heap4, -15, 10);
      	inserirNoHeap(heap4, -10, 3);
      	inserirNoHeap(heap4, -1, -1);

	puts("heap1:");
	imprimirHeap(heap);

	puts("heap2");
	imprimirHeap(heap2);

	puts("heap3");
	imprimirHeap(heap3);

	puts("heap4");
	imprimirHeap(heap4);

	puts("heap2 - remocao");
	while(!empty(heap2))
	{
		No raiz = removeNoHeap(heap2);

		imprimirHeap(heap2);
	}

	puts("destuir heaps");
	destruirHeap(heap);
	destruirHeap(heap2);
	destruirHeap(heap3);
	destruirHeap(heap4);	
}

void testeVertices()
{
	int n, v, e;
	puts("Teste grafos\n"); 
	puts("Passos: 1- inserir vertices\n 2- imprimir grafo\n 3- Inserir arestas\n 4- imprimir grafo\n 5- deletar grafo\n 6- imprimir grafoi\n ");

	printf("digite a quantidade de vertices: ");
	scanf("%d", &n);
	Grafo* g = novoGrafo();
	n = 5;

	for(int i = 0; i < n; i++)
	{
		insereVertice(g);
	}

	puts("Passo 2 - Imprimir grafo");
	imprimeGrafo(g);

	puts("Passo 3 - Inserir arestas");
	insereAresta(g, 0, 1, 1);
	insereAresta(g, 0, 0, 2);
	insereAresta(g, 0, 1, 3);
	insereAresta(g, 1, 10.198, 4);
	insereAresta(g, 2, 10, 4);
	insereAresta(g, 3, 0, 4);

	puts("Passo 4 - Imprimir grafo");
	imprimeGrafo(g);

	puts("Passo 5 - Deletar grafo");
	deletaGrafo(g);	
}

void testeGrafo(Grafo* g)
{
	return ;
}

typedef struct
{
	double x;
	double y;
} Ponto;

void setarPonto(Ponto* p, double a, double b)
{
	p->x = a;
	p->y = b;           
}

double distanciaEuclidiana(Ponto* p)
{
	a = p->x;
	b = p->y;

	h = pow(a, 2) + pow(b, 2); // Soma do quadrado dos catetos
	
	return sqrt(h);				  					 
}

int main()
{
	int n, m ,k; // Numero de clareiras, trilhas e portais, respectivamente
	double x, y; // Coordenadas de uma clareira no plano
    	int u, v; // Trilha entre duas clareiras
    	double s; // Energia de Link
    	int q; // Quantidade de portais que podem ser utilizados
    	double d; // Distancia euclideana de um ponto para outro
	Ponto* pontos; // Coordenadas dos vertices

	testeHeap();
	testeVertices();
	Grafo* grafo = novoGrafo();

    	/* Leitura das entradas */
    	
	
    	scanf("%d %d %d", &n, &m, &k);

	pontos = (Ponto*) malloc(sizeof(Ponto) * (n + 1));	
	
	// Verificacao da alocacao de memoria
	if(distancias == NULL)
	{
		printf("A alocacao do vetor de distancias falhou!");
		exit(1);
	}

	// Coordenadas das clareiras (vertices)
    	for(int i = 0; i < n; i++)
    	{
        	scanf("%lf %lf", &x, &y);
		insereVertice(g); // Criar um vertice 'i'
		setarPonto(&pontos[i], x, y); // Coloca as coordenadas do vertice no vetor
    	}
    
	// Trilhas entre clareiras (arestas)
    	for(int i = 0; i < m; i++)
    	{
        	scanf("%d %d", &u, &v);
		d = distanciaEuclideana(&pontos[i]);
		insereAresta(g, u, d, v); // Cria a aresta peso (distancia)
    	}
    
	// Clareiras com portais (arestas)
    	for(int i = 0; i < k; i++)
    	{
        	scanf("%d %d", &u, &v);
		insereAresta(g, u, 0, v); // Cria a aresta com peso 0 (zero)
    	}

    	scanf("%lf %d", &s, &q);
	
	imprimeGrafo(g);

	free(distancias);

    	return 0;
}
