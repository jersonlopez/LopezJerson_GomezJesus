#include <stdio.h>

int invertir_numero (int x);

int main() {
	int numero, numero_invertido;
	printf("Numero: ");
	scanf("%d", &numero);
	numero_invertido = invertir_numero(numero);
	printf("Numero invertido = %d\n", numero_invertido);
	return 0;
}

int invertir_numero (int x) {
	int numero_invertido = 0, residuo;
	while(x != 0) {
		residuo = x%10;
		numero_invertido = numero_invertido*10 + residuo;
		x /= 10;
	}
	return numero_invertido;
}