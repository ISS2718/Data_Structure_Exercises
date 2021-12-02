//Arquivo LDED.h - Lista Dinamica Encadeada Dupla

#define FALSO      0
#define VERDADEIRO 1

#define OK         1
#define ERRO       0

struct point_clouds3D {
    float x, y, z;
    unsigned int r, g, b;
    int id, cost;
};

struct min_max_coord {
    float min_X, min_Y, 
          min_Z, max_X, 
          max_Y, max_Z;
};

typedef struct point_clouds3D Tipo_Dado;

typedef struct min_max_coord mmCoordenadas;
//Definição do tipo lista
struct elemento{
    struct elemento *ant;
    Tipo_Dado dado;
    struct elemento *prox;
};

typedef struct elemento Elem;

typedef struct elemento* Lista;

Lista* cria_lista();
int consulta_lista_pos(Lista* li, int pos, Tipo_Dado *dt);
int calcula_custo_total_lista (Lista* li);
void imprime_dado (Tipo_Dado* dt);
void imprime_lista (Lista* li);
void imprime_TOT (Lista* LI, Lista* LF, Lista* LX);
int insere_lista_final(Lista* li, Tipo_Dado dt);
int insere_lista_inicio(Lista* li, Tipo_Dado dt);
int insere_lista_ordenada_X (Lista* li, Tipo_Dado dt);
int insere_lista_ordenada_Y (Lista* li, Tipo_Dado dt);
int insere_lista_ordenada_Z (Lista* li, Tipo_Dado dt);
void libera_lista(Lista* li);
int lista_vazia(Lista* li);
int procura_z_mais_prox (Lista* li);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int seleciona_dado_coordenadas (Lista *li, Lista* li_Coo, mmCoordenadas coo);
int seleciona_dado_ID (Lista* li, Lista* li_ID, int ID);
int tamanho_lista(Lista* li);
int verifica_ordenacao_z (Lista* li);


