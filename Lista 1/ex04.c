#include <stdio.h>
#include <locale.h>

int main (int argc, char *argv) {
	setlocale (LC_ALL, "");
	
	float media, p1, p2, tr, nc;
	
	printf("Insira a nota de corte: ");
	scanf("%f", &nc);
	printf("Insira a nota da p1: ");
	scanf("%f", &p1);
	printf("Insira a nota da p2: ");
	scanf("%f", &p2);
	printf("Insira a nota da tr: ");
	scanf("%f", &tr);
	
	media = (p1 * 0.4) + (p2 * 0.4) + (tr * 0.2);
	
	if (media >= nc) {
		printf("Parabéns, você foi aprovado!");
	} else {
		printf("Sinto muito, você foi reprovado!");
	}
	getchar ();
	getchar ();
	return 0;
}