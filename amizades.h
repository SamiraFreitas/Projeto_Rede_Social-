#ifndef AMIZADES_H_INCLUDED
#define AMIZADES_H_INCLUDED

#include "redesociais.h"

void cadastrar_amizade(TRedeSocial *rede, int i, int j);

void exibir_amizades(TRedeSocial *rede,int id);

int pesquisar_amizade(TRedeSocial *rede, int i, int j);

void excluir_amizade(TRedeSocial *rede, int i, int j);

#endif // AMIZADES_H_INCLUDED
