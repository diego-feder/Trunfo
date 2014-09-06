#include "Mesa.h"

Mesa::Mesa(): aralho()
{
    pano = load_bitmap("img/table.bmp", NULL);
    cursor = load_bitmap("img/cursor2.bmp", NULL);
    cursorY = 370;
    pos = 0;
    player = true;
}

Mesa::~Mesa()
{
    //dtor
}

void Mesa::setDados(string* v)
{
    aralho.setDados(v);
}
void Mesa::setBuffer(BITMAP* bmp)
{
    //allegro_message("Buffer MESA!\n");
    buffer = bmp;
    aralho.setBuffer(buffer);
}
void Mesa::preencheArvores(List<Arvore*>* Avs)
{
    aralho.preencheArvores(Avs);
}
void Mesa::resetar()
{
    aralho.embaralhar();
}
void Mesa::setCursor()
{
    if (key[KEY_DOWN])
    {
        pos++;
        cursorY+=35;
    }
    if (key[KEY_UP])
    {
        pos--;
        cursorY-=35;
    }
    if (cursorY > 510)
    {
        pos = 0;
        cursorY = 370;
    }
    if (cursorY < 370)
    {
        pos = 4;
        cursorY = 510;
    }
    rest(120);
}
void Mesa::execute(List<Arvore*>* Aprobabilidades)
{
    draw_sprite(buffer, pano, 0, 0);
    setCursor();
    player = aralho.execute(pos, player, Aprobabilidades);
    aralho.pontuacao();
    draw_sprite(buffer, cursor, 260, cursorY);

}


