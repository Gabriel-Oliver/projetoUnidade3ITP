#include <stdio.h>
#include "../../structs/index.h"
#include "../checagens/definicoes/checagens.h"
#include "./definicoes/executaJogada.h"

void fazerJogada(campo *mapaMinado){
    int linha, coluna;
    printf("Digite a posição no formato: linha coluna.\n");
    do{
        scanf("%d %d", &linha, &coluna);
        if(!posicaoValida(mapaMinado,linha,coluna))
            printf("Digite uma posição valida!!!\n");
    }while(!posicaoValida(mapaMinado,linha,coluna));
    executaJogada(mapaMinado,linha,coluna);
}