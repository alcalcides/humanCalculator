void mostrarRecordistas();

void mostrarRecordistas(){
	int nivel;
	char user[TAM_USER+1];
	unsigned int score;
	FILE *regs;
	regs = fopen("winners.txt", "r");
	if(regs){
		cout << endl;
		cout << "Nivel\tUser\tScore" << endl; 
		while(fscanf(regs, "%d", &nivel), !feof(regs)){
			fscanf(regs, "\n%s\n", user);
			fscanf(regs, "%u\n", &score);
			printf("%d\t%s\t%u\n", nivel, user, score);
		}
		cout << endl;
		fclose(regs);
	}
	else{
		cout << "ERRO: Falha ao ler recordistas" << endl;
	}
}