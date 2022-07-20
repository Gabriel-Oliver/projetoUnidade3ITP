#include <stdbool.h>
#include <stdlib.h>
#include "../../structs/index.h"

void sortearBombas(campo *mapaMinado){
  int linhaSorteada, colunaSorteada;
  for(int i = 0; i < mapaMinado->bombas; i++){
    
    linhaSorteada = rand() % mapaMinado->linhas;
    colunaSorteada = rand() % mapaMinado->colunas;

    if(!(mapaMinado->dados[linhaSorteada][colunaSorteada].ehBomba)){  
      mapaMinado->dados[linhaSorteada][colunaSorteada].ehBomba = true;
    }else{
        i--;
    }
  }
}