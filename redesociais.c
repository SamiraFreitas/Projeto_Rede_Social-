#include <stdlib.h>
#include<stdio.h>
#include "redesociais.h"
#include "interface.h"
#define MAX_TEXT_SIZE 100
void le_texto(char str[], char msg[])
{
    printf("%s", msg);
    fflush(stdin);
    fgets(str, MAX_TEXT_SIZE, stdin);
    str[strlen(str)-1]='\0';
}

void le_int_positivo(int *valor, char msg[])
{
    do
    {
        printf("%s", msg);
        fflush(stdin);
        scanf("%d", valor);
        if(*valor<0)
        {
            printf("O valor deve ser positivo!");
        }
    }
    while(*valor<0);
}

void LerDados(TUsuarios *User)
{
    printf("\n\n\t>>>>>>>>>>>>> Leitura de dados dos usuarios: <<<<<<<<<<<<<\n\n");
    le_texto(User->nome,"Digite o seu nome, por favor\n");
    le_texto(User->email,"\nDigite o seu email, por favor\n");
    le_texto(User->login, "\nDigite o seu login, por favor\n");
    le_texto(User->senha, "\nDigite a sua senha por favor\n");
    le_int_positivo(&User->data_de_nascimento.dia, "\nDia de nascimento:\n");
    le_int_positivo(&User->data_de_nascimento.mes, "\nMes do nascimento:\n");
    le_int_positivo(&User->data_de_nascimento.ano, "\nAno do nascimento:\n");
    getchar();
}

void ExibirDadosUsuario(TUsuarios User)
{
    printf("\n\n\t>>>>>>>>>>>>> USUARIO: <<<<<<<<<<<<<\n\n \tNome: %s \n\tEmail: %s \n\tLogin: %s \n\tSenha: %s \n\tData: %d/%d/%d\n \n\tID: %d \n\n", User.nome, User.email, User.login, User.senha, User.data_de_nascimento.dia, User.data_de_nascimento.mes, User.data_de_nascimento.ano, User.id);
}

void Iniciar(TRedeSocial *rede)
{
    rede->index = 0;
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            rede->matriz[i][j] = 0;
        }
    }
}

void Cadastrar(TRedeSocial *rede, TUsuarios user)
{
    user.id = rede->index;

    if (rede->index < 100)
    {
        rede->vet[rede->index] = user;
        rede->index++;
        printf("\nO usuario %s foi cadastrado com sucesso!!\n\n", rede->vet[rede->index].nome);
    }
    else
    {
        printf("\nVetor de usuários cheio!\n");
    }
}

void Imprimir(TRedeSocial *rede)
{
    for (int i = 0; i < rede->index; i++)
    {
        if ( rede->vet[i].id != -1)
        {
            ExibirDadosUsuario(rede->vet[i]);
            printf("_____________________________________________________\n");
        }
    }
}

int Pesquisar(TRedeSocial *rede, TUsuarios user)
{
    for(int i = 0; i < rede->index; i++)
    {
        if(!(strcmp(rede->vet[i].nome, user.nome)))
        {
            if ( rede->vet[i].id != -1)
            {
                ExibirDadosUsuario(rede->vet[i]);
            }
            return (rede->vet[i].id);
        }
    }

    return -1;
}

void Alterar(TRedeSocial *rede, TUsuarios user, int i)
{
    rede->vet[i] = user;
    printf("\nO usuario %s foi alterado com sucesso!!\n\n", rede->vet[i].nome);
}

void Excluir (TRedeSocial *rede, int i)
{
    rede->vet[i].id = -1;
    for(int column = 0; column < rede->index; column++)
    {
        if (rede->matriz[i][column] == 1)
            rede->matriz[i][column] = 0;
    }

    for(int line = 0; line < rede->index; line++)
    {
        if(rede->matriz[line][i] == 1)
            rede->matriz[line][i] = 0;
    }
    printf("\nO usuario %s foi excluido com sucesso!!\n\n", rede->vet[i].nome);
}

