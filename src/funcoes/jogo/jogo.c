#include <stdio.h>
#include <stdlib.h>
#include "../../structs/index.h"
#include "../acoesJogador/definicoes/ajuda.h"
#include "../acoesJogador/definicoes/fazerJogada.h"

void imprimeMapaMinado(campo *mapaMinado)
{
    for (int j = 0; j < mapaMinado->colunas; j++){
        if(j==0){
            printf("  ");
        }
        printf("%d ", j);
    }
    printf("\n");

    for (int i = 0; i < mapaMinado->linhas; i++)
    {
        for (int j = 0; j < mapaMinado->colunas; j++){
            if(j==0)
                printf("%d ", i);
            if(mapaMinado->dados[i][j].foiClicado && mapaMinado->dados[i][j].ehBomba){
                printf("B ");
            } else if(mapaMinado->dados[i][j].foiClicado){
                printf("%d ", mapaMinado->dados[i][j].quantidadeRedor);
            }else{
                printf("- ");
            }
        }
        printf("\n");
    }
}


void checaVitoria(campo *mapaMinado){
    int cont = 0;
    for (int i = 0; i < mapaMinado->linhas; i++)
    {
        for (int j = 0; j < mapaMinado->colunas; j++)
        {
            if(mapaMinado->dados[i][j].foiClicado && !mapaMinado->dados[i][j].ehBomba){
               cont++; 
            }
        }
        
    }

    if(cont ==((mapaMinado->linhas * mapaMinado->colunas)- mapaMinado->bombas))
        mapaMinado->vitoria = true;    
}

void imprimeInformacoesDeJogo(campo *mapaMinado){
    printf("Digite 1 para fazer uma jogada;\n");
    printf("Digite 2 para ver o tempo decorrido de partida;\n");
    printf("Digite 3 para solicitar ajuda do jogo;\n");
    printf("Quantidade de bombas no jogo: %d.\n", mapaMinado->bombas);
}


void imprimeTempoDecorrido(campo *mapaMinado){
    time_t tempoAgora = time(NULL);
    time_t tempoTotal = tempoAgora - mapaMinado->tempoInicial;
    printf("Tempo decorrido: %ld\n",tempoTotal);
}

void lidaComAcaoDoJogador(campo *mapaMinado,int acao){
    switch (acao)
        {
            case 1:
                fazerJogada(mapaMinado);
            break;

            case 2:
                imprimeTempoDecorrido(mapaMinado);
            break;

            case 3:
                ajuda(mapaMinado);
            break;
        }
}

void jogo(campo *mapaMinado){
    int acao;
    printf("Bem vindo ao Campo Minado;\n");
    
    do{
        imprimeInformacoesDeJogo(mapaMinado);
        scanf("%d",&acao);
        lidaComAcaoDoJogador(mapaMinado, acao);
        if(acao!=2){
            printf("---------------------------------------------\n");
            imprimeMapaMinado(mapaMinado);
            printf("---------------------------------------------\n");
        }
        checaVitoria(mapaMinado);
    } while (!mapaMinado->vitoria&&!mapaMinado->derrota);

    imprimeTempoDecorrido(mapaMinado);
    if(mapaMinado->vitoria){
        printf("-------------------VITÓRIA-------------------\n");
        return;
    }
    printf("-------------------DERROTA-------------------\n");
}