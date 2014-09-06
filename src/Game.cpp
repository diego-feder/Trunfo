#include "Game.h"

Game::Game(): table() //aralho()
{
    Tempo.startThread();
    buffer = create_bitmap(800,600);
    objMenu.setBuffer(buffer);
    table.setBuffer(buffer);
}

Game::~Game()
{

}

void Game::load()
{
    ifstream file;
    //file.open ("C:/Users/Andre/Desktop/Game/res/baralho.csv");
    file.open("res/baralho.csv");
    std::string::size_type sz;
    int i = 0;

    std::string line;
    std::string field;
    while(file)
    {
        while(std::getline(file, line))
        {
            std::istringstream s(line);
            while (getline(s, field,';'))
            {
                //cout<< "Field: "<< field;
                vet[i] = field;
                i++;
            }
        }
    }
    table.setDados(vet);
    //aralho.setDados(vet);
    file.close();
}

void Game::fillTrees()
{
    //aralho.preencheArvores(&Aprobabilidades);
    table.preencheArvores(&Aprobabilidades);
}
void Game::execute()
{
    //CHAMA INICIALIZADORA DE CARTAS
    //ADICIONA AS CARTAS DIVIDINDO ALEATORIAMENTE EM DOIS BARALHOS
    //CRIA 4 ARVORES E AS BALANCEIA
    //CHAMA O MENU
    load();
    table.resetar();
    fillTrees();

    int i, k;

    Arvore* pAux;

    for(i = 0; i < 4; i++)
    {
        cout<<i<<"- "<<endl;
        Aprobabilidades[i]->imprimir();
        pAux = Aprobabilidades[i];
        //cout<<"Numero elementos:"<< Aprobabilidades[i]->contarElementos()<<endl;/
    }

    cout<<endl;

    //Aprobabilidades[0]->imprimir();

    //cout<<endl<<"A esquerda do valor 4000 "<<Aprobabilidades[0]->contarElementosEsquerda(4000);


    if(objMenu.exec() == 0)
    {

        Tempo.stateTrue();
        while(!key[KEY_ESC])
        {
            table.execute(&Aprobabilidades);
            Tempo.printTimer(buffer);
            masked_blit(buffer, screen, 0, 0, 0, 0, 800, 600);
            clear(buffer);
        }
    }

}

