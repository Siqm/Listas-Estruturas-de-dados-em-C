#include <stdio.h>
#include <locale.h>

int main (int argc, char *argv) {
	setlocale (LC_ALL, "");
	
	int branco, nulo, valido;
	float total;
	
	printf("Insira a quantidade de votos em branco: ");
	scanf("%i", &branco);
	printf("Insira a quantidade de votos nulos: ");
	scanf("%i", &nulo);
	printf("Insira a quantidade de votos válidos: ");
	scanf("%i", &valido);
	total = branco + nulo + valido;
	
	printf("A porcentagem de votos em branco foram de: %.1f\n", (branco*100)/total);
	printf("A porcentagem de votos nulos foram de: %.1f\n", (nulo*100)/total);
	printf("A porcentagem de votos válidos foram de: %.1f", (valido*100)/total);
	getchar ();
}