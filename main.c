#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./src/structs/index.h"
#include "./src/funcoes/lidandoComOMapa/definicoes/lidaComOMapa.h"
#include "./src/funcoes/jogo/definicoes/jogo.h"

int main(void){   
    int linhas=10, colunas=20, bombas=40;
    srand ( time(NULL) );
    campo mapaMinado = criarMapaMinado(linhas, colunas, bombas);
    sortearBombas(&mapaMinado);
    defineQuantidadeBombasRedor(&mapaMinado);
    jogo(&mapaMinado);
    destruirMapaMinado(&mapaMinado);
    return 0;
}
