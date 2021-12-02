#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LDED.h" //inclui os Prot�tipos

struct elemento{
    struct elemento *ant;
    struct pesquisa dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int consulta_lista_pos(Lista* li, int pos, struct pesquisa *dt){
    if(li == NULL || pos <= 0)
        return 0;
    Elem *no = *li;
    int i = 1;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }
    if(no == NULL)
        return 0;
    else{
        *dt = no->dados;
        return 1;
    }
}

int consulta_lista_pref(Lista* li, char *pref, Lista *result){
    int i = 0;
    if(li == NULL)
        return 0;
    Elem *no = *li;
    while(no != NULL && strcmp(no->dados.pref, pref) != 0) {
        no = no->prox;
    }
    if(no == NULL)
        return 0;
    else{
        while (no != NULL && strcmp(no->dados.pref, pref) == 0 && i < 3) {
            insere_lista_final(result, no->dados);
            i++;
            no = no->prox;
        }
        return 1;
    }
}

int insere_lista_final(Lista* li, struct pesquisa al){
    if(li == NULL)
        return 0;
    Elem *no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;

    strcpy(no->dados.pref, al.pref);
    strcpy(no->dados.pala, al.pala);
    no->dados.cont = al.cont;
    
    no->prox = NULL;
    if((*li) == NULL){//lista vazia: insere in�cio
        no->ant = NULL;
        *li = no;
    }else{
        Elem *aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
        no->ant = aux;
    }
    return 1;
}

int insere_lista_inicio(Lista* li, struct pesquisa al){
    if(li == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;

    strcpy(no->dados.pref, al.pref);
    strcpy(no->dados.pala, al.pala);
    no->dados.cont = al.cont;

    no->prox = (*li);
    no->ant = NULL;
    if(*li != NULL)//lista n�o vazia: apontar para o anterior!
        (*li)->ant = no;
    *li = no;
    return 1;
}

int insere_lista_ordenada(Lista* li, struct pesquisa dt){
    if(li == NULL) {
        return 0;
    }
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) {
        return 0;
    }

    strcpy(no->dados.pref, dt.pref);
    strcpy(no->dados.pala, dt.pala);
    no->dados.cont = dt.cont;

    if((*li) == NULL){//lista vazia: insere in�cio
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return 1;
    }
    else{
        Elem *ante, *atual = *li;
        while(atual != NULL && (strcmp(atual->dados.pref, dt.pref) != 1)) {
            if (strcmp(atual->dados.pref, dt.pref) == 0) {
                while (atual != NULL && (strcmp(atual->dados.pref, dt.pref) == 0 && atual->dados.cont > dt.cont)) {
                    ante = atual;
                    atual = atual->prox;
                }
                break;
            }
            ante = atual;
            atual = atual->prox;
        }
        if(atual == *li){//insere in�cio
            no->ant = NULL;
            (*li)->ant = no;
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = ante->prox;
            no->ant = ante;
            ante->prox = no;
            if(atual != NULL)
                atual->ant = no;
        }
        return 1;
    }
}

int remove_lista(Lista* li, char *palavra) {//TERMINAR
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;
    Elem *no = *li;
    while(no != NULL && strcmp(no->dados.pala, palavra) != 0){
        no = no->prox;
    }
    if(no == NULL)//n�o encontrado
        return 0;

    if(no->ant == NULL)//remover o primeiro?
        *li = no->prox;
    else
        no->ant->prox = no->prox;

    if(no->prox != NULL)//n�o � o �ltimo?
        no->prox->ant = no->ant;

    free(no);
    return 1;
}


int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elem *no = *li;
    *li = no->prox;
    if(no->prox != NULL)
        no->prox->ant = NULL;

    free(no);
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elem *no = *li;
    while(no->prox != NULL)
        no = no->prox;

    if(no->ant == NULL)//remover o primeiro e �nico
        *li = no->prox;
    else
        no->ant->prox = NULL;

    free(no);
    return 1;
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia(Lista* li){
    return 0;
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    Elem* no = *li;
    while(no != NULL){
        printf("%s %s %d\n", no->dados.pref, no->dados.pala, no->dados.cont);
        no = no->prox;
    }
}

void imprime_resultado(Lista* li) {
    if(li == NULL)
        return;
    Elem* no = *li;
    while(no != NULL){
        printf("%s %d\n",no->dados.pala, no->dados.cont);
        no = no->prox;
    }
}