#include "../../structs/index.h"
#include "./definicoes/executaJogada.h"
#include "../checagens/definicoes/checagens.h"
#include <stdlib.h>

float probabilidadeNaoBomba(campo *mapaMinado, int linha, int coluna){
    if(!posicaoValida(mapaMinado, linha, coluna)||!mapaMinado->dados[linha][coluna].foiClicado)
        return ((float )mapaMinado->bombas/(float )(mapaMinado->linhas*mapaMinado->colunas));
    if (mapaMinado->dados[linha][coluna].quantidadeRedor == 0)
        return -64;
    
    return mapaMinado->dados[linha][coluna].quantidadeRedor*((float )mapaMinado->bombas/((float )mapaMinado->linhas*mapaMinado->colunas));   
}

float probabilidadeNaoBombaAoRedor(campo *mapaMinado, int linha, int coluna){
    float chance = 0;
    chance+=probabilidadeNaoBomba(mapaMinado,linha+1,coluna+1);//se clicado, se posicao valida, quantidade bombas redor
    chance+=probabilidadeNaoBomba(mapaMinado,linha+1,coluna);
    chance+=probabilidadeNaoBomba(mapaMinado,linha+1,coluna-1);
    chance+=probabilidadeNaoBomba(mapaMinado,linha,coluna+1);
    chance+=probabilidadeNaoBomba(mapaMinado,linha,coluna-1);
    chance+=probabilidadeNaoBomba(mapaMinado,linha-1,coluna+1);
    chance+=probabilidadeNaoBomba(mapaMinado,linha-1,coluna);
    chance+=probabilidadeNaoBomba(mapaMinado,linha-1,coluna-1);
    return chance;
}

void ajuda(campo *mapaMinado){
    if (!mapaMinado->tempoIniciado)
    {
        int linhaSorteada = rand() % mapaMinado->linhas;
        int colunaSorteada = rand() % mapaMinado->colunas;
        executaJogada(mapaMinado,linhaSorteada,colunaSorteada);
        return;
    }
    int linha = 0, coluna = 0;
    float chanceAtual = 64;
    for (int i = 0; i < mapaMinado->linhas; i++)
    {
        for (int j = 0; j < mapaMinado->colunas; j++)
        {
            if ( !mapaMinado->dados[i][j].foiClicado && chanceAtual > probabilidadeNaoBombaAoRedor(mapaMinado,i,j))
            {       
                chanceAtual = probabilidadeNaoBombaAoRedor(mapaMinado,i,j);
                linha = i;
                coluna = j;
            }
        }  
    }
    executaJogada(mapaMinado,linha,coluna);
}