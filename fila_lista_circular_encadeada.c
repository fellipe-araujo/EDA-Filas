#include <stdio.h>
#include <stdlib.h>
#include "fila_lista_circular_encadeada.h"

typedef struct celula
{
    int dado;
    struct celula *prox;
    int N;
} celula;

celula *fila;

int cria_fila()
{
    fila = malloc(sizeof(celula));
    if (fila == NULL)
        return 0;
    fila->prox = fila;
    fila->N = 0;
    return 1;
}

int enfileira(int x)
{
    celula *novo = malloc(sizeof(celula));
    if (novo == NULL)
        return 0;
    novo->prox = fila->prox;
    fila->prox = novo;
    fila->dado = x;
    fila = novo;
    fila->N++;
    return 1;
}

int desenfileira(int *x)
{
    if (fila_vazia())
        return 0;
    celula *lixo = fila->prox;
    *x = lixo->dado;
    fila->prox = lixo->prox;
    fila->N--;
    free(lixo);
    return 1;
}

int fila_vazia()
{
    if (fila->prox == fila)
        return 1;
    return 0;
}

int tamanho_fila()
{
    return fila->N;
}

void imprime_fila()
{
    printf(" ");
    for (int i = 0; i < fila->N; i++)
    {
        printf("------");
    }
    printf("\n");
    for (int i = 0; i < fila->N; i++)
    {
        printf("| %03d ", fila[i]);
    }
    printf(" |\n ");
    for (int i = 0; i < fila->N; i++)
    {
        printf("------");
    }
}
