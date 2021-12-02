//Arquivo LDED.h - Lista Dinamica Encadeada Dupla

#define FALSO      0
#define VERDADEIRO 1

#define OK         1
#define ERRO       0

struct pesquisa{
    char pref[5];
    char pala[30];
    int cont;
};

typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int consulta_lista_pos(Lista* li, int pos, struct pesquisa *dt);
int consulta_lista_pref(Lista* li, char *pref, Lista *result);
int insere_lista_final(Lista* li, struct pesquisa dt);
int insere_lista_inicio(Lista* li, struct pesquisa dt);
int insere_lista_ordenada(Lista* li, struct pesquisa dt);
int remove_lista(Lista* li, char *palavra);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
void imprime_lista(Lista* li);
void imprime_resultado(Lista* li);