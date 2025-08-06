#include <stdio.h>
#define MAX_BUFFER 10240

typedef unsigned char byte;

void copyString(char *out, char *in, int count);
int strSize(char* string);
byte compare_strings(char* str1, char* str2, int count);
byte str_in_str(char* pattern, char* string);

int main(int argc, char** argv){
	char entrada[MAX_BUFFER] = {'\0'};
	fgets(entrada, MAX_BUFFER, stdin);
	if (entrada[MAX_BUFFER-2] != '\0') {
		printf("A entrada não foi lida por inteiro. A leitura parou em: [%s]\n", entrada+MAX_BUFFER-20);
	}
	printf("%s\n", str_in_str(argv[1], entrada) ? "Padrão encontrado" : "Padrão não encontrado");

	return 0;
}

// Copia count caracteres de in para out
void copyString(char *out, char *in, int count){
	for(int i = 0; i < count; i++) {
		out[i] = in[i];
	}
}

// Retorna a quantidade de caracteres não-nulos em uma string
int strSize(char* string){
	int count = 0;
	for (int i = 0; string[i] != '\0'; i++) count++;
	return count;
}

// Compara duas strings em count caracteres. Retorna true se iguais.
byte compare_strings(char* str1, char* str2, int count){
	for (int i = 0; i < count; i++){
		if (str1[i] != str2[i]) return 0;
	}
	return 1;
}

// Retorna true se pattern estiver em string
byte str_in_str(char* pattern, char* string){
	int patternSize = strSize(pattern);
	int stringSize = strSize(string);

	char treatedPattern[patternSize];
	copyString(treatedPattern, pattern, patternSize);

	for (int position = 0; patternSize + position <= stringSize; position++){
		if (compare_strings(treatedPattern, string+position, patternSize)) return 1;
	}
	return 0;
}
