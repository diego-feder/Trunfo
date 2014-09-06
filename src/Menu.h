#pragma once

#include "stdafx.h"

class Menu
{
private:
    BITMAP* buffer;
    BITMAP* menu[4];
    int i, m;
public:
    Menu();
    ~Menu();

    void setBuffer(BITMAP* bmp);
    BITMAP* getBuffer();
    int exec();
};
