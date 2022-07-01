#ifndef FUNCOESAUX_H_INCLUDED
#define FUNCOESAUX_H_INCLUDED

#define MAX_STRING 50
#define MAX_TESTES 200


typedef struct{
    int dia;
    int mes;
    int ano;
} tipoData;


int lerInteiro(char mensagem[MAX_STRING], int minimo, int maximo);
float lerFloat(char mensagem[MAX_STRING], float minimo, float maximo);
void lerString(char mensagem[MAX_STRING], char vetorCaracteres[MAX_STRING], int maximoCaracteres);
void limpaBufferStdin(void);
tipoData lerData(void);
tipoData lerDataTeste();//teste vTeste[MAX_TESTES], int totaltestes);
tipoData lerDataMarcacao();
tipoData lerDataConf();
tipoData lerDataNovaDataMarcacao();
#endif
