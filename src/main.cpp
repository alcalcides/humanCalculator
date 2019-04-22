#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <windows.h>
using namespace std;

#include "defs.h"
#include "interface.h"
#include "nivel1.h"
#include "nivel2.h"
#include "nivel3.h"
#include "regs.h"


int main(void){
	bool gameOver = false;
	bool zerou = false;
	long int idUser;
	unsigned int comando;
	
	string user;
	string cargo;
	unsigned int nivel;
	unsigned int life;
	unsigned int bonus;

	apresentacao();
	user = qualUsuario();

	idUser = buscarUser(user);
	if(idUser <= -1){
		cargo = "Estudante";
		nivel = 1;
		life = 5;
		bonus = 0;
	}
	else {
		carregarUser(idUser, cargo, nivel, life, bonus);
	}
	if(user == "dev") {
		nivel = 3;
		cargo = "Desenvolvedor";
		life = 1;
	}
	if(life == 0)
		life++;

	relatorio(user, cargo, nivel, life, bonus);
	
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
		
		if(nivel == NUM_NIVEIS){
			zerou = true;
			zerouMaquina();
		}
		else if(!gameOver && comando != 0){
			parabensNivel(nivel);
			comando = oferecerUpgrade(nivel);
		}

	} while(!gameOver && !zerou && comando != 0);
	
	if(gameOver){
		perdeu();
	}

	relatorio(user, cargo, nivel, life, bonus);
	
	if(idUser <= -1){
		registrarUsuario(user, cargo, nivel, life, bonus);
	}
	else{
		atualizarUser(idUser, user, cargo, nivel, life, bonus);
	}


	system("pause");
	system("cls");

	return 0;
}