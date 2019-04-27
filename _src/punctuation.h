double duracaoSeg_d(clock_t ini, clock_t fim);
double coeRendimento(int numAcertos, int numItens);
bool verificarRecorde(unsigned int nivel, double score);
FILE* registrarRecorde(unsigned int nivel, double score, string user);
void atualizarCargo(string &cargo, string novoCargo);
string atualizarCargoPeloNivel(unsigned int nivel);
double pontuacao(clock_t ini, clock_t fim, unsigned int qtdAcertos, unsigned int qtdTotalItens, bool gameOver);
void processarRecorde(unsigned int nivel, double score, string user, string &cargo);
void mostrarRecordistas();


void mostrarRecordistas(){
	char user[TAM_USER+1];
	double score;
	cout << "Nivel\tUser\tScore" << endl; 
	
	FILE *regs;
	regs = fopen("_localRecords/n1.txt", "r");
	if(regs){
		fscanf(regs, "%lf\t%s\n", &score, user);
		fclose(regs);
		printf("%d\t%s\t%lf\n", 1, user, score);
	}
	else{
		cout << endl;
	}
	regs = fopen("_localRecords/n2.txt", "r");
	if(regs){
		fscanf(regs, "%lf\t%s\n", &score, user);
		fclose(regs);
		printf("%d\t%s\t%lf\n", 2, user, score);
	}
	else{
		cout << endl;
	}
	regs = fopen("_localRecords/n3.txt", "r");
	if(regs){
		fscanf(regs, "%lf\t%s\n", &score, user);
		fclose(regs);
		printf("%d\t%s\t%lf\n", 3, user, score);
	}
	else{
		cout << endl;
	}
}
double duracaoSeg_d(clock_t ini, clock_t fim){
	double duracao;	
	duracao = ((double)fim - (double)ini) / CLOCKS_PER_SEC;
	return duracao;
}

double coeRendimento(int numAcertos, int numItens){
	double cr;	
	cr = (double)numAcertos/numItens;
	cr *= 100;
	return cr;
}

bool verificarRecorde(unsigned int nivel, double score){
	bool isRecordista;
	double lastRecord = 0;
	char user[TAM_USER+1];
	FILE *bookOfRecords;
	switch (nivel){
		case 1:
			bookOfRecords = fopen("_localRecords/n1.txt", "r");
			break;
		case 2:
			bookOfRecords = fopen("_localRecords/n2.txt", "r");
			break;
		case 3:
			bookOfRecords = fopen("_localRecords/n3.txt", "r");
			break;
		default:
			bookOfRecords = NULL;
	}
	if(bookOfRecords){
		fscanf(bookOfRecords, "%lf\t%s\n", &lastRecord, user);
		isRecordista = lastRecord < score ? true : false;
		fclose(bookOfRecords);
	}
	else{
		isRecordista = true;
	}
	return isRecordista;
}

FILE* registrarRecorde(unsigned int nivel, double score, string user){
	FILE *bookOfRecords;
	switch (nivel){
		case 1:
			bookOfRecords = fopen("_localRecords/n1.txt", "w");
			break;
		case 2:
			bookOfRecords = fopen("_localRecords/n2.txt", "w");
			break;
		case 3:
			bookOfRecords = fopen("_localRecords/n3.txt", "w");
			break;
		default:
			bookOfRecords = NULL;
	}
	if(bookOfRecords){
		fprintf(bookOfRecords, "%lf\t%s\n", score, user.c_str());
		fclose(bookOfRecords);
	}
	else{
		bookOfRecords = NULL;
		cout << "ERRO: nao ha arquivo para armazenar recordista" << endl;
	}
	return bookOfRecords;
}

void atualizarCargo(string &cargo, string novoCargo){
	cargo = novoCargo;
}

string atualizarCargoPeloNivel(unsigned int nivel){
	string novoCargo;
	switch(nivel){
		case 1:
			novoCargo = "SomadorN1";
			break;
		case 2:
			novoCargo = "SomadorN2";
			break;
		case 3:
			novoCargo = "SomadorN3";
			break;
		default:
			cout << "ERRO: Nao ha cargo para este nivel" << endl;
			novoCargo = "Nivel " + nivel;
			break;
	}
	return novoCargo;
}

double pontuacao(clock_t ini, clock_t fim, unsigned int qtdAcertos, unsigned int qtdTotalItens, bool gameOver){
	double pontuacao, cr, duracao;
	
	duracao = duracaoSeg_d(ini, fim);
	cout << "Periodo decorrido: " << duracao << " s" << endl;

	cr = coeRendimento(qtdAcertos, qtdTotalItens);
	cout << "Coeficiente de Rendimento: " << cr << "%" << endl;
	
	if(!gameOver)
		pontuacao = cr/duracao;
	else 
		pontuacao = 0.0;
	cout << "Score: " << pontuacao << " NERDS" << endl;

	return pontuacao;
}

void processarRecorde(unsigned int nivel, double score, string user, string &cargo){
	if(verificarRecorde(nivel, score)){
		parabenizarRecorde(nivel, score, user);
		registrarRecorde(nivel, score, user);
		atualizarCargo(cargo, "Recordista");
	}
}