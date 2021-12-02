#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LDED.h"

int main()
{   
    Lista* li = cria_lista();
    Lista* result = cria_lista();
    struct pesquisa dado;
    FILE *fp;
    char *entrada = (char*)malloc(255 * (sizeof(char)));

    printf(">>> Autocompletar Palavras <<<\n");

    printf("\n>> Lendo arquivos de dados: ");
    scanf("%s", entrada);
    fp = fopen(entrada, "r");
    if (fp == NULL) {
        printf("ERRO!\n");
        exit(1);
    }

    char *status = fgets(entrada, 255, fp);
    while (status) {
        sscanf(entrada, "%s %s %d", &dado.pref, &dado.pala, &dado.cont);
        insere_lista_ordenada(li, dado);
        status = fgets(entrada, 255, fp);
    }
    fclose(fp);
    free(entrada);

    printf("%d dados lidos\n", tamanho_lista(li));
    imprime_lista(li);

    printf("\n>> Autocompletar:\n");
    entrada = (char*)malloc(5 * (sizeof(char)));
    printf("Informe o prefixo (2, 3 ou 4 caracteres): ");
    scanf("%s", entrada);

    int st_cons = consulta_lista_pref(li, entrada, result);
    if (st_cons != 0) {
         imprime_resultado(result);
    } else {
        printf("nao achou o prefixo!\n");
    }
    free(entrada);
    libera_lista(li);
    libera_lista(result);
    
    system("pause");
    return 0;
}

