#include "StdAfx.h"
#include "No.h"


No::No(const float cValor, const int cPeso)
{
	valor = cValor;
	altura = cPeso;
	peso = 0;
	direita = NULL;
	esquerda = NULL;
	membrosdireita = 0;
	membrosesquerda = 0;
}

No::~No(void)
{

}

void No::setDireita(No* pDir)
{
	direita = pDir;
}

void No::setEsquerda(No* pEsq)
{
	esquerda = pEsq;
}

No* No::getDireita() const
{
	return direita;
}

No* No::getEsquerda() const
{
	return esquerda;
}

float No::getValor() const
{
	return valor;
}

int No::getAltura() const
{
	return altura;
}

void No::setValor(const float N)
{
	valor = N;
}
void No::setAltura(const int N)
{
	altura = N;
}

void No::increasePeso()
{
	peso++;
}
void No::decreasePeso()
{
	peso--;
}

int No::getPeso() const
{
	return peso;
}

void No::setPeso(const int N)
{
	peso = N;
}

void No::setMembrosEsquerda(const int N)
{
	membrosesquerda = N;
}
void No::setMembrosDireita(const int N)
{
	membrosdireita = N;
}

int No::getMembrosEsquerda() const
{
	return membrosesquerda;
}

int No::getMembrosDireita() const
{
	return membrosdireita;
}