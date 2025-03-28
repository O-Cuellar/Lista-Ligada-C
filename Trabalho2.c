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

void Insert(node *head){//CRIAÇÃO DA FUNÇÃO DA FUNÇÃO QUE INSERE
    node *newNode = (node*)malloc(sizeof(node));//ALOCA DINAMICAMENTE O NOVO NÓ
    if(!newNode){//VERIFICA SE O NOVO NÓ FOI ALOCADO
        printf("\nMemória cheia!");
        return;
    }
    newNode->next = NULL;//INICIALIZA O NOVO NÓ
    printf("\nDigite o numero da conta do cliente:\n");
    scanf("%d", &newNode->numAcc);//SOLICITA O NÚMERO DA CONTA DO CLIENTE
    node *aux1 = head->next;//CRIAÇÃO DO NÓ AUX PARA PERCORRER O VETOR
    while (aux1 != NULL){//LOOP QUE PERCORRE A LISTA PARA VERIFICAR SE O NÚMERO DA CONTA JÁ EXISTE NO BANCO DE DADOS
        if(aux1->numAcc == newNode->numAcc){//SE O NÚMERO DA CONTA JÁ EXISTIR NA LISTA O NÓ NÃO É ALOCADO
            printf("\n-----------------------------------------------------");
            printf("\nO NÚMERO DA CONTA JÁ EXISTE NO BANCO DE DADOS!\n");
            printf("\n-----------------------------------------------------");
            free(newNode);
            return;
        }
        aux1 = aux1->next;
    }
    printf("\nDigite o nome do cliente:\n");
    scanf("%s", newNode->name);
    printf("\nDigite o saldo do cliente:\n");
    scanf("%f", &newNode->saldo);
    if (head->next == NULL){//SE HEAD->NEXT FOR NULO HEAD->NEXT RECEBE O NOVO NÓ
        head->next = newNode;
        }else{//SE NÃO FOR O NÓ AUXILIAR PERCORRE A LISTA ATÉ QUE ->NEXT SEJA NULO
            node *aux2 = head->next;
            while(aux2->next != NULL){
                aux2 = aux2->next;
            }
            aux2->next = newNode;//AUX->NEXT RECEBE O NOVO NÓ E ENTÃO ELE É ALOCADO
        }
}

void Remove(node *head){//CRIAÇÃO DA FUNÇÃO QUE REMOVE
    int num = 0;
    printf("\nDigite o número da conta que deseja remover:\n");
    scanf("%d", &num);
    node *prev = head;//PREV RECEBE HEAD COMO PARAMETRO
    node *aux3 = head->next;//AUX RECEBE HEAD->NEXT COMO PARAMETRO, O PRIMEIRO NÓ COM CONTEUDO VALIDO
    while (aux3 != NULL){//ENQUANTO AUX FOR DIFERENTE DE NULO
        if(aux3->numAcc == num){//SE AUX->NUM ACC FOR IGUAL AO NÚMERO DE ACC QUE FOI DIGITADO
            printf("\nREMOVIDO COM SUCESSO\n");//EXIBE A MENSAGEM DE REMOÇÃO
            prev->next = aux3 ->next;//PREV->NEXT RECEBE AUX->NEXT
            free(aux3);//E AUX É APAGADO DA MEMÓRIA SEM DEIXAR RASTROS COM FREE
            }else{
                printf("\nNúmero da conta não encontrado, logo não é possível remover!\n");
            }   
            prev = aux3;//CADA VEZ QUE O LOOP É ATUALIZADO PREV RECEBE AUX 
            aux3 = aux3->next;//PERCORRE A LISTA
    }
    
}

void Show(node *head){//CRIAÇÃO DA FUNÇÃO QUE EXIBE
    node *aux = head->next;//CRIAÇÃO DO NÓ AUXILIAR PARA PERCORRER A LISTA
    if (head->next == NULL){//SE A LISTA ESTIVER VAZIA EXIBE A MENSAGEM
        printf("\n-----------------------------------------------------");
        printf("\nLista vazia");
        printf("\n-----------------------------------------------------");
    }else{//SE NÃO ESTIVER VAZIA PERCORRE A LISTA E EXIBE NÓ POR NÓ ATÉ AUX SER NULL
        while (aux != NULL)
        {
            printf("\n------------------------------------------------------------------");
            printf("\nNúmero da conta do cliente:                      %d", aux->numAcc);
            printf("\nNome do cliente:                                 %s", aux->name);
            printf("\nSaldo do cliente:                                %f", aux->saldo);
            printf("\n------------------------------------------------------------------");
            aux = aux->next;//DECLARAÇÃO PARA QUE A LISTA SEJA PERCORRIDA
        }
    }
}

void Selection(int *option, node *head){//FUNÇÃO QUE LÊ A SELEÇÃO DA OPÇÃO ESCOLHIDA PELO USÚARIO
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