#include "../../structs/index.h"
#include "../jogo/definicoes/jogo.h"
#include "../checagens/definicoes/checagens.h"
#include <stdbool.h>

void cascataDeZeros(campo *mapaMinado, int linha, int coluna){
    if(!posicaoValida(mapaMinado, linha, coluna))
        return;
    if (mapaMinado->dados[linha][coluna].foiClicado||
    mapaMinado->dados[linha][coluna].quantidadeRedor!=0)
        return;

    mapaMinado->dados[linha][coluna].foiClicado = true;
    cascataDeZeros(mapaMinado, linha-1, coluna);
    cascataDeZeros(mapaMinado, linha+1, coluna);
    cascataDeZeros(mapaMinado, linha, coluna+1);
    cascataDeZeros(mapaMinado, linha, coluna-1);
}

void executaJogada(campo *mapaMinado, int linha, int coluna){
 if( !mapaMinado->tempoIniciado){
        mapaMinado->tempoIniciado =  true;
        mapaMinado->tempoInicial =  time(NULL);
    }


    if (mapaMinado->dados[linha][coluna].quantidadeRedor == 0&&!mapaMinado->dados[linha][coluna].ehBomba){
        cascataDeZeros(mapaMinado, linha, coluna);
    }else{
        mapaMinado->dados[linha][coluna].foiClicado = true;
    }

    if(mapaMinado->dados[linha][coluna].ehBomba)
        mapaMinado->derrota = true;
}