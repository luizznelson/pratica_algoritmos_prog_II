#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int chave;
    char nome[30];
    char endereco[50];
    char telefone[14];
} alunos;


// GERAR DADOS
void gerarDados(alunos vet[], int nVet, int ordemChave);
void geraCrescente(alunos vet[], int tVet);
void geraAleatorio(alunos vet[], int tVet);
void geraDecrescente(alunos vet[], int tVet);

// IMPRIMIR DADOS
void imprimeOrdem(alunos vet[], int tVet);

// ORDENA DADOS
void ordenaBolha(alunos vet[], int tVet);
void ordenaSelecao(alunos vet[], int tVet);
void ordenaInsercao(alunos vet[], int tVet);

void main()
{
    int tamVet = 0, ordChave = 0, tipoOrd = 0;

    srand((unsigned)time(NULL));

    scanf("%d", &tamVet);

    alunos aluno[tamVet];

    while(1)
    {
        scanf("%d", &ordChave);
        if (ordChave == 3)
        {
            break;
        }
        scanf("%d", &tipoOrd);

        gerarDados(aluno, tamVet, ordChave);

        switch (tipoOrd)
        {
        case 0:
            printf("bolha\n");
            imprimeOrdem(aluno, tamVet);
            ordenaBolha(aluno, tamVet);
            break;
        
        case 1:
            printf("selecao\n");
            imprimeOrdem(aluno, tamVet);
            ordenaSelecao(aluno, tamVet);
            break;
        
        case 2:
            printf("insercao\n");
            imprimeOrdem(aluno, tamVet);
            ordenaInsercao(aluno, tamVet);
            break;

        default:
            break;
        }

        imprimeOrdem(aluno, tamVet);
    }
}

void gerarDados(alunos vet[], int nVet, int ordemChave)
{
    switch (ordemChave)
    {
    case 0:
        geraCrescente(vet, nVet);
        break;

    case 1:
        geraAleatorio(vet, nVet);
        break;

    case 2:
        geraDecrescente(vet, nVet);
        break;

    default:
        printf("Numero invalido!\n");
        break;
    }
}

void geraCrescente(alunos vet[], int tVet)
{
    int i = 0;

    for (i = 0; i < tVet; i++)
    {
        vet[i].chave = i;
    }
}

void geraAleatorio(alunos vet[], int tVet)
{
    int i = 0;

    for (i = 0; i < tVet; i++)
    {
        vet[i].chave = rand() % 10001;
    }
}

void geraDecrescente(alunos vet[], int tVet)
{
    int i = 0, j = 0;

    for (j = tVet - 1; j >= 0; j--, i++)
    {
        vet[i].chave = j;
    }
}

void imprimeOrdem(alunos vet[], int tVet)
{
    int i = 0;

    for (i = 0; i < tVet; i++)
    {
        printf("%d ", vet[i].chave);
    }
    printf("\n");
}

void ordenaBolha(alunos vet[], int tVet)
{
    int i = 0, j = 0, aux = 0;

    for (i = 0; i < tVet - 1; i++)
    {
        for (j = 1; j < tVet - 1; j++)
        {
            if (vet[j].chave < vet[j - 1].chave)
            {
                aux = vet[j].chave;
                vet[j].chave = vet[j - 1].chave;
                vet[j - 1].chave = aux;
            }
        }
    }
}

void ordenaSelecao(alunos vet[], int tVet)
{
    int i, j, menor = 0, aux = 0;

    for (i = 0; i < tVet - 1; i++)
    {
        menor = i;
        for (j = i + 1; j < tVet; j++)
        {
           if (vet[menor].chave > vet[j].chave)
           {
               menor = j;
           } 
           if (i != menor)
           {
               aux = vet[i].chave;
               vet[i].chave = vet[menor].chave;
               vet[menor].chave = aux;
           }
        }
    }
}

void ordenaInsercao(alunos vet[], int tVet)
{
    int i, j, aux = 0;

    for (i = 1; i < tVet; i++)
    {
        aux = vet[i].chave;
        for (j = i - 1; j >= 0 && (vet[j].chave > aux); j--)
        {
            vet[j + 1].chave = vet[j].chave;
        }
        vet[j + 1].chave = aux;
    }       
}