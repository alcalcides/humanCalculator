bool acertouN11(int i, int j, int res);
bool jogarNivel11(unsigned int &life, unsigned int &bonus, bool &gameOver, string user, string &cargo);


bool jogarNivel11(unsigned int &life, unsigned int &bonus, bool &gameOver, string user, string &cargo){
	bool passouDeNivel;
	int i;
	int op1, op2;
	int res;
	clock_t ini, fim;
	unsigned int qtdAcertos;
	double score = 0;

	boasVindasNivel(11);
	cout << "Digite o resultado da divisão" << endl;

	srand (time(NULL));
	fim = ini = clock();
	qtdAcertos = 0;
	for(i = 0; i < 30 && !gameOver; i++ ){
		op1 = rand() % 10;
		op1++;
		op2 = rand() % 11;
		op2 *= op1;
		cout << op2 << " / " << op1 << " = ";
		cin >> res;
		if(acertouN11(op1, op2, res)){
			parabensAcertou();
			bonus++;
			qtdAcertos++;
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
			}
			else{
				cout << "Seu life eh: " << life << endl;
			}
		}
		if(i%10 == 0){
			fim = clock();
			tempoDecorrido(duracaoSeg_d(ini, fim));
		}
	}
	fim = clock();
	score = pontuacao(ini, fim, qtdAcertos, QTD_MAX_QUESTOES_N2, gameOver);
	processarRecorde(11, score, user, cargo);
	passouDeNivel = gameOver ? false : true;
	return passouDeNivel;
}

bool acertouN11(int i, int j, int res){
	bool acert;
	acert = (j/i == res)? true : false;
	return acert;
}
