bool acertouN3(int i, int j, int res);
bool jogarNivel3(unsigned int &life, unsigned int &bonus, bool &gameOver, string user, string &cargo);


bool jogarNivel3(unsigned int &life, unsigned int &bonus, bool &gameOver, string user, string &cargo){
	bool passouDeNivel;
	int op1, op2;
	int res;
	clock_t ini, fim;
	unsigned int qtdAcertos, qtdPerguntas;
	double score = 0;

	boasVindasNivel(3);
	cout << "Digite o resultado da soma" << endl;

	srand (time(NULL));
	/*obs 1:
		O nível 3 tem no mínimo 15 operações
		quando sempre é sorteado o valor 10. 
		No pior das hipóteses, sempre é sorteado 
		o valor 0 e então, haverá infinitas operações.
		No pior caso razoável, sempre é sorteado 
		o valor 1 e, então, haverá 150 operações.
	*/
	fim = ini = clock();
	qtdAcertos = qtdPerguntas = 0;
	op1 = 0;
	do{
		op2 = rand() % 11;
		cout << op1 << " + " << op2 << " = ";
		qtdPerguntas++;
		cin.ignore();
		cin >> res;
		if(acertouN3(op1, op2, res)){
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
		op1 += op2;
		if(op1%10 == 0 && !gameOver){
			fim = clock();
			tempoDecorrido(duracaoSeg_d(ini, fim));
		}

	} while(op1 < 150 && !gameOver); //obs 1
	fim = clock();
	score = pontuacao(ini, fim, qtdAcertos, qtdPerguntas, gameOver);
	processarRecorde(3, score, user, cargo);
	passouDeNivel = gameOver ? false : true;
	return passouDeNivel;
}

bool acertouN3(int i, int j, int res){
	bool acert;
	acert = (i+j == res)? true : false;
	return acert;
}