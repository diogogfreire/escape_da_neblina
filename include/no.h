#ifndef NO_H
#define NO_H

typedef struct no
{
	double distancia;
	int vertice;
	struct no* proximo;
} No;

No* criarNo(double d, int v);
double getDistancia(No* no);
int getVertice(No* no);
void setarNo(No* no, double d, int v);
void imprimirNo(No* no);

#endif
