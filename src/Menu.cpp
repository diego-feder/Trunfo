#include "Menu.h"


Menu::Menu()
{
    m = 0;
    //buffer = create_bitmap(800, 600);
    menu[0] = load_bitmap("img/menuTemporario0.bmp", NULL);
    menu[1] = load_bitmap("img/menuTemporario1.bmp", NULL);
}

Menu::~Menu()
{

}

void Menu::setBuffer(BITMAP* bmp)
{
    buffer = bmp;
}

BITMAP* Menu::getBuffer()
{
    return buffer;
}

int Menu::exec()
{
    rest(100);
    while (!key[KEY_ENTER]){
          masked_blit(menu[m], screen, 0, 0, 0, 0, 800, 600);
          rest(80);
          if (key[KEY_DOWN]) m++;
          if (key[KEY_UP]) m--;
          if (m > 1) m = 0;
          if (m < 0) m = 1;
    }
    for(i=0;i<2;i++)
        destroy_bitmap(menu[i]);
    return m;
}
