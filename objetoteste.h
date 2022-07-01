#ifndef OBJETOTESTE_H_INCLUDED
#define OBJETOTESTE_H_INCLUDED

#define MAX_TESTES 200
#define MAX_STRING 100

#include "funcoesAux.h"
#include "objetomembro.h"

typedef struct{
    int id; // id teste
    int tipoTeste;
    int numUtente;
    int resultadoTeste;
    int Horacolheita;
    int duracaoTeste;
    tipoData datateste;
    int quantTestes;
    int feito; //variavel 0 ou 1
    char designacao[MAX_STRING];
} teste;

int agendarTeste(teste vMembrosTeste[MAX_TESTES],membro vetorMembros[MAX_MEMBROS], int numMaxUtente, int totaltestes);
int atualizarTeste(teste vMembrosTeste[MAX_TESTES], int totaltestesRealizados, int totaltestes);
void alterarDataAgendada(teste vMembrosTeste[MAX_TESTES],int quantTestes, membro vetorMembros[MAX_MEMBROS],int quantMembros);
#endif

