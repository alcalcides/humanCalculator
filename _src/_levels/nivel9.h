bool acertouN9(int i, int j, int res);
bool jogarNivel9(unsigned int &life, unsigned int &bonus, bool &gameOver, string user, string &cargo);


bool jogarNivel9(unsigned int &life, unsigned int &bonus, bool &gameOver, string user, string &cargo){
	bool passouDeNivel;
	int op1, op2;
	int res;
	clock_t ini, fim;
	unsigned int qtdAcertos, qtdPerguntas;
	double score = 0;

	boasVindasNivel(9);
	cout << "Digite o resultado da multiplicacao" << endl;

	srand (time(NULL));
	/*obs 1:
		O nível 9 tem no mínimo 2 operações
		quando sempre é sorteado o valor 10. 
		No pior das hipóteses, sempre é sorteado 
		o valor 1 e então, haverá infinitas operações.
		No pior caso razoável, sempre é sorteado 
		o valor 2 e, então, haverá 9 operações.
	*/
	fim = ini = clock();
	qtdAcertos = qtdPerguntas = 0;
	op1 = 1;
	do{
		do{
			op2 = rand() % 11;
		} while(!op2);
		cout << op1 << " x " << op2 << " = ";
		qtdPerguntas++;
		cin.ignore();
		cin >> res;
		if(acertouN9(op1, op2, res)){
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
		op1 *= op2;
		if(op1%10 == 0 && !gameOver){
			fim = clock();
			tempoDecorrido(duracaoSeg_d(ini, fim));
		}

	} while(op1 < 500 && !gameOver); //obs 1
	fim = clock();
	score = pontuacao(ini, fim, qtdAcertos, qtdPerguntas, gameOver);
	processarRecorde(9, score, user, cargo);
	passouDeNivel = gameOver ? false : true;
	return passouDeNivel;
}

bool acertouN9(int i, int j, int res){
	bool acert;
	acert = (i*j == res || (i*j > 500 && res==0) )? true : false;
	return acert;
}