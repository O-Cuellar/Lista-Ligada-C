#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Banco{
    int numAcc;
    char name[30];
    float saldo;
    struct Banco *next;
};
typedef struct Banco node;

node* Allocation(){//FUNÇÃO QUE INICIALMENTE ALOCA HEAD NA MEMÓRIA
    node *head = (node*)malloc(sizeof(node));
    if(!head){//CASO A ALOCAÇÃO DE MEMÓRIA FALHE RETORNA NULL
        printf("\nA alocação de memória falhou, memória cheia!");
        return NULL;
    }
    head->next = NULL;//HEAD INICIALMENTE NÃO APONTA PARA NINGUEM
    return head;//RETORNA HEAD
}

void Insert(node *head){
    node *newNode = (node*)malloc(sizeof(node));
    if(!newNode){//CASO A ALOCAÇÃO DE MEMÓRIA FALHE RETORNA NULL
        printf("\nA alocação de memória falhou, memória cheia!");
        return;
    }
    newNode->next = NULL;//INICIALIZA NEWNODE
    //PEDE OS DADOS A SEREM INSERIDOS NO BANCO
    printf("\n-----------------------------------------------------");
    printf("\nDigite o número da conta do cliente a ser adionado:\n");
    scanf("%d", &newNode->numAcc);
    printf("\nDigite o nome do cliente:\n");
    scanf("%s", newNode->name);
    printf("\nDigite o saldo a ser adicionado:\n");
    scanf("%f", &newNode->saldo);
    printf("\n-----------------------------------------------------");
    if(head->next == NULL){//SE CABEÇA PRÓXIMO FOR NULO
        head->next = newNode;//CABEÇA PRÓXIMO RECEBE O NOVO NÓ
        }else{//SE NÃO FOR NULO
            node *aux = head->next;//CRIO UM NÓ AUXILIAR QUE RECEBE CABEÇA PRÓXIMO
            while (aux->next != NULL){//ENQUANTO AUXILIAR PROXIMO FOR DIFERENTE DE NULO
                aux = aux->next;//AUX RECEBE AUXILIAR PROXIMO
            }
            aux->next = newNode;//AO FIM DO LOOP AUXILIAR PROXIMO RECEBE O NOVO NÓ
        }
}

void Remove(node *head){
    
}

void Show(node *head){
    node *aux = head->next;
    if (head->next == NULL){
        printf("\n-----------------------------------------------------");
        printf("\nLista vazia");
        printf("\n-----------------------------------------------------");
    }else{
        while (aux != NULL)
        {
            printf("\n-------------------------------------------------");
            printf("\nNúmero da conta do cliente:----------------------%d", aux->numAcc);
            printf("\nNome do cliente:---------------------------------%s", aux->name);
            printf("\nSaldo do cliente:--------------------------------%f", aux->saldo);
            printf("\n-------------------------------------------------");
            aux = aux->next;
        }
    }
}

void Selection(int *option, node *head){
    printf("\nDigite o número correspondente a opção desejada:\n");
    printf("\n0-PARA SAIR\n1-PARA INSERIR UM CLIENTE\n2-PARA REMOVER UM CLIENTE\n3-PARA EXIBIR A LISTA DE CLIENTES\n");
    scanf("%d", option);
    switch (*option){
        case 0:
            printf("\n-------------------------------------------------");
            printf("\nSaindo...\n");
            printf("\n-------------------------------------------------");
            break;
        case 1:
            Insert(head);
            break;
        case 2:
            Remove(head);
            break;
        case 3:
            Show(head);
            break;
        default:
            printf("\nOPÇÃO INVÁLIDA, POR FAVOR SELECIONE UMA OPÇÃO VÁLIDA\n");
            break;
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    int option = 0;
    node *head = Allocation();
    do{
        Selection(&option, head);
    } while (option != 0);
    return 0;
}