#include <stdio.h>
#include <locale.h>
#define size 5

struct containner {
	int code;
	int heigth;
	int width;
	int profundity;
	char brand[20];
	char company[50];
};

int key = 0, topo = -1;
struct containner containners[size];

void stackCtrs () {
	int i;
	for (i = 0; i < size; i++) {
		containners[i].code = 0;
	}
}

void addContainner () {
	if (topo == size - 1) {
		printf("Pilha cheia");
	} else {
		topo += 1;
		key += 1;
		
		containners[topo].code = key;
		
		printf("Criando Containner de código: %i \n", containners[topo].code);
		
		printf("Insira a Altura do containner:  ");
		scanf("%i", &containners[topo].heigth);
		
		printf("Insira a largura do containner: ");
		scanf("%i", &containners[topo].width);
		
		printf("Insira a profundidade do containner: ");
		scanf("%i", &containners[topo].profundity);
		getchar();
		
		printf("Insira a marca do containner: ");
		gets(containners[topo].brand);
		
		printf("Insira a companhia do containner: ");
		gets(containners[topo].company);
	}
}

void removeContainner () {
	if (topo == -1) {
		printf("Pilha cheia \n");
	} else {
		printf("Posição %i desempilhada \n", topo);
		topo -= 1;
	}
}

//	Return -1 if it is empty and return 1 if not
int isEmpty () {
	if (topo == -1) {
		return -1;
	} else {
		return 1;
	}
}

//	Return 1 if it is empty and return -1 if not
int isFull () {
	if (topo == size -1) {
		return 1;
	} else {
		return -1;
	}
}

void printAll () {
	if (topo == -1) {
		printf("Pilha vazia \n");
	} else {
		int i;
		for (i = topo; i > -1; i--) {
			printf("Código: %i \n", containners[i].code);
			printf("Altura: %i, Largura: %i, Profundidade: %i \n",
			containners[i].heigth, containners[i].width, containners[i].profundity);
			printf("Marca: ");
			puts(containners[i].brand);
			printf("Companhia: ");
			puts(containners[i].company);
			printf("\n");
		}
	}
}

void printCompany () {
	int i;
	char compName[50];
	
	if (topo == -1) {
		printf("Pilha vazia \n");
	} else {
		getchar();
		printf("Insira o nome da empresa que deseja pesquisar: ");
		gets(compName);
		
		for (i = topo; i > -1; i--) {
			if (strcmp(compName, containners[i].company) == 0) {
				printf("Código: %i \n", containners[i].code);
				printf("Altura: %i, Largura: %i, Profundidade: %i \n",
				containners[i].heigth, containners[i].width, containners[i].profundity);
				printf("Marca: ");
				puts(containners[i].brand);
				printf("Companhia: ");
				puts(containners[i].company);
			}
		}
	}
}
 
void printTop () {
	if (topo == -1) {
		printf("Pilha vazia \n");
	} else {
		printf("Código: %i \n", containners[topo].code);
		printf("Altura: %i, Largura: %i, Profundidade: %i \n",
		containners[topo].heigth, containners[topo].width, containners[topo].profundity);
		printf("Marca: ");
		puts(containners[topo].brand);
		printf("Companhia: ");
		puts(containners[topo].company);
	}
}

void printCod () {
	if (topo == -1) {
		printf("Pilha vazia \n");
	} else {
		int pesqcod, i;
		
		printf("Insira o código que deseja pesquisar: ");
		scanf("%i", &pesqcod);
		
		for (i = topo; i > -1; i--) {
			if (pesqcod == containners[i].code) {
				printf("Código: %i \n", containners[i].code);
				printf("Altura: %i, Largura: %i, Profundidade: %i \n",
				containners[i].heigth, containners[i].width, containners[i].profundity);
				printf("Marca: ");
				puts(containners[i].brand);
				printf("Companhia: ");
				puts(containners[i].company);
			}
		}
	}
}

void main (int argc, char *argv) {
	setlocale(LC_ALL,"");
	
	int opcao = 0;
	
	while (opcao != 9) {
		printf("\t * MENU *\n");
		printf("1: Empilhar \n");
		printf("2: Desempilhar \n");
		printf("3: Imprimir \n");
		printf("9: Sair do programa \n");
		printf("Opção escolhida: ");
		scanf("%i", &opcao);
		printf("\n");
		
		switch (opcao) {
			case 1:
				addContainner();
			break;
			
			case 2:
				removeContainner();
			break;
			
			case 3:
				printf("1 = Não está vazio, -1 = Está vazio \nResultado: %i \n",isEmpty());
			break;
			
			case 4:
				printf("1 = Está cheio, -1 = Não está cheio \nResultado: %i \n",isFull());
			break;
			
			case 5:
				printAll();
			break;
			
			case 6:
				printCompany();
			break;
			
			case 7:
				printTop();
			break;
			
			case 8:
				printCod();
			break;
		}
	}
}
