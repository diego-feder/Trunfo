#pragma once

#include "stdafx.h"
#include "Baralho.h"
#include "Arvore.h"

class Mesa
{
private:
    Baralho aralho;
    BITMAP* buffer;
    BITMAP* pano;
    BITMAP* cursor;
    bool player;
    int cursorY, pos;

public:
    Mesa();
    ~Mesa();

    void setDados(string* v);
    void setBuffer(BITMAP* bmp);
    void preencheArvores(List<Arvore*>* Avs);
    void setCursor();
    void execute(List<Arvore*>* Avs);
    void resetar();
};
