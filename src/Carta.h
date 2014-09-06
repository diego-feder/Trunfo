#pragma once

#include "stdafx.h"

class Carta
{
private:
    int numero;
    //char classe;
    double cilindradas, potencia, velocidade, peso, comprimento;
    bool trunfo, tipo;
    BITMAP* img, *buffer;
    BITMAP* cartaCostas;

public:
    Carta(int n, double cil, double pot, double vel, double pes, double comp, int tr, int tip, BITMAP* bmp);
    Carta(Carta* cC);
    ~Carta();
    //void init(int n, float cil, float pot, float vel, float pes, float comp, bool tr, bool tip);
    //sets e gets
    void setNumero(int n);
    void setCilindradas(double cil);
    void setPotencia(double pot);
    void setVelocidade(double vel);
    void setPeso(double pes);
    void setComprimento(double comp);
    void setTrunfo(int tr);
    void setTipo(int tip);
    void setBMP(BITMAP* bmp);
    void setBuffer(BITMAP* bmp);
    void execute(int player);

    int getNumero();
    double getCilindradas();
    double getPotencia();
    double getVelocidade();
    double getPeso();
    double getComprimento();
    bool getTrunfo();
    bool getTipo();
    BITMAP* getBMP() const;
    BITMAP* getBuffer();

};
