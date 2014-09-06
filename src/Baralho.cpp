#include "Baralho.h"

Baralho::Baralho()
{
    setOrdem();
    setInit(false);
    p1 = 0;
    p2 = 0;
}

Baralho::~Baralho()
{

}

void Baralho::setBuffer(BITMAP* bmp)
{
    //allegro_message("buffer baralho");
    buffer = bmp;
}
void Baralho::setOrdem()
{
    //Completa o vetor "ordem"
    for(int i = 0; i<32; i++)
    {
        ordem[i] = i;
    }
    std::random_shuffle(ordem, ordem+32);
}
void Baralho::setInit(bool in)
{
    init = in;
}
void Baralho::setDados(string* v)
{
    int c = 0;
    for(int lin = 0; lin < 32; lin++)
    {
        for(int col = 0; col < 7; col++)
        {
            dados[lin][col] = v[c];
            c++;
        }
    }
    converte();
}
void Baralho::converte()
{
    std::ostringstream imgname;
    for(int i = 0; i <= 31; i++)
    {
        cil = atof(dados[i][1].c_str());
        pot = atof(dados[i][2].c_str());
        vel = atof(dados[i][3].c_str());
        pes = atof(dados[i][4].c_str());
        comp = atof(dados[i][5].c_str());
        tr = atoi(dados[i][6].c_str());
        if(dados[i][0] == "A")
            tip = 1;
        else
            tip = 0;

        //Constroi o nome da imagem da carta, como a classe muda a cada 8 cartas, o indice
        //é o resto da divisão de i por 8 mais uma unidade
        imgname.str("");
        imgname<<"img/"<<dados[i][0]<<(i%8)+1<<".bmp";
        cout<<imgname.str()<<endl;
        pAux = new Carta(i,cil,pot,vel,pes,comp,tr,tip, load_bitmap(imgname.str().c_str(), 0));
        pAux->setBuffer(buffer);
        card.includeTop(pAux);
    }
    for(int n = 0; n < 32; n++)
    {
        cout<< "Numero: " << card[n]->getNumero() << endl;
        cout<< "Cilindradas: " << card[n]->getCilindradas() << endl;
        cout<< "Potencia: " << card[n]->getPotencia() << endl;
        cout<< "Velocidade: " << card[n]->getVelocidade() << endl;
        cout<< "Peso: " << card[n]->getPeso() << endl;
        cout<< "Comprimento: " << card[n]->getComprimento() << endl;
        cout<< "Trunfo(S=1;N=0): " << card[n]->getTrunfo() << endl;
        cout<< "Tipo(A=0;OUTROS=1): " << card[n]->getTipo() << endl;
        cout << endl;
    }
}
void Baralho::loadCards()
{
    //monte.includeTop(card[aux]);
    for(int i = 0; i < 16; i++)
    {
        int aux = ordem[i];
        play1.includeTop(card[aux]);
        cout<< "CARTA: "<< aux <<endl;
    }
    for(int i = 16; i < 32; i++)
    {
        int aux = ordem[i];
        play2.includeTop(card[aux]);
        cout<< "CARTA: "<< aux <<endl;
    }
}

int Baralho::getOrdem()
{
    return *ordem;
}
bool Baralho::getInit()
{
    return init;
}


void Baralho::preencheArvores(List<Arvore*>* Avs)
{
    int i, j, k;
    Arvore* pAux;
    for(i = 0; i < 5; i++)
    {
        pAux = new Arvore;
        Avs->includeTop(pAux);
        for(j = 0; j < 32; j++)
        {
            switch (i)
            {
            case 0:
                pAux->adicionar(card[j]->getCilindradas());
                break;
            case 1:
                pAux->adicionar(card[j]->getPotencia());
                break;
            case 2:
                pAux->adicionar(card[j]->getVelocidade());
                break;
            case 3:
                pAux->adicionar(card[j]->getPeso());
                break;
            case 4:
                pAux->adicionar(card[j]->getComprimento());
                break;
            default:
                allegro_message("Error adding cards to trees");
                break;
            }
        }
    }

    for(i=0; i<5; i++)
    {
        (*Avs)[i]->contagem();
    }
}

void Baralho::embaralhar()
{
    srand((unsigned)time(NULL));
    for(int i = 0; i<rand()%10; i++)
    {
        setOrdem();
        //cout<<"Ordem"<<endl;
    }
    loadCards();
    setInit(true);
}

void Baralho::computa(int pos)
{
    cout<<"Computa: "<<pos<<endl;
    p1 = 0;
    p2 = 0;

//    bool trunfo, tipo;
//
//    pAux = play1.getTop()
//    trunfo = pAux.getTrunfo();
//    if (trunfo)
//    {
//        pAux = play2.getTop();
//        tipo = pAux.getTipo();
//        if(tipo)
//        {
//
//        }
//    }


    switch (pos)
    {
        case 0:
            pAux = play1.getTop();
            p1 = pAux->getCilindradas();
            pAux = play2.getTop();
            p2 = pAux->getCilindradas();
            break;
        case 1:
            pAux = play1.getTop();
            p1 = pAux->getPotencia();
            pAux = play2.getTop();
            p2 = pAux->getPotencia();
            break;
        case 2:
            pAux = play1.getTop();
            p1 = pAux->getVelocidade();
            pAux = play2.getTop();
            p2 = pAux->getVelocidade();
            break;
        case 3:
            pAux = play1.getTop();
            p1 = pAux->getPeso();
            pAux = play2.getTop();
            p2 = pAux->getPeso();
            break;
        case 4:
            pAux = play1.getTop();
            p1 = pAux->getComprimento();
            pAux = play2.getTop();
            p2 = pAux->getComprimento();
            break;
        default:
            //allegro_message("Error adding cards to trees");
            break;
    }
}

bool Baralho::verificaTrunfoPlayer()
{
    bool trunfo, tipo;

    pAux = play1.getTop();
    tipo = pAux->getTipo();
    cout << tipo << endl;
    if(tipo) // PLAYER TEM TRUNFO E PC TEM CARTA CLASSE A
    {
        play1.includeBottom(play2.removeTop());
        play1.includeBottom(play1.removeTop());
        allegro_message("COMPUTADOR GANHA RODADA!\n");
        return false;
    }
    else
    {
        play2.includeBottom(play1.removeTop());
        play2.includeBottom(play2.removeTop());
        allegro_message("PLAYER GANHA RODADA!\n");
        return true;
    }

}

bool Baralho::nextRodada(int pos)
{
    if (pos == 3) // FOI SELECIONADO O PESO
    {
        if(p1<p2)
        {
            //pAux = play2.removeTop();
            p1 = 0;
            p2 = 0;
            play1.includeBottom(play2.removeTop());
            play1.includeBottom(play1.removeTop());
            allegro_message("COMPUTADOR GANHA RODADA!\n");
            return 0;
        }

        if(p2<p1)
        {
            //pAux = play2.removeTop();
            p1 = 0;
            p2 = 0;
            play2.includeBottom(play1.removeTop());
            play2.includeBottom(play2.removeTop());
            allegro_message("PLAYER GANHA RODADA!\n");
            return 1;
        }
    }

    else // FOI SELECIONADO OUTROS (Cilindrada, Potencia, Velocidade ou Comprimento)
    {
        if(p1>p2)
        {
            //pAux = play2.removeTop();
            p1 = 0;
            p2 = 0;
            play1.includeBottom(play2.removeTop());
            play1.includeBottom(play1.removeTop());
            allegro_message("COMPUTADOR GANHA RODADA!\n");
            return 0;
        }

        if(p2>p1)
        {
            //pAux = play2.removeTop();
            p1 = 0;
            p2 = 0;
            play2.includeBottom(play1.removeTop());
            play2.includeBottom(play2.removeTop());
            allegro_message("PLAYER GANHA RODADA!\n");
            return 1;
        }
    }



}

bool Baralho::verificaTrunfoComputador()
{
    bool trunfo, tipo;
    pAux = play2.getTop();
    tipo = pAux->getTipo();
    cout << tipo << endl;
    if(tipo) // PC TEM TRUNFO E PLAYER TEM CARTA CLASSE A
    {
        play2.includeBottom(play1.removeTop());
        play2.includeBottom(play2.removeTop());
        allegro_message("COMPUTADOR USA TRUNFO.\n PLAYER GANHA RODADA!\n");
        return false;
    }
    else
    {
        play1.includeBottom(play2.removeTop());
        play1.includeBottom(play1.removeTop());
        allegro_message("COMPUTADOR USA TRUNFO E GANHA RODADA!\n");
        return true;
    }
}

bool Baralho::execute(int pos, bool player, List<Arvore*>* Avs)
{
    if(init)
    {

        //cout<<"size1: "<< play1.getListSize()<<endl;
        //cout<<"size2: "<< play2.getListSize()<<endl;

        if(play1.getStackSize() == 0)
        {
            allegro_message("PLAYER GANHOU O JOGO!");
            exit(0);
        }

        if (play2.getStackSize() == 0)
        {
            allegro_message("COMPUTADOR GANHOU O JOGO!");
            exit(0);
        }

        if((jogadas.getStackSize() > 0))
        {
            if(key[KEY_Z])
            {
                /*jogadaAux = jogadas.removeTop();
                play1 = jogadaAux.getPlay1();
                play2 = jogadaAux.getPlay2();
                allegro_message("Desfazendo jogada!");*/
                if(jogadas.getStackSize() > 0)
                {
                    int res;
                    if((res = jogadas.removeTop())==true)
                    {
                        play2.includeTop(play2.removeBottom());
                        play1.includeTop(play2.removeBottom());
                    }
                    else if(res == 0)
                    {
                        play1.includeTop(play1.removeBottom());
                        play2.includeTop(play1.removeBottom());
                    }
                }

            }
        }

        pAux = play1.getTop();
        pAux->execute(3);
        pAux = play2.getTop();
        pAux->execute(2);
        //PRECISA DIVIDIR AINDA AS ESCOLHAS DO PLAYER E COMPUTADOR
        //PRECISA ADD BOTAO DO SUPER TRUNFO ---> FEITO --> BOTAO T DE TRUNFO ---> FALTA FAZER PARA O PC!
        //TALVEZ DEIXAR UM TEMPO LIMITE MAXIMO DE JOGO
        //ARRUMAR (PASSAR POR PARAMETRO) QUAL PARTE ESTA ESCOLHENDO... NO CASO DE ESCOLHER PESO, O MAIS LEVE VENCE! -------------> FEITO!

        //PERCEBI QUE O JOGO NAO TA EMBARALHANDO
        //Ass Diego Feder (Fiz essas partes na fuleragem) não de um jeito elegante c++ e tals.

        if(player)
        {
            if(key[KEY_F])
            {
                pAux = play1.getTop();
                pAux->execute(1);
                masked_blit(buffer, screen, 0, 0, 0, 0, 800, 600);
                computa(pos);
                jogadas.includeTop(nextRodada(pos));
                return jogadas.getTop();
            }

            pAux = play2.getTop();
            if (pAux->getTrunfo())
            {
                if (key[KEY_T])
                {
                    allegro_message("SUPER TRUNFO!");
                    pAux = play1.getTop();
                    pAux->execute(1);
                    masked_blit(buffer, screen, 0, 0, 0, 0, 800, 600);
                    jogadas.includeTop(verificaTrunfoPlayer());
                    return jogadas.getTop();
                }
            }
            return 1;
        }
        else
        {
            //allegro_message("busca");
            double possiveis[5];
            int i, imin;
            double mini;
            possiveis[0] = (*Avs)[4]->buscarCaminho(play1.getTop()->getCilindradas())/32.0;
            possiveis[1] = (*Avs)[3]->buscarCaminho(play1.getTop()->getPotencia())/32.0;
            possiveis[2] = (*Avs)[2]->buscarCaminho(play1.getTop()->getVelocidade())/32.0;
            possiveis[3] = (31 - (*Avs)[1]->buscarCaminho(play1.getTop()->getPeso()))/32.0;
            possiveis[4] = (*Avs)[0]->buscarCaminho(play1.getTop()->getComprimento())/32.0;

            (*Avs)[0]->imprimir();
            cout<<"Caminho: "<<endl<<(*Avs)[0]->buscarCaminho(play1.getTop()->getCilindradas());
            cout<<"Cilindradas: "<<play1.getTop()->getCilindradas();

            mini = 1;
            for(i = 0; i<5; i++)
            {
                if(possiveis[i]<mini)
                {
                    mini = possiveis[i];
                    imin = i;
                }
            }

            if(play2.getTop()->getTrunfo() && (8.0/32)<mini)
            {
                //guardaJogada();
                jogadas.includeTop(verificaTrunfoComputador());
                return jogadas.getTop();
            }
            else
            {
                //guardaJogada();
                pAux = play1.getTop();
                pAux->execute(1);
                masked_blit(buffer, screen, 0, 0, 0, 0, 800, 600);
                computa(imin);
                switch (imin)
                {
                    case CILINDRADAS:
                        allegro_message("COMPUTADOR PEDE CILINDRADAS!\n");
                        break;

                    case POTENCIA:
                        allegro_message("COMPUTADOR PEDE POTENCIA!\n");
                        break;

                    case VELOCIDADE:
                        allegro_message("COMPUTADOR PEDE VELOCIDADE!\n");
                        break;

                    case PESO:
                        allegro_message("COMPUTADOR PEDE PESO!\n");
                        break;
                    case COMPRIMENTO:
                        allegro_message("COMPUTADOR PEDE COMPRIMENTO!\n");
                        break;

                    default:
                        allegro_message("NAO EXISTE ESSA OPCAO");
                        break;

                }
                jogadas.includeTop(nextRodada(imin));
                return jogadas.getTop();
            }
        }
    }
    else
    {
        allegro_message("Falta inicializar o baralho!\n");
    }

}

void Baralho::pontuacao()
{
    textprintf_ex(buffer, font, 200, 60, makecol(255,255,255), -1, "Cartas: %d", play2.getStackSize());
    textprintf_ex(buffer, font, 400, 60, makecol(255,255,255), -1, "Cartas: %d", play1.getStackSize());
    masked_blit(buffer, screen, 0, 0, 0, 0, 800, 600);
}

/*string* Baralho::getDados()
{
    return dados;
}*/
/*void Baralho::guardaJogada()
{
        if(jogadas.getStackSize() > 3)
        {
            jogadas.removeBottom();
        }
        jogadaAux.setPlats(play1, play2);
        jogadas.includeTop(jogadaAux);
}*/
