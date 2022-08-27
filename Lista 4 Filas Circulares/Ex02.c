#include <stdio.h>
#include <locale.h>
#include <string.h>
#define size 10

struct caminhao {
	int numeroCaixas;
	float peso;
	char placa[8];
	char marca [15];
};

struct caminhao veiculos[size];
int front = -1, rear = -1, elementsQueue = 0;

//	Inicia a "chave primária" do vetor em todas as posições para nulo
void startVector () {
	int i;
	for (i = 0; i < size; i++) {
		strcpy(veiculos[i].placa, "NULL");
	}
}

// Verifica se o vetor está vázio, retorna 1 para verdadeiro e 0 para falso
int isEmpty () {
	if (elementsQueue == 0) {
		return 1;
	} else {
		return 0;
	}
}

// Verifica se o vetor está cheio, retorna 1 para verdadeiro e 0 para falso
int isFull () {
	if (elementsQueue == size) {
		return 1;
	} else {
		return 0;
	}
}

//	Método responsável por reorganizar posição da fila, caso chegue ao fim será enviado para o começo
//	se estiver no meio do vetor, só será acrescido.
//	Recebe como parametro a variavel (exemplo front ou rear) que aponta para a posição da fila 
void reallocateIndex (int *index) {
	if (*index == size - 1) {
		*index = 0;
	} else {
		*index += 1;
	}
}

//	Método responsável por ler entrada string placa e pesquisar dentro do vetor se já existe um valor igual.
//	Só irá sair do looping quando a placa adicionada não existir no vetor
void registraPlaca () {
	char placaVerificavel[8];
	int i, existe = 0, presente;
//	Para o indice do vetor acompanhar a pesquisa, é declarada uma variavel que inicia com mesmo valor do inicio da fila
	int index;
	
	while (existe == 0) { // valor de presente e index devem ser atribuidos dentro do while
		index = front;
		presente = 0;
		printf("Insira a placa do caminhão: ");
		gets(placaVerificavel);

		for (i = 0; i < elementsQueue; i++) {//	Para a pesquisa ser efetiva, o numero de processamentos é limitado ao numero de elementos na fila 
			if (strcmp(placaVerificavel, veiculos[index].placa) == 0) {
				printf("Placa já existe no vetor! \n");
				presente = 1;
				break;
			} 
			reallocateIndex(&index);
		}
		if (presente != 1) {// Se a placa não existir dentro do vetor, presente será diferente de 1 e o loop é interrompido
			existe = 1;
		}
	}
	printf("Placa adicionada ao vetor! P:%i \n", rear);
	strcpy(veiculos[rear].placa, placaVerificavel);
}

//	Método respável por enfileirar, irá checar se pilha está cheia, se não estiver, irá checar se está vazia e caso esteja, iniciará 
//	as variaveis front e rear, caso não esteja vazia, irá ajustar adequadamente a variavel responsável pelo final da fila
void enqueue () {
	if (isFull()) {
		printf("Pilha Cheia! \n");
	} else {
		if (isEmpty()) {
			front = 0;
			rear = 0;
		} else {
			reallocateIndex(&rear);
		}
		elementsQueue += 1;
		
		registraPlaca ();
		
		printf("Insira a marca do caminhão: ");
		gets(veiculos[rear].marca);
		
		printf("Insira o peso do caminhão: ");
		scanf("%f", &veiculos[rear].peso);
		
		printf("Insira a quantidade de caixas: ");
		scanf("%i", &veiculos[rear].numeroCaixas);
		
		printf("Posição da fila registrada, total de elementos enfileirados: %i \n", elementsQueue);
	}
}

//	Método irá checar se fila está vazia, se não estiver, irá remover o elemento na posição front e reposicionar a posição
//	também irá decrescer a variavel responsável por contar os elementos em fila e caso a fila esvazie no processo, 
//	irá atribuir valores negativos para final e inicio de fila
void dequeue () {
	if (isEmpty()) {
		printf("Fila vazia, nada a retirar! \n");
	} else {
		printf("Elemento da posição %i removido da fila \n", front);
		
		reallocateIndex(&front);
		elementsQueue -= 1;
		
		printf("Total de elementos na fila agora: %i \n", elementsQueue);
		
		if (elementsQueue == 0) {
			front = -1;
			rear = -1;
		}
	}
}

void imprimir () {
	int i, index = front;
	
	if (isEmpty()) {
		printf("Fila Vázia! \n");
	} else {
		for (i = 0; i < elementsQueue; i++) {
			printf("Veículo %i \n", index);
			printf("Placa: ");
			puts(veiculos[index].placa);
			
			printf("Marca do caminhão: ");
			puts(veiculos[index].marca);
			
			printf("Peso do caminhão: %.3f toneladas \n", veiculos[index].peso);
			
			printf("Quantidade de caixas no caminhão: %i \n\n", veiculos[index].numeroCaixas);
			
			reallocateIndex(&index);
		}
	}
}

void main (int argc, char *argv) {
	setlocale(LC_ALL,"");
	
	int opcao = 0;
	
	while (opcao != 10) {
		printf("\t * MENU *\n");
		printf("1: Registrar Chegada \n");
		printf("2: Informar Descarregamento \n");
		printf("3: Imprimir \n");
		printf("4: Verificar se patio está cheio \n");
		printf("5: Pesquisar informações através da placa \n");
		printf("6: Pesquisar caminhão mais pesado \n");
		printf("7: Peso total \n");
		printf("8: Pesquisar caminhão com menor carga \n");
		printf("9: Numero de caminhões na fila \n");
		printf("10: Sair do programa \n");
		printf("Opção escolhida: ");
		scanf("%i", &opcao);
		getchar();
		printf("\n");
		
		switch (opcao) {
			case 1:
				enqueue();
			break;
			
			case 2:
				dequeue();
			break;
			
			case 3:
				imprimir();
			break;
			
			case 4:
				if(isFull()){
					printf("Pátio cheio! \n");
				} else {
					printf("Ainda há espaço no patio! \n");
				}
			break;
			
			case 5:
				
			break;
			
			case 6: 
				
			break;
			
			case 7: 
				
			break;
			
			case 8: 
				
			break;
			
			case 9: 
				printf("Estão na fila %i caminhões \n", elementsQueue);
			break;
		}
	}
}
