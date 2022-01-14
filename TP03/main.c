#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvNaoOrd.h"

#define ARQUIVO "circuit.txt"

typedef struct {
    char id[10];
    int val;
} INPUT;

int circuit_verify (ABNO *circuit);
int circuit_execution (ABNO *circuit, INPUT* input, int q_input);

int main()
{
    ABNO* circuit = cria_ABNO ();
    Tipo_Dado *dado = (Tipo_Dado*) malloc (1 * (sizeof (Tipo_Dado)));
    if (dado == NULL) {
        printf ("Faill to alocate memory for 'dado'\n");
        exit (-1);
    } 
    FILE *fp = fopen (ARQUIVO, "r"); 
    if (fp == NULL) {
        printf ("Failed to open %s\n", ARQUIVO);
        exit (-1);
    }
    char* filho = (char*) malloc (10 * (sizeof (char)));;
    if (filho == NULL) {
        printf ("Faill to alocate memory for 'filho'\n");
        exit (-1);
    }
    char* pai = (char*) malloc (10 * (sizeof (char)));;
    if (pai == NULL) {
        printf ("Faill to alocate memory for 'pai'\n");
        exit (-1);
    }
    char lado = ' '; 
    INPUT *input;
    int q_input = 0;

    fscanf (fp, "%s %c %s", filho, &lado, pai);
    strcpy(dado->id, filho);
    while (strcmp(filho, "$END00")) {
        if (filho[0] == 'I' && filho[1] == 'N' && filho[2] == 'P') {
            q_input++;
        }
        int res = insere_ABNO (circuit, pai, lado, *dado);
        if (!res) {
            printf ("CIRCUIT ERROR\n");
            exit(-1);
        }
        fscanf (fp, "%s %c %s", filho, &lado, pai);
        strcpy(dado->id, filho);
    }
    fclose (fp);
    free (dado);
    free (filho);
    free (pai);
    
    if (!circuit_verify (circuit)) {
        printf ("CIRCUIT ERROR\n");
        exit(-1);
    }
    
    input = malloc (q_input * (sizeof (INPUT)));
    if (input == NULL) {
        printf ("Faill to alocate memory for 'input'\n");  
        exit(-1);
    }

    for (int i = 0; i < q_input; i++) {
        scanf("%s %d", input[i].id, &input[i].val);
    }
    printf("%d\n", circuit_execution (circuit,input, q_input));

    free(input);
    libera_ABNO (circuit);
    return 0;
}

int circuit_execution (ABNO *circuit, INPUT* input, int q_input) {
    if (circuit == NULL) {
        printf("EMPTY CIRCUIT\n");
        exit(-1);
    }
    
    if (!strcmp((*circuit)->info.id, "OUTPUT")) {
        return circuit_execution (&((*circuit)->uni),input, q_input);
    } else if ((*circuit)->info.id[0] == 'N' && (*circuit)->info.id[1] == 'O' && (*circuit)->info.id[2] == 'T') {
        return (!circuit_execution (&((*circuit)->uni),input, q_input));
    } else if ((*circuit)->info.id[0] == 'A' && (*circuit)->info.id[1] == 'N' && (*circuit)->info.id[2] == 'D') {
        int a = circuit_execution (&((*circuit)->esq),input, q_input);
        int b = circuit_execution (&((*circuit)->dir),input, q_input);
        return (a && b);
    } else if ((*circuit)->info.id[0] == 'O' && (*circuit)->info.id[1] == 'R') {
        int a = circuit_execution (&((*circuit)->esq),input, q_input);
        int b = circuit_execution (&((*circuit)->dir),input, q_input);
        return (a || b);
    } else if ((*circuit)->info.id[0] == 'I' && (*circuit)->info.id[1] == 'N' && (*circuit)->info.id[2] == 'P') {
        for (int i = 0; i < q_input; i++) {
            if(!strcmp((*circuit)->info.id, input[i].id)) {
                int a = input[i].val;
                return a; 
            }
        }
    } 
}

int circuit_verify (ABNO *circuit) {
    if (circuit == NULL) {
        return 0;
    }

    if (*circuit == NULL) {
        return 0;
    }
    
    if ((*circuit)->uni != NULL) {
        return circuit_verify (&((*circuit)->uni));
    } else {
        int a, b;
        if (((*circuit)->esq != NULL) || ((*circuit)->dir != NULL)) {
            a = circuit_verify (&((*circuit)->esq));
            b = circuit_verify (&((*circuit)->dir));
            return (a && b);
        } else if ((*circuit)->info.id[0] == 'I' && (*circuit)->info.id[1] == 'N' && (*circuit)->info.id[2] == 'P') {
            return 1;
        } else  {
            return 0;
        }
    }    
}

