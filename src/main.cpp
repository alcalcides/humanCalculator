#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <windows.h>
using namespace std;

#include "interface.h"
#include "nivel1.h"
#include "nivel2.h"
#include "nivel3.h"
#include "regs.h"

#define numNiveis 3


int main(void){
	unsigned int life;
	bool gameOver = false;
	unsigned int bonus;
	unsigned int nivel;
	unsigned int comando;
	bool zerou = false;
	string user;
	string cargo;

	apresentacao();
	user = qualUsuario();

	buscarUser(user, cargo, nivel, life, bonus);

	if(user == "dev") {
		nivel = 3;
		cargo = "Desenvolvedor";
	}

	verSituacao(life, bonus);
	do{
		comando = menu(nivel);
		switch (comando){
			case 0:
				break;
			case 1: 
				jogarNivel1(life, bonus, gameOver);
				break;
			case 2: 
				jogarNivel2(life, bonus, gameOver);
				break;
			case 3: 
				jogarNivel3(life, bonus, gameOver);
				break;
			default:
				zerou = zerouMaquina();
				break;
		}
		
		if(nivel == numNiveis){
			zerou = true;
			zerouMaquina();
		}
		else if(!gameOver && comando != 0){
			parabensNivel(nivel);
			comando = oferecerUpgrade(nivel);
		}

	} while(!gameOver && !zerou && comando != 0);

	relatorio(user, cargo, nivel, life, bonus);

	registrarUsuario(user, cargo, nivel, life, bonus);

	return 0;
}