#ifndef JOGADA_H
#define JOGADA_H


class Jogada
{
    private:
    Stack<Carta*> play1;
    Stack<Carta*> play2;
    public:
    Jogada(Stack<Carta*> p1, Stack<Carta*> p2)
    {
        play1 = p1;
        play2 = p2;
    }
    ~Jogada(){}
    void setPlay1(Stack<Carta*> P1)
    {
        p1 = P1;
    }

    void setPlay2(Stack<Carta*> P2)
    {
        p2 = P2;
    }

    Stack<Carta*> getPlay1()
    {
        return p1;
    }

    Stack<Carta*> getPlay1()
    {
        return p2;
    }
};

#endif // JOGADA_H
