#include <locale.h>
#include <stdio.h>

float descontoGasolina (int lt) {
	
	if (lt > 15) {
		return 0.03;
	} else if (lt > 35) {
		return 0.06;
	}
}

float descontoAlcool (int lt) {
	
	if (lt > 20) {
		return 0.03;
	} else if (lt > 40) {
		return 0.05;
	}
}


void main (int argc, char *argv) {
	setlocale (LC_ALL,"");
	
	int litros, liquido;
	float desconto, total;
	
	printf("Preço gasolina: R$3,00 lt \tPreço alcool: R$2,00 lt\n");
	printf("Para selecionar gasolina insira 1\n");
	printf("Para selecionar alcool insira 2\n");
	printf("Escolha: ");
	scanf("%i", &liquido);
	printf("Insira a quantidade em litros: ");
	scanf("%i", &litros);
	
	if (liquido == 1) {
		
		desconto = descontoGasolina(litros);
		total = (litros * 3) - (litros * 3) * desconto;
	} else {
		
		desconto = descontoAlcool(litros);
		total = (litros * 2) - (litros * 2) * desconto;
	}
	

	
	printf("O total a ser pago é de R$%.2f, o desconto aplicado foi de %.0f%%", total, desconto*100);
}