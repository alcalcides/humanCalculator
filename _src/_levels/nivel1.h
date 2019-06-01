bool acertouN1(int i, int j, int res);
bool jogarNivel1(unsigned int &life, unsigned int &bonus, bool &gameOver);

bool jogarNivel1(unsigned int &life, unsigned int &bonus, bool &gameOver, string user, string &cargo){
	int i, j, k;
	int op1, op2;
	bool opUsado[11];
	int res;
	bool passouDeNivel = false;
	clock_t ini, fim;
	unsigned int qtdAcertos;
	double score = 0;

	boasVindasNivel(1);
	cout << "Digite APENAS o algarismo das UNIDADES" << endl;

	srand (time(NULL));
	fim = ini = clock();
	qtdAcertos = 0;
	for(i = 0; i < 11 && !gameOver; i++ ){
		op1 = i;
		for (k = 0; k < 11; ++k){
				opUsado[k] = false;
			}
		for (j = 0; j < 11 ; ++j){
			while(op2 = rand()%11, opUsado[op2]);
			opUsado[op2] = true;
			
			cout << op1 << " + " << op2 << " = ";
			cin >> res;
			if(acertouN1(op1, op2, res)){
				parabensAcertou();
				qtdAcertos++;
				bonus++;
				if(bonus == QTD_BONUS){
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
	processarRecorde(1, score, user, cargo);
	passouDeNivel = gameOver ? false : true;
	return passouDeNivel;
}

bool acertouN1(int i, int j, int res){
	bool acert;
	int resC = i + j;
	resC = resC % 10;
	if(res == resC){
		acert = true;
	}
	else{
		acert = false;
	}
	return acert;
}