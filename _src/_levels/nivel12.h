bool acertouN12(int i, int j, int res);
bool jogarNivel12(unsigned int &life, unsigned int &bonus, bool &gameOver, string user, string &cargo);


bool jogarNivel12(unsigned int &life, unsigned int &bonus, bool &gameOver, string user, string &cargo){
	bool passouDeNivel;
	int op1, op2;
	int res;
	clock_t ini, fim;
	unsigned int qtdAcertos, qtdPerguntas;
	double score = 0;

	boasVindasNivel(12);
	cout << "Digite o algarismo mais significativo" << endl;

	srand (time(NULL));
	/*obs 1:
		O nível 12 tem no mínimo 3 operações
		quando sempre é sorteado o valor 10. 
		No pior das hipóteses, sempre é sorteado 
		o valor 1 e então, haverá infinitas operações.
		No pior caso razoável, sempre é sorteado 
		o valor 2 e, então, haverá 10 operações.
	*/
	fim = ini = clock();
	qtdAcertos = qtdPerguntas = 0;
	op2 = 500;
	do{
		op1 = rand() % 10;
		op1++;
		cout << op2 << " / " << op1 << " = ";
		qtdPerguntas++;
		cin.ignore();
		cin >> res;
		if(acertouN12(op1, op2, res)){
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
		op2 /= op1;
	} while(op2 > 0 && !gameOver); //obs 1
	
	fim = clock();
	score = pontuacao(ini, fim, qtdAcertos, qtdPerguntas, gameOver);
	processarRecorde(12, score, user, cargo);
	passouDeNivel = gameOver ? false : true;
	return passouDeNivel;
}

bool acertouN12(int i, int j, int res){
	int temp;
	bool acert;
	int resC = j/i;	//i nunca é zero porque op1 nunca é zero
	temp = resC;
	while(resC>0){
		temp = resC;
		resC /= 10;
	}
	resC = temp;
	acert = (resC == res) ? true : false;
	return acert;
}