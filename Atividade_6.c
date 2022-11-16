#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Declaração das structs da Pilha */
typedef struct pilha Pilha;
typedef struct topo Topo;
int TAM;
int TAM_fila;

struct pilha{
  Topo* top; 
};

struct topo{
    int info;
    Topo* ant;
};

Pilha* inicializar_pilha(void){
    Pilha* l = (Pilha*)malloc(sizeof(Pilha)); //ponteira que aponta para a pilha
    l->top = NULL; //dizendo que a ponteira apontando para top é NULL
    return l; // retrona um ponteiro l que está apotando para a pilha
}

void pilha_inserir(Pilha *ponteiro, int valor){
    Topo* novo = (Topo*)malloc(sizeof(Topo));
    novo->info = valor;
    if (ponteiro->top == NULL){ /* Vendo se a Pilha está vazia */
        ponteiro->top = novo; /* ponteiro do topo vai apontat para o novo dado */
        ponteiro->top->ant = NULL; /* Ponteiro vai apontar para o anterior do novo dado e dizer que é lixo */
        TAM++;
    } else { // se caso a pilha tenha pelo menos um valor
        novo->ant = ponteiro->top; /* o valor do anterior desse novo dado vai apontar para o dado anterior, assim se tornando o topo agora */
        ponteiro->top = novo; /* fazendo com que o ponteiro principal aponte para o novo dado agora */
        TAM++;
    }
}

void pilha_remover(Pilha *ponteiro){
    Topo* removedor = (Topo*)malloc(sizeof(Topo));
    Topo* indicador = (Topo*)malloc(sizeof(Topo));
    if (ponteiro->top == NULL){
        printf("Pilha vazia!\n");
    } else { // com algum valor na pilha
        indicador = ponteiro->top->ant; /* o ponteiro indicador vai apontar para a posiçao anterior ao topo */
        removedor = ponteiro->top; /* O ponteiro removedor vai apontar para o topo */
        free(removedor); /* Liberar o removedor da memória, assim excluindo o topo */
        ponteiro->top = indicador; /* fazendo que o penultimo dado , agora seja o topo */
        TAM--;
        printf("\nValor do topo retirada com sucesso!\n");

    }
    
}

void pilha_buscar(Pilha *ponteiro, int valor){
    for(Topo* indicador = ponteiro->top; indicador != NULL; indicador = indicador->ant){ /* loop para passar por todos os nós */
        if( indicador->info == valor){ /* se o nó tiver um valor igual ao digitado pelo usuário */
            printf("\nValor encontrado!\n\n");
            break;
        } else {
            printf("\nValor nao encontrado, digite um valor que esteja na pilha!\n\n");
            break;
        }
    }
}

void pilha_imprimir(Pilha *ponteiro){
    Topo* indicador = (Topo*)malloc(sizeof(Topo));
    if (ponteiro->top == NULL){
        printf("Pilha vazia!\n");
    } else{
        for(Topo* indicador = ponteiro->top; indicador != NULL; indicador = indicador->ant){  /* loop para passar por todos os nós */
            printf("%d\n", indicador->info);
        }
        printf("\n");
    }
}

/*######################################################################################################################################*/

/* Declaraçao das structs da Fila */
typedef struct fila Fila;
typedef struct filaNo FilaNo;

struct fila{
    FilaNo* prim;
};

struct filaNo{
    int info;
    FilaNo* prox;
    FilaNo* ant;
};

Fila* inicializar_fila(void){
    Fila* p = (Fila*)malloc(sizeof(Fila));
    p->prim = NULL;
    return p;
}

void fila_inserir(Fila* ponteiro_fila, int valor){
    FilaNo* novo = (FilaNo*)malloc(sizeof(FilaNo));
    FilaNo* indicador = (FilaNo*)malloc(sizeof(FilaNo));
    if(ponteiro_fila->prim == NULL){ // se a lista está vazia
        novo->info = valor;
        ponteiro_fila->prim = novo;
        novo->prox = NULL;
        novo->ant = NULL;
        TAM_fila++; 
    } else {
        novo->info = valor; //valor novo no novo nó
        novo->prox = ponteiro_fila->prim; //apontando o ponteiro prox para o prox nó
        novo->ant = NULL; // ponteiro ant do novo é null
        indicador = ponteiro_fila->prim; //ponteiro indicador aponta para onde o ponteiro aponta
        indicador->ant = novo; //o prox nó da fila aponta para o anterior
        ponteiro_fila->prim = novo; //o ponteiro aponta para o novo nó
        TAM_fila++;
    }
}

void fila_remover(Fila* ponteiro_fila){
    FilaNo* removedor = (FilaNo*)malloc(sizeof(FilaNo));
    FilaNo* indicador_ant = (FilaNo*)malloc(sizeof(FilaNo));
    if(ponteiro_fila->prim == NULL){
        printf("\nNao eh possivel remover com a fila vazia!\n");
    } else {
        for(removedor = ponteiro_fila->prim; removedor != NULL; removedor = removedor->prox){
            if(removedor->prox == NULL){ //identificando o primeiro da fila
            indicador_ant = removedor; /* ponteiro aponta para o primeiro nó */
            indicador_ant = indicador_ant->ant; /* ponteiro indicador vai apontar pro nó anterior*/
            free(removedor); /* removendo o primeiro nó da memória */
            indicador_ant->prox = NULL; /* primerio da fila tendo o ponteiro prox como NULL */
            TAM_fila--;
            break;
            }
        }
    }
}

void fila_imprimir(Fila* ponteiro_fila){
    FilaNo* printer = (FilaNo*)malloc(sizeof(FilaNo));
    for( printer = ponteiro_fila->prim; printer != NULL; printer = printer->prox){
        printf("%d\t", printer->info);
    }
    printf("\n");
}

int fila_buscar(Fila* ponteiro_fila, int valor){
    FilaNo* buscador = (FilaNo*)malloc(sizeof(FilaNo));
    for(buscador = ponteiro_fila->prim; buscador != NULL; buscador = buscador->prox){
        if( buscador->info == valor){
            printf("\nValor encontrado!\n");
            break;
            return 0;
        }
    }
}

/*######################################################################################################################################*/

void iniciar_programa(){
    printf("\n\n---------------------------------------------------------\n");
    printf("-                                                       -\n");
    printf("-                                                       -\n");
    printf("-      Deseja entrar no programa de Pilha Dinamica      -\n");
    printf("-                 ou em Fila Dinamica?                  -\n");
    printf("-                                                       -\n");
    printf("-                                                       -\n");
    printf("---------------------------------------------------------\n\n");
}

void switch_program(){
    printf("\n\n---------------------------------------------------------\n");
    printf("-                                                       -\n");
    printf("-                                                       -\n");
    printf("-              Deseja trocar de programa?               -\n");
    printf("-                                                       -\n");
    printf("-                                                       -\n");
    printf("-                                                       -\n");
    printf("---------------------------------------------------------\n\n");
}

void creditos(){
    printf("\n\n---------------------------------------------------------\n");
    printf("-                                                       -\n");
    printf("- Programa desenvolvido por Gabriel Oliveira dos Santos -\n");
    printf("-       Engenharia de Computacao - UNILAB-CE            -\n");
    printf("-                      15/11/2022                       -\n");
    printf("-                                                       -\n");
    printf("---------------------------------------------------------\n\n");
    
}

void menu_pilha(){
    printf("\n*********************************************************\n");
    printf("*                                                       *\n");
    printf("*      Programa com Pilha com Alocacao Dinamica em C    *\n");
    printf("*                                                       *\n");
    printf("*             1- Adicinar valor na Pilha                *\n");
    printf("*             2- Remover valor na Pilha                 *\n");
    printf("*             3- Buscar um valor na Pilha               *\n");
    printf("*             4- Imprimir da Pilha                      *\n");
    printf("*             5- Quantidade de valores na Pilha         *\n");
    printf("*             6- Creditos                               *\n");
    printf("*             7- Trocar de Programa                     *\n");
    printf("*             8- Sair                                   *\n");
    printf("*                                                       *\n");
    printf("*********************************************************\n");
}

void menu_fila(){
    printf("\n*********************************************************\n");
    printf("*                                                       *\n");
    printf("*      Programa com fila com Alocacao Dinamica em C     *\n");
    printf("*                                                       *\n");
    printf("*             1- Adicinar valor na Fila                 *\n");
    printf("*             2- Remover valor na Fila                  *\n");
    printf("*             3- Buscar um valor na Fila                *\n");
    printf("*             4- Imprimir da Fila                       *\n");
    printf("*             5- Quantidade de valores na Fila          *\n");
    printf("*             6- Creditos                               *\n");
    printf("*             7- Trocar de Programa                     *\n");
    printf("*             8- Sair                                   *\n");
    printf("*                                                       *\n");
    printf("*********************************************************\n");
}

int main (){
    /* inicializando a pilha com uma ponteiro apotando para a pilha */ 
    Pilha* ponteiro = inicializar_pilha();
    Fila* ponteiro_fila = inicializar_fila();
    
    bool i = false, i_fila = false, i_pilha = false;
    char opcao_programa[20], switcher[20];    
    int opcao,opcao_fila,valor;
    
    /* Inicilaizando programa */
    iniciar_programa();
    printf("\n\nDigite Pilha ou Fila: ");
    scanf("%s",opcao_programa);
    
    /* COMEÇANDO O PROGRAMA DA PILHA */
    
    if(strcmp(opcao_programa, "pilha") == 0){
    
    system("cls");
    menu_pilha();
    printf("\n\nDigite uma opcao: ");
    scanf("%d",&opcao);
    printf("\n");
    do{
    switch(opcao){
        case 1: system("cls"); //limpa a tela
                printf("\nDigite um valor inteiro a ser adicionado a pilha: ");
                scanf("%d",&valor);
                pilha_inserir(ponteiro,valor);
                printf("\nValor adicionado com sucesso!\n\n");
                pilha_imprimir(ponteiro);
                menu_pilha();
                printf("\n\nDigite uma opcao: ");
                scanf("%d",&opcao);
                printf("\n");
                break;
        
        case 2: system("cls");
                pilha_remover(ponteiro);
                pilha_imprimir(ponteiro);
                menu_pilha();
                printf("\n\nDigite uma opcao: ");
                scanf("%d",&opcao);
                printf("\n");
                break;
        
        case 3: system("cls");
                printf("\nDigite valor a ser buscado na pilha: ");
                scanf("%d", &valor);
                pilha_buscar(ponteiro, valor);
                menu_pilha();
                printf("\n\nDigite uma opcao: ");
                scanf("%d",&opcao);
                printf("\n");
                break;
        
        case 4: system("cls");
                pilha_imprimir(ponteiro);
                menu_pilha();
                printf("\n\nDigite uma opcao: ");
                scanf("%d",&opcao);
                printf("\n");
                break;
        
        case 5: system("cls");
                printf("\nQuantidade de valores na pilha: %d", TAM);
                menu_pilha();
                printf("\n\nDigite uma opcao: ");
                scanf("%d",&opcao);
                printf("\n");
                break;
        
        case 6: system("cls");
                creditos();
                menu_pilha();
                printf("\n\nDigite uma opcao: ");
                scanf("%d",&opcao);
                printf("\n");
                break;
        
        case 7: system("cls");
                switch_program();
                printf("\n\nDigite sim ou nao: ");
                scanf("%s",switcher);

                if(strcmp(switcher, "sim") == 0){ 
                    // Programa fila
                    system("cls");
                    menu_fila();
                    printf("\n\nDigite uma opcao: ");
                    scanf("%d",&opcao_fila);
                    printf("\n");
                    do{
                    switch(opcao_fila){
                        case 1: system("cls"); //limpa a tela
                                printf("\nDigite um valor inteiro a ser adicionado a fila: ");
                                scanf("%d",&valor);
                                fila_inserir(ponteiro_fila,valor);
                                printf("\nValor adicionado com sucesso!\n\n");
                                fila_imprimir(ponteiro_fila);
                                menu_fila();
                                printf("\n\nDigite uma opcao: ");
                                scanf("%d",&opcao_fila);
                                printf("\n");
                                break;
                        
                        case 2: system("cls");
                                fila_remover(ponteiro_fila);
                                fila_imprimir(ponteiro_fila);
                                menu_fila();
                                printf("\n\nDigite uma opcao: ");
                                scanf("%d",&opcao_fila);
                                printf("\n");
                                break;
                        
                        case 3: system("cls");
                                printf("\nDigite valor a ser buscado na pilha: ");
                                scanf("%d", &valor);
                                fila_buscar(ponteiro_fila, valor);
                                menu_fila();
                                printf("\n\nDigite uma opcao: ");
                                scanf("%d",&opcao_fila);
                                printf("\n");
                                break;
                        
                        case 4: system("cls");
                                fila_imprimir(ponteiro_fila);
                                menu_fila();
                                printf("\n\nDigite uma opcao: ");
                                scanf("%d",&opcao_fila);
                                printf("\n");
                                break;
                        
                        case 5: system("cls");
                                printf("\nQuantidade de valores na fila: %d", TAM_fila);
                                menu_fila();
                                printf("\n\nDigite uma opcao: ");
                                scanf("%d",&opcao_fila);
                                printf("\n");
                                break;
                        
                        case 6: system("cls");
                                creditos();
                                menu_fila();
                                printf("\n\nDigite uma opcao: ");
                                scanf("%d",&opcao_fila);
                                printf("\n");
                                break;
                        
                        case 7: printf("\nVoltando para o programa da pilha dinamica!....\n");
                                i_fila = true;
                                
                        case 8: system("cls");
                                printf("\nFinalizando....\n");
                                i_fila = true;
                                break;

                        default: system("cls");
                                printf("\nValor digitado errado! \nPrograma reiniciando.....");
                                menu_fila();
                                printf("\n\nDigite uma opcao: ");
                                scanf("%d",&opcao_fila);
                                printf("\n");
                    }
                    } while(i_fila == false);
                    system("cls");
                    menu_pilha();
                    printf("\n\nDigite uma opcao: ");
                    scanf("%d",&opcao);
                    printf("\n");
                } else {
                    system("cls");
                    menu_pilha();
                    printf("\n\nDigite uma opcao: ");
                    scanf("%d",&opcao);
                    printf("\n"); 
                }
                break;
                                
        case 8: system("cls");
                printf("\nFinalizando....\n");
                i = true; 
                break;

        default: system("cls");
                printf("\nValor digitado errado! \nPrograma reiniciando.....");
                menu_pilha();
                printf("\n\nDigite uma opcao: ");
                scanf("%d",&opcao);
                printf("\n");
    }
    } while(i == false);
    }
    
 /*##########################################################################################################################*/

    /* COMEÇANDO O PROGRAMA NA FILA */
    
    /* Programa da Fila */

     
    if(strcmp(opcao_programa, "fila") == 0){

    system("cls");
    menu_fila();
    printf("\n\nDigite uma opcao: ");
    scanf("%d",&opcao_fila);
    printf("\n");
    do{
    switch(opcao_fila){
        case 1: system("cls"); //limpa a tela
                printf("\nDigite um valor inteiro a ser adicionado a fila: ");
                scanf("%d",&valor);
                fila_inserir(ponteiro_fila,valor);
                printf("\nValor adicionado com sucesso!\n\n");
                fila_imprimir(ponteiro_fila);
                menu_fila();
                printf("\n\nDigite uma opcao: ");
                scanf("%d",&opcao_fila);
                printf("\n");
                break;
        
        case 2: system("cls");
                fila_remover(ponteiro_fila);
                fila_imprimir(ponteiro_fila);
                menu_fila();
                printf("\n\nDigite uma opcao: ");
                scanf("%d",&opcao_fila);
                printf("\n");
                break;
        
        case 3: system("cls");
                printf("\nDigite valor a ser buscado na pilha: ");
                scanf("%d", &valor);
                fila_buscar(ponteiro_fila, valor);
                menu_fila();
                printf("\n\nDigite uma opcao: ");
                scanf("%d",&opcao_fila);
                printf("\n");
                break;
        
        case 4: system("cls");
                fila_imprimir(ponteiro_fila);
                menu_fila();
                printf("\n\nDigite uma opcao: ");
                scanf("%d",&opcao_fila);
                printf("\n");
                break;
        
        case 5: system("cls");
                printf("\nQuantidade de valores na fila: %d", TAM_fila);
                menu_fila();
                printf("\n\nDigite uma opcao: ");
                scanf("%d",&opcao_fila);
                printf("\n");
                break;
        
        case 6: system("cls");
                creditos();
                menu_fila();
                printf("\n\nDigite uma opcao: ");
                scanf("%d",&opcao_fila);
                printf("\n");
                break;
        
        case 7: system("cls");
                switch_program();
                printf("\n\nDigite sim ou nao: ");
                scanf("%s",switcher);
                if(strcmp(switcher, "sim") == 0){  
                    // Programa pilha 
                    system("cls");
                    menu_pilha();
                    printf("\n\nDigite uma opcao: ");
                    scanf("%d",&opcao);
                    printf("\n");
                    do{
                    switch(opcao){
                        case 1: system("cls"); //limpa a tela
                                printf("\nDigite um valor inteiro a ser adicionado a pilha: ");
                                scanf("%d",&valor);
                                pilha_inserir(ponteiro,valor);
                                printf("\nValor adicionado com sucesso!\n\n");
                                pilha_imprimir(ponteiro);
                                menu_pilha();
                                printf("\n\nDigite uma opcao: ");
                                scanf("%d",&opcao);
                                printf("\n");
                                break;
                        
                        case 2: system("cls");
                                pilha_remover(ponteiro);
                                pilha_imprimir(ponteiro);
                                menu_pilha();
                                printf("\n\nDigite uma opcao: ");
                                scanf("%d",&opcao);
                                printf("\n");
                                break;
                        
                        case 3: system("cls");
                                printf("\nDigite valor a ser buscado na pilha: ");
                                scanf("%d", &valor);
                                pilha_buscar(ponteiro, valor);
                                menu_pilha();
                                printf("\n\nDigite uma opcao: ");
                                scanf("%d",&opcao);
                                printf("\n");
                                break;
                        
                        case 4: system("cls");
                                pilha_imprimir(ponteiro);
                                menu_pilha();
                                printf("\n\nDigite uma opcao: ");
                                scanf("%d",&opcao);
                                printf("\n");
                                break;
                        
                        case 5: system("cls");
                                printf("\nQuantidade de valores na pilha: %d", TAM);
                                menu_pilha();
                                printf("\n\nDigite uma opcao: ");
                                scanf("%d",&opcao);
                                printf("\n");
                                break;
                        
                        case 6: system("cls");
                                creditos();
                                menu_pilha();
                                printf("\n\nDigite uma opcao: ");
                                scanf("%d",&opcao);
                                printf("\n");
                                break;
                        
                        case 7: printf("\nVoltando para o programa da pilha dinamica!....\n");
                                i_pilha = true;


                        case 8: system("cls");
                                printf("\nFinalizando....\n");
                                i_pilha = true;
                                break;

                        default: system("cls");
                                printf("\nValor digitado errado! \nPrograma reiniciando.....");
                                menu_fila();
                                printf("\n\nDigite uma opcao: ");
                                scanf("%d",&opcao);
                                printf("\n");
                    }
                    } while(i_pilha == false);
                    } else {
                    system("cls");
                    menu_fila();
                    printf("\n\nDigite uma opcao: ");
                    scanf("%d",&opcao_fila);
                    printf("\n"); 
                }
                break;
                
        case 8: system("cls");
                printf("\nFinalizando....\n");
                i = true;
                break;

        default: system("cls");
                printf("\nValor digitado errado! \nPrograma reiniciando.....");
                menu_fila();
                printf("\n\nDigite uma opcao: ");
                scanf("%d",&opcao_fila);
                printf("\n");
    }
    } while(i == false);
    }

    
    exit(0);
}