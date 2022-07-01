#ifndef OBJETOMEMBRO_H_INCLUDED
#define OBJETOMEMBRO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcoesAux.h"

int lerInteiro(char mensagem[MAX_STRING], int minimo, int maximo)
{
    int numero, controlo;
    do
    {
        printf("%s (%d a %d) :", mensagem, minimo, maximo);
        controlo = scanf ("%d", &numero);  // scanf devolve quantidade de valores vàlidos obtidos
        limpaBufferStdin();     //limpa todos os caracteres do buffer stdin (nomeadamente o \n)

        if (controlo == 0)
        {
            printf("Devera inserir um numero inteiro \n");
        }
        else
        {

            if(numero<minimo || numero>maximo)
            {
                printf("Numero invalido. Insira novamente:\n");
            }

        }
    }
    while(numero<minimo || numero>maximo || controlo ==0);

    return numero;
}

float lerFloat(char mensagem[MAX_STRING], float minimo, float maximo)
{
    float numero;
    int controlo;
    do
    {
        printf("%s (%.2f a %.2f) :", mensagem, minimo, maximo);
        controlo = scanf ("%f", &numero);  // scanf devolve quantidade de valores vàlidos obtidos
        limpaBufferStdin();

        if (controlo == 0)
        {
            printf("Devera inserir um numero decimal (float) \n");
        }
        else
        {

            if(numero<minimo || numero>maximo)
            {
                printf("Numero invalido. Insira novamente:\n");
            }

        }
    }
    while(numero<minimo || numero>maximo || controlo ==0);

    return numero;
}

void lerString(char mensagem[MAX_STRING],char vetorCaracteres[MAX_STRING],int maximoCaracteres)
{
    int tamanhoString;

    do  		// Repete leitura caso sejam obtidas strings vazias
    {
        //   puts(mensagem);
        printf("%s", mensagem);
        fgets(vetorCaracteres, maximoCaracteres, stdin);

        /*tamanhoString = strlen(vetorCaracteres);

        if (tamanhoString == 1)
        {
            printf("Nao foram introduzidos caracteres!!! . apenas carregou no ENTER \n\n");  // apenas faz sentido limpar buffer se a ficarem caracteres
        }
        */
    }
    while (tamanhoString == 1);

    if(vetorCaracteres[tamanhoString-1] != '\n')   // ficaram caracteres no buffer....
    {
        limpaBufferStdin();  // apenas faz sentido limpar buffer se a ficarem caracteres
    }
    else
    {
        vetorCaracteres[tamanhoString-1] ='\0';          //substitui \n da string armazenada em vetor por \0 (evitar problemas com listagens)
    }
}

void limpaBufferStdin()
{
    char chr;
    do
    {
        chr = getchar();
    }
    while (chr != '\n' && chr != EOF);
}

tipoData lerData()
{
    tipoData data;
    int maxDiasMes;

    printf("\n |DATA DE NASCIMENTO|\n");
    data.ano = lerInteiro(" .Ano", 1920, 2022);
    data.mes = lerInteiro(" .Mes", 1, 12);

    switch (data.mes)
    {
    case 2:
        if ((data.ano % 400 == 0) || (data.ano % 4 == 0 && data.ano % 100 != 0))
        {
            maxDiasMes = 29;
        }
        else
        {
            maxDiasMes = 28;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        maxDiasMes = 30;
        break;
    default:
        maxDiasMes = 31;
    }

    data.dia = lerInteiro(" .Dia:", 1, maxDiasMes);
    return data;
}

tipoData lerDataTeste() //teste vTeste[MAX_TESTES], int totaltestes) // ler data da funcao agendar teste
{

    tipoData data;
    int i;
    int maxDiasMes;
    /*do
    {*/
    //int qTestesDia=0; // quantidade de testes marcados por dia

    printf("\n |DATA DE AGENDAMENTO|\n");
    data.ano = lerInteiro(" .Ano", 2022, 2023);
    data.mes = lerInteiro(" .Mes", 1, 12);

    switch (data.mes)
    {
    case 2:
        if ((data.ano % 400 == 0) || (data.ano % 4 == 0 && data.ano % 100 != 0))
        {
            maxDiasMes = 29;
        }
        else
        {
            maxDiasMes = 28;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        maxDiasMes = 30;
        break;
    default:
        maxDiasMes = 31;
    }

    data.dia = lerInteiro(" .Dia:", 1, maxDiasMes);
    /*for(i=0; i<totaltestes; i++)
    {
        if(vTeste[i].data == data && vTeste[i].tipoTeste == 1)
        {
            qTestesDia++
        }
    }
    if(qTestesDia<16)
    {
        printf("Nesse dia o horario esta completo!");
    }
    }
    while(qTestesDia>15); */
    return data;
}

tipoData lerDataMarcacao()  //funcao ler data de atualizar testes
{
    tipoData data;
    int maxDiasMes;

    printf("\n |DATA ATUAL|\n");
    data.ano = lerInteiro(" .Ano", 2022, 2030);
    data.mes = lerInteiro(" .Mes", 1, 12);

    switch (data.mes)
    {
    case 2:
        if ((data.ano % 400 == 0) || (data.ano % 4 == 0 && data.ano % 100 != 0))
        {
            maxDiasMes = 29;
        }
        else
        {
            maxDiasMes = 28;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        maxDiasMes = 30;
        break;
    default:
        maxDiasMes = 31;
    }

    data.dia = lerInteiro(" .Dia:", 1, maxDiasMes);
    return data;
}

tipoData lerDataConf()
{
    tipoData data;
    int maxDiasMes;

    printf("\n |DATA DE INICIO DE CONFINAMENTO|\n");
    data.ano = lerInteiro(" .Ano", 2022, 2022);
    data.mes = lerInteiro(" .Mes", 1, 12);

    switch (data.mes)
    {
    case 2:
        if ((data.ano % 400 == 0) || (data.ano % 4 == 0 && data.ano % 100 != 0))
        {
            maxDiasMes = 29;
        }
        else
        {
            maxDiasMes = 28;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        maxDiasMes = 30;
        break;
    default:
        maxDiasMes = 31;
    }

    data.dia = lerInteiro(" .Dia:", 1, maxDiasMes);
    return data;
}

tipoData lerDataNovaDataMarcacao()  //funcao ler data de atualizar testes
{
    tipoData data;
    int maxDiasMes;

    printf("\n |NOVA DATA|\n");
    data.ano = lerInteiro(" .Ano", 2022, 2030);
    data.mes = lerInteiro(" .Mes", 1, 12);

    switch (data.mes)
    {
    case 2:
        if ((data.ano % 400 == 0) || (data.ano % 4 == 0 && data.ano % 100 != 0))
        {
            maxDiasMes = 29;
        }
        else
        {
            maxDiasMes = 28;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        maxDiasMes = 30;
        break;
    default:
        maxDiasMes = 31;
    }

    data.dia = lerInteiro(" .Dia:", 1, maxDiasMes);
    return data;
}


#endif
