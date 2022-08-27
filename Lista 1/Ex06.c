#include <stdio.h>
#include <locale.h>



void calculaTaxas (int ano, float porcentagem[]) {
	// O m�todo tem o intuito de calcular todas as taxas baseadas em ano de ve�culo e apontar para o array
	// do tipo float declarado no main, respeitando as posi��es IPI, ICMS e LUCRO (consultar m�todo main)
	
	// carros fabricados at� ano 2000:
	if (ano <= 2000) {
		porcentagem[0] = 0.1;
		porcentagem[1] = 0.05;
		porcentagem[2] = 0.25;
	}
	// carros fabricados depois de 2000 at� 2010:
	else if (ano > 2000) {
		porcentagem[1] = 0.07;
		porcentagem[2] = 0.2;
		
		// Posi��o 0 s� ser� referenciado se o ano do ve�culo for at� 2010, caso contr�rio entrar� no prox if:
		if (ano <= 2010) {
			porcentagem[0] = 0.11;
		}//carros f�bricados depois de 2011
		else if(ano >= 2011) {
			porcentagem[0] = 0.13;
		}
	}
	
}


int main (int argc, char *argv) {
	setlocale (LC_ALL, "");
	
	int anoFab;
	float precoFinal, lucro, ipi, icms, valorFab, taxas[3];
	
	// O array do tipo float taxas[] deve ser acessado em cada posi��o com valores respectivos a:
	// Posi��o 0: IPI
	// Posi��o 1: ICMS
	// Posi��o 2: LUCRO
	
	//Entrada de dados:
	printf("Insira o ano de Fabrica��o: ");
	scanf("%i", &anoFab);
	printf("Insira o pre�o de f�brica: ");
	scanf("%f", &valorFab);
	
	//Processamento de taxas:
	calculaTaxas(anoFab, taxas);
	
	//Processamento de sa�das:
	ipi = (taxas[0] * valorFab);
	icms = (taxas[1] * valorFab);
	lucro = (taxas[2] * valorFab);
	precoFinal = ipi + icms + lucro + valorFab;
	
	//Sa�das:
	printf("Valor original:	R$ %.2f\n", valorFab);
	printf("Valor IPI:	R$ %.2f\n", ipi);
	printf("Valor ICMS:	R$ %.2f\n", icms);
	printf("Valor de lucro:	R$ %.2f\n", lucro);
	printf("------------------------------\n");
	printf("Valor total:	R$ %.2f", precoFinal);
}