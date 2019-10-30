#include <stdio.h>
#include <stdlib.h>
#include "fila_vetor.h"

int num_elements, element;

void inserir()
{
    int qtd_insered = 0;
    printf("Digite quantos elementos você deseja inserir: ");
    scanf("%d", &num_elements);
    for (int i = 0; i < num_elements; i++)
    {
        printf("Elemento %d: ", i);
        scanf("%d", &element);
        if (enfileira(element))
            qtd_insered++;
    }
    if (num_elements == qtd_insered)
        printf("%d elemento(s) foram inseridos na fila.\n", qtd_insered);
    else
        printf("%d elemento(s) foram inseridos na lista, porém %d não coube(ram).\n", qtd_insered, num_elements - qtd_insered);
}

void remover()
{
    int qtd_removed = 0;
    printf("Digite quantos elementos você deseja remover: ");
    scanf("%d", &num_elements);
    while (num_elements != qtd_removed)
    {
        if (!fila_vazia())
        {
            desenfileira(&element);
            printf("Elemento removido: %d\n", element);
        }
        else
        {
            printf("Não é possível remover mais elementos, a fila está vazia!\n");
            break;
        }
    }
}
