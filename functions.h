//library

#ifndef CIPHER
#define CIPHER

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 26

int found(char* list, char input);
void encrypt(char* key);
void decrypt(char* key, char* decryptArray);
void writeToFile(FILE *fin,FILE *fout, char* key);
#endif 
