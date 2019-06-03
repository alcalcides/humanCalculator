#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
//#include <windows.h>
using namespace std;

#include "defs.h"
#include "interface.h"
#include "punctuation.h"
#include "regs.h"
#include "_levels/nivel1.h"
#include "_levels/nivel2.h"
#include "_levels/nivel3.h"
#include "_levels/nivel4.h"
#include "_levels/nivel5.h"
#include "_levels/nivel6.h"
#include "_levels/nivel7.h"
#include "_levels/nivel8.h"
#include "_levels/nivel9.h"
#include "_levels/nivel10.h"
#include "_levels/nivel11.h"
#include "_levels/nivel12.h"


int main(void){	
	bool gameOver = false;
	bool zerou = false;
	long int idUser;
	unsigned int comando;
	bool passouDeNivel;
	
	string user;
	string cargo;
	unsigned int nivel;
	unsigned int life;
	unsigned int bonus;
	int ultimoNivelJogado;

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
		nivel = (unsigned int)NUM_NIVEIS;
		cargo = "Desenvolvedor";
		life = 1;
	}

	relatorio(user, cargo, nivel, life, bonus);
	
	do{
		comando = menu(nivel);
		passouDeNivel = false;
		ultimoNivelJogado = 0;
		switch (comando){
			case 0:
				break;
			case 1: 
				passouDeNivel = jogarNivel1(life, bonus, gameOver, user, cargo);
				ultimoNivelJogado = 1;
				break;
			case 2: 
				passouDeNivel = jogarNivel2(life, bonus, gameOver, user, cargo);
				ultimoNivelJogado = 2;
				break;
			case 3: 
				passouDeNivel = jogarNivel3(life, bonus, gameOver, user, cargo);
				ultimoNivelJogado = 3;
				break;
			case 4: 
				passouDeNivel = jogarNivel4(life, bonus, gameOver, user, cargo);
				ultimoNivelJogado = 4;
				break;
			case 5: 
				passouDeNivel = jogarNivel5(life, bonus, gameOver, user, cargo);
				ultimoNivelJogado = 5;
				break;
			case 6: 
				passouDeNivel = jogarNivel6(life, bonus, gameOver, user, cargo);
				ultimoNivelJogado = 6;
				break;
			case 7: 
				passouDeNivel = jogarNivel7(life, bonus, gameOver, user, cargo);
				ultimoNivelJogado = 7;
				break;
			case 8: 
				passouDeNivel = jogarNivel8(life, bonus, gameOver, user, cargo);
				ultimoNivelJogado = 8;
				break;
			case 9: 
				passouDeNivel = jogarNivel9(life, bonus, gameOver, user, cargo);
				ultimoNivelJogado = 9;
				break;
			case 10: 
				passouDeNivel = jogarNivel10(life, bonus, gameOver, user, cargo);
				ultimoNivelJogado = 10;
				break;
			case 11: 
				passouDeNivel = jogarNivel11(life, bonus, gameOver, user, cargo);
				ultimoNivelJogado = 11;
				break;
			case 12: 
				passouDeNivel = jogarNivel12(life, bonus, gameOver, user, cargo);
				ultimoNivelJogado = 12;
				break;
			case (NUM_NIVEIS + 1):
				mostrarRecordistas();
				break;
		}
		
		if(gameOver && ultimoNivelJogado){
			perdeu();
			gameOver = false;
			relatorio(user, cargo, nivel, life, bonus);
			cout << "Voce ganhou um life para continuar" << endl;
			life = 1;

		}
		else if(nivel == NUM_NIVEIS && passouDeNivel && ultimoNivelJogado == NUM_NIVEIS){
			zerou = true;
			zerouMaquina();
		}
		else if(passouDeNivel && ultimoNivelJogado == nivel){
			parabensNivel(nivel);
			comando = oferecerUpgrade(nivel);
			if(cargo != "Recordista")
				cargo = atualizarCargoPeloNivel(nivel);
		}

	} while(comando != 0);
	

	relatorio(user, cargo, nivel, life, bonus);
	
	if(idUser <= -1){
		registrarUsuario(user, cargo, nivel, life, bonus);
	}
	else{
		atualizarUser(idUser, user, cargo, nivel, life, bonus);
	}


	//system("pause");
	system("clear");

	return 0;
}
