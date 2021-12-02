#include <stdio.h>
#include <stdlib.h>

#include "LDED.h" //inclui os Prot�tipos

Lista* cria_lista()
{
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li)
{
    if (li != NULL)
	{
        Elem* no;
        while ((*li) != NULL)
		{
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int consulta_lista_pos(Lista* li, int pos, Tipo_Dado *dt)
{
    if (li == NULL || pos <= 0)
        return ERRO;
    Elem *no = *li;
    int i = 1;
    while (no != NULL && i < pos)
	{
        no = no->prox;
        i++;
    }
    if (no == NULL)
        return ERRO;
    else
	{
        *dt = no->dado;
        return OK;
    }
}

int consulta_lista_dado(Lista* li, Tipo_Dado dt, Elem **el)
{
    if (li == NULL)
        return 0;
    Elem *no = *li;
    while (no != NULL && no->dado != dt){
        no = no->prox;
    }
    if (no == NULL)
        return ERRO;
    else
	{
        *el = no;
        return OK;
    }
}

int insere_lista_final(Lista* li, Tipo_Dado dt)
{
    Elem *no;

    if (li == NULL) return ERRO;
    no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)  return ERRO;

    no->dado = dt;
    no->prox = NULL;

	if ((*li) == NULL)
	{   //lista vazia: insere in�cio
        no->ant = NULL;
        *li = no;
    }else
	{
        Elem *aux;
        aux = *li;
        while (aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
        no->ant = aux;
    }
    return OK;
}

int insere_lista_inicio(Lista* li, Tipo_Dado dt)
{
    if (li == NULL)
        return ERRO;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)
        return ERRO;

    no->dado = dt;
    no->prox = (*li);
    no->ant = NULL;

	if (*li != NULL) //lista n�o vazia: apontar para o anterior!
        (*li)->ant = no;
    *li = no;
    return OK;
}

int insere_lista_ordenada_crescente(Lista* li, Tipo_Dado dt)
{
    if (li == NULL)
        return ERRO;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)
        return ERRO;
    no->dado = dt;
    if ((*li) == NULL)
	{  //lista vazia: insere in�cio
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return OK;
    }
    else{
        Elem *ante, *atual = *li;
        while (atual != NULL && atual->dado < dt)
		{
            ante = atual;
            atual = atual->prox;
        }
        if (atual == *li)
		{   //insere in�cio
            no->ant = NULL;
            (*li)->ant = no;
            no->prox = (*li);
            *li = no;
        } else
		{
            no->prox = ante->prox;
            no->ant = ante;
            ante->prox = no;
            if (atual != NULL)
                atual->ant = no;
        }
        return OK;
    }
}

int insere_lista_ordenada_decrescente(Lista* li, Tipo_Dado dt) {
    if (li == NULL)
        return ERRO;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)
        return ERRO;
    no->dado = dt;
    if ((*li) == NULL)
	{  //lista vazia: insere in�cio
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return OK;
    }
    else{
        Elem *ante, *atual = *li;
        while (atual != NULL && atual->dado > dt)
		{
            ante = atual;
            atual = atual->prox;
        }
        if (atual == *li)
		{   //insere in�cio
            no->ant = NULL;
            (*li)->ant = no;
            no->prox = (*li);
            *li = no;
        } else
		{
            no->prox = ante->prox;
            no->ant = ante;
            ante->prox = no;
            if (atual != NULL)
                atual->ant = no;
        }
        return OK;
    }
}

int remove_lista(Lista* li, Tipo_Dado dt)
{   //TERMINAR
    if (li == NULL)
        return ERRO;
    if ((*li) == NULL)//lista vazia
        return ERRO;
    Elem *no = *li;
    while (no != NULL && no->dado != dt){
        no = no->prox;
    }
    if (no == NULL)//n�o encontrado
        return ERRO;

    if (no->ant == NULL)//remover o primeiro?
        *li = no->prox;
    else
        no->ant->prox = no->prox;

    if (no->prox != NULL)//n�o � o �ltimo?
        no->prox->ant = no->ant;

    free(no);
    return OK;
}


int remove_lista_inicio(Lista* li)
{
    if (li == NULL)
        return ERRO;
    if ((*li) == NULL)//lista vazia
        return ERRO;

    Elem *no = *li;
    *li = no->prox;
    if (no->prox != NULL)
        no->prox->ant = NULL;

    free(no);
    return OK;
}

int remove_lista_final(Lista* li)
{
    if (li == NULL)
        return ERRO;
    if ((*li) == NULL) //lista vazia
        return ERRO;

    Elem *no = *li;
    while (no->prox != NULL)
        no = no->prox;

    if (no->ant == NULL) //remover o primeiro e �nico
        *li = no->prox;
    else
        no->ant->prox = NULL;

    free(no);
    return OK;
}

int tamanho_lista(Lista* li)
{
    if (li == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
    while (no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia(Lista* li)
{
    return FALSO;
}

int lista_vazia(Lista* li)
{
    if (li == NULL)
        return OK;
    if (*li == NULL)
        return OK;
    return FALSO;
}

void imprime_lista(Lista* li) 
{
    Elem* no = *li;

    if (li == NULL)
        return;
    while (no != NULL)
    {
        printf("%f ",no->dado);
        no = no->prox;
    }
}

void imprime_lista_int(Lista* li) {
    Elem* no = *li;

    if (li == NULL)
        return;
    while (no != NULL)
    {
        printf("%.0f ",no->dado);
        no = no->prox;
    }
}

void imprime_lista_float(Lista* li) {
    Elem* no = *li;
    
    if (li == NULL)
        return;
    while (no != NULL)
    {
        printf("%.1f ",no->dado);
        no = no->prox;
    }
}

void mescla_listas_ordenadas_crescente(Lista* li1, Lista* li2, Lista* Ordenada) {
    Tipo_Dado li1_num, li2_num;
    int li1_pos = 1, li2_pos = 1;
    int li1_status, li2_status;
    
    li1_status = consulta_lista_pos(li1, li1_pos, &li1_num);
    li2_status = consulta_lista_pos(li2, li2_pos, &li2_num);
    
    while (li1_status == OK && li2_status == OK) {
        
        if (li1_num <= li2_num) {
            insere_lista_final(Ordenada, li1_num);
            li1_pos++;
            li1_status = consulta_lista_pos(li1, li1_pos, &li1_num);
        } else if (li1_num >= li2_num){
            insere_lista_final(Ordenada, li2_num);
            li2_pos++;
            li2_status = consulta_lista_pos(li2, li2_pos, &li2_num);
        }
        
    }

    while (li1_status != ERRO) {
        insere_lista_final(Ordenada, li1_num);
        li1_pos++;
        li1_status = consulta_lista_pos(li1, li1_pos, &li1_num);
    }

    while (li2_status != ERRO) {
        insere_lista_final(Ordenada, li2_num);
        li2_pos++;
        li2_status = consulta_lista_pos(li2, li2_pos, &li2_num);
    }
}

void mescla_listas_ordenadas_decrescente(Lista* li1, Lista* li2, Lista *Ordenada) {
    Tipo_Dado li1_num, li2_num;
    int li1_pos = 1, li2_pos = 1;
    int li1_status, li2_status;
    
    li1_status = consulta_lista_pos(li1, li1_pos, &li1_num);
    li2_status = consulta_lista_pos(li2, li2_pos, &li2_num);
    
    while (li1_status == OK && li2_status == OK) {
        
        if (li1_num >= li2_num) {
            insere_lista_final(Ordenada, li1_num);
            li1_pos++;
            li1_status = consulta_lista_pos(li1, li1_pos, &li1_num);
        } else if (li1_num <= li2_num){
            insere_lista_final(Ordenada, li2_num);
            li2_pos++;
            li2_status = consulta_lista_pos(li2, li2_pos, &li2_num);
        }
        
    }

    while (li1_status != ERRO) {
        insere_lista_final(Ordenada, li1_num);
        li1_pos++;
        li1_status = consulta_lista_pos(li1, li1_pos, &li1_num);
    }

    while (li2_status != ERRO) {
        insere_lista_final(Ordenada, li2_num);
        li2_pos++;
        li2_status = consulta_lista_pos(li2, li2_pos, &li2_num);
    }
}
