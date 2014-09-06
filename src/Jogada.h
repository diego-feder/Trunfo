#ifndef JOGADA_H
#define JOGADA_H

#include "Stack.h"


class Jogada
{
    private:
    Stack<Carta*> play1;
    Stack<Carta*> play2;
    public:
    Jogada(Stack<Carta*> p1, Stack<Carta*> p2)
    {
        int i;
        for(i=0;i<p1.getStackSize();i++)
        {
            play1.includeTop(new Carta(p1.removeBottom()));
        }
        for(i=0;i<p2.getStackSize();i++)
        {
            play2.includeTop(new Carta(p2.removeBottom()));
        }
    }
    Jogada()
    {

    }


    ~Jogada(){}
    void setPlay1(Stack<Carta*> P1)
    {
        play1 = P1;
    }

    void setPlay2(Stack<Carta*> P2)
    {
        play2 = P2;
    }

    Stack<Carta*> getPlay1()
    {
        return play1;
    }

    Stack<Carta*> getPlay2()
    {
        return play2;
    }

    void setPlats(Stack<Carta*> p1, Stack<Carta*> p2)
    {
        int i;
        for(i=0;i<p1.getStackSize();i++)
        {
            play1.includeTop(new Carta(p1.removeBottom()));
        }
        for(i=0;i<p2.getStackSize();i++)
        {
            play2.includeTop(new Carta(p2.removeBottom()));
        }
    }
};

#endif // JOGADA_H
