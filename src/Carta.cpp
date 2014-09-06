#include "Carta.h"

Carta::Carta(int n , double cil, double pot, double vel, double pes, double comp, int tr, int tip, BITMAP* bmp)
{
    setNumero(n);
    setCilindradas(cil);
    setPotencia(pot);
    setVelocidade(vel);
    setPeso(pes);
    setComprimento(comp);
    setTrunfo(tr);
    setTipo(tip);
    setBMP(bmp);

    //teste
    cartaCostas = load_bitmap("img/costas.bmp", NULL);
}

Carta::Carta(Carta* cC)
{
    setNumero(cC->getNumero());
    setCilindradas(cC->getCilindradas());
    setPotencia(cC->getPotencia());
    setVelocidade(cC->getVelocidade());
    setPeso(cC->getPeso());
    setComprimento(cC->getComprimento());
    setTrunfo(cC->getTrunfo());
    setTipo(cC->getTipo());
    setBMP(cC->getBMP());
    setBuffer(cC->getBuffer());

    //teste
    cartaCostas = load_bitmap("img/costas.bmp", NULL);

}

Carta::~Carta()
{

}

void Carta::setNumero(int n)
{
    numero = n;
}
void Carta::setCilindradas(double cil)
{
    cilindradas = cil;
}
void Carta::setPotencia(double pot)
{
    potencia = pot;
}
void Carta::setVelocidade(double vel)
{
    velocidade = vel;
}
void Carta::setPeso(double pes)
{
    peso = pes;
}
void Carta::setComprimento(double comp)
{
    comprimento = comp;
}
void Carta::setTrunfo(int tr)
{
    if(tr == 1)
        trunfo = true;
    else
        trunfo = false;  /**Deixei assim e não if tr==0 caso venha um numero zuado**/
}
void Carta::setTipo(int tip)
{
    if(tip == 1)
        tipo = true;
    else
        tipo = false;  /**Deixei assim e não if tip==0 caso venha um numero zuado**/
}

int Carta::getNumero()
{
    return numero;
}
double Carta::getCilindradas()
{
    return cilindradas;
}
double Carta::getPotencia()
{
    return potencia;
}
double Carta::getVelocidade()
{
    return velocidade;
}
double Carta::getPeso()
{
    return peso;
}
double Carta::getComprimento()
{
    return comprimento;
}
bool Carta::getTrunfo()
{
    return trunfo;
}
bool Carta::getTipo()
{
    return tipo;
}

void Carta::setBMP(BITMAP* bmp)
{
    img = bmp;
}

BITMAP* Carta::getBMP() const
{
    return img;
}

void Carta::setBuffer(BITMAP* bmp)
{
    //allegro_message("buffer carta");
    buffer = bmp;
}

void Carta::execute(int player)
{
    //allegro_message("Draw!\n");
    if(player == 1)
        draw_sprite(buffer, img, 450, 90);
    if(player == 2)
        draw_sprite(buffer, img, 30, 90);

    if(player == 3) // ANTES DE ABRIR A CARTA!
        draw_sprite(buffer, cartaCostas, 450, 90);
}

BITMAP* Carta::getBuffer()
{
    return buffer;
}
