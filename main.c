#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "objetomembro.h"
#include "objetoteste.h"

#define MAX_MEMBROS 200
#define MAX_TESTES 200


char menu(int quantMembros, float percPositivas, int vacinados, int confinados, int quantidadetestes, int totaltestesRealizados, int totaltestesAgendados);
int main()
{
    int totalMembros, quantAvaliados, totalReservas, vacinados, confinados,totaltestes,totaltestesRealizados,totaltestesAgendados, i;
    float percentagemPos;
    char opcao;
    membro vetorMembros[MAX_MEMBROS];
    teste vMembrosTeste[MAX_TESTES];


    totaltestesAgendados=0;
    totaltestesRealizados=0;
    totaltestes=0;
    confinados=0;
    vacinados=0;
    totalMembros=0;
    totalReservas=0;
    percentagemPos = 0.0;

    do
    {
        confinados = atualizarvacinados(vetorMembros,totalMembros,1);
        vacinados = atualizarvacinados(vetorMembros,totalMembros,4);
        opcao = menu(totalMembros, percentagemPos,vacinados,confinados,totaltestes,totaltestesRealizados,totaltestesAgendados);
        switch(opcao)
        {
        case 'A': //inserir dados novo membro
            totalMembros = acrescentaMembro(vetorMembros, totalMembros);
            break;
        case 'U': // Atualizar resultado testes
            totaltestesRealizados = atualizarTeste(vMembrosTeste, totaltestesRealizados, totaltestes);
            for(i=0; i<totaltestes; i++)
            {
                if(vMembrosTeste[i].feito == 1 && totaltestesAgendados!=0)
                {
                    totaltestesAgendados--;
                }
            }
            gravaFicheiroTextoTeste(vMembrosTeste,totaltestes);
            break;
        case 'T': //agendar teste
            // printf("VMEMBROS: %d",vetorMembros[1].id);
            totaltestes = agendarTeste(vMembrosTeste, vetorMembros, totalMembros, totaltestes);
            totaltestesAgendados=0;
            for(i=0; i<totaltestes; i++)
            {
                if(vMembrosTeste[i].feito==0)
                {
                    totaltestesAgendados++;
                }
            }
            break;
        case 'E': // Exibir membros
            mostrarMembro(vetorMembros, totalMembros,vMembrosTeste,totaltestes);
            break;
        case 'K': // Listar testes
            listarTestes(vMembrosTeste, totaltestes, vetorMembros,totalMembros);
            break;
        case 'N': // Listar testes
            listarTestesMembro(vMembrosTeste, totaltestes, vetorMembros,totalMembros);
            break;
        case 'O': // Listar testes
            alterarDataAgendada(vMembrosTeste, totaltestes, vetorMembros,totalMembros);
            break;
        case 'D': // Dados Estatisticos
            dadosEstatisticos(vetorMembros,vMembrosTeste,totalMembros,totaltestes);
            break;
        case 'I': // Casos de confinamento
            casosDeConfinamento(vetorMembros,totalMembros);
            break;
        case 'G':
            printf(" \nºGravar para ficheiro.\n");
            gravaFicheiroBinario(vetorMembros,totalMembros);
            gravaFicheiroBinarioTeste(vMembrosTeste,totaltestes);
            gravaFicheiroTexto(vetorMembros,totalMembros);
            gravaFicheiroTextoTeste(vMembrosTeste,totaltestes);
            break;
        case 'L':
            printf(" \nºLer de ficheiro.\n");
            totalMembros = leFicheiroBinario(vetorMembros);
            totaltestes = leFicheiroBinarioTeste(vMembrosTeste);
            for(i=0; i<totaltestes; i++)
            {
                if(vMembrosTeste[i].feito==0)
                {
                    totaltestesAgendados++;
                }
                else
                {
                    totaltestesRealizados++;
                }
            }
            break;
        }
    }
    while (opcao != 'F');
    return 0;
}
char menu(int quantMembros, float percentagemPos, int vacinados, int confinados, int quantidadetestes, int totaltestesRealizados, int totaltestesAgendados)
{
    char opcao;

    do
    {
        printf("\n\n\t\t\t       ::Programa Principal::\n\nºTotal de membros da Comunidade: %2d\t\t ºQuantidade de testes agendados:%d\n",quantMembros,totaltestesAgendados);
        printf("ºMembros em isolamento: %2d\t\t\t ºCasos Positivos: %d\n", confinados, percentagemPos);
        printf("ºQuantidade de testes realizados:%d\t\t ºMembros vacinados:%d\n",totaltestesRealizados,vacinados);
        printf("\n\nºAº -´ Acrescenta membro da comunidade escolar\nºTº -´ Agendar teste \n");
        printf("ºUº -´ Atualizar teste \n");
        printf("ºEº -´ Exibir informacao membros\nºGº -´ Gravar dados em ficheiros\n");
        printf("ºLº -´ Ler dados de ficheiro \n");

        //POR FAZER

        printf("ºKº -´ Listar Testes\n");
        printf("ºNº -´ Listar Testes De Utente\n");
        printf("ºOº -´ Alterar Teste Agendado pelo Utente\n");
        printf("ºIº -´ Listagem de Membros em Confinamento \n");
        printf("ºCº -´ Atualizar Confinamento de Membro \n");
        ~~
        printf("ºVº -´ Atualizar Vacina de Membro \n");
        printf("ºDº -´ Dados Estatisticos \n");
        //


        printf("\nºFº-Fim\n\n\tOpcao--> ");
        scanf(" %c", &opcao);
        opcao = toupper(opcao);

        if(opcao!='A' && opcao!='U' && opcao!='T' && opcao!='E' && opcao!='O' && opcao!='I'
                && opcao!='G' && opcao!='L' && opcao!='K' && opcao!='N' && opcao!='C' && opcao!='V'
                && opcao!='D'
                && opcao!='1' && opcao!='2'
                && opcao!='3' && opcao!='F')
        {
            printf("\nTem de ser dentro dos caracteres validos");
        }
        limpaBufferStdin();
    }
    while (opcao!='A' && opcao!='U' && opcao!='T' && opcao!='E' && opcao!='O' && opcao!='I'
            && opcao!='G' && opcao!='L' && opcao!='K' && opcao!='N' && opcao!='C' && opcao!='V'
            && opcao!='D'
            && opcao!='1' && opcao!='2'
            && opcao!='3' && opcao!='F');
    return opcao;
}

void mostrarMembro(membro vMembro[MAX_MEMBROS], int quantMembros, teste vMembrosTeste[MAX_TESTES], int quantTestes)
{
    int i,j;
    int incrementa;
    teste varivel[1];
    if (quantMembros == 0)
    {
        printf("\n\n|| Ainda nao existem membros registados!||\n\n");
    }
    else
    {
        printf("\n\n-------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t |INFORMACAO DE MEMBROS|\t\t\t");
        printf("\n---------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\n\n\t/Utente/\t/Tipo Membro/\t/Estado Vacina/\t/Estado confinamento/\t/Data de Nascimento/\t/Quantidade de testes/\t/Tipo de teste/\t/Data/\t/Nome/\n");
        printf("\n---------------------------------------------------------------------------------------------------------------------------------\n");
        for (i=0; i<quantMembros; i++)
        {
            incrementa=0;
            printf("\n\t%d\t\t%d", vMembro[i].id, vMembro[i].tipomembro);
            printf("\t\t%d\t",vMembro[i].estadovac);
            if(vMembro[i].estadoconf>1)
            {
                printf("    %d (%d/%d/%d)\t", vMembro[i].estadoconf,vMembro[i].dataConfinamento.dia,vMembro[i].dataConfinamento.mes,vMembro[i].dataConfinamento.ano);
            }
            else
            {
                printf("\t%d\t\t", vMembro[i].estadoconf);
            }
            printf("  (%d/%d/%d)", vMembro[i].data.dia,vMembro[i].data.mes,vMembro[i].data.ano);
            for(j=0; j<quantTestes; j++)
            {
                if(vMembrosTeste[j].numUtente==vMembro[i].id)
                {
                    incrementa++;
                    if(vMembrosTeste[j].feito == 0)
                    {
                        varivel[0] = vMembrosTeste[j];
                    }
                }
            }
            if(varivel[0].feito==0)
            {
                printf("\t\t%d\t\t%d\t\t(%d/%d/%d)\t", incrementa, varivel[0].tipoTeste, varivel[0].datateste.dia,varivel[0].datateste.mes,varivel[0].datateste.ano);
            }
            else
            {
                printf("\t\t\t%d\t\t\t\t\t", incrementa);
            }
            printf("%s\t\n",vMembro[i].nome);


            printf("\n\n------------------------------------------------------------------------------------------------------------------------------------\n");
        }
        printf("\n\t\t\t\t\t |LEGENDA|\n");
        printf("\n  -Tipo membro(1- Estudante | 2- Docente | 3- Tecnico)");
        printf("\n  -Estado vacina(1-Sem vacina | 2- 1 dose | 3- 2 dose | 4- 3 dose)");
        printf("\n  -Estado confinamento(1- Nao confinado | 2- Quarentena | 3- Isolamento Profilatico)\n\n");
    }
}

void listarTestes(teste vMembrosTeste[MAX_TESTES], int quantTestes,membro vMembro[MAX_MEMBROS],int quantMembros)
{
    int i,j;
    if (quantTestes == 0)
    {
        printf("\n\n|| Ainda nao existem testes registados!||\n\n");
    }
    else
    {
        printf("\n\n------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t\t\t\t |INFORMACAO DE TESTES|\t\t\t");
        printf("\n------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\n\n\t/Id Utente/\t/Nome de Utente/\t/Tipo de Teste/\t\t/Realizado/\t/Data de Realizacao/\t/Resultado/\t/Hora e Duracao/\t\n");
        printf("\n------------------------------------------------------------------------------------------------------------------------------------------------\n");
        for (i=0; i<quantTestes; i++)
        {
            printf("\n\t%d\t\t", vMembrosTeste[i].numUtente);
            printf("DIOGO");
            for(j=0; j<quantMembros; j++)
            {
                if(vMembrosTeste[i].numUtente==vMembro[j].id)
                {
                    printf("%s",vMembro[j].nome);
                }
            }
            printf("\t\t\t\t%d\t",vMembrosTeste[i].tipoTeste);
            if(vMembrosTeste[i].feito==1)
            {
                printf("\tSim\t\t\t%d/%d/%d\t",vMembrosTeste[i].datateste.dia,vMembrosTeste[i].datateste.mes,vMembrosTeste[i].datateste.ano);
                if(vMembrosTeste[i].resultadoTeste==1)
                {
                    printf("Negativo");
                }
                else if(vMembrosTeste[i].resultadoTeste==2)
                {
                    printf("Positivo");
                }
                else
                {
                    printf("Inconclusivo");
                }
                printf("\t\t%d/%d\t",vMembrosTeste[i].Horacolheita,vMembrosTeste[i].duracaoTeste);
            }
            else
            {
                printf("\tNao\t\t");
            }
            printf("\n\n------------------------------------------------------------------------------------------------------------------------------------------------\n");
        }
    }
}

void listarTestesMembro(teste vMembrosTeste[MAX_TESTES], int quantTestes,membro vMembro[MAX_MEMBROS],int quantMembros)
{
    membro tipoMembro[1];
    int i,j,numUtente;
    int posicao=0;
    tipoData data;
    teste vetorMembrosTeste[MAX_TESTES];
    int varivel=0,qTestesP=0;
    if (quantTestes == 0)
    {
        printf("\n\n|| Ainda nao existem testes registados!||\n\n");
    }
    else
    {
        printf("\n Inserir num de utente valido: "); // inserir membro com id de 100000000 a 999999999
        scanf(" %d", &numUtente);
        for(i=0; i<quantMembros; i++)
        {
            if(numUtente==vMembro[i].id)
            {
                tipoMembro[0] = vMembro[1];
                posicao = -1;
            }
        }
        if(posicao==-1)
        {
            data = lerDataMarcacao();
            for(i=0; i<quantTestes; i++)
            {
                vetorMembrosTeste[varivel] = vMembrosTeste[i]; // PROBLEMA POR RESOLVER COM O STOR
                varivel++; //
                if(numUtente == vMembrosTeste[i].numUtente)
                {
                    //PARA METER AQUI MAS DA A BRONCADA
                }
            }
            for(i=0; i<varivel; i++)
            {
                if(vetorMembrosTeste[i].resultadoTeste==2)
                {
                    qTestesP++; // acrescenta teste positivo
                }
            }
            printf("\n\n--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\t\t\t\t\t\t\t |INFORMACAO DE TESTES DE UM MEMBRO|\t\t\t");
            printf("\n--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\n\n\t/Nome de Utente/\t/Tipo de Teste/\t\t/Realizado/\t/Data/\t\t/Resultado/\t/Hora e Duracao/\t/Tipo de Membro/\t/Quantidade de Testes Positivos\t\n");
            printf("\n--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
            for(i=0; i<varivel; i++)
            {
                if(vetorMembrosTeste[i].datateste.ano == data.ano && vetorMembrosTeste[i].datateste.mes == data.mes && vetorMembrosTeste[i].datateste.dia == data.dia)
                {
                    printf("\t\t%s\t\t\t%d\t",tipoMembro[0].nome,vetorMembrosTeste[i].tipoTeste);
                    if(vetorMembrosTeste[i].feito==1)
                    {
                        printf("\t  Sim\t\t%d/%d/%d\t",vetorMembrosTeste[i].datateste.dia,vetorMembrosTeste[i].datateste.mes,vetorMembrosTeste[i].datateste.ano);
                        if(vetorMembrosTeste[i].resultadoTeste==1)
                        {
                            printf("Negativo");
                        }
                        else if(vetorMembrosTeste[i].resultadoTeste==2)
                        {
                            printf("Positivo");
                        }
                        else
                        {
                            printf("Inconclusivo");
                        }
                        printf("\t\t%d/%d\t\t",vetorMembrosTeste[i].Horacolheita,vetorMembrosTeste[i].duracaoTeste);
                    }
                    else
                    {
                        printf("\t  Nao\t\t%d/%d/%d\t\t\t\t\t\t",vetorMembrosTeste[i].datateste.dia,vetorMembrosTeste[i].datateste.mes,vetorMembrosTeste[i].datateste.ano);
                    }
                    printf("\t %d\t\t\t%d\t\t",tipoMembro[0].tipomembro,qTestesP);
                    printf("\n\n--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");


                }
            }
        }
        else
        {
            printf(" -> Esse numero de utente nao esta registado no sistema.\n");
        }
    }

}

void dadosEstatisticos(membro vMembro[MAX_MEMBROS],teste vMembrosTeste[MAX_TESTES], int quantMembros,int quantTestes)
{
    int i,j;
    int estudantes=0,docentes=0,tecnicos=0;
    int estudantes1=0,docente1=0,tecnicos1=0;
    int tInconclusivos=0;
    int totaldata,totaldata2=0;
    float resultado;
    for(i=0; i<quantMembros; i++)
    {
        if(vMembro[i].tipomembro==1)
        {
            estudantes++;
        }
        else if(vMembro[i].tipomembro==2)
        {
            docentes++;
        }
        else
        {
            tecnicos++;
        }
    }
    printf("Quantidade de Estudantes: %d", estudantes);
    printf("Quantidade de Docentes: %d", docentes);
    printf("Quantidade de Tecnicos: %d", tecnicos);

    estudantes=0;
    docentes=0;
    tecnicos=0; //Estudantes -> soma de todos os tempos ; Docentes -> quantidade de tempos que existe; Tecnicos -> media;

    for(i=0; i<quantTestes; i++)
    {
        if(vMembrosTeste[i].feito==1)
        {
            estudantes += vMembrosTeste[i].duracaoTeste;
            docentes++;
            if(vMembrosTeste[i].resultadoTeste==3)
            {
                tInconclusivos++;
            }
            for(j=0; j<quantMembros; j++)
            {
                if(vMembrosTeste[i].numUtente == vMembro[j].id)
                {
                    if(vMembro[j].tipomembro == 1)
                    {
                        estudantes1++;
                    }
                    else if(vMembro[j].tipomembro==2)
                    {
                        docente1++;
                    }
                    else
                    {
                        tecnicos1++;
                    }
                }
            }
        }
    }
    tecnicos = estudantes/docentes; //media de duracao
    printf("\nMedia de duracao de cada teste realizado: %d", tecnicos); //considerar um arrendomento da media a unidade FICA EM MINUTOS
    resultado= (float)(100*tInconclusivos/docentes); // percentagem de testes inconclusivos ; Docentes - totaltestes feitos
    printf("\nPercentagem de testes inconclusivos feitos: %.2f %%", resultado); // Duas casas decimais
    if(estudantes1<docente1) // NAO FUNCIONA POR CAUSA DOS VALORES QUE ESTAO TODOS ALTERADOS (FALAR COM STOR)
    {
        if(estudantes1<tecnicos1)
        {
            printf("Os Estudantes sao os membros da comunidade com menos testes realizados tendo apenas: %d Testes", estudantes1);
        }
        else if(docente1<tecnicos1)
        {
            printf("Os Docentes sao os membros da comunidade com menos testes realizados tendo apenas: %d Testes", docente1);
        }
    }
    else
    {
        if(docente1<tecnicos1)
        {
            printf("Os Docentes sao os membros da comunidade com menos testes realizados tendo apenas: %d Testes", docente1);
        }
        else
        {
            printf("Os Tecnicos sao os membros da comunidade com menos testes realizados tendo apenas: %d Testes", tecnicos1);
        }
    }
    for(i=0; i<quantTestes; i++) // ID  MEMBRO MINADO
    {
        if(vMembrosTeste[i].feito == 1)
        {
            totaldata = (vMembrosTeste[i].datateste.ano*365) + (vMembrosTeste[i].datateste.mes*30) + (vMembrosTeste[i].datateste.dia); // Associar que 1 mes tem 30 dias e um ano tem 365 dias
            if(totaldata>totaldata2)
            {
                totaldata2 = totaldata;
                estudantes = vMembrosTeste[i].numUtente; //
            }
        }
    }
    for(i=0; i<quantMembros; i++)
    {
        if(vMembro[i].id == estudantes)
        {
            printf("O id e o nome do membro que fez o teste mais recente foi: %d com o nome %s ", vMembro[i].id, vMembro[i].nome);
        }
    }
}

