#include <stdio.h>
#include <stdlib.h>

#include "LDED.h"

int confere_float(float num);
void mescla_tipo(int tipo, Lista* li1, Lista* li2, Lista *Ordenada);

int main() {
    int tipo, qnt_lista, imprime_float;
    scanf ("%d%d", &tipo, &qnt_lista);
    
    Tipo_Dado dado;
    Lista **li = malloc(qnt_lista * (sizeof(Lista)));
    Lista *liOrdenada = cria_lista();
    
    for (int i = 0; i < qnt_lista; i++) {
        li[i] = cria_lista();
        scanf("%f", &dado);
        imprime_float = confere_float(dado);    
        while (dado != 0) { 
            if(tipo == 1) {
                insere_lista_final(li[i], dado);
            } else if (tipo == 2) {
                insere_lista_ordenada_crescente(li[i], dado);
            } else if (tipo == 3) {
                insere_lista_ordenada_decrescente(li[i], dado);
            }
            scanf("%f", &dado);
        } 
    }

    if (qnt_lista == 2) {
        mescla_tipo(tipo, li[0], li[1], liOrdenada);
    } if (qnt_lista == 4) {
        Lista* li_provisoria1 = cria_lista();
        Lista* li_provisoria2 = cria_lista();

        mescla_tipo(tipo, li[0], li[1], li_provisoria1);
        mescla_tipo(tipo, li[2], li[3], li_provisoria2);
        mescla_tipo(tipo, li_provisoria1, li_provisoria2, liOrdenada);
        
        libera_lista(li_provisoria1);
        libera_lista(li_provisoria2);
    }

    for (int i = 0; i < qnt_lista; i++) {
        libera_lista(li[i]);
    }
    free(li);
    
    if(imprime_float) {
        imprime_lista_float(liOrdenada);
    } else {
        imprime_lista_int(liOrdenada);
    }
    
    libera_lista(liOrdenada);
    
    return 0;
}

void mescla_tipo(int tipo, Lista* li1, Lista* li2, Lista *Ordenada) {
    if (tipo == 1 || tipo == 2) {
        mescla_listas_ordenadas_crescente(li1, li2, Ordenada);
    } else if (tipo == 3) {
        mescla_listas_ordenadas_decrescente(li1, li2, Ordenada);
    }
}

int confere_float(float num) {
    int eh_float;
    int int_num = (int)num;
    float num_dps_pont = num - int_num;

    if (num_dps_pont == 0) {
        eh_float = 0;
    } else {
        eh_float = 1;
    }

    return eh_float;
}