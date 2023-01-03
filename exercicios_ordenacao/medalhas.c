#include <stdio.h>

#define N 500

typedef struct medalhas
{
    char pais[20];
    int ouro, prata, bronze;    
} participantes;

void insertionParticipantes(participantes part[], int tamanho);

void main()
{
    int n_part, i;
    participantes partc[N];

    scanf("%d", &n_part);

    for(i = 0; i < n_part; i++)
    {
        scanf("%s %d %d %d", partc[i].pais, &partc[i].ouro, &partc[i].prata, &partc[i].bronze);
    }

    insertionParticipantes(partc, n_part);

    for (i = 0; i < n_part; i++)
    {
        printf("%s %d %d %d\n", partc[i].pais, partc[i].ouro, partc[i].prata, partc[i].bronze);
    }
}

void insertionParticipantes(participantes part[], int tamanho)
{
    int i, j;
    participantes aux;

    for (i = 0; i < tamanho - 1; i++)
    {
        for (j = i + 1; j < tamanho; j++)
        {
            if (part[j].ouro > part[i].ouro)
            {
                aux = part[j];
                part[j] = part[i];
                part[i] = aux;  
            } else
            {
                if (part[j].ouro == part[i].ouro && part[j].prata > part[i].prata)
                {
                    aux = part[j];
                    part[j] = part[i];
                    part[i] = aux;         
                } else 
                {
                    if (part[j].prata == part[i].prata && part[j].bronze > part[i].bronze)
                    {
                        aux = part[j];
                        part[j] = part[i];
                        part[i] = aux;  
                    }
                }
            }
        }
    }
}