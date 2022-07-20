#include "../../structs/index.h"
#include <stdbool.h>
#include <stdlib.h>

posicao geraPosicao(int posX, int posY, int quantidadeRedor, bool ehBomba, bool foiClicado)
{
    posicao pos;

    pos.posX = posX;
    pos.posY = posY;
    pos.quantidadeRedor = quantidadeRedor;
    pos.ehBomba = ehBomba;
    pos.foiClicado = foiClicado;

    return pos;
}

campo criarMapaMinado(int l, int c, int bombas)
{
    campo m;
    m.linhas = l;
    m.colunas = c;
    m.derrota = false;
    m.vitoria = false;
    m.tempoIniciado = false;
    m.bombas = bombas;
    m.dados = malloc(sizeof(posicao *) * l);
    for (int i = 0; i < l; i++)
        m.dados[i] = malloc(sizeof(posicao) * c);

    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++)
            m.dados[i][j] = geraPosicao(i, j, 0, false, false);
    return m;
}