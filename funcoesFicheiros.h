#ifndef FUNCOESFICHEIROS_H_INCLUDED
#define FUNCOESFICHEIROS_H_INCLUDED

#include "objetomembro.h"
#include "objetoteste.h"
void gravaFicheiroBinario(membro vetorMembros[MAX_MEMBROS],int numMembros);
int leFicheiroBinario(membro vetorMembros[MAX_MEMBROS]);
void gravaFicheiroBinarioTeste(teste vMembrosTeste[MAX_TESTES],int numTestes);
int leFicheiroBinarioTeste(teste vMembrosTeste[MAX_TESTES]);
void gravaFicheiroTextoTeste(teste vMembrosTeste[MAX_TESTES],int numTestes);

#endif

