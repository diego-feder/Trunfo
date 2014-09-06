#include "StdAfx.h"
#include "Arvore.h"


Arvore::Arvore(void)
{
	raiz = NULL;
}


Arvore::~Arvore(void)
{

}

No* Arvore::getRaiz() const
{
	return raiz;
}

void Arvore::adicionar(const float cValor)
{
	if(raiz == NULL)
	{
		raiz = new No(cValor);
	}
	else
	{
		adicionar(cValor, raiz);
	}
}

No* Arvore::adicionar(const float cValor, No* pNo)
{
	if(cValor < pNo->getValor())
	{
		if(pNo->getEsquerda())
		{
			pAux3 = adicionar(cValor, pNo->getEsquerda());
			if(pAux3)
			{
				pNo->setEsquerda(pAux3);
			}
			altura(pNo);
			pAux3 = balancear(pNo);
		}
		else
		{
			pNo->setEsquerda(new No(cValor));
			return NULL;
		}
	}
	else
	{
		if(pNo->getDireita())
		{
			pAux3 = adicionar(cValor, pNo->getDireita());
			if(pAux3)
			{
				pNo->setDireita(pAux3);
			}
			altura(pNo);
			pAux3 = balancear(pNo);
		}
		else
		{
			pNo->setDireita(new No(cValor));
			return NULL;
		}
	}

	return pAux3;
}

void Arvore::imprimir()
{
	altura(raiz);
	if(raiz)
	{
		imprimir(raiz);
	}
	else
	{
		cout<<endl<<"Nao existem elementos nessa arvore"<<endl;
	}
}

void Arvore::imprimir(No* pNo)
{
	if(pNo != NULL)
	{
		imprimir(pNo->getEsquerda());
		cout<<pNo->getValor()<<" - ";
		cout<<altura(pNo)<<" ";
		cout<<" - "<<pNo->getPeso()<<endl;
		imprimir(pNo->getDireita());
	}

}

int Arvore::altura(No* pNo)
{
	if(pNo)
	{
		int alturaesquerda = altura(pNo->getEsquerda()) ;
		int alturadireita = altura(pNo->getDireita());
		pNo->setAltura(max(alturaesquerda,alturadireita)+ 1);
		pNo->setPeso(alturadireita - alturaesquerda);
		return pNo->getAltura();
	}
	else
	{
		return 0;
	}
}

No* Arvore::balancear(No* pNo)
{
	if(pNo)
	{
		if(pNo->getPeso() == 2)
		{
			if(pNo->getDireita()->getPeso()  == -1)
			{
				//return rotacaoDuplaEsquerda(pNo);
				pNo->setDireita(rotacaoDireita(pNo->getDireita()));
				return rotacaoEsquerda(pNo);
			}
			else
			{
				return rotacaoEsquerda(pNo);
			}
		}
		else if(pNo->getPeso() == -2)
		{
			if(pNo->getEsquerda()->getPeso()  == 1)
			{
				//return rotacaoDuplaDireita(pNo);
				pNo->setEsquerda(rotacaoEsquerda(pNo->getEsquerda()));
				return rotacaoDireita(pNo);
			}
			else
			{
				return rotacaoDireita(pNo);
			}

		}
	}

	return pNo;
}


No* Arvore::rotacaoEsquerda(No* pNo)
{

	pAux = pNo;  //Guarda a raiz velha
	pAux2 = pNo->getDireita()->getEsquerda(); //Guarda o elemento a esquerda da nova raiz

	pNo = pNo->getDireita(); //A nova raiz é agora o Nó da direita
	pAux->setDireita(pAux2);
	pNo->setEsquerda(pAux); //A nova raiz tem como o Nó à sua esquerda a velha raiz

	if(pAux == raiz)
	{
		raiz = pNo;
	}
	else if(pAux == raiz->getEsquerda())
	{
		raiz->setEsquerda(pNo);
	}
	else if(pAux == raiz->getDireita())
	{
		raiz->setDireita(pNo);
	}

	pNo->setPeso(0);
	pAux->setPeso(0);

	return pNo;
}

No* Arvore::rotacaoDireita(No* pNo)
{
	pAux = pNo;  //Guarda a raiz velha
	pAux2 = pNo->getEsquerda()->getDireita(); //Guarda o elemento a esquerda da nova raiz

	//Verifica casos em que exista alteração diretamente na raiz ou em seus filhos diretos
	pNo = pNo->getEsquerda(); //A nova raiz é agora o Nó da esquerda da velha
	pAux->setEsquerda(pAux2);
	pNo->setDireita(pAux); //A nova raiz tem como o Nó à sua esquerda a velha raiz

	if(pAux == raiz)
	{
		raiz = pNo;
	}
	else if(pAux == raiz->getEsquerda())
	{
		raiz->setEsquerda(pNo);
	}
	else if(pAux == raiz->getDireita())
	{
		raiz->setDireita(pNo);
	}

	pNo->setPeso(0); //Regula pesos
	pAux->setPeso(0);

	return pNo;
}

No* Arvore::rotacaoDuplaDireita(No* pNo)
{
	pAux = pNo; //Guarda a velha raiz
	pAux2 = pNo->getEsquerda(); //Guarda o elemento à esquerda da velha raiz
	pNo = pAux2->getDireita(); //A nova raiz é dada pelo filho à direita do nó à esquerad
	pAux2->setDireita(pNo->getEsquerda());  // adota filho esquerdo do novo raiz
    pAux2->setEsquerda(pNo->getDireita());   // adota filho direito  do novo raiz
	pNo->setEsquerda(pAux2);
    (pNo)->setDireita(pAux);

	if(pAux == raiz)
	{
		raiz = pNo;
	}
	else if (pAux == raiz->getEsquerda())
	{
		raiz->setEsquerda(pNo);
	}
	else if (pAux == raiz->getDireita())
	{
		raiz->setDireita(pNo);
	}


	if (pNo->getPeso() == -1)
	{
	  pAux2->setPeso(0);
	  pAux->setPeso(+1);
	}
	else if (pNo->getPeso() == 0)
	{
		pAux2->setPeso(0);
		pAux->setPeso(0);
	}
	else
	{
		pAux2->setPeso(-1);
		pAux->setPeso(0);
	}
	pNo->setPeso(0);

	return pNo;
}

No* Arvore::rotacaoDuplaEsquerda(No* pNo)
{
	pAux = pNo; //Guarda a velha raiz
	pAux2 = pNo->getDireita(); //Guarda o elemento à Direita da velha raiz

	if(pAux == raiz)
	{
		raiz = pNo;
	}
	else if (pAux == raiz->getEsquerda())
	{
		raiz->setEsquerda(pNo);
	}
	else if (pAux == raiz->getDireita())
	{
		raiz->setDireita(pNo);
	}

	pNo = pAux2->getEsquerda(); //A nova raiz é dada pelo filho à Esquerda do nó à esquerad
	pAux2->setEsquerda(pNo->getDireita());  // adota filho esquerdo do novo raiz
    pAux2->setDireita(pNo->getEsquerda());   // adota filho direito  do novo raiz
	pNo->setDireita(pAux2);
    (pNo)->setEsquerda(pAux);


	if (pNo->getPeso() == -1)
	{
	  pAux2->setPeso(0);
	  pAux->setPeso(+1);
	}
	else if (pNo->getPeso() == 0)
	{
		pAux2->setPeso(0);
		pAux->setPeso(0);
	}
	else
	{
		pAux2->setPeso(-1);
		pAux->setPeso(0);
	}
	pNo->setPeso(0);

	return pNo;
}

No* Arvore::buscar(const float cValor) const
{
	if(raiz->getValor() == cValor)
	{
		return raiz;
	}
	else if(cValor < raiz->getValor())
	{
		return buscar(cValor, raiz->getEsquerda());
	}
	else if(cValor > raiz->getValor())
	{
		return buscar(cValor, raiz->getDireita());
	}
}

No* Arvore::buscar(const float cValor, No* pNo) const
{
	if(pNo)
	{
		if(pNo->getValor() == cValor)
		{
			return pNo;
		}
		else if(cValor < pNo->getValor())
		{
			return buscar(cValor, pNo->getEsquerda());
		}
		else if(cValor > pNo->getValor())
		{
			return buscar(cValor, pNo->getDireita());
		}
	}
}

int Arvore::contarElementos()
{
	if(raiz)
	{
		return (contarElementos(raiz->getDireita()) + contarElementos(raiz->getEsquerda()))+1;
	}
	else
	{
		return 0;
	}
}

int Arvore::contarElementos(No* pNo)
{
	if(pNo)
	{
		return (contarElementos(pNo->getDireita()) + contarElementos(pNo->getEsquerda())+1);
	}
	else
	{
		return 0;
	}
}

int Arvore::contarElementosEsquerda(const float cValor)
{

	if(pAux = buscar(cValor))
	{
		return contarElementos(pAux->getEsquerda());
	}
	else
	{
		return 0;
	}
}

int Arvore::contarAte(const float cValor, No* pNo) const
{
	if(pNo)
	{
		if(pNo->getValor() != cValor)
		{
			return contarAte(cValor,pNo->getEsquerda()) + contarAte(cValor,pNo->getDireita()) + 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

int Arvore::contarMenores(const float cValor)
{
	return contarAte(cValor, raiz);
}

void Arvore::contagem()
{
	contagem(raiz);
}

int Arvore::contagem(No* pNo)
{
	int esq, dir;
	if(pNo)
	{
		pNo->setMembrosEsquerda(esq = contagem(pNo->getEsquerda()));
		pNo->setMembrosDireita(dir = contagem(pNo->getDireita()));
		return esq + dir + 1;
	}
	else
	{
		return 0;
	}
}
int Arvore::buscarCaminho(const float cValor, No* pNo) const
{
    int inter = 0, joao;
	if(pNo)
	{
	    joao = pNo->getValor();
		if( pNo->getValor() - 0.5< cValor && cValor < pNo->getValor() + 0.5)
		{
			inter = pNo->getMembrosDireita();
			return inter;
		}
		else if(cValor < pNo->getValor())
		{
			inter = buscarCaminho(cValor, pNo->getEsquerda()) + pNo->getMembrosDireita() + 1;
			return inter;
		}
		else if(cValor > pNo->getValor())
		{
			inter = buscarCaminho(cValor, pNo->getDireita());
			return inter;
		}
	}
}
int Arvore::buscarCaminho(const float cValor) const
{
	return buscarCaminho(cValor, raiz);
}
