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
Caixa * InsereLLE_F (Caixa * L, int d,int saida, int i,char* desc,int Codigo) //F = fim (terminar)
{
 Caixa *pAux, *novo;//pAux será usado na busca pelo fim
                  // novo receberá o dado para inserir
    novo=(Caixa *) malloc(sizeof (Caixa));//aloca memória
    novo->data = d;
    novo->tsaida = saida;
    novo->valor = i;
    strcpy(novo->descricao,desc);
    novo->codigo = Codigo;
    novo->elo = NULL; // vai ser o último

    if (L == NULL)
      L = novo; // 1º nodo
    else{
        pAux = L; // p1 no início da lista
    while (pAux->elo != NULL){
        pAux = pAux->elo;   //p1 no final da lista
        }
        pAux->elo = novo; //encadeia com o novo
        }
 return L;
}
Caixa * RemoverPorCodigo(Caixa * lAux,int cod ){

Caixa *ptAux, *desaloca;
    if(lAux==NULL) //lista vazia
    {
        printf("ERRO - Lista Vazia!\n\n");
        return lAux;
        }


        ptAux = lAux; // p1 no início da lista
        while(ptAux->elo->codigo != cod){
            ptAux = ptAux->elo;
            }
        desaloca = ptAux->elo;
        ptAux->elo = ptAux->elo->elo;
        free (desaloca);
    return lAux ;

}

void ExibeData(Caixa * L, int d){
    Caixa * Paux;
    Paux = L;
    if (L == NULL){ //nenhum elemento
    printf("\nLista vazia!\n\n");
    return 0;
    }

      Paux = L; //Paux recebe o endereço do início da lista
        while (Paux != NULL){
            if(d == Paux->data){//Percorrer a lista
                printf("-----------------------------------------------\n\n");
                printf("codigo:%d\t tipo:%d\t valor = %d\t na data: %d\t descricao:%s\t\n", Paux->codigo,Paux->tsaida, Paux->valor,Paux->data,Paux->descricao);
                }

                Paux = Paux->elo;
                }
                return 0;
}

void MostraSaldo(Caixa * L){
Caixa * Paux;
int deposito=0;
int saque=0;
int saldo=0;
    Paux = L;
    if (L == NULL){ //nenhum elemento
    printf("\nLista vazia!\n\n");
    return 0;
    }

      Paux = L; //Paux recebe o endereço do início da lista
        while (Paux != NULL){
            if(Paux->tsaida == 1){//Percorrer a lista
                printf("tipo: entrada.\t valor:%d descricao:%s\n",Paux->valor,Paux->descricao);
                deposito=Paux->valor+deposito;
                }
            else if(Paux->tsaida == 2){
                printf("tipo: saida.\t valor:%d descricao:%s\n",Paux->valor,Paux->descricao);
                saque=Paux->valor+saque;
            }

                Paux = Paux->elo;
                }
                saldo=deposito-saque;
                printf("saldo = %d\n",saldo);
                return 0;
}





int main(){
int opcao,x=0,valor,pos,data,saida,codigo,i;
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
    fflush(stdin);  //para resolver alguns problemas do scanf, limpando o buffer de teclado
    switch (opcao)
    {
      case 1:
                printf("Digite a data:\n");
                scanf("%d",&data);
                printf("Digite o tipo de saida 1 - saida 2 - entrada:\n");
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
            system("pause");
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


