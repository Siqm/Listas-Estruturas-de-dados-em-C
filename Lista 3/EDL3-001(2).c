#include <stdio.h>
#include <locale.h>
#define size 5

struct Livro {
	int codigo;
	char titulo[40];
	float preco;
};

struct Livro livros[size];
int topo = -1, chave = 0;

void empilhar () {
	
	if (topo == size - 1) {
		printf("Pilha cheia \n");
	} else {
		chave += 1;
		topo += 1;
		livros[topo].codigo = chave;
		
		printf("Criando cadastro para livro Codigo: %i \n", livros[topo].codigo);
		getchar();
		
		printf("Insira o titulo do livro: ");
		gets(livros[topo].titulo);
		
		printf("Insira o pre�o do livro: ");
		scanf("%f", &livros[topo].preco);
	}
}

void desempilhar () {
	
	if (topo == -1) {
		printf("Pilha vazia \n");
	} else {
		printf("Posi��o %i desempilhada", topo);
		topo -= 1;
	}
}

void imprimir () {
	if (topo == -1) {
		printf("Pilha vazia \n");
	} else {
		int i;
		for (i = topo; i > -1; i--) {
			printf("C�digo: %i \n", livros[i].codigo);
			printf("T�tulo do livro: ");
			puts(livros[i].titulo);
			printf("Pre�o: %.2f", livros[i].preco);
		}
	}
}

void main (int argc, char *argv) {
	setlocale (LC_ALL,"");
	
	int opcao = 0;
	
	while (opcao != 9) {
		printf("\t * MENU *\n");
		printf("1: Empilhar \n");
		printf("2: Desempilhar \n");
		printf("3: Imprimir \n");
		printf("9: Sair do programa \n");
		printf("Op��o escolhida: ");
		scanf("%i", &opcao);
		printf("\n");
		
		switch (opcao) {
			case 1:
				empilhar();
			break;
			
			case 2:
				desempilhar();
			break;
			
			case 3:
				imprimir();
			break;
		}
	}
}
