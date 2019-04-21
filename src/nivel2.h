bool acertouN2(int i, int j, int res);
void jogarNivel2(unsigned int &life, unsigned int &bonus, bool &gameOver);


void jogarNivel2(unsigned int &life, unsigned int &bonus, bool &gameOver){

	int i;
	int op1, op2;
	int res;

	boasVindasNivel(2);
	cout << "Digite o resultado da soma" << endl;

	srand (time(NULL));
	for(i = 0; i < 30 && !gameOver; i++ ){
		op1 = rand() % 11;
		op2 = rand() % 11;
		cout << op1 << " + " << op2 << " = ";
		cin >> res;
		if(acertouN2(op1, op2, res)){
			parabensAcertou();
			bonus++;
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
	}
}



bool acertouN2(int i, int j, int res){
	bool acert;
	acert = (i+j == res)? true : false;
	return acert;
}