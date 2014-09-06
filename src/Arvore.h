#pragma once

#include "No.h"
#include "stdafx.h"

class Arvore
{
public:
	No* raiz;
	No* pAux;
	No* pAux2;
	No* pAux3;
	/*Funções acessadas somente pela classe e suas derivadas*/
	No* adicionar(const float cValor, No* pNo);
	void imprimir(No* pNo);
	int altura(No* pNo);
	No* balancear(No* pNo);
	int contarElementos(No* pNo);
	No* buscar(const float cValor, No* pNo) const;
	No* rotacaoEsquerda(No* pNo);
	No* rotacaoDireita(No* pNo);
	No* rotacaoDuplaDireita(No* pNo);
	No* rotacaoDuplaEsquerda(No* pNo);
	No* buscar(const float cValor) const;
	No* getRaiz() const;
	int buscarCaminho(const float cValor, No* pNo) const;
	int contarAte(const float cValor, No* pNo) const;
	int contagem(No* pNo);


public:
	Arvore(void);
	~Arvore(void);


	/*Funções acessadas externamento, criando assim um padrão de interfaceamento*/
	void adicionar(const float cValor);
	void imprimir();
	int contarElementos();
	int contarElementosEsquerda(const float cValor);
	int contarMenores(const float cValor);
	void contagem();
	int buscarCaminho(const float cValor) const;

};

