#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvNaoOrd.h" //inclui os Prot�tipos

ABNO* cria_ABNO(){
    ABNO* raiz = (ABNO*) malloc(sizeof(ABNO));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->uni);
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ABNO(ABNO* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada n�
    free(raiz);//libera a raiz
}

struct NO* procura_abno_nodo (ABNO *raiz, char *id_nodo_pai) {
    if(raiz == NULL)
        return NULL;
        
    struct NO* atual = *raiz;
    if(!strcmp(atual->info.id, id_nodo_pai)){
        return atual;
    } else {
        if(atual->uni != NULL) {
            atual = procura_abno_nodo (&atual->uni, id_nodo_pai);
            if (atual != NULL) {
                return atual;
            }
        } else {
            if(atual->dir != NULL) {
                atual = procura_abno_nodo (&atual->dir, id_nodo_pai);
                if (atual != NULL) {
                    return atual;
                }
            }
            if(atual->esq != NULL) {
                atual = procura_abno_nodo (&atual->esq, id_nodo_pai);
                if (atual != NULL) {
                    return atual;
                }
            }
        }
    }
    return NULL;
}

int insere_ABNO (ABNO *raiz, char *id_nodo_pai, char lado, Tipo_Dado dado) {
    if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    strcpy(novo->info.id, dado.id);
    novo->uni = NULL;
    novo->dir = NULL;
    novo->esq = NULL;

    if (*raiz == NULL) {
        if (!strcmp(id_nodo_pai, ".ROOT.")){
            *raiz = novo;
        } else {
            return 0;//Não existe o .ROOT.
        }
    } else {
        struct NO* atual = procura_abno_nodo (raiz, id_nodo_pai);
        if (atual != NULL) {
            if (lado == 'U') {
                if (atual->uni == NULL) {
                    atual->uni = novo;
                    return 1;
                } else {
                    return 0;
                }
            } else if (lado == 'R') {
                if (atual->dir == NULL) {
                    atual->dir = novo;
                    return 1;
                } else {
                    return 0;
                }
            } else if (lado == 'L') {
                if (atual->esq == NULL) {
                    atual->esq = novo;
                    return 1;
                } else {
                    return 0;
                }
            }
        } else {
            return 0;
        }
    }
    return 1;
}

void preOrdem_ABNO (ABNO *raiz) {
    if(raiz == NULL)
        return;
    if(*raiz != NULL) {
        if ((*raiz)->uni != NULL) {
            printf("%s\n",(*raiz)->info.id);
            preOrdem_ABNO(&((*raiz)->uni));
        } else {
            printf("%s\n",(*raiz)->info.id);
            preOrdem_ABNO(&((*raiz)->esq));
            preOrdem_ABNO(&((*raiz)->dir)); 
        }
    }
}
