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

//	Inicia a "chave prim�ria" do vetor em todas as posi��es para nulo
void startVector () {
	int i;
	for (i = 0; i < size; i++) {
		strcpy(veiculos[i].placa, "NULL");
	}
}

// Verifica se o vetor est� v�zio, retorna 1 para verdadeiro e 0 para falso
int isEmpty () {
	if (elementsQueue == 0) {
		return 1;
	} else {
		return 0;
	}
}

// Verifica se o vetor est� cheio, retorna 1 para verdadeiro e 0 para falso
int isFull () {
	if (elementsQueue == size) {
		return 1;
	} else {
		return 0;
	}
}

//	M�todo respons�vel por reorganizar posi��o da fila, caso chegue ao fim ser� enviado para o come�o
//	se estiver no meio do vetor, s� ser� acrescido.
//	Recebe como parametro a variavel (exemplo front ou rear) que aponta para a posi��o da fila 
void reallocateIndex (int *index) {
	if (*index == size - 1) {
		*index = 0;
	} else {
		*index += 1;
	}
}

//	M�todo respons�vel por ler entrada string placa e pesquisar dentro do vetor se j� existe um valor igual.
//	S� ir� sair do looping quando a placa adicionada n�o existir no vetor
void registraPlaca () {
	char placaVerificavel[8];
	int i, existe = 0, presente;
//	Para o indice do vetor acompanhar a pesquisa, � declarada uma variavel que inicia com mesmo valor do inicio da fila
	int index;
	
	while (existe == 0) { // valor de presente e index devem ser atribuidos dentro do while
		index = front;
		presente = 0;
		printf("Insira a placa do caminh�o: ");
		gets(placaVerificavel);

		for (i = 0; i < elementsQueue; i++) {//	Para a pesquisa ser efetiva, o numero de processamentos � limitado ao numero de elementos na fila 
			if (strcmp(placaVerificavel, veiculos[index].placa) == 0) {
				printf("Placa j� existe no vetor! \n");
				presente = 1;
				break;
			} 
			reallocateIndex(&index);
		}
		if (presente != 1) {// Se a placa n�o existir dentro do vetor, presente ser� diferente de 1 e o loop � interrompido
			existe = 1;
		}
	}
	printf("Placa adicionada ao vetor! P:%i \n", rear);
	strcpy(veiculos[rear].placa, placaVerificavel);
}

//	M�todo resp�vel por enfileirar, ir� checar se pilha est� cheia, se n�o estiver, ir� checar se est� vazia e caso esteja, iniciar� 
//	as variaveis front e rear, caso n�o esteja vazia, ir� ajustar adequadamente a variavel respons�vel pelo final da fila
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
		
		printf("Insira a marca do caminh�o: ");
		gets(veiculos[rear].marca);
		
		printf("Insira o peso do caminh�o: ");
		scanf("%f", &veiculos[rear].peso);
		
		printf("Insira a quantidade de caixas: ");
		scanf("%i", &veiculos[rear].numeroCaixas);
		
		printf("Posi��o da fila registrada, total de elementos enfileirados: %i \n", elementsQueue);
	}
}

//	M�todo ir� checar se fila est� vazia, se n�o estiver, ir� remover o elemento na posi��o front e reposicionar a posi��o
//	tamb�m ir� decrescer a variavel respons�vel por contar os elementos em fila e caso a fila esvazie no processo, 
//	ir� atribuir valores negativos para final e inicio de fila
void dequeue () {
	if (isEmpty()) {
		printf("Fila vazia, nada a retirar! \n");
	} else {
		printf("Elemento da posi��o %i removido da fila \n", front);
		
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
		printf("Fila V�zia! \n");
	} else {
		for (i = 0; i < elementsQueue; i++) {
			printf("Ve�culo %i \n", index);
			printf("Placa: ");
			puts(veiculos[index].placa);
			
			printf("Marca do caminh�o: ");
			puts(veiculos[index].marca);
			
			printf("Peso do caminh�o: %.3f toneladas \n", veiculos[index].peso);
			
			printf("Quantidade de caixas no caminh�o: %i \n\n", veiculos[index].numeroCaixas);
			
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
		printf("4: Verificar se patio est� cheio \n");
		printf("5: Pesquisar informa��es atrav�s da placa \n");
		printf("6: Pesquisar caminh�o mais pesado \n");
		printf("7: Peso total \n");
		printf("8: Pesquisar caminh�o com menor carga \n");
		printf("9: Numero de caminh�es na fila \n");
		printf("10: Sair do programa \n");
		printf("Op��o escolhida: ");
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
					printf("P�tio cheio! \n");
				} else {
					printf("Ainda h� espa�o no patio! \n");
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
				printf("Est�o na fila %i caminh�es \n", elementsQueue);
			break;
		}
	}
}
