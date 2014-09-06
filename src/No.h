#pragma once

#include "stdafx.h"

class No
{
private:
	float valor;
	int peso;
	int altura;

	No* direita;
	No* esquerda;

	int membrosesquerda;
	int membrosdireita;

public:
	No(const float cValor = 0.0, const int cPeso = 0);
	~No(void);

	void setDireita(No* pDir);
	void setEsquerda(No* pEsq);

	No* getDireita() const;
	No* getEsquerda() const;

	float getValor() const;
	int getAltura() const;
	int getPeso() const;
	int getMembrosEsquerda() const;
	int getMembrosDireita() const;

	void setValor(const float N);
	void setAltura(const int N);
	

	void increasePeso();
	void decreasePeso();

	void setPeso(const int N);

	void setMembrosEsquerda(const int N);
	void setMembrosDireita(const int N);



};

