//implementation

#include "functions.h"
	
int found(char* list, char target){
	

	//find duplicates
	int counter = 0;
	while(*list != '\0'){
		if(counter > strlen(list)) return 1;

		if(list[counter] == target) return 0;
		list++;
		counter++;
	} 
	return 1;
}

void encrypt(char* key){

	//add the alphabets in reverse
	
	char letter = 'z';
	int len = 0;

	while(len != SIZE){	
		len = strlen(key);
	
		if(found(key, letter) == 1){
			key[len] = letter;
			key[len + 1] = '\0';
		} 
		letter--;
	} 
}

void decrypt(char* key, char* decryptArray){

	for(int i = 0; i < SIZE; i++){
		decryptArray[key[i] - 'a'] = 'a' + i;
	}
}

void writeToFile(FILE *fin, FILE *fout, char* key){
	char ch;
	while(fscanf(fin, "%c", &ch) != EOF){
		if(isalpha(ch)){
			fprintf(fout, "%c", key[ch - 'a']);
		}else{
			fprintf(fout, "%c", ch);
		}
	}
}
