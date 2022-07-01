#include <stdio.h>
#include <stdlib.h>

#include "objetoteste.h"
#include "funcoesAux.h"
#include "objetomembro.h"

int agendarTeste(teste vMembrosTeste[MAX_TESTES],membro vetorMembros[MAX_MEMBROS], int numMaxUtente,int totaltestes)
{
    //printf("NUMMAX: %d", vetorMembros[1].id);
    int posicao=0;
    int qTestesDia;
    int numUtente;
    int i;
    int quantidadetestes = totaltestes;
    teste tipoTeste;

    printf("\n Inserir num de utente valido: "); // inserir membro com id de 100000000 a 999999999
    scanf(" %d", &numUtente);
    for(i=0; i<numMaxUtente; i++)
    {
        if(numUtente==vetorMembros[i].id)
        {
            posicao = -1;
        }
    }
    if (posicao=-1){

        lerString("Insere uma designacao unica para este teste: ", vMembrosTeste[i].designacao, MAX_STRING);
        posicao=-2;
    }
    if (posicao == -2)
    {
        tipoTeste.id = quantidadetestes;
        tipoTeste.tipoTeste = inserircamposmembro("Tipo Teste(1- PCR | 2- Antigenio): ", 3); //tipo teste
        //lerDataTeste();//tipoTeste, totaltestes); //funcao de lerData
        do
        {
            tipoTeste.datateste = lerDataTeste();
            qTestesDia=0;
            for(i=0; i<totaltestes; i++)
            {
                if((vMembrosTeste[i].datateste.ano == tipoTeste.datateste.ano) &&
                        (vMembrosTeste[i].datateste.mes == tipoTeste.datateste.mes) &&
                        (vMembrosTeste[i].datateste.dia == tipoTeste.datateste.dia) &&
                        (vMembrosTeste[i].tipoTeste == 1))
                {
                    qTestesDia++;
                }
            }
            if(qTestesDia>14)
            {
                printf("Nesse dia o horario esta completo!\n");
            }

        }
        while(qTestesDia>14);

        tipoTeste.feito = 0; // 0 significa agendado
        vMembrosTeste[quantidadetestes] = tipoTeste;
        quantidadetestes++;
    }
    else
    {
        printf(" -> Esse numero de utente nao esta registado no sistema.\n");
    }
    return quantidadetestes;
}

int atualizarTeste(teste vMembrosTeste[MAX_TESTES], int totaltestesRealizados, int totaltestes)
{
    int i;
    int fazteste=0, testesRealizadosVolta=0;
    char designacao[MAX_STRING];
    tipoData data;
    data = lerDataMarcacao();
    for(i=0; i<totaltestes; i++)
    {
        fazteste=0;
        if(vMembrosTeste[i].feito == 0)
        {
            if(vMembrosTeste[i].datateste.ano < data.ano)
            {
                fazteste=1;
            }
            else if(vMembrosTeste[i].datateste.ano == data.ano)
            {
                if(vMembrosTeste[i].datateste.mes < data.mes)
                {
                    fazteste=1;
                }
                else if(vMembrosTeste[i].datateste.mes == data.mes)
                {
                    if(vMembrosTeste[i].datateste.dia <= data.dia)
                    {
                        fazteste=1;
                    }
                }
            }
        }
        if(fazteste == 1)
        {
            vMembrosTeste[i].resultadoTeste = rand()%3+1;
            vMembrosTeste[i].Horacolheita = rand()%24+1;
            vMembrosTeste[i].duracaoTeste = rand()%60+1;
            vMembrosTeste[i].feito = 1; // 1 significa realizado
            testesRealizadosVolta++;
            totaltestesRealizados++;
        }
    }

    printf("\n > %d com sucesso!", testesRealizadosVolta);
    return totaltestesRealizados;
}

// A FUNCAO DE ATUALIZAR O ESTADO DE CONF / VAC = ALTERAR DATA AGENDADA MAS PARTE DE VALIDAR A EXISTIR QUANTMEMBROS LINHA 123 ; COPYPASTE DO NUMERO DE UTENTE VALIDO LINHA 129  ATE LINHA 139 ; DAI VOU TER QUE FZR UM PRINTF A PEDIR UM NOVO VALOR CORRESPONDE AO ESTADO DE CONF/VAC COM A LEGENDA ; CONF>1 PEDIR DATA ; ATUALIZAR O VETOR DE ENTRADA (MEMBRO) = NOVO VALOR QUE VEIO DO SCANF (PRINTF);
           /*if(infomembro.estadoconf > 1)
            {
                infomembro.dataConfinamento= lerDataConf();
            }*/


void alterarDataAgendada(teste vMembrosTeste[MAX_TESTES],int quantTestes, membro vetorMembros[MAX_MEMBROS],int quantMembros)
{
    int i,numUtente,controlo=0;
    int posicao=0;
    tipoData data;
    tipoData data2;
    int varivel=0;
    char designacao[MAX_STRING];
    if (quantTestes == 0)
    {
        printf("\n\n|| Ainda nao existem testes registados!||\n\n");
    }
    else
    {
        printf("\n Inserir num de utente valido: "); // inserir membro com id de 100000000 a 999999999
        scanf(" %d", &numUtente);
        /*limpaBufferStdin();
        lerString("\nInsere a designacao do teste que desjeja alterar: ", designacao[i], MAX_STRING);*/


        for(i=0; i<quantMembros; i++)
        {
            if(numUtente==vetorMembros[i].id)
            {
                posicao = -1;
                lerString("\nInsere a designacao do teste que deseja alterar: ", designacao, MAX_STRING);
            }
        }
        if(posicao==-1 && designacao==vMembrosTeste[i].designacao)
        {
            data = lerDataTeste();
            for(i=0; i<quantTestes; i++)
            {
                if(vMembrosTeste[i].feito == 0) // devia de ir para dentro do if mais adiante
                {
                    if(vMembrosTeste[i].datateste.ano == data.ano && vMembrosTeste[i].datateste.mes == data.mes && vMembrosTeste[i].datateste.dia == data.dia)
                    {
                        controlo=1;
                    }//
                }
                if(numUtente == vMembrosTeste[i].numUtente)
                {
                    //PARA METER AQUI MAS DA A BRONCADA
                }
            }
            if(controlo==1)
            {
                data2 = lerDataNovaDataMarcacao();
            }

            for(i=0; i<quantTestes; i++)
            {
                if(vMembrosTeste[i].feito == 0) // devia de ir para dentro do if mais adiante
                {
                    vMembrosTeste[i].datateste.dia = data2.dia;
                    vMembrosTeste[i].datateste.mes = data2.mes;
                    vMembrosTeste[i].datateste.ano = data2.ano;
                }
                if(numUtente == vMembrosTeste[i].numUtente)
                {
                    //PARA METER AQUI MAS DA A BRONCADA
                }
            }
        }
    }
}




