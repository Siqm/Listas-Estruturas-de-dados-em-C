#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Livro { // Defini��o de uma classe: Estrutura de um Livro
	int codigo;
	char titulo[20];
	float preco;
	struct Livro *proximo;
}Livro;

typedef struct Pilha { // Defini��o de uma classe: Estrutura de uma Pilha
	Livro *topo; 
//	Tudo que uma pilha tem � um ponteiro apontando para seu topo,
//	como estamos criando uma pilha de livros o ponteiro � do tipo
//	Livro.
}Pilha;

void inicializaPilha (Pilha *p) { // Sempre que uma pilha � criada, seu topo PRECISA ser nulo
	p->topo = NULL;
}

void push (Pilha *p) {
	Livro *ptr = (Livro*) malloc(sizeof(Livro)); // Criando ponteiro tempor�rio que apontar� para novo Livro a ser criado
	if (ptr == NULL) {
		printf("Erro de aloca��o \n");
	} else {
		getchar();
		printf("Insira o t�tulo do livro: ");
		gets(ptr->titulo);
		printf("Insira o c�digo do livro: "); // Linhas 28~34 apenas inser��o de dados referentes ao livro adicionado.
		scanf("%i", &ptr->codigo);
		
		printf("Insira o pre�o do livro: ");
		scanf("%f", &ptr->preco);
//	A grande sacada:
//	ptr neste momento tem todos os valores do livro a ser adicionado em nossa fila.
//	Linha 40 faz com que o ponteiro PROXIMO de LIVRO aponte para elemento mais recente adicionado na fila
//	Caso a fila esteja vazia Livro->proximo ser� igual a nulo
		ptr->proximo = p->topo;
//	Uma vez que um elemento � adicionado a fila, precisamos marcar este novo elemetno como o elemento do topo, logo o ponteiro
//	de nossa fila, apontara para o novo elemento criado.
		p->topo = ptr;
		printf("\n");
	}
}

//	Retorna 1 para true e 0 para false
int isEmpty (Pilha *p) {
	if (p->topo == NULL) {
		return 1;
	} else {
		return 0;
	}
}

void pop (Pilha *p) {
	Livro *ptr = p->topo; // Cria��o de ponteiro de Livro que aponta para elemento do topo
	if (isEmpty(p)) {
		printf("Pilha vazia \n");
	} else {
		p->topo = ptr->proximo; // Elemento do topo aponta para o elemento de baixo dele (Livro->proximo),
//	como este elemento ser� removido, o topo recebe o valor de Livro->proximo.
		printf("Codigo do livro sendo removido: %i \n", ptr->codigo);
		ptr->proximo = NULL; // Desligamento completo do elemento em quest�o com a fila.
		free(ptr);  // Libera��o de mem�ria no espa�o que o elemento ocupava.
	}
}

void imprimir (Pilha *p) {
	Livro *ptr = p->topo; // Cria��o de ponteiro de Livro que aponta para elemento do topo
	if (isEmpty(p)) {
		printf("Pilha vazia. \n\n");
	} else {
		while (ptr != NULL) {
			printf("C�digo do livro: %i \n", ptr->codigo);
			printf("Pre�o do livro: %f \n", ptr->preco);
			printf("Titulo do livro: ");
			puts(ptr->titulo);
			ptr = ptr->proximo;
			printf("\n");
		}
	}
}

float MaisCaro (Pilha *pilha) {
	float temporario;
	Livro *ptr = pilha->topo;

	if (pilha->topo == NULL) {
		printf("Fila vazia!");
	} else {
		printf("Informe o valor que deseja pesquisar: ");
		scanf("%f", &temporario);

		while (ptr != NULL) {
			if(ptr->preco > temporario) {
				printf("Valor encontrado na pesquisa! \n");
				printf("Codigo do livro: %i \n", ptr->codigo);
				printf("Pre�o do livro encontrado: %.2f \n\n", ptr->preco);
			}
			ptr = ptr->proximo;
		}
	}
}

void elementOnTop (Pilha *p) {
	
	if (isEmpty(p)) {
		printf("Pilha vazia! \n\n");
	} else {
		printf("T�tulo: ");
		puts(p->topo->titulo);
		printf("C�digo: �%i \n", p->topo->codigo);
		printf("Pre�o: %.2f \n\n", p->topo->preco);
	}
}

int sizeOf(Pilha *p) {
	int contador = 0;
	 Livro *ptr = p->topo;
	
	if(isEmpty(p)) {
		return 0;
	} else {
		while (ptr != NULL) {
			contador += 1;
			ptr = ptr->proximo;
		}
	}
	
	return contador;
}

void main () {
	setlocale(LC_ALL,"");
	Pilha *p1 = (Pilha*) malloc(sizeof(Pilha));
	int opcao = 0;
	
	if (p1 == NULL) {
		printf("Erro de aloca��o da pilha \n");
	} else {
		inicializaPilha(p1);
		while (opcao != 9) {
			printf(":: PILHA Livros :: \n");
			printf("1. Empilhar        \n");
			printf("2. Desempilhar     \n");
			printf("3. Imprimir        \n");
			printf("4. Elemento do topo \n");
			printf("5. Quantidade de elementos empilhados \n");
			printf("9. Sair \n");
			printf("Digite a opcao desejada: ");
			scanf("%d", &opcao);
			printf("\n");
			
			switch(opcao) {
				case 1:
					push(p1);
				break;
				
				case 2:
					pop(p1);
				break;
				
				case 3:
					imprimir(p1);
				break;
				
				case 4:
					elementOnTop(p1);
				break;
				
				case 5:
					printf("A quantidade de Livros na pilha � de: %i \n\n", sizeOf(p1));
				break;
				
				case 6:
					MaisCaro(p1);
				break;
			}
		}
		
	}
}


