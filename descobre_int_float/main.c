#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int potencia(int x, int y);
float char_to_float(char *str_float);
int confere_float(float *num);

int main()
{
    float num = 0.0;
    int eh_float = confere_float(&num);
    if(eh_float) {
        printf("eh float!\n");
        printf("%f", num);
    } else {
        printf("nao eh float!\n");
        printf("%.0f", num);
    }
    return 0;
}

int potencia(int x, int y) {
    int result = 1;
    for (int i = 0; i < y; i++) {
        result *= x;
    }
    return result;
}

float char_to_float(char *str_float) {
    float complete_num = 0.0;
    int ant_pont_num = 0;
    float dps_pont_num = 0.0;
    char* int_num = strtok(str_float, ".");
    char* pont_num = strtok(NULL, ".");
    
    ant_pont_num = (float)atoi(int_num);

    int i = 0;
    while (pont_num[i] != '\0') {
        i++;
    }
    
    int div_dez = potencia(10, i);

    dps_pont_num = (float)atoi(pont_num);
    dps_pont_num /= div_dez;

    complete_num = ant_pont_num + dps_pont_num;
    
    return complete_num;
}

int confere_float(float *num) {
    char entry[125];  
    int eh_float = 0;
    int i = 0;
    for (i; i < 10; i++) {
        scanf("%c", &entry[i]);
        if (entry[i] == '.') {
            eh_float = 1;
        } else if(entry[i] == ' ') {
            entry[i] = '\0';
            break;
        }
    }
    if(eh_float) {
        *num = char_to_float(entry);
    } else {
        *num = (float)atoi(entry);
    }
    
    return eh_float;
}