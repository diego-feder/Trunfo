#pragma once

#include "stdafx.h"

#include "AllegroManager.h"
#include "Menu.h"
#include "Baralho.h"
#include "Carta.h"
#include <sstream>
#include "Timer.h"
#include "Mesa.h"

class Game {
private:
	AllegroManager objAllegroManager;
	Menu objMenu;
	//string mat[32][7];
	string vet[224];
	//Baralho aralho;
	Mesa table;
	List<Arvore*> Aprobabilidades;
	//Carta vetCartas[32];
	Timer Tempo;
	BITMAP* buffer;

public:
	Game();
	~Game();
	void load();
	void execute();
	void fillTrees();
};
