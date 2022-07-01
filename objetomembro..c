#include <stdio.h>
#include <stdlib.h>

#include "objetomembro.h"
#include "funcoesAux.h"
#include "objetoteste.h"

int acrescentaMembro(membro vetorMembro[MAX_MEMBROS],
                     int quantidademembros){
    int posicao;
    membro infomembro;

    if( quantidademembros == MAX_MEMBROS )  // vetor cheio
    {
        printf("Nao cabem mais membros no sistema!!!");
    }
    else
    {
        printf("\n Inserir membro:\n"); // inserir membro com id de 100000000 a 999999999

        infomembro.id = lerInteiro(" Numero de utente",NUMUTENTE_MIN,NUMUTENTE_MAX);
        posicao = procuraMembro(vetorMembro,
                                quantidademembros,
                                infomembro.id);
        if (posicao == -1)
        {
            lerString("\n Nome do membro: ", infomembro.nome, MAX_STRING); //nome

            infomembro.tipomembro = inserircamposmembro("\n Tipo membro(1- Estudante | 2- Docente | 3- Tecnico): ", 4); //tipo membro
            infomembro.estadoconf = inserircamposmembro("\n Estado confinamento(1- Nao confinado | 2- Quarentena | 3- Isolamento Profilatico): ", 4); //estado confinamento
            if(infomembro.estadoconf > 1)
            {
                infomembro.dataConfinamento= lerDataConf();
            }
            infomembro.estadovac = inserircamposmembro("\n Estado vacina(1-Sem vacina | 2- 1 dose | 3- 2 dose | 4- 3 dose): ", 5); //estado vacina
            infomembro.data = lerData(); //funcao de lerData

            vetorMembro[quantidademembros] = infomembro;
            quantidademembros++;
            if(infomembro.tipomembro==1)
            {
                printf("\n -> Estudante acrescentado com sucesso ");
            }
            else if(infomembro.tipomembro==2)
            {
                printf("\n -> Docente acrescentado com sucesso ");
            }
            else
            {
                printf("\n -> Tecnico acrescentado com sucesso ");
            }
        }
        else
        {
            printf("\n -> Esse numero de utente ja existe.\n");
        }
    }
    return quantidademembros;
}


int procuraMembro(membro vetorMembros[MAX_MEMBROS],
                  int quantidademembros, int numero){

    int posicao=-1;
    for(int i=0; i<quantidademembros; i++)
    {
        if (vetorMembros[i].id == numero)
        {
            posicao = i;
            i = quantidademembros;
        }
    }
    return posicao;
}

int inserircamposmembro(char mensagem[MAX_STRING],int opcoes)
{
    int tipomembro;
    do
    {
        printf("%s", mensagem);
        scanf("%d", &tipomembro);
        if(!(tipomembro>0 && tipomembro<opcoes)) // e utilizado opcoes para que seja definido dinamicamente o numero maximo de opcoes
        {
            tipomembro=0;
            printf("Opçao invalida\n");
        }
    }
    while(tipomembro==0);
    return tipomembro;
}



int atualizarvacinados(membro vacinados[MAX_MEMBROS], int totalMembros, int tipoconf){
    int totalvacinados=0;
    int i;
    for (i=0; i<totalMembros; i++)
    {
        if(tipoconf==1)
        {
            if(vacinados[i].estadoconf!=1)
            {
                totalvacinados++;
            }
        }
        else
        {
            if(vacinados[i].estadovac!=1)
            {
                totalvacinados++;
            }
        }
    }
    return totalvacinados;

}

void casosDeConfinamento(membro vetorMembros[MAX_MEMBROS], int totalMembros)
{
    int i;
    printf("\n\n-------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t |INFORMACAO DE CONFINAMENTO|\t\t\t");
        printf("\n---------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\n\n\t\t/Tipo de Confinamento/\t   /Data/\t/Tempo de duracao(dias)/   /Nome/\n");
        printf("\n---------------------------------------------------------------------------------------------------------------------------------\n");
    for (i=0; i<totalMembros; i++)
        {

            if(vetorMembros[i].estadoconf>1)
            {
                printf(" \t\t  \t %d\t \t(%d/%d/%d)\t\t %d\t\t   %s\t",vetorMembros[i].estadoconf,vetorMembros[i].dataConfinamento.dia,vetorMembros[i].dataConfinamento.mes,vetorMembros[i].dataConfinamento.ano,rand()%7+1,vetorMembros[i].nome);
            }

            printf("\n\n------------------------------------------------------------------------------------------------------------------------------------\n");
        }

}
