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
Caixa * InsereLLE_F (Caixa * L, int d,int saida, int i) //F = fim (terminar)
{
 Caixa *pAux, *novo;//pAux será usado na busca pelo fim
                  // novo receberá o dado para inserir
    novo=(Caixa *) malloc(sizeof (Caixa));//aloca memória
    novo->data = d;
    novo->tsaida = saida;
    novo->valor = i;
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
Caixa * RemoverPorData(Caixa * L, ) (TERMINAR)

int main(){
int opcao,x=0,valor,pos,data,saida;
Caixa * L;
L = InicializaLLE();
do{
    system("cls");
    printf("\nEntre com a opcao:\n");
    printf(" 1 - Inserir entrada\n");
    printf(" 2 - Remover entrada por data\n");
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
                printf("Digite o tipo de saida 1 - saque 2 - deposito:\n");
                scanf("%d",&saida);
                printf("Digite um valor para inserir:\n");
                scanf("%d",&valor);

              L=InsereLLE_F(L,data,saida,valor);

      case 2:
              break;
      case 3:
              break;
      case 4:
          ExibeLLE(L);
         system("pause");
              break;
      case 5:
            break;
      case 6:
              break;
      case 7: exit(0);
              break;
      default:
               printf("\tATENCAO - Opcao invalida, tente novamente!\n");
               system("pause");
     }
 }while(x == 0);
}








