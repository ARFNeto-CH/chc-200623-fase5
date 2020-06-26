#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"

int fase(int etapa, int alvo);

int main()
{
	int tentativas = 3;
	int senhas = 5;
	int ok = 0;
	int pre_a = 2;
	int  a = 12;
	int pos_a = 4;
	int* p = &a;

	const int senha[5] = { 1, 99, 17, 57, 50 };

	// vai ter 'x' tentativas de acertar as 'y' senhas
	for (int t = 0; t < tentativas; t = t + 1)
	{
		ok = 0;
		printf("\nTentativa %d de %d\n\n", 1 + t, tentativas);
		for (int f = 0; f < senhas; f = f + 1)
		{	// se o cara errou tenta ate 'tentativas'
			if (fase(f, senha[f]) == 0) break;
			ok = ok + 1; // passou mais uma
		};
		if (ok != senhas) continue; // outra tentativa

		printf("\nPORTA LIBERADA!\n\n");
		return 0;
	};
	printf("\nTente outra vez. Encerrando!...\n\n");
	return 0;
};

int fase(int etapa, int alvo)
{
	int numero = -1;
	printf("[Etapa %d de 5] Digite o numero: ", 1 + etapa);
	scanf("%d", &numero);
	if (numero != alvo) return 0;
	printf("Voce passou pela etapa %d! Continue...\n\n", 1 + etapa);
	return 1;
};

int fase1(int etapa, int alvo)
{
	int numero = -1;
	printf("[Etapa %d de 5] Digite o numero: ", 1 + etapa);
	scanf("%d", &numero);
	while (numero != alvo)
	{
		printf("\nVoce digitou um numero incorreto!\n");
		printf("Tente novamente\n\n");
		printf("[Etapa %d de 5] Digite o numero: ", etapa);
		scanf("%d", &numero);
	};
	if (numero != alvo) return 0;
	printf("Voce passou pela etapa %d! Continue...\n\n", 1 + etapa);
	return 1;
};

