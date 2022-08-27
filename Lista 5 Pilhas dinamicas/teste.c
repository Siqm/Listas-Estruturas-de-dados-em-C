#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Livro {
	int codigo;
	char titulo[20];
	float preco;
	struct Livro *prox;
};

typedef struct Livro *vetorPilha; // definir tipo de Variavel de ponteiro para Livro
typedef vetorPilha pilha; // definir tipo de variavel 

pilha topoPilha; // Variavel do tipo ponteiro de 

vetorPilha* criar (pilha p) {
	p = NULL;
	return p;
}

//	Verifica a condi��o de fila vazia, se verdadeiro returns 1,
//	se falso returns 0
int isEmpty(pilha topo) {
	
	if (topo == NULL) {
		return 1;
	} else {
		return 0;
	}
}

/*
A fun��o  malloc  (o nome � uma abreviatura de memory allocation)
 aloca espa�o para um bloco de bytes consecutivos na mem�ria RAM
(= random access memory) do computador e devolve o endere�o desse
bloco.  O n�mero de bytes � especificado no argumento da fun��o.
No seguinte fragmento de c�digo, malloc aloca 1 byte: 
*/
vetorPilha* push(int idade, pilha topo) {
//	cria��o de um novo elemento
	pilha novoLivro;
	
//	atribui��o dos valores do elemento
	novoLivro = malloc(sizeof(vetorPilha));
	printf("Insira o c�digo do livro: ");
	scanf("%i", &novoLivro->codigo );
	printf("Insira o pre�o do livro: ");
	scanf("%f", &novoLivro->preco);
	getchar();
	printf("Insira o titulo do livro (at� 20 caracteres): ");
	gets(novoLivro->titulo);
	
//	elemento aponta para o topo da pilha
	novoLivro->prox = topo;
	
	return novoLivro;
}

vetorPilha* pop(pilha topo) {
	pilha auxiliar;
	
	if (isEmpty()) {
		printf("Pilha vazia! \n");
		
		return;
	} else {
		auxiliar = topo;
		
		auxiliar = topo->prox;
		free(topo);
		
		return auxiliar;
	}
}

void imprimir (pilha topo) {
	pilha auxiliar;
	
	if (isEmpty()) {
		printf("Pilha vazia! \n");
	} else {
		auxiliar = topo;
		
		while (auxiliar != NULL) {
			printf("C�digo: %i \n", auxiliar->codigo);
			printf("T�tulo: ");
			puts(auxiliar->titulo);
			printf("Pre�o: %.2f", auxiliar->preco);
			auxiliar = auxiliar->prox;
		}
	}
}

void main () {
	printf("%i", 56);
	printf("%i", topoPilha);
}
