#include <stdio.h>
#include <stdlib.h>
#include "redesociais.h"
#include "interface.h"

int main()

{

    TRedeSocial rede;
    Iniciar(&rede);
    TUsuarios user;

    //Menu
    int opcao= 0;
    do
    {

        system("@cls||clear");
        MSG_MENU();
        printf("Digite uma opcao, por favor\n");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
            // Chamada de Função para submenu para o módulo I
            SubMenuModulo1(&rede, user);
            break;
        case 2:
            // Chamada de Função para submenu para o módulo II
            SubMenuModulo2(&rede, user);
        case 3:
            system("@cls||clear");
            printf("Digite uma opcao valida, por favor, ou pressione uma tecla\n");
            system("PAUSE");
            fflush(stdin);
            getchar();
        }
    } while(opcao != 3);

    system("PAUSE");
    fflush(stdin);
    getchar();
    return 0;
}
