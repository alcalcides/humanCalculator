bool acertouN5(int i, int j, int res);
bool jogarNivel5(unsigned int &life, unsigned int &bonus, bool &gameOver, string user, string &cargo);


bool jogarNivel5(unsigned int &life, unsigned int &bonus, bool &gameOver, string user, string &cargo){
	bool passouDeNivel;
	int i;
	int op1, op2;
	int res;
	clock_t ini, fim;
	unsigned int qtdAcertos;
	double score = 0;

	boasVindasNivel(5);
	cout << "Digite o resultado da subtração" << endl;

	srand (time(NULL));
	fim = ini = clock();
	qtdAcertos = 0;
	for(i = 0; i < 30 && !gameOver; i++ ){
		op1 = rand() % 11;
		op2 = rand() % 11;
		cout << op1 << " - " << op2 << " = ";
		cin >> res;
		if(acertouN5(op1, op2, res)){
			parabensAcertou();
			bonus++;
			qtdAcertos++;
			if(bonus == 5){
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
	processarRecorde(5, score, user, cargo);
	passouDeNivel = gameOver ? false : true;
	return passouDeNivel;
}

bool acertouN5(int i, int j, int res){
	bool acert;
	acert = (i-j == res)? true : false;
	if((i - j) < 0 && res == 0) acert = true; //o jogador não precisa saber números negativos
	return acert;
}
