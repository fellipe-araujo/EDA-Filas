#include <stdio.h>
#include <stdlib.h>
#include "fila_vetor.h"

#define N 5
int fila[N];
int p, u;

void cria_fila()
{
    p = 0;
    u = 0;
}

int enfileira(int x)
{
    if (fila_cheia())
        return 0;
    fila[u] = x;
    u++;
    return 1;
}

int desenfileira(int *x)
{
    if (fila_vazia())
        return 0;
    *x = fila[p];
    p++;
    return 1;
}

int fila_cheia()
{
    if (u == N)
        return 1;
    return 0;
}

int fila_vazia()
{
    if (p == u)
        return 1;
    return 0;
}

void tamanho_fila()
{
    int tamanho = u - p;
    if (p > u)
    {
        tamanho += N;
    }
    printf("Tamanho da fila: %d\n", tamanho);
}

void imprime_fila()
{
    printf(" ");
    for (int i = 0; i < N; i++)
    {
        printf("------");
    }
    printf("\n");
    for (int i = 0; i < N; i++)
    {
        printf("| %03d ", fila[i]);
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