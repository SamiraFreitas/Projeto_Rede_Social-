#include <stdio.h>
#include <stdlib.h>
#include "redesociais.h"
#include "interface.h"
void MSG_MENU()
{
    printf("\n\n\t>>>>>>>>>>>>> BEM VINDO AO MENU: <<<<<<<<<<<<<\n\n");
    printf("\n\n\t1. MODULO 1 - GERENCIAMENTO DE USUARIOS\n\n");
    printf("\n\n\t2. MODULO 2- GERENCIAMENTO DE AMIZADES \n\n");
    printf("\n\n\t3. 3 - SAIR \n\n");
}
void MSG_SUBMENU(int numero_modulo)
{
    system("@cls||clear");
    printf("\n\n\t>>>>>>>>>>>>> MODULO %d <<<<<<<<<<<<<\n\n", numero_modulo);
    printf("\n\n\t1. CADASTRAR");
    printf("\n\t2. PESQUISAR");
    printf("\n\t3. ALTERAR");
    printf("\n\t4. EXCLUIR");
    printf("\n\t5. IMPRIMIR");
    printf("\n\t6. SAIR");
}
void MSG_SUBMENU2(int numero2_modulo)
{
    system("@cls||clear");
    printf("\n\n\t>>>>>>>>>>>>> MODULO %d <<<<<<<<<<<<<\n\n", numero2_modulo);
    printf("\n\n\t1.CADASTRAR AMIZADE");
    printf("\n\t2. PESQUISAR AMIZADE");
    printf("\n\t3. EXCLUIR AMIZADE");
    printf("\n\t4. IMPRIMIR AMIZADE");
    printf("\n\t5. SAIR");
}
void SubMenuModulo1(TRedeSocial *rede, TUsuarios user)
{
    int opcao =0;
    do
    {
        system("@cls||clear");
        MSG_SUBMENU(1);
        printf("\nDigite uma opcao, por favor\n");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
            // Chamada de Função para menu cadastrar
            printf("\n\n\t>>>>>>>>>>>>> CADASTRAR: <<<<<<<<<<<<<\n\n");
            LerDados(&user);
            Cadastrar(rede, user);
            system("PAUSE");
            break;
        case 2:
            // Chamada de Função para menu pesquisar
            printf("\n\n\t>>>>>>>>>>>>> PESQUISAR: <<<<<<<<<<<<<\n\n");
            printf("Digite o nome do usuario, por favor\n");
            fflush(stdin);
            scanf("%s", user.nome);
            int idUser = Pesquisar(rede, user);
            if(idUser <= -1)
            {
                printf("\n\n Usuario nao encontrado\n\n");
            }
            system("PAUSE");
            break;
        case 3:
            // Chamada de Função para menu alterar
            printf("\n\n\t>>>>>>>>>>>>> ALTERAR: <<<<<<<<<<<<<\n\n");
            printf("Digite o nome do usuario, por favor\n");
            fflush(stdin);
            scanf("%s", user.nome);
            idUser = Pesquisar(rede, user);
            if(idUser <= -1)
            {
                printf("\n\n Usuario nao encontrado\n\n");
                system("PAUSE");
                break;
            }
            LerDados(&user);
            Alterar(rede, user, idUser);
            system("PAUSE");
            break;
        case 4:
            // Chamada de Função para menu excluir
            printf("\n\n\t>>>>>>>>>>>>> EXCLUIR: <<<<<<<<<<<<<\n\n");
            printf("Digite o nome do usuario, por favor\n");
            fflush(stdin);
            scanf("%s", user.nome);
            idUser = Pesquisar(rede, user);
            if(idUser <= -1)
            {
                printf("\n\n Usuario nao encontrado\n\n");
                system("PAUSE");
                break;
            }
            Excluir (rede, idUser);
            system("PAUSE");
            break;

        case 5:
            // Chamada de Função para menu imprimir
            printf("\n\n\t>>>>>>>>>>>>> IMPRIMIR: <<<<<<<<<<<<<\n\n");
            Imprimir(rede);
            system("PAUSE");
            break;
        case 6:
            // Chamada de Função para menu sair
            system("@cls||clear");
            printf(">>>>>>>>>>> MSG: SAINDO DO MENU <<<<<<<<<<<\n");
            system("PAUSE");
            fflush(stdin);
            getchar();
            break;
        default:
            system("\nDIGITE UMA OPCAO VALIDA\n");
           fflush(stdin);
            getchar();
        }
    }
    while(opcao != 6);
}
void SubMenuModulo2(TRedeSocial *rede, TUsuarios user)
{
    int opcao =0;
    do
    {
        system("@cls||clear");
        MSG_SUBMENU2(2);
        printf("\nDigite uma opcao, por favor\n");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
            // Chamada de Função para menu cadastrar
            printf("\n\n\t>>>>>>>>>>>>> CADASTRAR AMIZADE: <<<<<<<<<<<<<\n\n");
            printf("Digite o nome do 1 usuario, por favor\n");
            fflush(stdin);
            scanf("%s", user.nome);
            int idUser1 = Pesquisar(rede, user);
            if(idUser1 <= -1)
            {
                printf("\n\n Usuario nao encontrado\n\n");
                system("PAUSE");
                break;
            }
            printf("Digite o nome do 2 usuario, por favor\n");
            fflush(stdin);
            scanf("%s", user.nome);
            int idUser2 = Pesquisar(rede, user);
            if(idUser2 <= -1)
            {
                printf("\n\n Usuario nao encontrado\n\n");
                system("PAUSE");
                break;
            }
            cadastrar_amizade(rede, idUser1, idUser2);
            system("PAUSE");
            break;
        case 2:
            // Chamada de Função para menu pesquisar
            printf("\n\n\t>>>>>>>>>>>>> PESQUISAR AMIZADE: <<<<<<<<<<<<<\n\n");
            printf("Digite o nome do 1 usuario, por favor\n");
            fflush(stdin);
            scanf("%s", user.nome);
            idUser1 = Pesquisar(rede, user);
            if(idUser1 <= -1)
            {
                printf("\n\n Usuario nao encontrado\n\n");
                system("PAUSE");
                break;
            }
            printf("Digite o nome do 2 usuario, por favor\n");
            fflush(stdin);
            scanf("%s", user.nome);
            idUser2 = Pesquisar(rede, user);
            if(idUser2 <= -1)
            {
                printf("\n\n Usuario nao encontrado\n\n");
                system("PAUSE");
                break;
            }
            int flag =  pesquisar_amizade(rede, idUser1, idUser2);
            system("PAUSE");

            break;
        case 3:
            // Chamada de Função para menu excluir
            printf("\n\n\t>>>>>>>>>>>>> EXCLUIR AMIZADE: <<<<<<<<<<<<<\n\n");
            printf("Digite o nome do 1 usuario, por favor\n");
            fflush(stdin);
            scanf("%s", user.nome);
            idUser1 = Pesquisar(rede, user);
            if(idUser1 <= -1)
            {
                printf("\n\n Usuario nao encontrado\n\n");
                system("PAUSE");
                break;
            }
            printf("Digite o nome do 2 usuario, por favor\n");
            fflush(stdin);
            scanf("%s", user.nome);
            idUser2 = Pesquisar(rede, user);
            if(idUser2 <= -1)
            {
                printf("\n\n Usuario nao encontrado\n\n");
                system("PAUSE");
                break;
            }
            excluir_amizade(&rede, idUser1, idUser2);
        case 4:
            // Chamada de Função para menu imprimir
            printf("\n\n\t>>>>>>>>>>>>> IMPRIMIR AMIZADE: <<<<<<<<<<<<<\n\n");
            printf("Digite o nome do usuario, por favor\n");
            fflush(stdin);
            scanf("%s", user.nome);
            int idUser = Pesquisar(rede, user);
            if(idUser <= -1)
            {
                printf("\n\n Usuario nao encontrado\n\n");
                system("PAUSE");
                break;
            }
            exibir_amizades(rede, idUser);
            system("PAUSE");
            break;
        case 5:
            // Chamada de Função para menu sair
            system("@cls||clear");
            printf(">>>>>>>>>>> MSG: SAINDO DO MENU <<<<<<<<<<<\n");
            system("PAUSE");
            fflush(stdin);
            getchar();
            break;
        default:
            system("\nDIGITE UMA OPCAO VALIDA\n");
            fflush(stdin);
            getchar();
        }
    }
    while(opcao != 5);
}
