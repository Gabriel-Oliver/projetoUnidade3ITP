#ifndef mapa_h
#include "../../../structs/index.h"
#include <stdbool.h>

campo criarMapaMinado(int l, int c, int bombas);
void sortearBombas(campo *mapaMinado);
void destruirMapaMinado(campo *m);
void defineQuantidadeBombasRedor(campo *mapaMinado);
#endif