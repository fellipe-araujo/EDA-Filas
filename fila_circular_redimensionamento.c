#include <stdio.h>
#include <stdlib.h>
#include "fila_circular_redimensionamento.h"

int *fila;
int N, p, u;

void cria_fila()
{
    N = 5;
    fila = malloc(N * sizeof(int));
    p = 0;
    u = 0;
}

int enfileira(int x)
{
    if (fila_cheia())
    {
        if (redimensiona())
        {
            fila[u] = x;
            u = (u + 1) % N;
            return 1;
        }
    }
    else
    {
        fila[u] = x;
        u = (u + 1) % N;
        return 1;
    }

    return 0;
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
    for (int i = 0; i < N; i++)
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

int redimensiona()
{
    int i, j;

    fila = realloc(fila, 2 * N * sizeof(int));
    if (fila == NULL)
        return 0;
    if (u != N - 1)
    {
        if (u - 1 < N - p)
        {
            for (i = N, j = 0; j < u; i++, j++)
            {
                fila[i] = fila[j];
            }
            u = N + u;
        }
        else
        {
            for (i = p, j = N + p; i < N; i++, j++)
            {
                fila[j] = fila[i];
            }
            p = N + p;
        }
    }
    N *= 2;
    return 1;
}

void destroi_fila()
{
    free(fila);
}
