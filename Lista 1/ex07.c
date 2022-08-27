#include <locale.h>
#include <stdio.h>

void main (int argc, char *argv) {
	setlocale (LC_ALL,"");
	
	int pera, alface, laranja;
	float precoPera, precoAlface, precoLaranja, total;
	
	printf("\t\t\t* Insira a quantidade de produtos comprados *\n");
	printf("Insira a quantidade de Peras: ");
	scanf("%i", &pera);
	printf("Insira a quantidade de pés de Alface: ");
	scanf("%i", &alface);
	printf("Insira a quantidade de laranjas: ");
	scanf("%i", &laranja);
	
	if (pera <= 5) {
		precoPera = 1.5;
	} else {
		precoPera = 1.2;
	}
	if (alface <= 2) {
		precoAlface = 2;
	} else {
		precoAlface = 1.5;
	}
	if (laranja <= 6) {
		precoLaranja = 0.5;
	} else {
		precoLaranja = 0.4;
	}
	
	total = precoLaranja * laranja + precoAlface * alface + precoPera * pera;
	printf("O total da compra é de R$%.2f", total);
}