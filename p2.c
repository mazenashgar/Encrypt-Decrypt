
#include "functions.h"

int main(int argc, char* argv[]){

	int choice, strCounter, n;
	char* input;
	FILE *fin, *fout;
	
	if(argc != 5){
		printf("Usage: cipher_option key input_file output_file\n");
		printf("Option 1 for encrypt, option 2 for decrypt\n");
		exit(1);
	}

	choice = atoi(argv[1]);
	input = argv[2];

	strCounter = strlen(input);

	char* key = (char*) malloc(SIZE * sizeof(char));
	char* decryptArray = (char*) malloc(SIZE * sizeof(char));

	fin = fopen(argv[3], "r");
	fout = fopen(argv[4], "w");

	if(fin == NULL || fout == NULL){
		printf("couldn't access files\n");
		exit(1);
	}

	//find the duplicats
	for(int i = 0; i < strCounter; i++){
		int len = strlen(key);

		if(found(key, input[i]) == 1){
			key[len] = input[i];
			key[len + 1] = '\0';
		}
	}


	//perform the operation chosen	
	if(choice == 1){

		encrypt(key);
		writeToFile(fin, fout, key);
		//printf("\n\n\t\t%s has been encrypted to %s\n\n", argv[3], argv[4]);

	}else if(choice == 2){
		
		encrypt(key);
		decrypt(key, decryptArray);
		writeToFile(fin, fout, decryptArray);
		//printf("\n\n\t\t%s has been decrypted to %s\n\n", argv[3], argv[4]);
	}else{
		printf("invalid option");
		printf("Option 1 for encrypt, option 2 for decrypt\n");
	}
	return 0;
}
