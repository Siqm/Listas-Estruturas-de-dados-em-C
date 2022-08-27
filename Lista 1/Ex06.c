#include <stdio.h>
#include <locale.h>



void calculaTaxas (int ano, float porcentagem[]) {
	// O método tem o intuito de calcular todas as taxas baseadas em ano de veículo e apontar para o array
	// do tipo float declarado no main, respeitando as posições IPI, ICMS e LUCRO (consultar método main)
	
	// carros fabricados até ano 2000:
	if (ano <= 2000) {
		porcentagem[0] = 0.1;
		porcentagem[1] = 0.05;
		porcentagem[2] = 0.25;
	}
	// carros fabricados depois de 2000 até 2010:
	else if (ano > 2000) {
		porcentagem[1] = 0.07;
		porcentagem[2] = 0.2;
		
		// Posição 0 só será referenciado se o ano do veículo for até 2010, caso contrário entrará no prox if:
		if (ano <= 2010) {
			porcentagem[0] = 0.11;
		}//carros fábricados depois de 2011
		else if(ano >= 2011) {
			porcentagem[0] = 0.13;
		}
	}
	
}


int main (int argc, char *argv) {
	setlocale (LC_ALL, "");
	
	int anoFab;
	float precoFinal, lucro, ipi, icms, valorFab, taxas[3];
	
	// O array do tipo float taxas[] deve ser acessado em cada posição com valores respectivos a:
	// Posição 0: IPI
	// Posição 1: ICMS
	// Posição 2: LUCRO
	
	//Entrada de dados:
	printf("Insira o ano de Fabricação: ");
	scanf("%i", &anoFab);
	printf("Insira o preço de fábrica: ");
	scanf("%f", &valorFab);
	
	//Processamento de taxas:
	calculaTaxas(anoFab, taxas);
	
	//Processamento de saídas:
	ipi = (taxas[0] * valorFab);
	icms = (taxas[1] * valorFab);
	lucro = (taxas[2] * valorFab);
	precoFinal = ipi + icms + lucro + valorFab;
	
	//Saídas:
	printf("Valor original:	R$ %.2f\n", valorFab);
	printf("Valor IPI:	R$ %.2f\n", ipi);
	printf("Valor ICMS:	R$ %.2f\n", icms);
	printf("Valor de lucro:	R$ %.2f\n", lucro);
	printf("------------------------------\n");
	printf("Valor total:	R$ %.2f", precoFinal);
}