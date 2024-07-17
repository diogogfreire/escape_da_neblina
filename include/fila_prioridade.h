#ifndef FILA_PRIORIDADE_H
#define FILA_PRIORIDADE_H

#include "../include/no.h"

typedef struct
{
	int tamanho;
	int ocupados;
	No* vetor;
} Heap;


Heap* criarHeap(int n);
int getAncestral(int i);
int getSucessorEsq(int i);
int getSucessorDir(int i);
void destruirHeap(Heap* heap);
void inserirNoHeap(Heap* heap, double d, int v);
No removeNoHeap(Heap* heap);
void imprimirHeap(Heap* heap);
int empty(Heap* heap);

#endif
