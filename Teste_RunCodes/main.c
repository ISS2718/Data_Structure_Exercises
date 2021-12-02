#include "stdio.h"
#include "stdlib.h"

int main()
{   
   /* 
    float mult = 0.0, var = 0.0;
    int quant = 0;
    scanf("%f%d%f", &mult, &quant, &var);
    float i = 0.0;
    while (i <= quant) {
        printf("%0.1f\n", mult * i);
        i += var;
    }
   */
    FILE *fp;
    float x_eq = 0.0, x = 0.0;
    char *entrada = (char*)malloc(255 * (sizeof(char)));

    fp = fopen("tn.txt", "r");
    if (fp == NULL) {
        printf("ERRO!\n");
        exit(1);
    }
    scanf("%f", &x_eq);
    printf("\n");
    char *status = fgets(entrada, 255, fp);
    while (status) {
        sscanf(entrada, "%f", &x);
        printf("%f\n", x_eq - x);
        status = fgets(entrada, 255, fp);
    }

/*   
    FILE *Arq;
    int valor;
    char linha1[256];
    char linha2[256];

    Arq=fopen("arq.txt","rt");
    if (Arq==NULL) { 
        printf("ERRO!\n");
        exit(1); 
    }
    
    fgets(linha1,255,Arq);
    fgets(linha2,255,Arq);
    
    fclose(Arq);

    scanf("%d",&valor);
    if (valor == 1) {
        printf("%s",linha1);
    }
    else
    if (valor == 2) {
        printf("%s",linha2);
    }
    else
        printf("Entrada Invalida\n");
*/
    return 0;
}
