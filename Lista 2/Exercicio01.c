#include<stdio.h>
#include <locale.h>


int posicaoVazia(int ra[]) {
	int i;
	for (i = 0; i<10; i++) {
		if (ra[i] == 0) {
			return i;
		}
	}
}


void adicionaRA(int ra[]) {
	int i;
	i = posicaoVazia(ra);
	
	printf("Insira o RA que deseja ADICIONAR: ");
	scanf("%i", &ra[i]);
}

void apagaRA(int ra[]) {
	int consulta, i;
	
	printf("Insira o RA que deseja apagar: ");
	scanf("%i", &consulta);
	
	for (i = 0; i<10; i++) {
		if (ra[i] == consulta) {
			ra[i] = 0;
			printf("Passei aqui");
			printf("%i %i %i",ra[i], i, consulta);
		}
	}
}

void consultaRA(int ra[]) {
	int consulta, i;
	printf("Insira o RA que deseja consultar: ");
	scanf("%i", &consulta);
	for (i = 0; i<10; i++) {
		if (consulta == ra[i]) {
			printf("A posição que o RA: %i ocupa dentro do vetor é: %i\n", consulta, i+1);
		}
	}
}

void imprimeTodos(int ra[]) {
	int i=0;
	for(i=0; i<10; i++) {
		printf("RA N%i: %i\n", i+1, ra[i]);
	}
}

void contaQtdCadastrados (int ra[]) {
	int i, contaRA=0;
	for (i = 0; i<10; i++) {
		if (ra[i] != 0) {
			contaRA += 1;
		}
	}
	printf("A quantidade de cadastrados é de %i\n", contaRA);
}

void main (int agrc, char *argv) {
	setlocale(LC_ALL,"");
	
	int ra[10], i, opcao;
	
	for (i = 0; i < 10; i++) {
		ra[i] = 0;
	}
	
	while (opcao != 9) {
		printf("\t\t ** Cadastro de RA **\n");
		printf("1 - Adicionar RA\n");
		printf("2 - Remover RA\n");
		printf("3 - Imprimir POSIÇÃO do RA\n");
		printf("4 - Imprimir todos\n");
		printf("5 - Contar quantidade de RA cadastrados\n");
		printf("9 - Sair do programa\n");
		printf("Opção selecioada: ");
		scanf("%i", &opcao);
		
		switch (opcao) {
			case 1:
				adicionaRA(ra);
			break;
			
			case 2:
				apagaRA(ra);
			break;
			
			case 3:
				consultaRA(ra);
			break;
			
			case 4:
				imprimeTodos(ra);
			break;
			
			case 5:
				contaQtdCadastrados(ra);
			break;
		}
		
	}
}
	

