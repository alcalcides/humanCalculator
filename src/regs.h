void registrarUsuario(string user, string cargo, unsigned int nivel, unsigned int life, unsigned int bonus);
void buscarUser(string user, string &cargo, unsigned int &nivel, unsigned int &life, unsigned int &bonus);

void registrarUsuario(string user, string cargo, unsigned int nivel, unsigned int life, unsigned int bonus){
	fstream regUsers;
	regUsers.open("regUsers.txt", ios::app);
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
		cout << "Falha na escrita de registros" << endl;
	}
}

void buscarUser(string user, string &cargo, unsigned int &nivel, unsigned int &life, unsigned int &bonus){
	bool achou = false;
	char user_temp[10];
	char cargo_temp[10];
	
	FILE* regUsers;
	regUsers = fopen("regUsers.txt", "r");
	unsigned int nivel_temp, life_temp, bonus_temp;
	
	if(regUsers){
		while(!achou && fgetc(regUsers) != EOF){
			fscanf(regUsers, "ser: %s\n", user_temp);
			fscanf(regUsers, "Cargo: %s\n", cargo_temp);
			fscanf(regUsers, "Nivel: %u\n", &nivel_temp);
			fscanf(regUsers, "Life: %u\n", &life_temp);
			fscanf(regUsers, "Bonus: %u\n\n", &bonus_temp);

			if(user_temp == user){
				achou = true;
				cargo = cargo_temp;
				nivel = nivel_temp;
				life = life_temp;
				bonus = bonus_temp;
			}
		}
		if(!achou){
			cargo = "Estudante";
			nivel = 1;
			life = 5;
			bonus = 0;
		}
	}
	else{
		cout << "Nenhum usuario cadastrado ainda" << endl;
		cargo = "Estudante";
		nivel = 1;
		life = 5;
		bonus = 0;
	}

	fclose(regUsers);
}