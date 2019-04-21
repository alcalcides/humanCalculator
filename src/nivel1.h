bool acertouN1(int i, int j, int res);
void jogarNivel1(unsigned int &life, unsigned int &bonus, bool &gameOver);

void jogarNivel1(unsigned int &life, unsigned int &bonus, bool &gameOver){
	int i, j, k;
	int op1, op2;
	bool opUsado[11];
	int res;

	boasVindasNivel(1);
	cout << "Digite APENAS o algarismo das UNIDADES" << endl;

	srand (time(NULL));
	for(i = 0; i < 11 && !gameOver; ++i ){
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
	}
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