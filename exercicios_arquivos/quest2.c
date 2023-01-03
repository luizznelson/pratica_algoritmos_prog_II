#include <stdio.h>

typedef struct q2
{
    int cod;
    char carro[20];
    double valor;
} registro;

registro reg;

int menu();
void formatacao();
void escrita();
void leitura();
void busca();

void main()
{
    int op = -1;

    do
    {
        op = menu();

        switch (op)
        {
        case 1:
            formatacao();
            break;
        case 2:
            escrita();
            break;
        default:
            break;
        }
    } while (op != 0);
    
}

int menu()
{
    int opc;
    printf("Sistema de locacao baseado em arquivo\n");
    printf("Informe a opcao desejada\n");
    printf("1 - Formatar   2 - Escrever\n3 - Ler   4 - Buscar\n0 - Finalizar\n");
    scanf("%d", &opc);

    return opc;
}

void formatacao()
{
    FILE *file;
    registro reg = {0, "", 0.00};
    int i;

    if ((file = fopen("dados.bin", "wb")) == NULL)
    {
        printf("ERRO NO ARQUIVO!\n");
    } else {
        for (i = 0; i < 10001; i++)
        {
            fwrite(&reg, sizeof(reg), 1, file);
        }
        printf("Operacao concluida com sucesso!\n\n");
        fclose(file);
    }
}

void escrita()
{
    FILE *file;
    registro reg;
    int i;

    if ((file = fopen("dados.bin", "rb+")) == NULL)
    {
        printf("ERRO NO ARQUIVO!\n");
    } else {
        reg.cod = -1;

        while(1)
        {
            printf("Digite o codigo de locacao (0 - finalizar): ");
            scanf("%d", &reg.cod);
            setbuf(stdin, NULL);
            if (reg.cod == 0)
            {
                break;
            }

            printf("Digite o nome do veiculo: ");
            gets(reg.carro);
            setbuf(stdin, NULL);

            printf("Digite o valor da locacao: ");
            scanf("%f", &reg.valor);

            fseek(file, (reg.cod - 1) * sizeof(reg), SEEK_SET);
            fwrite(&reg, sizeof(reg), 1, file);
        }

        printf("Operacao concluida com sucesso\n\n");
        fclose(file);
    }
}

void leitura()
{
    FILE *file;

    if ((file = fopen("dados.bin", "rb+")) == NULL)
    {
        printf("ERRO NO ARQUIVO!\n");
    } else {

        while (!feof(file))
        {
            registro reg = {0, "", 0.00};

            fread(&reg, sizeof(registro), 1, file);

            
            if (reg.cod != 0)
            {
                printf("Codigo de locacao  Nome do veiculo  Valor da locacao\n");
                printf("%-18d %-16s %.2f\n", reg.cod, reg.carro, reg.valor);
            }
        }
        printf("Operacao concluida com sucesso!\n");
        fclose(file);
    }
}

void busca()
{
    FILE *file;
    registro reg;  
    int i;

    if ((file = fopen("dados.bin", "rb+")) == NULL)
    {
        printf("ERRO NO ARQUIVO!\n");
    } else {
        printf("Digite o codigo de locacao: ");
        scanf("%d", &reg.cod);
        
        fseek(file, ((reg.cod - 1) * sizeof(reg)), SEEK_SET);
        fread(&reg, sizeof(reg), 1, file);

        if (reg.cod == 0)
        {
            printf("Nenhum registro de locacao com a chave informada foi encontrado.\n");
        } else {
                printf("Codigo de locacao  Nome do veiculo  Valor da locacao\n");
                printf("%-18d %-16s %.2f\n", reg.cod, reg.carro, reg.valor);
        }

        printf("Operacao concluida com sucesso!\n");
        fclose(file);
    }
}