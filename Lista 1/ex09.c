#include <locale.h>
#include <stdio.h>

void main (int argc, char *argv) {
	setlocale (LC_ALL,"");
	
	float altura, peso, imc;
	
	printf("Insira sua altura: ");
	scanf("%f", &altura);
	printf("Insira seu peso: ");
	scanf("%f", &peso);
	
	imc = peso / (altura*altura);
	printf("Seu IMC é de %f", imc);
}
