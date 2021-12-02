#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LDED.h"

#define arquivo "dados3d.txt"

void selectfunction (char* entry, Lista *LX, Lista *LY, Lista *LZ, Lista *LI, Lista *LF);

int main()
{
    Elem  *el;
    Lista *li_X = cria_lista (), 
          *li_Y = cria_lista (),
          *li_Z = cria_lista (),
          *li_I = cria_lista (),
          *li_F = cria_lista ();
    Tipo_Dado *dado = (Tipo_Dado*) malloc (1 * (sizeof (Tipo_Dado)));
    if (dado == NULL ) {
        printf ("Faill to alocate memory for 'dado'\n");
        exit (-1);
    } 
    FILE *fp = fopen (arquivo, "r"); 
    if (fp == NULL ) {
        printf ("Failed to open dados3d.txt\n");
        exit (-1);
    }
    char* cmd;

    fscanf (fp, "%f %f %f %d %d %d %d", &dado->x, &dado->y, &dado->z, &dado->r, &dado->g, &dado->b, &dado->id);
    dado->cost = 1;
    while (dado->id != -1) {
        insere_lista_ordenada_X (li_X, *dado);
        insere_lista_ordenada_Y (li_Y, *dado);
        insere_lista_ordenada_Z (li_Z, *dado);
        insere_lista_inicio (li_I, *dado);
        insere_lista_final (li_F, *dado);
        fscanf (fp, "%f %f %f %d %d %d %d", &dado->x, &dado->y, &dado->z, &dado->r, &dado->g, &dado->b, &dado->id);
    }
    free (dado);

    cmd = (char*) malloc (10 * (sizeof (char)));
    if (cmd == NULL ) {
        printf ("Faill to alocate memory for 'cmd'\n");
        exit (-1);
    } 
    scanf ("%s", cmd);
    selectfunction (cmd, li_X, li_Y, li_Z, li_I, li_F);
    free (cmd);

    libera_lista (li_X);
    libera_lista (li_Y);
    libera_lista (li_Z);
    libera_lista (li_I);
    libera_lista (li_F);
    return 0;
}

void selectfunction (char* cmd, Lista *LX, Lista *LY, Lista *LZ, Lista *LI, Lista *LF) {
    if (!strcmp(cmd, "LX")) {
        imprime_lista (LX);
        return;
    } else if (!strcmp(cmd, "LY")) {
        imprime_lista (LY);
        return;
    } else if (!strcmp(cmd, "LZ")) {
        imprime_lista (LZ);
        return;
    } else if (!strcmp(cmd, "LI")) {
        imprime_lista (LI);
        return;
    } else if (!strcmp(cmd, "LZ")) {
        imprime_lista (LZ);
        return;
    } else if (!strcmp (cmd, "LI")) {
        imprime_lista (LI);
        return;
    } else if (!strcmp(cmd, "LF")) {
        imprime_lista (LF);
        return;
    } else if (!strcmp (cmd, "TOT")) {
        imprime_TOT (LI, LF, LX);
        return;
    } else if (!strcmp (cmd, "PZ")) {
        procura_z_mais_prox (LZ);
        return;
    } else if (!strcmp (cmd, "PI")) {
        procura_z_mais_prox (LI);
        return;
    } else if (!strcmp (cmd, "ID")) {
        int id;
        scanf ("%d", &id);
        Lista *li_ID = cria_lista ();
        seleciona_dado_ID (LX, li_ID, id);
        imprime_lista (li_ID);
        libera_lista(li_ID);
        return;
    } else if (!strcmp (cmd, "CUT")) {
        mmCoordenadas coo; 
        scanf ("%f %f %f %f %f %f", &coo.min_X, &coo.min_Y, &coo.min_Z, &coo.max_X, &coo.max_Y, &coo.max_Z);
        Lista *li_Coo = cria_lista ();
        seleciona_dado_coordenadas (LX, li_Coo, coo);
        imprime_lista (li_Coo);
        libera_lista(li_Coo);
        return;
    } else {
        return;
    }
}