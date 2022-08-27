#include <stdio.h>
#include <locale.h>
#define size 10

struct livro {
	int cod;
	char titulo[21];
	float preco
};

struct livro pilhaLivros[size];

void inicializaVetor () {
	int i = 0;
	
	for (i = 0; i < size; i++) {
		pilhaLivros[i].cod = 0;
	}
}

void imprimeVetor (int *fp) {
	int i = 0;
	
	for (i = 0; i < *fp+1; i++) {
		printf("Livro Codigo: %i \n", pilhaLivros[i].cod);
		printf(" Titulo: ");
		puts(pilhaLivros[i].titulo);
		printf("\t Preço: %f \n", pilhaLivros[i].preco);
	}
}

void empilhar (int *fp, int *codigo) {
	
	if (*fp == size - 1) {
		printf("Pilha cheia! \n");
	} else {
		*fp += 1;
		int i = *fp;
		*codigo += 1;
		pilhaLivros[*fp].cod = *codigo;
		
		printf("Codigo do novo livro: %i\n", pilhaLivros[*fp].cod);
		
		printf("Insira o titulo do livro: ");
		gets(pilhaLivros[i].titulo);
		
		printf("Insira o preço do livro: ");
		scanf("%f", &pilhaLivros[*fp].preco);
	}
}

void main (int argc, char *argv[]) {
	setlocale(LC_ALL,"");
	
	int firstPos = -1, codigo = 0, opcao;
	
	while (opcao != 9) {
		printf("\t * MENU *\n");
		printf("1: Empilhar \n");
		printf("2: Desempilhar \n");
		printf("3: Imprimir \n");
		printf("9: Sair do programa \n");
		printf("Opção escolhida: ");
		scanf("%i", &opcao);
		printf("\n");
		
		switch (opcao) {
			case 1:
				empilhar(&firstPos, &codigo);
			break;
			
			case 2:
				
			break;
			
			case 3:
				imprimeVetor(&firstPos);
			break;
			
			case 4:
				
			break;
		}
	}
//		MENU
//	1 - Empilhar
//	2 - Desempilhar
//	3 - Imprimir
//	99 - Sair

	return 0;
}
