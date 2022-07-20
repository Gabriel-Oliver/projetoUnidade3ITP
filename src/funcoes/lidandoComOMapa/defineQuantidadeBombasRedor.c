#include "../../structs/index.h"
#include "../checagens/definicoes/checagens.h"

bool ehBomba(campo *mapaMinado, int linha, int coluna){
  if(!posicaoValida(mapaMinado, linha, coluna)){
    return false;
  }
  return mapaMinado->dados[linha][coluna].ehBomba;
}

void defineQuantidadeBombasRedor(campo *mapaMinado){
    int contBombas = 0;
    
    for(int i = 0; i < mapaMinado->linhas; i++){
        for(int j = 0; j < mapaMinado->colunas; j++){
          contBombas = 0;
          contBombas += ehBomba(mapaMinado,i-1,j);//Checa posicao acima
          contBombas += ehBomba(mapaMinado,i-1,j+1);//Checa posicao a acima a direita
          contBombas += ehBomba(mapaMinado,i,j+1);//Checa posicao a direita
          contBombas += ehBomba(mapaMinado,i+1,j+1);//Checa posicao a abaixo a direita
          contBombas += ehBomba(mapaMinado,i+1,j);//Checa posicao a baixo
          contBombas += ehBomba(mapaMinado,i+1,j-1);//Checa posicao a abaixo a esquerda
          contBombas += ehBomba(mapaMinado,i,j-1);//Checa posicao a esquerda
          contBombas += ehBomba(mapaMinado,i-1,j-1);//Checa posicao a acima a esquerda
          mapaMinado->dados[i][j].quantidadeRedor = contBombas;
        }
    }
}