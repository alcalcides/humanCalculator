bool acertouN1(int i, int j, int res);
bool jogarNivel1(unsigned int &life, unsigned int &bonus, bool &gameOver);
double pontuacaoN1(clock_t ini, clock_t fim, unsigned int qtdAcertos, bool gameOver);
double duracaoSeg_d(clock_t ini, clock_t fim);


bool jogarNivel1(unsigned int &life, unsigned int &bonus, bool &gameOver){
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
	fim = ini = clock();;
	qtdAcertos = 0;
	for(i = 0; i < 11 && !gameOver; i++ ){
		op1 = i;
		for (k = 0; k < 12; ++k){
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
		fim = clock();
		cout << "Segundos decorridos: " << duracaoSeg_d(ini, fim) << " s" << endl;
		if(!gameOver) passouDeNivel = true;
	}
	fim = clock();
	score = pontuacaoN1(ini, fim, qtdAcertos, gameOver);
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

double pontuacaoN1(clock_t ini, clock_t fim, unsigned int qtdAcertos, bool gameOver){
	double pontuacao, duracao;
	
	duracao = duracaoSeg_d(ini, fim);
	cout << "Periodo decorrido: " << duracao << " s" << endl;

	pontuacao = (double)qtdAcertos/QTD_MAX_QUESTOES_N1;
	pontuacao *= 100;
	cout << "Coeficiente de Rendimento em N1: " << pontuacao << "%" << endl;
	
	if(!gameOver)
		pontuacao /= duracao;
	else 
		pontuacao = 0.0;
	cout << "Score em N1: " << pontuacao << " NERDS" << endl;

	return pontuacao;
}

double duracaoSeg_d(clock_t ini, clock_t fim){
	double duracao;	
	duracao = ((double)fim - (double)ini) / CLOCKS_PER_SEC;
	return duracao;
}