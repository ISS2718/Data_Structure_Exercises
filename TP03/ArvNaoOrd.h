//  Arquivo ArvBinaria.h
//  TAD: ProjArvoreBinaria-V2

#define FALSO      0
#define VERDADEIRO 1

#define OK         1
#define ERRO       0

typedef struct {
    char id[10];
} Tipo_Dado;

//Defini��o do tipo Arvore
struct NO{
    Tipo_Dado info;
    struct NO *uni;
    struct NO *esq;
    struct NO *dir;
};

typedef struct NO NodoABNO;
typedef struct NO *ABNO;

ABNO* cria_ABNO();
void libera_ABNO(ABNO *raiz);
struct NO* procura_abno_nodo (ABNO *raiz, char *id_nodo_pai);
int insere_ABNO (ABNO *raiz, char *id_nodo_pai, char lado, Tipo_Dado dado);
void preOrdem_ABNO (ABNO *raiz);