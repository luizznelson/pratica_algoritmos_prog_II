#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 1000

typedef struct
{
    int codloc;
    char nome[20];
} registro;

typedef struct
{
    registro item[MAX + 1];
    int tamanho;
} tabela;

// funcoes usadas
void preenche(int pos);
void salvarDados(tabela t, char nomearq[]);
void restaurarDados(tabela t, char fnome[]);

registro reg;
tabela t;

void main()
{
    int i, op = 0;
    char nomearq[30];

    srand(time(NULL));

    // Menu
    printf("Sistema de backup de dados\n\n");
    printf("Informe a operacao desejada (1 - Salvar; 2 - Restaurar): ");
    scanf("%d", &op);
    fflush(stdin);

    switch (op)
    {
    case 1:
        for (i = 0; i < 1000; i++)
        {
            preenche(i);
        }
        printf("Informe o nome do arquivo de backup: ");
        scanf("%s", nomearq);
        salvarDados(t, nomearq);
        break;
    case 2:
        printf("Informe o nome do arquivo de backup: ");
        scanf("%s", nomearq);
        restaurarDados(t, nomearq);
    default:
        break;
    }
}

void preenche(int pos)
{
    t.item[pos].codloc = rand () % 1001;
    strcpy(t.item[pos].nome, "Gol");
}

void salvarDados(tabela t, char nomearq[])
{
    int i;
    FILE *file;
    file = fopen(nomearq, "w");

    if (file == NULL)
    {
        printf("Erro na abertura do arquivo!\n");
    } else {
        for (i = 0; i < 1000; i++)
        {
            fprintf(file, "Veiculo %d\n", i + 1);
            fprintf(file, "Codigo de locacao: %d\n", t.item[i].codloc);
            fprintf(file, "Nome do veiculo: %s\n\n", t.item[i].nome);
        }
        printf("Operacao concluida com sucesso!\n");
    }

    fclose(file);
}

void restaurarDados(tabela t, char fnome[])
{
    int i;
    FILE *file;

    file = fopen(fnome, "r");

    if (file == NULL)
    {
        printf("ERRO NA ABERTURA DO ARQUIVO!\n");
    } else {
        printf("Operacao concluida com sucesso!\n");

        for (i = 0; i < 1000; i++)
        {
            fscanf(file, "%d %s", t.item[i].codloc, t.item[i].nome);
        }
    }
}