bool registrarUsuario(char* user, string cargo, unsigned int nivel, unsigned int life, unsigned int bonus){
	FILE * regUsers;

	regUsers = fopen("regUsers.txt", "a+");
	if(regUsers == NULL){
		cout << "Falha na escrita de registros" << endl;
	}
	else{
		fprintf(regUsers, "User: %s \n", user); //verificar bug
		fprintf(regUsers, "Cargo: %s \n", cargo); //verificar bug
		fprintf(regUsers, "Nivel: %d\n", nivel);
		fprintf(regUsers, "Life: %d\n", life);
		fprintf(regUsers, "Bonus: %d\n", bonus);
		fprintf(regUsers, "     ==========     \n");
	}

	fclose(regUsers);
	return true;
}