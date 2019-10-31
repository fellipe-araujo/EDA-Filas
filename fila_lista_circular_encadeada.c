#include <stdio.h>
#include <stdlib.h>
#include "fila_lista_circular_encadeada.h"

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

int N;
int p, u;
celula *fila;

int cria_fila()
{
    fila = malloc(sizeof(celula));
    if (fila == NULL)
        return 0;
    fila->prox = fila;
    N = 0;
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
    u = u + 1;
    N++;
    return 1;
}

int desenfileira(int *x)
{
    if (fila_vazia())
        return 0;
    celula *lixo = fila->prox;
    *x = lixo->dado;
    fila->prox = lixo->prox;
    u = u - 1;
    N--;
    free(lixo);
    return 1;
}

int fila_vazia()
{
    if (fila->prox == fila)
        return 1;
    return 0;
}

void tamanho_fila()
{
    printf("Tamanho da fila: %d\n", N);
}

void imprime_fila()
{
    celula *imprime;
    int i;
    if (N > 0)
    {
        printf(" ");
        for (int i = 0; i < N; i++)
        {
            printf("------");
        }
        printf("\n");
        if (imprime != fila)
        {
            for (imprime = fila, i = 0; i <= N; imprime = imprime->prox, i++)
            {
                if (imprime == fila)
                    continue;
                printf("| %03d ", imprime->dado);
            }
        }
        printf(" |\n ");
        for (int i = 0; i < N; i++)
        {
            printf("------");
        }
        printf("\n");
        for (int i = 0; i <= N; i++)
        {
            if (i == p && i == u)
            {
                printf("  p u ");
            }
            else if (i == p)
            {
                printf("   p  ");
            }
            else if (i == u)
            {
                printf("   u  ");
            }
            else
            {
                printf("      ");
            }
        }
    }
    else
    {
        printf("Fila vazia!\n");
    }
}
