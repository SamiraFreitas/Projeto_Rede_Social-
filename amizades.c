#include <stdlib.h>
#include<stdio.h>
#include "redesociais.h"
#include "amizades.h"

void cadastrar_amizade(TRedeSocial *rede, int i, int j)
{
    if ((i != j))
    {
        rede->matriz[j][i] = 1;
        rede->matriz[i][j] = 1;
        printf("\n Amizade concluida com sucesso!\n");
    }
    else
    {
        printf("\nNao é possivel ser amigo de você mesmo ! rsrsr\n");
    }
}
void exibir_amizades(TRedeSocial *rede, int id)
{
    for (int i = 0; i < rede->index; i++)
    {
        if (rede->matriz[id][i])
        {
            if(i!=id)
            ExibirDadosUsuario(rede->vet[i]);

        }
    }
}
int pesquisar_amizade(TRedeSocial *rede, int i, int j)
{
    if (rede->matriz[j][i] == 1 &&  rede->matriz[i][j] == 1 )
    {
        printf("\nEsses 2 usuarios sao amigos!\n");
        return 1;


    }
    else
    {
        printf("\nEsses 2 usuarios nao sao amigos!\n");
        return 0;
    }
}

 void excluir_amizade(TRedeSocial *rede, int i, int j)
 {
     if ((i != j))
    {
        rede->matriz[j][i] = 0;
        rede->matriz[i][j] = 0;
        printf("\n Amizade excluida com sucesso!\n");
    }
    else
    {
        printf("\nNao é possivel desfazer amizade com voce mesmo ! rsrsr\n");
    }
 }
