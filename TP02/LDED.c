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

int calcula_custo_total_lista (Lista* li) {
    int cost = 0;
    Elem* no = *li;

    if (li == NULL)
        return ERRO;
    while (no != NULL)
    {
        cost += no->dado.cost;
        no = no->prox;
    }
    return cost;
}

int insere_lista_final(Lista* li, Tipo_Dado dt)
{   
    Elem *no;
    if (li == NULL) return ERRO;
    no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)  return ERRO;
    
    no->prox = NULL;
    no->dado = dt;

	if ((*li) == NULL)
	{   //lista vazia: insere in�cio
        no->ant = NULL;
        *li = no;
    }else
	{   
        no->dado.cost++;
        Elem *aux;
        aux = *li;
        while (aux->prox != NULL){
            no->dado.cost++;
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

int insere_lista_ordenada_X (Lista* li, Tipo_Dado dt)
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
        while (atual != NULL && atual->dado.x < dt.x)
		{
            ante = atual;
            atual = atual->prox;
            no->dado.cost++;
        }
        while (atual != NULL && atual->dado.x == dt.x && atual->dado.y < dt.y)
		{
            ante = atual;
            atual = atual->prox;
            no->dado.cost++;
        }
        while (atual != NULL && atual->dado.x == dt.x && atual->dado.y == dt.y && atual->dado.z < dt.z)
		{
            ante = atual;
            atual = atual->prox;
            no->dado.cost++;
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

int insere_lista_ordenada_Y (Lista* li, Tipo_Dado dt)
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
        while (atual != NULL && atual->dado.y < dt.y)
		{
            ante = atual;
            atual = atual->prox;
            no->dado.cost++;
        }
        while (atual != NULL && atual->dado.y == dt.y && atual->dado.x < dt.x)
		{
            ante = atual;
            atual = atual->prox;
            no->dado.cost++;
        }
        while (atual != NULL && atual->dado.y == dt.y && atual->dado.x == dt.x && atual->dado.z < dt.z)
		{
            ante = atual;
            atual = atual->prox;
            no->dado.cost++;
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

int insere_lista_ordenada_Z (Lista* li, Tipo_Dado dt)
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
        while (atual != NULL && atual->dado.z < dt.z)
		{
            ante = atual;
            atual = atual->prox;
            no->dado.cost++;
        }
        while (atual != NULL && atual->dado.z == dt.z && atual->dado.x < dt.x)
		{
            ante = atual;
            atual = atual->prox;
            no->dado.cost++;
        }
        while (atual != NULL && atual->dado.z == dt.z && atual->dado.x == dt.x && atual->dado.y < dt.y)
		{
            ante = atual;
            atual = atual->prox;
            no->dado.cost++;
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

int procura_z_mais_prox (Lista* li)
{   
    int cost = 1;
    if (li == NULL)
        return ERRO;
    if ((*li) == NULL)
        return ERRO;
    Tipo_Dado dado = (*li)->dado;
    
    if (!verifica_ordenacao_z(li)) {
        Elem *atual = *li;
        while (atual != NULL)
	    {   
            if (atual->dado.z < dado.z) {
                dado = atual->dado;
            }

            atual = atual->prox;
            if(atual != NULL) {
                cost++;
            }
        }
    }

    if (dado.z != (*li)->dado.z)
	{ 
        dado.cost = cost;
    } else {
        dado.cost = 1;
    }
    imprime_dado(&dado); 
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

int seleciona_dado_coordenadas (Lista *li, Lista* li_Coo, mmCoordenadas coo) {
    if (li == NULL)
        return ERRO;
    Elem *atual = *li;

    while (atual != NULL)
	{   
        if ((atual->dado.x >= coo.min_X && atual->dado.x <= coo.max_X) 
            && (atual->dado.y >= coo.min_Y && atual->dado.y <= coo.max_Y) 
            && (atual->dado.y >= coo.min_Y && atual->dado.y <= coo.max_Y)) {
            
            insere_lista_final (li_Coo, atual->dado);
        }
        atual = atual->prox;
    }

    return OK;
}

int seleciona_dado_ID (Lista* li, Lista* li_ID, int ID) {
    if (li == NULL)
        return ERRO;
    Elem *atual = *li;

    while (atual != NULL)
	{   
        if (atual->dado.id == ID) {
            insere_lista_final (li_ID, atual->dado);
        }
        atual = atual->prox;
    }

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

int verifica_ordenacao_z (Lista* li) 
{
    if (*li == NULL)
        return ERRO;

    Elem *primeiro = *li, *atual = primeiro->prox;

    int size_list = tamanho_lista(li),
        cost_t_li = calcula_custo_total_lista (li),
        cost_in_f = 0;

    for (int i = 0; i <= size_list; i++) {
        cost_in_f += i;
    }

    if (cost_t_li > size_list && cost_t_li < cost_in_f)
    {
        while (atual != NULL && atual->dado.z >= primeiro->dado.z)
		{   
            if (atual->dado.z == primeiro->dado.z) {
                while (atual != NULL && atual->dado.z == primeiro->dado.z && atual->dado.x > primeiro->dado.x)
		        {
                    atual = atual->prox;
                }
                while (atual != NULL && atual->dado.z == primeiro->dado.z && atual->dado.x == primeiro->dado.x && atual->dado.y > primeiro->dado.y)
		        {
                    atual = atual->prox;
                }
            } else {
                atual = atual->prox;
            }
        }
        
        if (atual == NULL)
		{  
            return VERDADEIRO;
        }
    }
    return FALSO;    
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

void imprime_dado (Tipo_Dado* dt)
{
    if (dt == NULL)
        return;
    printf("%.5f %.5f %.5f TOTAL:%d\n", dt->x, dt->y, dt->z, dt->cost);
    return;
}

void imprime_lista (Lista* li)
{
    Elem* no = *li;

    if (li == NULL)
        return;
    while (no != NULL)
    {
        printf("%.5f, %.5f, %.5f, %d, %d, %d, %d\n",no->dado.x, no->dado.y, no->dado.z, no->dado.r, no->dado.g, no->dado.b, no->dado.id);
        no = no->prox;
    }
    return;
}

void imprime_TOT (Lista* LI, Lista* LF, Lista* LX) {
    int cost_LI = calcula_custo_total_lista(LI), 
        cost_LF = calcula_custo_total_lista(LF), 
        cost_LX = calcula_custo_total_lista(LX);
    
    printf("LX:%d LI:%d LF:%d", cost_LX, cost_LI, cost_LF);
}
