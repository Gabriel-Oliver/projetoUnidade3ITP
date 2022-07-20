#include "../../structs/index.h"
#include <stdlib.h>

void destruirMapaMinado(campo *m){
	for(int i=0; i<m->linhas; i++)
		free(m->dados[i]);
	free(m->dados);
}