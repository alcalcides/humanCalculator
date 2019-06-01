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
	cout << endl << "Nivel\tUser\tScore" << endl; 
	
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
	regs = fopen("_localRecords/n4.txt", "r");
	if(regs){
		fscanf(regs, "%lf\t%s\n", &score, user);
		fclose(regs);
		printf("%d\t%s\t%lf\n", 4, user, score);
	}
	else{
		cout << endl;
	}
	regs = fopen("_localRecords/n5.txt", "r");
	if(regs){
		fscanf(regs, "%lf\t%s\n", &score, user);
		fclose(regs);
		printf("%d\t%s\t%lf\n", 5, user, score);
	}
	else{
		cout << endl;
	}
	regs = fopen("_localRecords/n6.txt", "r");
	if(regs){
		fscanf(regs, "%lf\t%s\n", &score, user);
		fclose(regs);
		printf("%d\t%s\t%lf\n", 6, user, score);
	}
	else{
		cout << endl;
	}
	regs = fopen("_localRecords/n7.txt", "r");
	if(regs){
		fscanf(regs, "%lf\t%s\n", &score, user);
		fclose(regs);
		printf("%d\t%s\t%lf\n", 7, user, score);
	}
	else{
		cout << endl;
	}
	regs = fopen("_localRecords/n8.txt", "r");
	if(regs){
		fscanf(regs, "%lf\t%s\n", &score, user);
		fclose(regs);
		printf("%d\t%s\t%lf\n", 8, user, score);
	}
	else{
		cout << endl;
	}
	regs = fopen("_localRecords/n9.txt", "r");
	if(regs){
		fscanf(regs, "%lf\t%s\n", &score, user);
		fclose(regs);
		printf("%d\t%s\t%lf\n", 9, user, score);
	}
	else{
		cout << endl;
	}
	regs = fopen("_localRecords/n10.txt", "r");
	if(regs){
		fscanf(regs, "%lf\t%s\n", &score, user);
		fclose(regs);
		printf("%d\t%s\t%lf\n", 10, user, score);
	}
	else{
		cout << endl;
	}
	regs = fopen("_localRecords/n11.txt", "r");
	if(regs){
		fscanf(regs, "%lf\t%s\n", &score, user);
		fclose(regs);
		printf("%d\t%s\t%lf\n", 11, user, score);
	}
	else{
		cout << endl;
	}
	regs = fopen("_localRecords/n12.txt", "r");
	if(regs){
		fscanf(regs, "%lf\t%s\n", &score, user);
		fclose(regs);
		printf("%d\t%s\t%lf\n", 12, user, score);
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
		case 4:
			bookOfRecords = fopen("_localRecords/n4.txt", "r");
			break;
		case 5:
			bookOfRecords = fopen("_localRecords/n5.txt", "r");
			break;
		case 6:
			bookOfRecords = fopen("_localRecords/n6.txt", "r");
			break;
		case 7:
			bookOfRecords = fopen("_localRecords/n7.txt", "r");
			break;
		case 8:
			bookOfRecords = fopen("_localRecords/n8.txt", "r");
			break;
		case 9:
			bookOfRecords = fopen("_localRecords/n9.txt", "r");
			break;
		case 10:
			bookOfRecords = fopen("_localRecords/n10.txt", "r");
			break;
		case 11:
			bookOfRecords = fopen("_localRecords/n11.txt", "r");
			break;
		case 12:
			bookOfRecords = fopen("_localRecords/n12.txt", "r");
			break;
		default:
			bookOfRecords = NULL;
	}
	if(bookOfRecords){
		fscanf(bookOfRecords, "%lf\t%s\n", &lastRecord, user);
		isRecordista = lastRecord < score ? true : false;
		reportarRecordeAnterior(user, lastRecord);
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
		case 4:
			bookOfRecords = fopen("_localRecords/n4.txt", "w");
			break;
		case 5:
			bookOfRecords = fopen("_localRecords/n5.txt", "w");
			break;
		case 6:
			bookOfRecords = fopen("_localRecords/n6.txt", "w");
			break;
		case 7:
			bookOfRecords = fopen("_localRecords/n7.txt", "w");
			break;
		case 8:
			bookOfRecords = fopen("_localRecords/n8.txt", "w");
			break;
		case 9:
			bookOfRecords = fopen("_localRecords/n9.txt", "w");
			break;
		case 10:
			bookOfRecords = fopen("_localRecords/n10.txt", "w");
			break;
		case 11:
			bookOfRecords = fopen("_localRecords/n11.txt", "w");
			break;
		case 12:
			bookOfRecords = fopen("_localRecords/n12.txt", "w");
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
		case 4:
			novoCargo = "SubtratorN1";
			break;
		case 5:
			novoCargo = "SubtratorN2";
			break;
		case 6:
			novoCargo = "SubtratorN3";
			break;
		case 7:
			novoCargo = "MultiplicadorN1";
			break;
		case 8:
			novoCargo = "MultiplicadorN2";
			break;
		case 9:
			novoCargo = "MultiplicadorN3";
			break;
		case 10:
			novoCargo = "DivisorN1";
			break;
		case 11:
			novoCargo = "DivisorN2";
			break;
		case 12:
			novoCargo = "DivisorN3";
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