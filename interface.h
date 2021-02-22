#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "redesociais.h"
#include "amizades.h"
void MSG_MENU();//Menu Principal
void MSG_SUBMENU(int numero_modulo);
void MSG_SUBMENU2(int numero2_modulo);
void SubMenuModulo1(TRedeSocial *rede, TUsuarios user);
void SubMenuModulo2(TRedeSocial *rede, TUsuarios user);

#endif // INTERFACE_H_INCLUDED
