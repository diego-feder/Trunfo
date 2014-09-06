#pragma once


#include<stdio.h>
#include<stdlib.h>

#define _USE_MATH_DEFINES

#include<cmath>
#include<math.h>


#include <sstream>

#include<conio.h>
#include<time.h>

/*Includes Relacionados  às APIs*/
#include <allegro.h>
#include <winalleg.h>

/*Includes reacionados à fluxo de dados*/
#include<iostream>
#include <fstream>


/*Includes relacionados a STL*/
#include<string>
#include<vector>
#include<list>
#include <queue>
#include<algorithm>


/*Includes gerais*/
#include<math.h>
#include<typeinfo>
#include<random>
#include <functional>



/*Defines referentes as condições iniciais do player*/
#define PLAYER_START_SCORE 0
#define PLAYER_START_HEALTH 5
#define PLAYER_START_ATTACK 1
#define PLAYER_START_X 100
#define PLAYER_START_Y 294
#define PLAYER_SC02_Y 180

/*Defines dos Scenarios*/
#define SCENARIO01_RIGHTBORDER 5630
#define SCENARIO01_END_LENGHT 620
#define SCENARIO02_RIGHTBORDER 2100
#define SCENARIO02_END_LENGHT 838


/*Defines gerais do Jogo*/
#define REST_TIME 75
#define PAUSE_X 300
#define PAUSE_Y 170


/*Using relacionados a impressão em console*/
using std::cout;
using std::endl;
using std::cerr;

/*Using realacionados a listas STL*/
using std::vector;
using std::list;
using std::queue;

/*Outros tipos de using*/
using std::string;

/*Using relacionados a file*/
using std::ifstream;
using std::ofstream;

using std::ios;

/*Using relacionados a funcoes matematicas*/
using::std::max;



enum enumMenu {PLAY,SETTINGS,HIGHSCORES,CREDITS,EXIT};
enum enumJogadas {CILINDRADAS = 0, POTENCIA, VELOCIDADE, PESO, COMPRIMENTO};


