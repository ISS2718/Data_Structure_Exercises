#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LDED.h"

void selectfunction (char* entry, Lista *LX, Lista *LY, Lista *LZ, Lista *LI, Lista *LF);

int main()
{
    Elem  *el;
    Lista *li_X = cria_lista(), 
          *li_Y = cria_lista(),
          *li_Z = cria_lista(),
          *li_I = cria_lista(),
          *li_F = cria_lista();
    Tipo_Dado *dado = (Tipo_Dado*) malloc(1 * (sizeof(Tipo_Dado)));
    if (dado == NULL ) {
        printf("Faill to alocate memory for 'dado'\n");
        exit(-1);
    } 
    FILE *fp = fopen ("dados3d.txt", "r"); 
    if (fp == NULL ) {
        printf("Failed to open dados3d.txt\n");
        exit(-1);
    }
    char* cmd;

    fscanf (fp, "%f %f %f %d %d %d %d", &dado->x, &dado->y, &dado->z, &dado->r, &dado->g, &dado->b, &dado->id);
    dado->cost = 1;
    while (dado->id != -1) {
        insere_lista_ordenada_X(li_X, *dado);
        insere_lista_ordenada_Y(li_Y, *dado);
        insere_lista_ordenada_Z(li_Z, *dado);
        insere_lista_inicio(li_I, *dado);
        insere_lista_final(li_F, *dado);
        fscanf (fp, "%f %f %f %d %d %d %d", &dado->x, &dado->y, &dado->z, &dado->r, &dado->g, &dado->b, &dado->id);
    }
    free(dado);

    cmd = (char*)malloc(10 * (sizeof(char)));
    if (cmd == NULL ) {
        printf("Faill to alocate memory for 'cmd'\n");
        exit(-1);
    } 
    scanf ("%s", cmd);
    selectfunction (cmd, li_X, li_Y, li_Z, li_I, li_F);
    free(cmd);

    libera_lista(li_X);
    libera_lista(li_Y);
    libera_lista(li_Z);
    libera_lista(li_I);
    libera_lista(li_F);
    return 0;
}

void selectfunction (char* cmd, Lista *LX, Lista *LY, Lista *LZ, Lista *LI, Lista *LF) {
    char *command = strupr(cmd);
    if (!strcmp(command, "LX")) {
        imprime_lista(LX);
        return;
    } else if (!strcmp(command, "LY")) {
        imprime_lista(LY);
        return;
    } else if (!strcmp(command, "LZ")) {
        imprime_lista(LZ);
        return;
    } else if (!strcmp(command, "LI")) {
        imprime_lista(LI);
        return;
    } else if (!strcmp(command, "LZ")) {
        imprime_lista(LZ);
        return;
    } else if (!strcmp(command, "LI")) {
        imprime_lista(LI);
        return;
    } else if (!strcmp(command, "LF")) {
        imprime_lista(LF);
        return;
    } else if (!strcmp(command, "TOT")) {
        imprime_TOT(LI, LF, LX);
        return;
    } else if (!strcmp(command, "PZ")) {
        procura_z_mais_prox(LZ, VERDADEIRO);
        return;
    } else if (!strcmp(command, "PI")) {
        procura_z_mais_prox(LI, FALSO);
        return;
    } else if (!strcmp(command, "ID")) {
        int id;
        scanf("%d", &id);
        printf("ID: %d", id);
        return;
    } else if (!strcmp(command, "CUT")) {
        float min_X, min_Y, min_Z, max_X, max_Y, max_Z; 
        scanf("%f %f %f %f %f %f", &min_X, &min_Y, &min_Z, &max_X, &max_Y, &max_Z);
        printf("%f %f %f %f %f %f", min_X, min_Y, min_Z, max_X, max_Y, max_Z);
        return;
    }  else {
        return;
    }
}