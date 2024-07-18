#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "../include/no.h"
#include "../include/graph.h"
#include "../include/fila_prioridade.h"

typedef struct
{
	int* vertices;
	double menor_distancia;
} Caminho;

Caminho dijkstra(Grafo *g);

#endif
