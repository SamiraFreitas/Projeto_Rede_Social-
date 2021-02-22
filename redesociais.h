#ifndef REDESOCIAIS_H_INCLUDED
#define REDESOCIAIS_H_INCLUDED
#include <stdlib.h>
#include<stdio.h>
#include <string.h>

typedef struct Data
{
    int dia;
    int mes;
    int ano;
}TData;

typedef struct Usuario
{
    char nome[100];
    char email[100];
    char login[50];
    char senha[50];
    TData data_de_nascimento;
    int id;
}TUsuarios;

typedef struct Rede_Social
{
    TUsuarios vet[100];
    int matriz[100][100];
    int index;

}TRedeSocial;

void Iniciar(TRedeSocial *rede);
void LerDados(TUsuarios *User);
void ExibirDadosUsuario(TUsuarios User);
void le_texto(char str[], char msg[]);
void le_int_positivo(int *valor, char msg[]);
void Cadastrar(TRedeSocial *rede, TUsuarios user);
void Imprimir(TRedeSocial *rede);
int  Pesquisar(TRedeSocial *rede, TUsuarios user);
void Alterar(TRedeSocial *rede, TUsuarios user, int i);
void Excluir (TRedeSocial *rede, int i);


#endif // REDESOCIAIS_H_INCLUDED
