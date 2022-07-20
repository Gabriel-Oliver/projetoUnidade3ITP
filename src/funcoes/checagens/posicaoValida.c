#include "../../structs/index.h"
#include <stdbool.h>

bool posicaoValida(campo *mapaMinado, int linha, int coluna)
{
  if(linha < mapaMinado->linhas && linha >= 0 && coluna < mapaMinado->colunas && coluna >= 0){
    return true;
  }
  return false;
}