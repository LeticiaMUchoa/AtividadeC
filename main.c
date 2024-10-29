#include <stdio.h>
#include <stdlib.h>
struct nodo { int valor; struct nodo *proximo; };
typedef struct nodo Lista;

Lista* criaLista() { return NULL; }
Lista* insereLista(Lista *l, int v) {
Lista* novo = (Lista*) malloc(sizeof(Lista)); novo->valor = v; novo->proximo = l; return novo;
}

Lista* ordemcrescente(Lista *l, int v) {
Lista *novo = (Lista*) malloc(sizeof(Lista)); novo->valor = v;
if (l == NULL || l->valor >= v) { novo->proximo = l; return novo; }
Lista *atual = l; while (atual->proximo && atual->proximo->valor < v) atual = atual->proximo;
novo->proximo = atual->proximo; atual->proximo = novo; return l;
}

void mostraLista(Lista *l) {
while (l) { printf("%d ,", l->valor); l = l->proximo; }
}

int listaVazia(Lista *l) { return l == NULL; }
int buscaLista(Lista *l, int v) {
int pos = 0; while (l) { if (l->valor == v) return pos; l = l->proximo; pos++; }
return -1;
}

Lista* removeLista(Lista *l, int v) {
Lista *ant = NULL; Lista *atual = l; 
while (atual && atual->valor != v) { ant = atual; atual = atual->proximo; }
if (atual == NULL) return l; 
if (ant) ant->proximo = atual->proximo; else l = atual->proximo; 
free(atual); 
return l;
}

void liberaLista(Lista *l) { while (l) { Lista *temp = l->proximo; free(l); l = temp; } }
int main() {
Lista *minhaLista = criaLista();
minhaLista = ordemcrescente(minhaLista, 20);
minhaLista = ordemcrescente(minhaLista, 10);
minhaLista = ordemcrescente(minhaLista, 30);
minhaLista = ordemcrescente(minhaLista, 15);
printf("Lista: "); mostraLista(minhaLista);
int indice = buscaLista(minhaLista, 20);
if (indice != -1) printf("achei o 20 na posicao %d\n", indice);
else printf("20 nao encontrado\n");
minhaLista = removeLista(minhaLista, 20);
printf("Depois de remover 20:\nLista: "); 
mostraLista(minhaLista);
liberaLista(minhaLista);
return 0;
}
