#include <iostream>
#include <locale.h>
#include "pilha.cpp"

using namespace std;

int main()
{
	Pilha pilha;

	no* nodo = NULL;
	char expressao[251];
	int n = 1;

	setlocale(LC_ALL, "Portuguese");
	printf("--------------------------------------------------------\n");
	printf("--------------------------------------------------------\n");
	printf("========================================================\n");
	printf("========= UNIVERSIDADE FEDERAL FLUMINESE - UFF =========\n");
	printf("========== Mestrado em Modelagem Computacional =========\n");
	printf("=========== Estrutura de Dados e Algoritimos ===========\n");
	printf("========================================================\n");
	printf("--------------------------------------------------------\n");
	printf("--------------------------------------------------------\n");
	printf("============== Yuri Lucas de Souza Paropat =============\n");
	printf("--------------------------------------------------------\n");
	printf("--------------------------------------------------------\n");
	printf("------ Estudo de pilhas e como ela pode ser usada ------\n");
	printf("--------- como ferramenta para resolver equaçoes -------\n");
	printf("----- parentesadas com profundidades imprevisiveis -----\n");
	printf("--------------------------------------------------------\n");
	printf("--------------------------------------------------------\n");
	printf("---------------- Volta Redonda/RJ - 2022 ---------------\n");
	printf("--------------------------------------------------------\n");
	printf("--------------------------------------------------------\n");

	printf("Insira a expressão:\n");

	scanf_s("%250s", expressao, (unsigned)_countof(expressao));

	for (int i = 0; i < sizeof(expressao); i++)
	{
		if (expressao[i] == ' ' || expressao[i] == NULL)
			break;
		n++;
	}

	nodo = pilha.ParaPosfix(expressao, n);

	printf("\nResulatdo: %f \n", pilha.ResolvePosFix(&nodo));
	printf("\n----------------------------------------------\n");
	printf("\nFinal do programa.\n");

	return 0;
}