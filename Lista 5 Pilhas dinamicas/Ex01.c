#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Livro { // Definição de uma classe: Estrutura de um Livro
	int codigo;
	char titulo[20];
	float preco;
	struct Livro *proximo;
}Livro;

typedef struct Pilha { // Definição de uma classe: Estrutura de uma Pilha
	Livro *topo; 
//	Tudo que uma pilha tem é um ponteiro apontando para seu topo,
//	como estamos criando uma pilha de livros o ponteiro é do tipo
//	Livro.
}Pilha;

void inicializaPilha (Pilha *p) { // Sempre que uma pilha é criada, seu topo PRECISA ser nulo
	p->topo = NULL;
}

void push (Pilha *p) {
	Livro *ptr = (Livro*) malloc(sizeof(Livro)); // Criando ponteiro temporário que apontará para novo Livro a ser criado
	if (ptr == NULL) {
		printf("Erro de alocação \n");
	} else {
		getchar();
		printf("Insira o título do livro: ");
		gets(ptr->titulo);
		printf("Insira o código do livro: "); // Linhas 28~34 apenas inserção de dados referentes ao livro adicionado.
		scanf("%i", &ptr->codigo);
		
		printf("Insira o preço do livro: ");
		scanf("%f", &ptr->preco);
//	A grande sacada:
//	ptr neste momento tem todos os valores do livro a ser adicionado em nossa fila.
//	Linha 40 faz com que o ponteiro PROXIMO de LIVRO aponte para elemento mais recente adicionado na fila
//	Caso a fila esteja vazia Livro->proximo será igual a nulo
		ptr->proximo = p->topo;
//	Uma vez que um elemento é adicionado a fila, precisamos marcar este novo elemetno como o elemento do topo, logo o ponteiro
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
	Livro *ptr = p->topo; // Criação de ponteiro de Livro que aponta para elemento do topo
	if (isEmpty(p)) {
		printf("Pilha vazia \n");
	} else {
		p->topo = ptr->proximo; // Elemento do topo aponta para o elemento de baixo dele (Livro->proximo),
//	como este elemento será removido, o topo recebe o valor de Livro->proximo.
		printf("Codigo do livro sendo removido: %i \n", ptr->codigo);
		ptr->proximo = NULL; // Desligamento completo do elemento em questão com a fila.
		free(ptr);  // Liberação de memória no espaço que o elemento ocupava.
	}
}

void imprimir (Pilha *p) {
	Livro *ptr = p->topo; // Criação de ponteiro de Livro que aponta para elemento do topo
	if (isEmpty(p)) {
		printf("Pilha vazia. \n\n");
	} else {
		while (ptr != NULL) {
			printf("Código do livro: %i \n", ptr->codigo);
			printf("Preço do livro: %f \n", ptr->preco);
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
				printf("Preço do livro encontrado: %.2f \n\n", ptr->preco);
			}
			ptr = ptr->proximo;
		}
	}
}

void elementOnTop (Pilha *p) {
	
	if (isEmpty(p)) {
		printf("Pilha vazia! \n\n");
	} else {
		printf("Título: ");
		puts(p->topo->titulo);
		printf("Código: ¨%i \n", p->topo->codigo);
		printf("Preço: %.2f \n\n", p->topo->preco);
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
		printf("Erro de alocação da pilha \n");
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
					printf("A quantidade de Livros na pilha é de: %i \n\n", sizeOf(p1));
				break;
				
				case 6:
					MaisCaro(p1);
				break;
			}
		}
		
	}
}


