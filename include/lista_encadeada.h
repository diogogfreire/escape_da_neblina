#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include "./no.h"

typedef struct lista
{
	int vertices;
	int item;
	No* primeiro;
	No* ultimo;
	struct lista* proximaLista;
} Lista;

Lista* criarLista(int idVertice);
int listaVazia(Lista* l);
No* get(Lista* l, int v);
void insereFinal(Lista* l, double d, int v);
void removeFinal(Lista* l);
//TipoItem pesquisa(Lista* l, int c);
void imprimirLista(Lista* l);
void destruirLista(Lista* l);



#endif
