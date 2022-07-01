#ifndef OBJETOMEMBRO_H_INCLUDED
#define OBJETOMEMBRO_H_INCLUDED

#define MAX_MEMBROS 200
#define MAX_STRING 100
#define NUMUTENTE_MIN 100000000
#define NUMUTENTE_MAX 999999999

#include "funcoesAux.h"

typedef struct{
    int id; // numero utente
    char nome[MAX_STRING];
    int tipomembro;
    int estadoconf;
    int estadovac;
    tipoData data;
    tipoData dataConfinamento;
} membro;

int acrescentaMembro(membro vMembros[MAX_MEMBROS],int quantMembros);
int procuraMembro(membro vetorMembros[MAX_MEMBROS], int quantidademebros, int numero);
int inserircamposmembro(char mensagem[MAX_STRING],int opcoes);
int atualizarvacinados(membro vacinados[MAX_MEMBROS], int totalMembros, int tipoconf);
void casosDeConfinamento(membro vetorMembros[MAX_MEMBROS], int totalMembros);
#endif
