#include <stdio.h>
#include <stdlib.h>
#include "fila_vetor.h"

#define N 5
static int fila[N];
static int p, u;

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
    u = (u + 1) % N;
    return 1;
}

int desenfileira(int *x)
{
    if (fila_vazia())
        return 0;
    *x = fila[p];
    p = (p + 1) % N;
    return 1;
}

int fila_cheia()
{
    if ((u + 1) % N == p)
        return 1;
    return 0;
}

int fila_vazia()
{
    if (p == u)
        return 1;
    return 0;
}

int tamanho_fila()
{
    int tamanho = u - p;
    if (p > u)
    {
        tamanho += N;
    }
    return tamanho;
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
    for (int i = 0; i < N; i++)
    {
        if (i == p)
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