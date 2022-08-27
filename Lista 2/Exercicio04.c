#include <locale.h>
#include <stdio.h>
#include <stdlib.h>


// Método para o funcionamento CORRETO do meu Algortimo
void iniciaVetor(float vetor[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		vetor[i] = 0;
	}
}

// Método para o funcionamento CORRETO do meu Algortimo
// Devolve a primeira posição vazia do vetor
int posicaoVazia(float vetor[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		if (vetor[i] == 0) {
			return i;
		}
	}
}


void adiciona(float vetor[], int size) {
	int i = posicaoVazia(vetor, size);
	float valor;
	
	printf("Insira a seu sálario: ");
	scanf("%f", &valor);
	vetor[i] = valor;
}


void remover(float vetor[]) {
	int posicao;
	
	printf("Insira a posição que deseja remover: ");
	scanf("%i", &posicao);
	vetor[posicao] = 0;
}



void imprimeTudo (float vetor[], int size) {
	int i;
	
	for (i = 0; i < size; i++) {
		if (vetor[i] != 0) {
			printf("Posição %i: %.2f\n", i+1, vetor[i]);
		}
	}
}


void pesquisarX (float vetor[], int size) {
	int i, condicao = 0;
	float valor;
	
	printf("Insira o valor que deseja pesquisar: ");
	scanf("%f", &valor);
	
	for (i = 0; i < size; i++) {
		if (vetor[i] == valor) {
			printf("O valor %.2f existe na posição %i", valor, i+1);
			condicao += 1;
		}
	}
	if (condicao == 0) {
		printf("O valor pesquisado não existe no vetor.");
	}
}

void adicionarNaPosicao (float vetor[]) {
	int posicao;
	float valor;
	
	printf("Informa a posição que deseja adicionar ou alterar o valor: ");
	scanf("%i", &posicao);
	printf("Informe o valor que deseja atribuir: ");
	scanf("%f", &valor);
	
	vetor[posicao] = valor;
}

void pesquisarIgualX (float vetor[], int size) {
	float valor;
	int i, contador = 0;
	
	printf("Insira o valor que quer pesquisar: ");
	scanf("%f", &valor);
	
	for (i = 0; i < size; i++) {
		if (vetor[i] == valor) {
			contador += 1;
		}
	}
	if (contador > 0) {
		printf("Esse valor aparece %i vezes dentro do vetor", contador);
	} else {
		printf("Esse valor não está presente no vetor.");
	}
	printf("\n");
}


void soma (float vetor[], int size) {
	int i;
	float total;
	for (i = 0; i < size; i++) {
		total += vetor[i];
	}
	printf("O valor da soma dos salários é de R$%.2f\n", total);
}


void somarX(float vetor[], int size) {
	int i;
	float valor, total;
	
	printf("Informe um valor para somar todos os salários com o mesmo valor: ");
	scanf("%f", &valor);
	
	for (i = 0; i < size; i++) {
		if (vetor[i] == valor) {
			total += vetor[i];
		}
	}
	
	printf("A soma de todos os salários de R$%.2f é de R$%.2f", valor, total);
}


void contaPosicoes (float vetor[], int size) {
	int i, contador = 0;
	
	for (i = 0; i < size; i++) {
		if (vetor[i] != 0) {
			contador += 1;
		}
	}
	printf("O vetor tem %i posições ocupadas", contador);
}


void contaIgualX (float vetor[], int size) {
	float valor;
	int i, contador;
	
	printf("Insira o valor que deseja contar: ");
	scanf("%f", &valor);
	
	for (i = 0; i < size; i++) {
		if (vetor[i] == valor) {
			contador += 1;
		}
	}
	printf("O vetor tem %i posições iguais a %.2f", contador, valor);
} 


void contaMaiorQueX(float vetor[], int size) {
	float valor;
	int contador, i;
	
	printf("Insira um valor para comparação: ");
	scanf("%f", &valor);
	printf("Pesquisando valores maiores que %.2f", valor);
	
	for (i = 0; i < size; i++) {
		if (vetor[i] > valor) {
			contador += 1;
		}
	}
	
	printf("O vetor tem %i posições maiores que %.2f", contador, valor);
}


void maiorValor(float vetor[], int size) {
	int i;
	float maior = 0;
	
	for (i = 0; i < size; i++) {
		if (vetor[i] > maior) {
			maior = vetor[i];
		}
	}
	
	printf("O maior salário é %.2f", maior);
}


void menorValor (float vetor [], int size) {
	int i;
	float menor = vetor[0];
	
	for (i = 0; i < size; i++) {
		if (vetor[i] < menor) {
			menor = vetor[i];
		}
	}
	
	printf("O menor salário é %.2f", menor);
}


void mediaValores (float vetor[], int size) {
	float media = 0;
	int i;
	
	for (i = 0; i < size; i++) {
		media += vetor[i];
	}
	media = media/size;
	
	printf("A média dos valores é igual a %.2f", media);
}


void removeIgualX (float vetor[], int size) {
	float valor;
	int i;
	
	printf("Insira o valor que deseja remover do vetor: ");
	scanf("%f", &valor);
	
	for (i = 0; i < size; i++) {
		if (vetor[i] == valor) {
			vetor[i] = 0;
			printf("Posição %i alterada", i+1);
		}
	}
}

void removeTudo (float vetor[], int size) {
	int i;
	
	for (i = 0; i < size; i++) {
		vetor[i] = 0;
	}
	printf("Todas as posições foram apagadas.\n");
}


void imprimirPosicao (float vetor[]) {
	int posicao;
	
	printf("Insira a posição que deseja imprimir: ");
	scanf("%i", &posicao);
	
	printf("%.2f", vetor[posicao]);
}

void imprimirMenorQue(float vetor[], int size) {
	int i;
	float x;
	
	printf("Todos os salários MENORES que o salário informado serão impressos\n");
	printf("Informe o salário: ");
	scanf("%f", &x);
	
	for (i = 0; i < size; i++) {
		if (vetor[i] < x && vetor[i] != 0) {
			printf("Posição %i: R$ %.2f\n", i+1, vetor[i]);
		}
	}
}

void acrescerPorcentagem (float vetor[], int size) {
	int i;
	float valor;
	
	printf("Insira a porcentagem que deseja acrescer a todos os valores: ");
	scanf("%f", &valor);
	
	valor = valor/100;
	
	for (i = 0; i < size; i++) {
		vetor [i] += vetor[i] * valor;
	}
}

void descontarPorcentagemX (float vetor[], int size) {
	int i;
	float porcentagem, valor;
	
	printf("Insira a porcentagem que deseja decrescer: ");
	scanf("%f", &porcentagem);
	printf("Insira o valor que deseja aplicar o desconto: ");
	scanf("%f", &valor);
	
	porcentagem = porcentagem/100;
	
	for (i = 0; i < size; i++) {
		if (vetor[i] == valor) {
			vetor [i] -= vetor[i] * valor;
			printf("Posição %i alterada", i+1);
		}
	}
}


int main (int argc, char *argv) {
	setlocale (LC_ALL,"");
	
	int opcao, sz = 5;
	float salario[sz];
	
	iniciaVetor(salario, sz);
	
	while (opcao != 99) {
		printf("\t ** MENU **\n");
		printf(" 1: Adicionar \n");
		printf(" 2: Remover posição X \n");
		printf(" 3: Imprimir tudo \n");
		printf(" 4: Pesquisar Salario X \n");
		printf(" 5: Adicionar na posição X \n");
		printf(" 6: Pesquisar quantidade de salarios X \n");
		printf(" 7: Somar Salários \n");
		printf(" 8: Somar salários X \n");
		printf(" 9: Contar salários \n");
		printf("10: Contar salários X \n");
		printf("11: Contar salários maiores que X \n");
		printf("12: Maior salário \n");
		printf("13: Menor salário \n");
		printf("14: Média dos salários \n");
		printf("15: Remover salários com valor X \n");
		printf("16: Remover todos os salários \n");
		printf("17: Imprimir salário da posição X \n");
		printf("18: Imprimir salários menores que X \n");
		printf("19: Acrescer porcentagem em todos os salários \n");
		printf("20: Decrescer porcentagem em todos os salários maiores que X \n");
		printf("99: Sair do programa \n");
		printf("Opção escolhida: ");
		scanf("%i", &opcao);
		printf("\n");
		
		switch (opcao) {
			
			case 1:
				adiciona(salario, sz);
				printf("\n\n");
			break;
			
			case 2:
				remover(salario);
			break;
			
			case 3:
				imprimeTudo(salario, sz);
				printf("\n\n");	
			break;
			
			case 4:
				pesquisarX(salario, sz);
			break;
			
			case 5:
				adicionarNaPosicao(salario);
			break;
			
			case 6:
				pesquisarIgualX(salario, sz);
			break;	
				
			case 7:
				soma(salario, sz);
				printf("\n\n");
			break;
			
			case 8:
				somarX(salario, sz);	
			break;
			
			case 9:
				contaPosicoes(salario, sz);
			break;	
			
			case 10:
				contaIgualX(salario, sz);
			break;	
				
			case 11:
				contaMaiorQueX(salario, sz);
			break;
			
			case 12:
				maiorValor(salario, sz);
			break;
			
			case 13:
				menorValor(salario, sz);
			break;
			
			case 14:
				mediaValores(salario, sz);
			break;
			
			case 15:
				removeIgualX(salario, sz);
			break;
			
			case 16:
				removeTudo(salario, sz);
			break;
			
			case 17:
				imprimirPosicao(salario);
			break;	
			
			case 18:
				imprimirMenorQue(salario, sz);
				printf("\n\n");
			break;
			
			case 19:
				acrescerPorcentagem(salario, sz);
			break;
			
			case 20:
				descontarPorcentagemX(salario, sz);
		}	
	}
}