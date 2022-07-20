#ifndef structs_h
#define structs_h  
#include <time.h>
#include <stdbool.h>

typedef struct posicao_t
{
    int posX;
    int posY;
    int quantidadeRedor;
    bool ehBomba;
    bool foiClicado;
} posicao;

typedef struct campo_t
{
    int linhas;
    int colunas;
    int bombas;
    bool vitoria;
    bool derrota;
    time_t tempoInicial;
    bool tempoIniciado;
    posicao **dados;
} campo;

#endif