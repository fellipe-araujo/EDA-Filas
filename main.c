#include <stdio.h>
#include <stdlib.h>
#include "fila_vetor.h"

int opcao;
int num_elements, element;

void inserir()
{
    int qtd_insered = 0;
    printf("Digite quantos elementos você deseja inserir: ");
    scanf("%d", &num_elements);
    printf("\nDigite elementos que possuam o valor entre 1 e 999.\n");
    for (int i = 1; i <= num_elements; i++)
    {
        printf("Elemento %d: ", i);
        scanf("%d", &element);
        while (element < 1 || element > 999)
        {
            printf("Elemento inválido! por favor, digite novamente.\n");
            printf("Elemento %d: ", i);
            scanf("%d", &element);
        }
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

void reiniciar()
{
    cria_fila();
    printf("Fila reiniciada!\n");
}

void menu()
{
    printf("===========MENU===========\n\n");
    printf("1 - Inserir elementos na fila\n");
    printf("2 - Remover elementos da fila\n");
    printf("3 - Imprimir fila\n");
    printf("4 - Reiniciar fila\n");
    printf("5 - Sair\n\n");

    printf("Escolha uma opção: %d\n", opcao);
    switch (opcao)
    {
    case 1:
        inserir();
        break;
    case 2:
        remover();
        break;
    case 3:
        imprime_fila();
        break;
    case 4:
        reiniciar();
        break;
    case 5:
        exit(1);
        break;
    default:
        printf("Está opção é inválida, por favor digite novamente: ");
    }

    printf("\n");
    system("pause");
    system("cls || clear");
}
