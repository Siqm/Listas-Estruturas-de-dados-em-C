/* 								EDL2-003 (IDADES)
Crie uma aplicação console em Java, esta aplicação deverá ser capaz de armazenar até 100 Idades.
 Para este exercício, crie uma classe (TDA) que será responsável pela manipulação de cada operação,
o vetor responsável pelo armazenamento das idades deverá estar oculto (private) dentro da classe
e qualquer acesso ao mesmo deverá ser realizado através dos métodos da mesma. O menu abaixo deverá 
ser criado para interagir com as idades, é importante lembrar que cada opção do menu deverá invocar
 um método da classe que será responsável pela execução do mesmo.

1 - Adicionar

2 - Adicionar Idade na Posição X (deverá solicitar do usuário uma idade e também a posição que se
 deseja armazenar a idade, caso a posição esteja ocupada, o usuário deverá ser informado que não 
 será possível adicionar a idade pois a posição está ocupada)

3 - Imprimir Posição X (caso exista uma idade na posição informada, esta idade deverá ser impressa)

4 - Imprimir Todas

5 - Remover Idade da Posição X

6 - Remover Todas 

7 - Contar Idades 

8 - Somar Idades

9 - Somar Idades Impares

10 - Imprimir Idades Pares

99 - Sair.				*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int posicaoVazia(int vetor[]) {
	int i;
	for (i = 0; i<10; i++) {
		if (vetor[i] == 0) {
			return i;
		}
	}
}	                                                


void iniciaVetor(int vetor[], int size) {
	int i;

	for (i = 0; i < size; i++) {
		vetor[i] = 0;
		}
}
	

void adiciona(int vetor[], size) {
	int valor, i = posicaoVazia(vetor, size);
	
	printf("Insira a sua idade: ");
	scanf("%i", &valor);
	vetor[i] = valor;
}


void adicionaPosicao (int vetor[]) {
	int i, valor;
	
	printf("Insira a sua idade: ");
	scanf("%i", &valor);
	printf("Insira a posição que deseja armazena-la no vetor: ");
	scanf("%i", &i);
	vetor[i] = valor;
}


void consulta (int vetor[]) {
	int index;
	
	printf("Insira a posição de deseja consultar: ");
	scanf("%i", &index);
	
	if (age[index] != 0) {
		printf("O valor na posição %i é %i\n", index, vetor[index]);
	} else {
		printf("Valor inválido");
	}
}


void imprimeTudo (int vetor[], int size) {
	int i;
	
	for (i = 0; i < size; i++) {
		printf("Posição %i: %.i\n", i+1, vetor[i]);
	}
}

		
void apagaPosicao (int vetor[]) {
	int i;
	
	printf("Insira a posição que deseja apagar: ");
	scanf("%i", i)
	printf("Apagando idade %i na posição %i", vetor[i], i);
	
	vetor[i] = 0;
}


void contaQtdCadastrados (int vetor[], int size) {
	int i, conta = 0;
	
	for (i = 0; i < size; i++) {
		
		if (vetor[i] != 0) {
			conta += 1;
		}
	}
	printf("A quantidade de cadastrados é de %i\n", conta);
}

void somaTudo(int vetor[], int size) {
	float total;
	
	for (i = 0; i < size; i++) {
		
		total += vetor[i];
	}
	printf("A soma de todos os valores é igual a %.2f", total);
}

void somaImpar (int vetor[], int size) {
	int i;
	float total;
	
	                            
	
	
			total += vetor[i];
		}
	}
	printf("A soma de todos os valores impares é igual a %.2f", total);
}

void imprimePar (int vetor[], int size) {
	int i;
	
	for (i = 0; i < size; i++) {
			if (vetor[i] % 2 == 0) {    
				printf("Divis�veis por 2 = %i \n", vetor[i]);
		}
	}
	
	for (i = 0; i < size; i++) {
			if (vetor[i] % 3 == 0) {    
				printf("Divis�veis por 2 = %i \n", vetor[i]);
		}
	}
}

int main (int argc, char *argv) {
	setlocale (LC_ALL,"");
	
	int opcao, sz = 100;
	int idade[]
	
	                            
	
	
		printf("2:  Adicionar em posição específica \n");
		printf("3:  Consultar posição específica \n");
		printf("4:  Imprimir todos os valores armazenados \n");
		printf("5:  Remover dados de uma posição \n");
		printf("6:  Remover tudo \n");
		printf("7:  Contar quantidade de valores armazenados \n");
		printf("8:  Somar todos os valores \n");
		printf("9:  Somar todos os valores impares \n");
		printf("10: Somar todos os valores \n");
		printf("99: Sair do programa \n");
		printf("Opção escolhida: ");
		scanf("%i", &opcao);
	}
}
