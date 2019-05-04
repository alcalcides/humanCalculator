bool acertouN4(int op1, int op2, int res);
bool jogarNivel4(unsigned int &life, unsigned int &bonus, bool &gameOver);

bool jogarNivel4(unsigned int &life, unsigned int &bonus, bool &gameOver, string user, string &cargo){
	int i, j, k;
	int op1, op2;
	bool opUsado[11];
	int res;
	bool passouDeNivel = false;
	clock_t ini, fim;
	unsigned int qtdAcertos;
	double score = 0;

	boasVindasNivel(4);
	cout << "Digite o resultado da subtração" << endl;

	srand (time(NULL));
	fim = ini = clock();
	qtdAcertos = 0;
	for(i = 0; i < 11 && !gameOver; i++ ){
		op1 = i;
		for (k = 0; k <= i ; ++k){
				opUsado[k] = false;
			}
		for (j = 0; j <= i ; ++j){
			while(op2 = rand()%(i+1), opUsado[op2]);
			opUsado[op2] = true;
			
			cout << op1 << " - " << op2 << " = ";
			cin >> res;
			if(acertouN4(op1, op2, res)){
				parabensAcertou();
				qtdAcertos++;
				bonus++;
				if(bonus == 11){
					maisLife(life, bonus);
				}
			}
			else{
				mensagemErrouItem();
				life--;
				bonus = 0;
				if(life == 0){
					gameOver = true;
					break;
				}
				else{
					cout << "Seu life eh: " << life << endl;
				}
			}
		}
		if(i<10){
			fim = clock();
			tempoDecorrido(duracaoSeg_d(ini, fim));
		}
	}
	fim = clock();
	score = pontuacao(ini, fim, qtdAcertos, QTD_MAX_QUESTOES_N1, gameOver);
	processarRecorde(4, score, user, cargo);
	passouDeNivel = gameOver ? false : true;
	return passouDeNivel;
}

bool acertouN4(int op1, int op2, int res){
	bool acert;
	int resC = op1 - op2;
	if(res == resC){
		acert = true;
	}
	else{
		acert = false;
	}
	return acert;
}