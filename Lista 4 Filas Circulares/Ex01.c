#include <stdio.h>
#include <locale.h>
#include <string.h>
#define size 10
#define True 1

struct veiculo {
	char placa[8];
	char nomeMotorista[21];
	float totalPedido;
};

struct veiculo carros[size];
int front = -1, rear = -1, elementsQueue = 0;

void iniciaFila () {
	int i;
	
	for (i = 0; i < size; i++) {
		strcpy(carros[i].placa, "NULL");
		carros[i].totalPedido = 0.0;
	}
}

//	Return 0 if false, return 1 if true
int isEmpty () {
	if (elementsQueue == 0) {
		return 1;
	} else {
		return 0;
	}
}

//	Return 0 if false, return 1 if true
int isFull () {
	if (elementsQueue == size) {
		return 1;
	} else {
		return 0;
	}
}

void checaPlaca () {
	char verificaPlaca[8];
	int i, verdadeiro = 0, placaExiste = -1;
	
	while (verdadeiro == 0) {
		
		printf("Insira a placa do carro: ");
		getchar();
		gets(verificaPlaca);
		
		for (i = 0; i < elementsQueue; i++) {
			printf("\n\tPesquisando placa posição %i \n", i);
			placaExiste = strcmp(carros[i].placa, verificaPlaca);
			if (placaExiste == 0) {
				printf("A placa já existe dentro do vetor \n");
				break;
			}
		}
		if (placaExiste != 0){
			strcpy(carros[rear].placa, verificaPlaca);
			verdadeiro = 1;
		}
	}
}

void enqueue () {
	if (isFull() == True) {
		printf("Fila Cheia \n");
	} else {
		if (front == -1) {
			front = 0;
			rear = 0;
		} else if (rear == (size -1)) {
			rear = 0;
		} else {
			rear += 1;
		}
		
		elementsQueue += 1;
		
		checaPlaca();
		
		printf("Insira o nome do motorista: ");
		gets(carros[rear].nomeMotorista);
		
		printf("Insira o total do pedido: ");
		scanf("%f", &carros[rear].totalPedido);
	}
}

void dequeue () {
	if (isEmpty() == True) {
		printf("Fila vazia, nada a remover \n");
	} else {
		if (front == size - 1) {
			
			front = 0;		
		} else {
			front += 1;
		}
		
		elementsQueue -= 1;
		
		if (elementsQueue == 0) {
			front = -1;
			rear = -1;
		}
	}
}

void carrosNaFila () {
	int i, index = front;
	
	if (isEmpty() == True) {
		printf("Fila Vázia \n");
	} else {
		for (i = 0; i < elementsQueue; i++) {
			printf("%i° Veículo \n", index);
			
			printf("Placa: ");
			puts(carros[index].placa);
			printf("Nome do motorista: ");
			puts(carros[index].nomeMotorista);
			printf("Total do pedido: R$%.2f \n", carros[index].totalPedido);
			
			if (index == elementsQueue -1) {
				index = 0;
			} else {
				index += 1;
			}
		}
	}
}

void pesquisaPlaca () {
	char verificaPlaca[8];
	int i, verdadeiro = 0, placaExiste = -1, index = front;
	
	printf("Insira a placa do carro: ");
	getchar();
	gets(verificaPlaca);
	
	for (i = 0; i < elementsQueue; i++) {
		placaExiste = strcmp(verificaPlaca, carros[index].placa);
		if (placaExiste == 0) {
			break;
		}
		if (index == elementsQueue -1) {
			index = 0;
		} else {
			index += 1;
		}
	}
	printf("A placa está na posição %i da fila", index);
}

void somaTotal () {
	float total;
	int i, ini = front;
	
	if (elementsQueue == 0) {
		printf("Pilha vazia! \n");
	} else {
		for (i = 0; i < size; i++) {
			total += carros[i].totalPedido;
			
			if (ini == (size - 1)) {
				ini = 0;
			} else {
				ini += 1;
			}
		}
	}
	printf("Existem atualmente %i pedidos \n", elementsQueue);
	printf("Soma total dos pedisos: R$%.2f \n", total);
	total = total/elementsQueue;
	printf("O valor médio dos pedidos é de R$%.2f \n", total);
}

void pedidosExistentes () {
	
}
	

void main (int agrc, char *argv) {
	setlocale(LC_ALL,"");
	
	iniciaFila();
	int opcao = 0;
	
	while (opcao != 9) {
		printf("\t * MENU *\n");
		printf("1: Empilhar \n");
		printf("2: Desempilhar \n");
		printf("3: Imprimir \n");
		printf("4: Número de carros esperando \n");
		printf("5: Pesquisar por placa \n");
		printf("6: MÉTODO PEDIDO NA PROVA \n");
		printf("9: Sair do programa \n");
		printf("Opção escolhida: ");
		scanf("%i", &opcao);
		printf("\n");
		
		switch (opcao) {
			case 1:
				enqueue();
			break;
			
			case 2:
				dequeue();
			break;
			
			case 3:
				carrosNaFila();
			break;
			
			case 4:
				printf("Estão presentes na fila %i carro(s)", elementsQueue);
			break;
			
			case 5:
				pesquisaPlaca();
			break;
			
			case 6:
				somaTotal();
			break;
		}
	}
}
