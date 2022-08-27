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

//	Verifica a condição de fila vazia, se verdadeiro returns 1,
//	se falso returns 0
int isEmpty(pilha topo) {
	
	if (topo == NULL) {
		return 1;
	} else {
		return 0;
	}
}

/*
A função  malloc  (o nome é uma abreviatura de memory allocation)
 aloca espaço para um bloco de bytes consecutivos na memória RAM
(= random access memory) do computador e devolve o endereço desse
bloco.  O número de bytes é especificado no argumento da função.
No seguinte fragmento de código, malloc aloca 1 byte: 
*/
vetorPilha* push(int idade, pilha topo) {
//	criação de um novo elemento
	pilha novoLivro;
	
//	atribuição dos valores do elemento
	novoLivro = malloc(sizeof(vetorPilha));
	printf("Insira o código do livro: ");
	scanf("%i", &novoLivro->codigo );
	printf("Insira o preço do livro: ");
	scanf("%f", &novoLivro->preco);
	getchar();
	printf("Insira o titulo do livro (até 20 caracteres): ");
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
			printf("Código: %i \n", auxiliar->codigo);
			printf("Título: ");
			puts(auxiliar->titulo);
			printf("Preço: %.2f", auxiliar->preco);
			auxiliar = auxiliar->prox;
		}
	}
}

void main () {
	printf("%i", 56);
	printf("%i", topoPilha);
}
