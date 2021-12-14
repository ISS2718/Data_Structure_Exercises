/* ------------------------------------------------------------
Prova P02 (final) de Estrutura de Dados I (ED1) - SSC0603
Isaac Santos Soares n°USP: 12751713
Feito: 14/12/2021 
------------------------------------------------------------ */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArvoreAVL.h"

#define arquivo "cepdata.txt"

void selectfunction (ArvAVL *raiz, int cmd) ;

int main()
{
    ArvAVL* cep_avl = cria_ArvAVL();
    Tipo_Dado *dado = (Tipo_Dado*) malloc (1 * (sizeof (Tipo_Dado)));
    if (dado == NULL) {
        printf ("Faill to alocate memory for 'dado'\n");
        exit (-1);
    } 
    FILE *fp = fopen (arquivo, "r"); 
    if (fp == NULL) {
        printf ("Failed to open dados3d.txt\n");
        exit (-1);
    }
    char* cidade = (char*) malloc (30 * (sizeof (char)));
    if (cidade== NULL) {
        printf ("Failed to open dados3d.txt\n");
        exit (-1);
    }
    char* estado = (char*) malloc (5 * (sizeof (char)));;
    if (estado == NULL) {
        printf ("Failed to open dados3d.txt\n");
        exit (-1);
    }
    int cmd;

    fscanf (fp, "%d %d %s %s", &dado->ini_cep, &dado->fin_cep, cidade, estado);
    strcpy(dado->cidade, cidade);
    strcpy(dado->estado, estado);
    while (dado->ini_cep != 0 && dado->fin_cep != 0 && strcmp(dado->cidade, "0") != 0 && strcmp(dado->estado, "0") != 0) {
        int res = insere_ArvAVL (cep_avl, *dado);
        if (!res) {
            printf("ERROR\n");
            exit(-1);
        }
        fscanf (fp, "%d %d %s %s", &dado->ini_cep, &dado->fin_cep, cidade, estado);
        strcpy(dado->cidade, cidade);
        strcpy(dado->estado, estado);
    }
    free(cidade);
    free(estado);
    free (dado);

    scanf ("%d", &cmd);
    selectfunction (cep_avl, cmd);

    libera_ArvAVL(cep_avl);
    return 0;
}

void selectfunction (ArvAVL *raiz, int cmd) {
    switch (cmd)
    {
    case 1:
        printf ("%d\n", totalNO_ArvAVL(raiz));
        break;
    case 2:
        printf ("%d\n", altura_ArvAVL(raiz));
        break;
    case 3:
        scanf("%d", &cmd);
        int res = consulta_cep(raiz, cmd);
        if (!res) {
            printf("FAIL");
        }
        break;
    case 4:
        preOrdem_ArvAVL(raiz);
        break;
    case 5:
        emOrdem_ArvAVL(raiz);
        break;
    }
    return;
}