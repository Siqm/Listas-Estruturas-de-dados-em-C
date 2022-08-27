#include <locale.h>
#include <stdio.h>
// aplicação deverá solicitar do usuário o valor da mensalidade e também o dia em que ele deseja realizar o pagamento.
//1~5 não deverá ocorrer nenhum ajuste de valor
//6~10 acrescimo 5%
//11~20 acrescimo 8%
//21~31 acrescimo 10% 
//apresentar o valor original, o valor correspondente ao juros e também o valor final (valor original + juros)

float calculaJuros(int dia) {
	if (dia <= 5) {
		
		return 0;
	} else if (dia <=10) {
		
		return 0.05;
	} else if (dia <= 20) {
		
		return 0.08;
	} else if (dia <= 31) {
		
		return 0.1;
	} else {
		
		printf("Dia do mês inválido\n");
		return 0;
	}
}

void main (int argc, char *argv) {
	setlocale (LC_ALL,"");
	
	float mensalidade, juros, total;
	int diaPgto;
	
	printf("Insira o valor da mensalidade: ");
	scanf("%f", &mensalidade);
	printf("Em qual dia do mês deseja pagar: ");
	scanf("%i", &diaPgto);
	
	juros = calculaJuros(diaPgto);
	total = mensalidade + mensalidade * juros;
	
	printf("O valor original é de R$%.2f\n", mensalidade);
	printf("O valor do juros é de R$%.2f\n", juros*100);
	printf("O valor com o juros aplicado é de R$%.2f\n", total);
	
}