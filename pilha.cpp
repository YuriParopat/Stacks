#include <stdio.h>
#include <stdlib.h>
#include "utils.cpp"

using namespace std;

typedef	struct nodo {
	char dado;
	struct nodo* proximo;
}no;

class Pilha {
private:

	int empilha(no** topo, char valor) {
		no* novo;
		int erro = 0;
		if ((*topo) == NULL) {
			if (((*topo) = (no*)malloc(sizeof(no))) == NULL) erro = 1;
			else {
				(*topo)->dado = valor;
				(*topo)->proximo = NULL;
			}
		}
		else {
			if ((novo = (no*)malloc(sizeof(no))) == NULL) erro = 1;
			else {
				novo->proximo = *topo;
				*topo = novo;
				(*topo)->dado = valor;
			}
		}
		return erro;
	}
	int desempilha(no** topo, char* valor) {
		no* aux;
		int erro = 0;
		if ((*topo) == NULL) erro = 1;
		else if ((aux = (no*)malloc(sizeof(no))) != NULL) {
			aux = *topo;
			(*topo) = aux->proximo;
			(*valor) = aux->dado;
			free(aux);
		}
		return erro;
	}
	int mostra(no** pilha) {
		int erro = 0;
		if ((*pilha) == NULL)erro = 1;
		else {
			no* aux = *pilha;
			printf("\nPILHA:\n");
			while (aux != NULL) {
				printf("%c\n", (aux->dado));
				aux = (aux->proximo);
			}
		}
		return erro;
	}
	no* InvertPilha(no** pilha) {
		no* saida = NULL;
		if ((*pilha) == NULL)return NULL;
		else {
			no* aux = *pilha;
			while (aux != NULL) {
				empilha(&saida, (aux->dado));
				aux = (aux->proximo);
			}
		}
		return saida;
	}
public:
	Pilha() { no* nv = NULL; }
	float ResolvePosFix(no** pilha) {
		Util util;
		char x, y, s;
		no* pilha2 = NULL;
		if ((*pilha) == NULL)return -1;
		else {
			no* aux = *pilha;
			while (aux != NULL) {
				if (util.IsOperator(aux->dado) != -1) {
					desempilha(&pilha2, &x);
					desempilha(&pilha2, &y);
					float result = util.Operation(x, y, aux->dado);
					empilha(&pilha2, result);
				}
				else if (util.IsDigit(aux->dado) > 0) {
					empilha(&pilha2, util.ScanNum(aux->dado));
				}
				aux = aux->proximo;
			}
			desempilha(&pilha2, &s);
			return s;
		}
	}

	no* ParaPosfix(char* expressao, int n) {
		int i;
		Util util;
		no* pilha = NULL;
		no* saida = NULL;
		char  t = ' ';

		for (i = 0; i < n; i++) {
			if (expressao[i] == '(') {
				empilha(&pilha, '(');
			}
			else if (expressao[i] == ')' || (pilha != NULL && i == n - 1)) {
				do {
					if (pilha == NULL) break;
					desempilha(&pilha, &t);
					if (t != '(') {
						empilha(&saida, t);
					}
				} while (t != '(');
			}
			if (util.IsDigit(expressao[i]) > 0)
				empilha(&pilha, expressao[i]);
			if (util.IsOperator(expressao[i]) != -1) {
				desempilha(&pilha, &t);
				empilha(&pilha, expressao[i]);
				empilha(&pilha, t);
			}
		}
		return InvertPilha(&saida);
	}
};


