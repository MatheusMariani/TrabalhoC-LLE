#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 5
struct nodo{
	int codigo;
	int data;
	int tsaida;
	char descricao[40];
	int valor;
	struct nodo * elo;
   };
    typedef struct nodo Caixa;

    Caixa * InicializaLLE()
{
	return NULL;
}
//exibe a lista completa
void ExibeLLE(Caixa * L)
{
    Caixa * Paux;
    int cont=0;
    if (L == NULL){
        printf("\nSem movimentacao!\n\n");
        }
    else{
        Paux = L;
    while (Paux != NULL){ //Percorrer a lista
       printf("codigo:%d tipo:%d, valor = %d, na data: %d, descricao:%s\n", Paux->codigo,Paux->tsaida, Paux->valor,Paux->data,Paux->descricao);
       Paux = Paux->elo;
       cont++;
    }
        printf("\n\n numero de movimentacoes %d.\n\n",cont);
 }
}
//Insere o elemento no final da lista
Caixa * InsereLLE_F (Caixa * L, int d,int saida, int i,char* desc,int Codigo)
{
 Caixa *pAux, *novo;
    novo=(Caixa *) malloc(sizeof (Caixa));
    novo->data = d;
    novo->tsaida = saida;
    novo->valor = i;
    strcpy(novo->descricao,desc);
    novo->codigo = Codigo;
    novo->elo = NULL;

    if (L == NULL)
      L = novo;
    else{
        pAux = L;
    while (pAux->elo != NULL){
        pAux = pAux->elo;
        }
        pAux->elo = novo;
        }
 return L;
}
//remove pelo código digitado
Caixa * RemoverPorCodigo(Caixa * lAux,int cod ){

Caixa *ptAux, *desaloca;
    if(lAux==NULL)
    {
        printf("ERRO - Lista Vazia!\n\n");
        return lAux;
        }


        ptAux = lAux;
        while(ptAux->elo->codigo != cod){
            ptAux = ptAux->elo;
            }
        desaloca = ptAux->elo;
        ptAux->elo = ptAux->elo->elo;
        free (desaloca);
    return lAux ;

}
//exibe as entradas/saidas da data digitada
void ExibeData(Caixa * L, int d){
    Caixa * Paux;
    Paux = L;
    int contador=0;
    if (L == NULL){
    printf("\nLista vazia!\n\n");
    return 0;
    }

      Paux = L;
        while (Paux != NULL){
            if(d == Paux->data){
                printf("-----------------------------------------------\n\n");
                printf("codigo:%d\t tipo:%d\t valor = %d\t na data: %d\t descricao:%s\t\n", Paux->codigo,Paux->tsaida, Paux->valor,Paux->data,Paux->descricao);
                contador++;
                }

                Paux = Paux->elo;
                }
                if(contador == 0)
                    printf("\nSem movimentacao nessa data!\n");
                return 0;
}
//mostra o saldo com todas as entradas e saidas.
void MostraSaldo(Caixa * L){
Caixa * Paux;
int deposito=0;
int saque=0;
int saldo=0;
    Paux = L;
    if (L == NULL){
    printf("\nLista vazia!\n\n");
    return 0;
    }

      Paux = L;
      printf("Entradas:\n");
        while (Paux != NULL){
            if(Paux->tsaida == 1){
                printf("valor:%d descricao:%s\n",Paux->valor,Paux->descricao);
                deposito=Paux->valor+deposito;
                }
                Paux = Paux->elo;
                }
                Paux = L; //Paux recebe o endereço do início da lista
                printf("Saidas:\n");
        while (Paux != NULL){
            if(Paux->tsaida == 2){
                printf("valor:%d descricao:%s\n",Paux->valor,Paux->descricao);
                saque=Paux->valor+saque;
            }
            Paux = Paux->elo;
        }
                saldo=deposito-saque;
                printf("saldo = %d\n",saldo);
                return 0;
}
//salva as movimentacoes em um arquivo de texto.
void SalvaArquivo(Caixa * L){
    char nome[20] = "Caixa.txt";
    FILE * FFLuxo;
    Caixa * Paux;
    Paux = L;

      if(L == NULL){
         printf("lista vazia");
      }
      else{
        FFLuxo = fopen(nome,"a+");
        Paux = L;
        while(Paux!= NULL){
            fprintf(FFLuxo,"codigo:%d tipo:%d, valor = %d, na data: %d, descricao:%s\n", Paux->codigo,Paux->tsaida, Paux->valor,Paux->data,Paux->descricao);
            Paux = Paux->elo;
        }
        fclose(FFLuxo);
        return 0;
      }
}




int main(){
int opcao,x=0,valor,pos,data,saida,codigo,i,op;
Caixa * L;
char descri[30];
L = InicializaLLE();
do{
    system("cls");
    printf("\nEntre com a opcao:\n");
    printf(" 1 - Inserir entrada\n");
    printf(" 2 - Remover entrada por codigo\n");
    printf(" 3 - Consulta movimentacao por data\n");
    printf(" 4 - Exibir todas as movimentacoes\n");
    printf(" 5 - Exibir total de saidas, entradas e saldo\n");
    printf(" 6 - Sair\n");

    scanf("%d",&opcao);
    fflush(stdin);
    switch (opcao)
    {
      case 1:
                printf("Digite a data:\n");
                scanf("%d",&data);
                printf("Digite o tipo de saida 1 - entrada 2 - saida:\n");
                scanf("%d",&saida);
                printf("Digite um valor para inserir:\n");
                scanf("%d",&valor);
                printf("Descricao: ");
                fflush(stdin);
                fgets(descri, 40, stdin);
                printf("codigo:\n");
                scanf("%d",&codigo);

              L=InsereLLE_F(L,data,saida,valor,descri,codigo);
                break;
      case 2:
          printf("digite o codigo");
          scanf("%d",&codigo);
          RemoverPorCodigo(L,codigo);
              break;
      case 3:
          printf("coloque uma data:");
                scanf("%d", &i);
                ExibeData(L,i);
                system("pause");
                break;
      case 4:
          ExibeLLE(L);
          printf("deseja salvar a lista? 1 - sim 2 - nao\n");
          scanf("%d",&op);
          if(op == 1){
          SalvaArquivo(L);
          }
            break;
      case 5:
          MostraSaldo(L);
          system("pause");
            break;
      case 6:
             exit(0);
              break;
      default:
               printf("\tATENCAO - Opcao invalida, tente novamente!\n");
               system("pause");
     }
 }while(x == 0);
}
