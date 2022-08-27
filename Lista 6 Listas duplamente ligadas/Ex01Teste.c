
#include <locale.h>
#include <stdio.h>

typedef struct Livro {
	int codigo;
	char nome[25];
	int classificacao;
	float preco;
	struct Livro *proximo;
	struct Livro *anterior;
}Livro;

typedef struct Lista {
	Livro *inicio;
	Livro *final;
	int quantidadeItens;
	float maior;
	int contaTerror, contaAvent, contaFic, contaCienc;
}Lista;

Livro *criaLivro () {
	Livro *temporario = (Livro*) malloc(sizeof(Livro));
	
	if (temporario == NULL) {
		printf("Erro de alocação do Livro! \n");
	} else {
		printf("Insira o codigo do livro: ");
		scanf("%i", &temporario->codigo);
		getchar();
		printf("Insira o nome do livro: ");
		gets(temporario->nome);
		printf("Classificações disponíveis: \n");
		printf("1-Terror \n2-Aventura \n3-Ficção \n4-Ciencia \n");
		printf("Insira o numero da calssificação do livro: ");
		scanf("%i", &temporario->classificacao);
		printf("Insira o preço do livro: ");
		scanf("%f", &temporario->preco);
		
		return temporario;
	}
}

Lista *criaLista ()  {
	Lista *l1 = (Lista*) malloc(sizeof(Lista));
	
	if (l1 == NULL) {
		printf("Erro de alocação da lista! \n");
	} else {
		l1->final = NULL;
		l1->inicio = NULL;
		l1->maior = 0.0;
		l1->quantidadeItens = 0;
		l1->contaAvent = 0;
		l1->contaCienc = 0;
		l1->contaFic = 0;
		l1->contaTerror = 0;
		return l1;
	}
}

float comparaMaior (float maior, float daVez) {
	
	if (maior > daVez) {
		return daVez;
	}
	return maior;
}

int isEmpty (Lista *l1) {
	if (l1->inicio == NULL) {
		return 1;
	}
	return 0;
}

int singleElementOnList (Lista *l1) {
	
	if (l1->final == NULL) {
		return 1;
	}
	return 0;
}

Livro *comparaCodigo (Lista *l1, int codigo) {
	Livro *compara;
	
	for (compara = l1->inicio; compara->codigo == codigo || compara->proximo == NULL; compara = compara->proximo) {
	}
	if (compara->codigo == codigo) {
		return compara;
	} else {
		printf("Codigo não encontrado \n\n");
		return NULL;
	}
}

void imprimeLivro (Livro *livro) {
	
	printf("Código: %i \n", livro->codigo);
	printf("Nome: ");
	puts(livro->nome);
	printf("Classificação: ");
	puts(livro->classificacao);
	printf("Preço: %.2f \n\n", livro->preco);
}

void comparaClassificacao (Lista *lista) {
	
	if(lista->contaAvent > lista->contaCienc && lista->contaAvent > lista->contaFic && lista->contaAvent > lista->contaCienc) {
		
		printf("Aventura tem mais titulos, total: %i \n", lista->contaAvent);
	} else if (lista->contaCienc > lista->contaAvent && lista->contaCienc > lista->contaFic && lista->contaCienc > lista->contaTerror) {
		
		printf("Ciencia tem mais titulos, total: %i \n", lista->contaCienc);
	} else if (lista->contaFic > lista->contaCienc && lista->contaFic > lista->contaAvent && lista->contaFic > lista->contaTerror) {
		
		printf("Ficção tem mais titulos, total: %i \n", lista->contaFic);
	} else {
		
		printf("Terror tem mais titulos, total: %i \n", lista->contaTerror);
	}
}

void controlaClassificacao (Lista *lista, int classificacao) {
	if (classificacao == 1) {
		
		lista->contaTerror++;
	} else if (classificacao == 2) {
		
		lista->contaAvent++;
	} else if (classificacao == 3) {
		
		lista->contaFic++;
	} else {
		
		lista->contaCienc++;
	}
}

void adicionaFinal (Lista *lista) {
	Livro *livroTemporario = criaLivro();
	
	if(isEmpty(lista)) {
		lista->inicio = livroTemporario;
	} else {
		
		if(singleElementOnList(lista)) {
			lista->inicio->proximo = livroTemporario;
			lista->final = livroTemporario;
			livroTemporario->anterior = lista->inicio;
		} else {
			lista->final->proximo = livroTemporario;
			livroTemporario->anterior = lista->final;
			lista->final = livroTemporario;
		}
		
		lista->quantidadeItens++;
		lista->maior = comparaMaior(lista->maior, livroTemporario->preco);
		controlaClassificacao (lista, livroTemporario->classificacao);
	}
}

void adicionaInicio (Lista *lista) {
	Livro *livroTemporario = criaLivro ();
	
	if(isEmpty(lista)) {
		lista->inicio = livroTemporario;
	} else {
		if(singleElementOnList(lista)) {
			lista->inicio->anterior = livroTemporario; // dizer que o ponteiro.anterior do antigo primeiro elemento aponta para o novo elemento
			livroTemporario->proximo = lista->inicio; 
			lista->final = lista->inicio; // antes de trocar o ponteiro de inicio, dizer que o final recebe o incio
			lista->inicio = livroTemporario; // trocar o inicio para o novo elemento da fila
		} else {
			lista->inicio->anterior = livroTemporario;
			livroTemporario->proximo = lista->inicio;
			lista->inicio = livroTemporario;
		}
		lista->quantidadeItens++;
		lista->maior = comparaMaior(lista->maior, livroTemporario->preco);
		controlaClassificacao (lista, livroTemporario->classificacao);
	}
}

void adicionaAposCodigo (Lista *lista) {
	Livro *livroTemporario = criaLivro ();
	Livro *compara;
	int pesquisa, condicao = 1;
	
	if (isEmpty(lista)) {
		printf("Lista vazia, adicionando no inicio! \n");
		lista->inicio = livroTemporario;
	} else {
		printf("Insira o codigo do livro que deseja comparar: ");
		scanf("%i", &pesquisa);
		
		for (compara = lista->inicio; compara->proximo == NULL; compara = compara->proximo) {
			if (compara->codigo == pesquisa) {
				compara->proximo->anterior = livroTemporario;
				livroTemporario = compara->proximo;
				livroTemporario = compara;
				compara->proximo = livroTemporario;
				condicao = 0;
			}
		}
		lista->maior = comparaMaior(lista->maior, livroTemporario->preco);
		lista->quantidadeItens++;
		controlaClassificacao (lista, livroTemporario->classificacao);
	}
	if (condicao) {
		printf("Livro não encontrado, o livro criado será desalocado \n");
		free(livroTemporario);
		return;
	}
}

void adicionaAntesCodigo (Lista *lista) {
	Livro *livroTemporario = criaLivro ();
	Livro *compara;
	int pesquisa, condicao = 0;
	
	if (isEmpty(lista)) {
		printf("Lista vazia, adicionando no inicio! \n");
		lista->inicio = livroTemporario;
	} else {
		printf("Insira o codigo do livro que deseja comparar: ");
		scanf("%i", &pesquisa);
		
		for (compara = lista->inicio; compara->proximo == NULL; compara = compara->proximo) {
			if (compara->codigo == pesquisa) {
				compara->anterior->proximo = livroTemporario;
				livroTemporario->proximo = compara;
				livroTemporario->anterior  = compara->anterior;
				compara->anterior = livroTemporario;
				condicao = 1;
			}
		}
		lista->quantidadeItens++;
		lista->maior = comparaMaior(lista->maior, livroTemporario->preco);
		controlaClassificacao (lista, livroTemporario->classificacao);
	}
	
	if (condicao == 0) {
		printf("Livro não encontrado, o livro criado será desalocado \n");
		free(livroTemporario);
		return;
	}
}

void removerInicio (Lista *lista) {
	if(isEmpty(lista)) {
		printf("Lista vazia! \n");
	} else {
		Livro *temporario = lista->inicio;
		lista->inicio = temporario->proximo;
		printf("removendo livro %i", temporario->codigo);
		free(temporario);
		
		if(isEmpty(lista)) {
			lista->final = NULL;
		}
		lista->quantidadeItens--;
	}
}

void removerFinal (Lista *lista) {
	if(isEmpty(lista)) {
		printf("Lista vazia! \n");
	} else {
		Livro *temporario = lista->final;
		lista->final = temporario->anterior;
		printf("removendo livro %i", temporario->codigo);
		
		if(lista->final == NULL) {
			lista->inicio = NULL;
		}
		free(temporario);
		lista->quantidadeItens--;
	}
}

void removerCodigo (Lista *lista) {
	Livro *compara;
	int pesquisa;
	
	if(isEmpty(lista)) {
		printf("Lista vazia! \n");
		return;
	} else {
		printf("Insira o codigo que deseja remover: ");
		scanf("%i", &pesquisa);
		
		compara = comparaCodigo(lista, pesquisa);
		
		if (compara == NULL) {
			return;
		} else {
			if(singleElementOnList(lista)) {
				printf("Removendo codigo N°%i \n", compara->codigo);
				printf("A lista agora está vazia! \n\n");
				lista->inicio = NULL;
				free(compara);
			} else {
				compara->anterior->proximo = compara->proximo;
				compara->proximo->anterior = compara->anterior;
				printf("Removendo livro do codigo N°%i \n\n", compara->codigo);
				free(compara);
			}
		lista->quantidadeItens--;
		}
	}
}

void pesquisaCodigo (Lista *lista) {
	int codigo;
	Livro *compara;
	
	if(isEmpty(lista)) {
		printf("Fila vazia! \n\n");
		return;
	} else {
		printf("Insira o codigo que quer pesquisar: ");
		scanf("%i", &codigo);
		
		compara = comparaCodigo(lista, codigo);
		if(compara == NULL) {
			return;
		} else {
			printf("Livro encontrado! \n\n");
			return;
		}
	}
}

void imprimeInicioFinal (Lista *lista) {
	Livro *daVez;
	
	if(isEmpty(lista)) {
		printf("Fila vazia! \n\n");
		return;
	} else {
		for(daVez = lista->inicio; daVez->proximo == NULL; daVez = daVez->proximo) {
			imprimeLivro(daVez);
		}
		printf("Total de livros: %i \n\n", lista->quantidadeItens);
	}
}

void imprimeFinalInicio (Lista *lista) {
	Livro *daVez;
	
	if(isEmpty(lista)) {
		printf("Fila vazia! \n\n");
		return;
	} else {
		for(daVez = lista->final; daVez->anterior == NULL; daVez = daVez->anterior) {
			imprimeLivro(daVez);
		}
		printf("Total de livros: %i \n\n", lista->quantidadeItens);
	}
}

float calculaMedia (Lista *lista) {
	Livro *compara;
	float media = 0.0;
	
	if (isEmpty(lista)) {
		printf("Lista vazia! \n\n");
	} else {
		for(compara = lista->inicio; compara->proximo = NULL; compara = compara->proximo) {
			media += compara->preco;
		}
		return media/lista->quantidadeItens;
	}
	
}

void imprimeClassificacao (Lista *lista) {
	int pesquisa;
	
	if(isEmpty(lista)){
		printf("Lista vazia! \n\n");
		return;
	} else {
		switch(pesquisa):
			
			case 1:
				printf("")
	}
}

void main () {
	Lista *novaLista = criaLista();
	int opcao = -1;
	
		while (opcao != 99) {	
			printf(":: Lista Livros ::						\n");
			printf("1. Adicionar no inicio					\n");
			printf("2. Adiconar no final					\n");
			printf("3. Adicionar após						\n");
			printf("4. Adicionar antes						\n");
			printf("5. Remover inicio						\n");
			printf("6. Remover final						\n");
			printf("7. Remover código						\n");
			printf("8. Pesquisar código						\n");
			printf("9. Imprimir inicio -> final				\n");
			printf("10. Imprimir final -> inicio			\n");
			printf("11. Imprimir quantidade					\n");
			printf("12. Imprimir maior preço				\n");
			printf("13. Imprimir média de preços			\n");
			printf("14. Contar determinada classificação	\n");
			printf("15. Imprimir números classificações		\n");
			printf("16. Apagar por classificação			\n");
			printf("17. Classificação com maior quantidade	\n");
			printf("18. Imprimir organizado por codigo		\n");
			printf("99. Encerrar programa	\n");
			printf("Digite a opcao desejada: ");
			scanf("%d", &opcao);
			printf("\n");
			
			switch(opcao) {
				case 1:
					adicionaInicio(novaLista);
				break;
				
				case 2:
					adicionaFinal(novaLista);
				break;
				
				case 3:
					adicionaAposCodigo(novaLista);
				break;
				
				case 4:
					adicionaAntesCodigo(novaLista);
				break;
				
				case 5:
					removerInicio(novaLista);
				break;
				
				case 6:
					removerFinal(novaLista);
				break:
					
				case 7:
					removerCodigo(novaLista);
				break:
					
				case 8:
					pesquisaCodigo(novaLista);
				break:
					
				case 9:
					imprimeInicioFinal(novaLista);
				break:
					
				case 10:
					imprimeFinalInicio(novaLista)
				break:
					
				case 11:
					printf("O número de livros é de: %i", novaLista->quantidadeItens);
				break:
					
				case 12:
					printf("O livro mais caro custa: R$%.2f", novaLista->maior);
				break:
					
				case 13:
					printf("A média dos preços é de R$%2.f", calculaMedia(novaLista));
				break:
					
				case 14:
					
				break:
					
				case 15:
					
				break:
					
				case 16:
					
				break:
					
				case 17:
					
				break:
					
				case 18:
					
				break:
					
			}
		}
	
 }
