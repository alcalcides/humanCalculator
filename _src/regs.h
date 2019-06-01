void registrarUsuario(string user, string cargo, unsigned int nivel, unsigned int life, unsigned int bonus);
long int buscarUser(string user);
bool atualizarUser(long int idUser, string user, string cargo, unsigned int nivel, unsigned int life, unsigned int bonus);
bool carregarUser(long int idUser, string &cargo, unsigned int &nivel, unsigned int &life, unsigned int &bonus);

void registrarUsuario(string user, string cargo, unsigned int nivel, unsigned int life, unsigned int bonus){
	fstream regUsers;
	regUsers.open("regUsers.txt", ios::out | ios::app);
	if(regUsers.is_open()){	
		regUsers << "User: " << user << endl;
		regUsers << "Cargo: " << cargo << endl;
		regUsers << "Nivel: " << nivel << endl;
		regUsers << "Life: " << life << endl;
		regUsers << "Bonus: " << bonus << endl;
		regUsers << endl;
		regUsers.close();
		cout << endl << "Dados salvos" << endl;
	}
	else{
		cout << endl << "Falha na escrita de registros" << endl;
	}
}

long int buscarUser(string user){
	long int idUser;
	bool achou = false;
	char user_temp[TAM_USER + 1];
	char cargo_temp[TAM_CARGO + 1];
	unsigned int nivel_temp, life_temp, bonus_temp;
	
	FILE* regUsers;
	regUsers = fopen("regUsers.txt", "r");
	
	if(regUsers){
		idUser = ftell(regUsers);
		while(!achou && fgetc(regUsers) != EOF){			
			fscanf(regUsers, "ser: %s\n", user_temp);
			fscanf(regUsers, "Cargo: %s\n", cargo_temp);
			fscanf(regUsers, "Nivel: %u\n", &nivel_temp);
			fscanf(regUsers, "Life: %u\n", &life_temp);
			fscanf(regUsers, "Bonus: %u\n\n", &bonus_temp);
			if(user_temp == user){
				achou = true;
			}
			else{
				idUser = ftell(regUsers);
			}
		}
		if(!achou){
			idUser = -1;
		}
		fclose(regUsers);
	}
	else{
		idUser = -2;
	}

	return idUser;
}

bool atualizarUser(long int idUser, string user, string cargo, unsigned int nivel, unsigned int life, unsigned int bonus){
	bool atualizado;

	FILE* regUsers;
	regUsers = fopen("regUsers.txt", "r+");
	
	if(regUsers){
		fseek(regUsers, idUser, SEEK_SET);
		fprintf(regUsers, "User: %s\n", user.c_str());
		fprintf(regUsers, "Cargo: %s\n", cargo.c_str());
		fprintf(regUsers, "Nivel: %u\n", nivel);
		fprintf(regUsers, "Life: %u\n", life);
		fprintf(regUsers, "Bonus: %u\n\n", bonus);
		fclose(regUsers);
		atualizado = true;
	}
	else {
		atualizado = false;
	}

	return atualizado;
}

bool carregarUser(long int idUser, string &cargo, unsigned int &nivel, unsigned int &life, unsigned int &bonus){
	bool carregado;

	char user_temp[TAM_USER + 1]; 
	char cargo_temp[TAM_CARGO + 1];
	unsigned int nivel_temp, life_temp, bonus_temp;

	FILE* regUsers;
	regUsers = fopen("regUsers.txt", "r");
	
	if(regUsers){
		fseek(regUsers, idUser, SEEK_SET);
		fscanf(regUsers, "User: %s\n", user_temp);
		fscanf(regUsers, "Cargo: %s\n", cargo_temp);
		fscanf(regUsers, "Nivel: %u\n", &nivel_temp);
		fscanf(regUsers, "Life: %u\n", &life_temp);
		fscanf(regUsers, "Bonus: %u\n\n", &bonus_temp);
		fclose(regUsers);
		cargo = cargo_temp;
		nivel = nivel_temp;
		life = life_temp;
		bonus = bonus_temp;
		carregado = true;
	}
	else {
		carregado = false;
	}

	return carregado;
}