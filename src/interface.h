void apresentacao(void);
string qualUsuario(void);
unsigned int menu (unsigned int nivel);
void parabensNivel(unsigned int nivel);
void parabensAcertou();
void mensagemErrouItem();
void maisLife(unsigned int &life, unsigned int &qtdConsecutivaAcertos);
void boasVindasNivel(unsigned int nivel);
unsigned int oferecerUpgrade(unsigned int &nivel);
bool zerouMaquina();
void relatorio(string user, string cargo, int nivel, int life, int bonus);
void perdeu();

void apresentacao(void){
	system("cls");
	
	cout << endl << endl << endl << endl << endl << endl << endl;
	cout <<	"****************************************" << endl;
	cout <<	"********** Calculadora Humana **********" << endl;
	cout <<	"****************************************" << endl;
	cout << endl;
}

string qualUsuario(void){
	string user;
	do{
		cout << "Username: " ;
		cin >> user;
		if (user.length() >= 10){
			cout << "Limite de 10 caracteres excedido" << endl;
		}
	} while (user.length() >= 10);
	return user;
}

unsigned int menu (unsigned int nivel){
	unsigned int op;
	int i;
	cout << "Menu: " << endl;
	cout << 0 << " para sair" << endl;
	for (i = 1; i <= nivel && i <= NUM_NIVEIS; ++i)	{
		cout << i << " para nivel " << i << endl;	
	}
	while(cin >> op, op > nivel);
	return op;
}

void parabensNivel(unsigned int nivel) { 
	cout <<	endl;
	cout <<	"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	cout <<	"^^^ Parabens! Voce passou no nivel " << nivel << " ^^^" << endl;
	cout <<	"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
}

void parabensAcertou(void){
	cout << "Resposta Correta :)" << endl;
}

void mensagemErrouItem(void){
	cout << "ERRRRRROU :(" << endl;
}

void maisLife(unsigned int &life, unsigned int &qtdConsecutivaAcertos){
	life++;
	cout << "Mais life!!!" << life << endl;
	qtdConsecutivaAcertos = 0;
}

void boasVindasNivel(unsigned int nivel){
	int w;
	cout <<	"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	cout <<	"^^^^ Nivel " << nivel << flush;
	for(int w = 0; w < 4; w++){
		Sleep(700);
		cout << "." << flush;
	}
	Sleep(1000);
	cout << " Esteja Preparado!" << flush;
	Sleep(2000);
	cout << "  ^^^^" << endl;
	cout <<	"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	Sleep(1000);
}

unsigned int oferecerUpgrade(unsigned int &nivel){
	char resp;
	int cmd;
	cout << "Nivel desbloqueado: Nivel " << nivel + 1 << endl;
	cout << "Quer fazer upgrade gratuito agora? (S/N): ";
	while(cin >> resp, resp != 'S' && resp != 'N');
	if(resp == 'S'){
		cmd = 1;
		nivel++;
	}
	else{
		cmd = 0;
	}
	return cmd;		
}

bool zerouMaquina(){
	cout << endl << endl;
	cout <<	"****************************************" << endl;
	cout <<	"***** Nossa! Voce Zerou a Maquina! *****" << endl;
	cout <<	"**************  Parabens  **************" << endl;
	cout <<	"****************************************" << endl;
	cout << endl;
	cout << endl;
	return true;
}

void relatorio(string user, string cargo, int nivel, int life, int bonus){
	cout << "User: " << user << endl;
	cout << "Cargo: " << cargo << endl;
	cout << "Nivel: " << nivel << endl;
	cout << "Life: " << life << endl;
	cout << "Bonus: " << bonus << endl;
}

void perdeu(){
	int i;
	cout << "Voce perdeu..." << flush;
	Sleep(1000);
	cout << "   :)" << flush; 
	Sleep(800);
	cout << "\b|" << flush;
	Sleep(120);
	cout << "\b(" << flush;
	Sleep(2000);
	cout << endl;
}