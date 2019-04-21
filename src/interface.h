void apresentacao(void);
string qualUsuario(void);
unsigned int menu (unsigned int nivel);
void verSituacao(int life, int bonus);
bool passou (int life, int bonus);
bool perdeu (int life, int bonus);
void parabensNivel(unsigned int nivel);
void parabensAcertou();
void mensagemErrouItem();
void maisLife(unsigned int &life, unsigned int &qtdConsecutivaAcertos);
void boasVindasNivel(unsigned int nivel);
unsigned int oferecerUpgrade(unsigned int &nivel);
bool zerouMaquina();
void relatorio(string user, string cargo, int nivel, int life, int bonus);

void apresentacao(void){
	cout << endl << endl << endl << endl << endl << endl << endl;
	cout <<	"****************************************" << endl;
	cout <<	"********** Calculadora Humana **********" << endl;
	cout <<	"****************************************" << endl;
	cout << endl;
}

string qualUsuario(void){
	string user;
	cout << "Username: " ;
	cin >> user;
	return user;
}


void verSituacao(int life, int bonus){
	cout << "Life: " << life << endl;
	cout << "Acertos Consecutivos: " << bonus << endl;
}

unsigned int menu (unsigned int nivel){
	unsigned int op;
	int i;
	cout << "Menu: " << endl;
	cout << 0 << " para sair" << endl;
	for (i = 1; i <= nivel; ++i)	{
		cout << i << " para nivel " << i << endl;	
	}
	while(cin >> op, op > nivel);
	return op;
}

bool perdeu (int life, int bonus){
	cout << "Voce PERDEU" << endl;
	cout << ":(" << endl;
	verSituacao(life, bonus);
	return false;
}

bool passou (int life, int bonus){
	cout << "Parabéns! Voce passou de nivel!" << endl;
	verSituacao(life, bonus);
	return true;
}

void parabensNivel(unsigned int nivel) { 
	cout <<	endl;
	cout <<	"^^^ Parabéns! Você passou no nível " << nivel << " ^^^" << endl;
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
	cout <<	"^^^^ Nivel " << nivel << " => ";	
	cout << " Esteja Preparado!  ^^^^" << endl << endl;
	Sleep(2000);
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