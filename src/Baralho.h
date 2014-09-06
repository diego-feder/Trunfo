#pragma once

#include "stdafx.h"
#include "Carta.h"
#include "List.h"
#include "Stack.h"
#include "Arvore.h"


class Baralho
{
private:
    Stack<Carta*> play1;
    Stack<Carta*> play2;
    Stack<bool> jogadas;

    BITMAP* buffer;
    List<Carta*> card;
    Carta* pAux;
    int ordem[32];
    bool init;
    string dados[32][7];
    double cil,pot,vel,pes,comp,p1, p2;
    int tr, tip;
public:
    Baralho();
    ~Baralho();

    void setOrdem();
    void setInit(bool in);
    void setDados(string* v);
    void converte();
    void loadCards();
    void preencheArvores(List<Arvore*>* Avs);
    void setBuffer(BITMAP* bmp);
    void embaralhar();
    void computa(int pos);
    void guardaJogada();
    bool nextRodada(int pos);
    bool execute(int pos, bool player, List<Arvore*>* Avs);
    void pontuacao();

    bool verificaTrunfoPlayer();
    bool verificaTrunfoComputador();

    int getOrdem();
    bool getInit();
    //string* getDados();
};


