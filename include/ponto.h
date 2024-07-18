#ifndef PONTO_H
#define PONTO_H

typedef struct
{
	double x;
	double y;
} Ponto;

void setPonto(Ponto* p, double a, double b);
double getXPonto(Ponto* p);
double getYPonto(Ponto* p);
double distanciaXY(Ponto p1, Ponto p2);


#endif
