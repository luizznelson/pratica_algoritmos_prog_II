#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int codg;
    char descricao[24];
    int idade;
    float preco;
} brinquedos;

void cadastrar(brinquedos reg);
void visualiza(brinquedos reg);
void busca(brinquedos reg);
void buscaMultipla(brinquedos reg);

int main(int argc, char *argv[]){
    int opcao=0;
    brinquedos reg = {0,"",0.00};
    while (opcao != 5){
        if (opcao == 0){
            printf(" 1 - Cadastrar\n 2 - Visualizar \n 3 - Buscar um Registro\n 4 - Buscar Muitos Registros\n 5 - Finalizar \n Informe o modulo desejado: ");
            scanf("%d", &opcao);
        }

        switch (opcao){
        case 1:
            cadastrar(reg);
            break;
        case 2:
            imprimir(reg);
            break;
        case 3:
            busca(reg);
            break;
        case 4:
            buscaMultipla(reg);
            break;
        }
        printf("\nInforme o modulo desejado: ");
        scanf("%d", &opcao);
    }
}
void cadastrar(brinquedos reg){
    FILE *fptr;
    if((fptr = fopen("dados.bin", "rb+")) == NULL){
        printf("Arquivo nao encontrado\n");
    }else{
            printf("Digite o codigo: ");
            scanf("%d", &reg.codg);
            setbuf(stdin, NULL);
            printf("Digite a descricao: ");
            scanf("%[^\n]s", reg.descricao);
            printf("Digite a idade: ");
            scanf("%d", &reg.idade);
            printf("Digite o preco: ");
            scanf("%f", &reg.preco);
            fseek(fptr, (reg.codg - 1) * sizeof (reg), SEEK_SET );
            fwrite(&reg, sizeof(reg), 1 ,fptr);

        printf("Operacao de escrita finalizada\n");
    }
    fclose(fptr);
}

void visualiza(brinquedos reg){
    FILE *fptr;
    if((fptr = fopen("dados.bin", "rb")) == NULL){
        printf("Arquivo nao encontrado\n");
    }else{
        while (!feof(fptr)){
          fread(&reg, sizeof(Registro), 1, fptr);
          if (reg.codg != 0){
                printf("Codigo, descricao, idade e preco\n");
                printf("%d,%s,%d,%.2f\n", reg.codg, reg.descricao, reg.idade, reg.preco);
            }
        }
        printf("Operacao de leitura finalizada\n");
    }
    fclose(fptr);
}


void busca(brinquedos reg){
  FILE *arq;
  int busca_cod;
  printf("Codigo de busca: ");
  scanf("%d",&busca_cod);
  if(busca_cod == 0){
    exit(1);
  }
  else{
    if(!(arq = fopen("dados.bin","rb"))){
      printf("[!]Erro - Abertura incorreta!\n");
      exit(1);
    }
    else{
      while( !feof(arq) ){
        fread(&reg,sizeof(brinquedos),1,arq);
        if(reg.cod != 0 && reg.codg == busca_cod){
          printf("%d %s %d %.2f\n",reg.codg,reg.descricao,reg.idade, reg.preco);
        }
      }
    }
  }
}

void buscaMultipla(brinquedos reg){
  FILE *arq;
  int busca = -1,n, i = 0;
  printf("Quantidade de Códigos para busca: ");
  scanf("%d",&n);
  int codigos_dig[n];
  while(busca != 0 &&  i < n){
    printf("Codigo de busca: ");
    scanf("%d",&busca);
    if(busca == 0){
      exit(1);
    }
    else{
      codigos_dig[i] = busca;
      i++;
    }
  }
  if(!(arq = fopen("dados.bin","rb"))){
    printf("[!]Erro - Abertura incorreta!\n");
    exit(1);
  }
  else{
    i = 0;
    while( !feof(arq) && i < n){
      fread(&reg,sizeof(brinquedos),1,arq);
      if(reg.codg != 0 && reg.codg == codigos_dig[i]){
        printf("%d %s %d %.2f\n",reg.codg,reg.descricao,reg.idade, reg.preco);
        i++;
      }
    }
  }
}
