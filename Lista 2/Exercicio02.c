/* 							EDL2-002 (ALTURAS)
Crie uma aplicação console, esta aplicação deve ser capaz de armazenar 10 valores numéricos
reais (alturas), para manipular este vetor, deve-se criar o menu com as opções abaixo.
****************************
.									MENU
1 - Adicionar (deve-rá solicitar a POSIÇÃO e VALOR do usuário, o valor fornecido,
 deverá ser adicionado na posição informada, caso a posição informada não exista,
  deverá exibir msg para o usuário informando que a posição é inválida).

2 - Ler (Deverá solicitar do usuário uma posição qualquer do vetor e então exibir
 o valor existente nesta posição, validar se a posição existe antes de ler o valor).

3 - Somar (Deve somar todos os valores do vetor e apresentar o resultado da soma).

4 - Contar (Deve percorrer o vetor e contar quantos valores maior que zero existem no vetor).

5 - Contar posições vazias 																	*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

void iniciaVetor(float vetor[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		vetor[i] = 0;
	}
}

void adiciona (float age[]) {
	int i;
	float valor;
	
	printf("Insira a sua altura: ");
	scanf("%f", &valor);
	printf("Insira a posição que deseja armazena-la no vetor: ");
	scanf("%i", &i);
	age[i] = valor;
}

void consulta (float age[]) {
	int index;
	
	printf("Insira a posição de deseja consultar: ");
	scanf("%i", &index);
	
	if (age[index] != 0) {
		printf("O valor na posição %i é %f\n", index, age[index]);
	}
}

float soma (float age[], int size) {
	int i;
	float total;
	for (i = 0; i < size; i++) {
		total += age[i];
	}
	return total;
}

void contaQtdCadastrados (float age[], int size) {
	int i, contador = 0;
	for (i = 0; i < size; i++) {
		if (age[i] != 0) {
			contador += 1;
		}
	}
	printf("A quantidade de cadastrados é de %i\n", contador);
}

void contaQtdVazio (float age[], int size) {
	int i, contador = 0;
	for (i = 0; i < size; i++) {
		if (age[i] == 0) {
			contador += 1;
		}
	}
	printf("A quantidade de cadastrados é de %i\n", contador);
}

int main (int argc, char *argv) {
	setlocale (LC_ALL,"");
	
	int opcao, sz = 10;
	float idade[sz];
	
	iniciaVetor(idade, sz);
	
	while (opcao != 9) {
		printf("\t ** MENU **\n");
		printf("1: Adicionar Altura no Vetor \n");
		printf("2: Consultar posição no vetor \n");
		printf("3: Somar todas as alturas \n");
		printf("4: Contar quantidade de elementos armazenados \n");
		printf("5: Contar posições vazias\n");
		printf("9: Sair do programa \n");
		printf("Opção escolhida: ");
		scanf("%i", &opcao);
		
		switch (opcao) {
			case 1:
				adiciona(idade);
			break;
			
			case 2:
				consulta(idade);
			break;
			
			case 3:
				printf("A soma de todos os valores é: %.2f\n",	soma(idade, sz));
			break;
			
			case 4:
				contaQtdCadastrados(idade, sz);
			break;
			
			case 5:
				contaQtdVazio(idade, sz);
			break;
		}
	}
}