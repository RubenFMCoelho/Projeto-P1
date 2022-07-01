#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcoesFicheiros.h"
#include "objetomembro.h"
#include "objetoteste.h"

void gravaFicheiroBinario(membro vetorMembros[MAX_MEMBROS],int numMembros){
	FILE *ficheiro;
	int quantEscritaParaFicheiro;
	ficheiro=fopen("dadosMembros.dat","wb");
	if (ficheiro == NULL) {
		printf("Erro abrir ficheiro");
	}else{
		quantEscritaParaFicheiro = fwrite(&numMembros,sizeof(int),1,ficheiro);
        if (quantEscritaParaFicheiro != 1) {
            printf("Erro ao escrever a quantidade de membros");
        }
		quantEscritaParaFicheiro = fwrite(vetorMembros,sizeof(membro),numMembros,ficheiro);
        if (quantEscritaParaFicheiro != numMembros) {
            printf("Erro ao escrever dados de Membros");
        }
		fclose(ficheiro);
    }
}

int leFicheiroBinario(membro vetorMembros[MAX_MEMBROS]){
    FILE *ficheiro;
    int numElementos;
    int quantLeituraDeFicheiro;
    ficheiro=fopen("dadosMembros.dat","rb");
    if (ficheiro == NULL) {
        printf ("Erro abrir ficheiro");
    }else{
        quantLeituraDeFicheiro = fread(&numElementos,sizeof(int),1,ficheiro);
        if (quantLeituraDeFicheiro != 1) {
            printf("Erro ao obter informacao da quantidade de membros");
        }
        quantLeituraDeFicheiro = fread(vetorMembros,sizeof(membro),numElementos,ficheiro);
        if (quantLeituraDeFicheiro != numElementos) {
            printf("Erro ao obter informacao dos Membros");
        }
        fclose(ficheiro);
    }
    return numElementos;
}

void gravaFicheiroBinarioTeste(teste vMembrosTeste[MAX_TESTES],int numTestes){
	FILE *ficheiro;
	int quantEscritaParaFicheiro;
	ficheiro=fopen("dadosTeste.dat","wb");
	if (ficheiro == NULL) {
		printf("Erro abrir ficheiro");
	}else{
		quantEscritaParaFicheiro = fwrite(&numTestes,sizeof(int),1,ficheiro);
        if (quantEscritaParaFicheiro != 1) {
            printf("Erro ao escrever a quantidade de testes");
        }
		quantEscritaParaFicheiro = fwrite(vMembrosTeste,sizeof(teste),numTestes,ficheiro);
        if (quantEscritaParaFicheiro != numTestes) {
            printf("Erro ao escrever dados de Testes");
        }
		fclose(ficheiro);
    }
}

int leFicheiroBinarioTeste(teste vMembrosTeste[MAX_TESTES]){
    FILE *ficheiro;
    int numElementos;
    int quantLeituraDeFicheiro;
    ficheiro=fopen("dadosTeste.dat","rb");
    if (ficheiro == NULL) {
        printf ("Erro abrir ficheiro");
    }else{
        quantLeituraDeFicheiro = fread(&numElementos,sizeof(int),1,ficheiro);
        if (quantLeituraDeFicheiro != 1) {
            printf("Erro ao obter informacao da quantidade de testes");
        }
        quantLeituraDeFicheiro = fread(vMembrosTeste,sizeof(teste),numElementos,ficheiro);
        if (quantLeituraDeFicheiro != numElementos) {
            printf("Erro ao obter informacao dos Testes");
        }
        fclose(ficheiro);
    }
    return numElementos;
}


void gravaFicheiroTexto(membro vetorMembros[MAX_MEMBROS],int numMembros) {
    FILE *fich;
    int i;
    fich = fopen("dadosMembros.txt","w");
    if (fich == NULL) {
        printf ("Erro abrir ficheiro");
    }else{
        fprintf(fich,"%d\n\n", numMembros);
        for (i=0; i<numMembros; i++) {
            fprintf(fich,"%d\n",vetorMembros[i].id);
            fprintf(fich,"%s\n",vetorMembros[i].nome);
            fprintf(fich,"%d\n",vetorMembros[i].tipomembro);
            fprintf(fich,"%d\n",vetorMembros[i].estadovac);
            fprintf(fich,"%d\n",vetorMembros[i].estadoconf);
            fprintf(fich,"%02d/%02d/%04d\n\n",
                    vetorMembros[i].data.dia,
                    vetorMembros[i].data.mes,
                    vetorMembros[i].data.ano);
        }
        fclose(fich);
    }
}
void gravaFicheiroTextoTeste(teste vMembrosTeste[MAX_TESTES],int numTestes) {
    FILE *fich;
    int i;
    fich = fopen("dadosTeste.txt","w");
    if (fich == NULL) {
        printf ("Erro abrir ficheiro");
    }else{
        fprintf(fich,"%d\n\n", numTestes);
        for (i=0; i<numTestes; i++) {
            fprintf(fich,"%d\n",vMembrosTeste[i].id);
            fprintf(fich,"%s\n",vMembrosTeste[i].numUtente);
            fprintf(fich,"%d\n",vMembrosTeste[i].quantTestes);
            fprintf(fich,"%d\n",vMembrosTeste[i].resultadoTeste);
            fprintf(fich,"%d\n",vMembrosTeste[i].tipoTeste);
            fprintf(fich,"%d\n",vMembrosTeste[i].Horacolheita);
            fprintf(fich,"%d\n",vMembrosTeste[i].duracaoTeste);
            fprintf(fich,"%d\n",vMembrosTeste[i].feito);
            fprintf(fich,"%02d/%02d/%04d\n\n",
                    vMembrosTeste[i].datateste.dia,
                    vMembrosTeste[i].datateste.mes,
                    vMembrosTeste[i].datateste.ano);
        }
        fclose(fich);
    }
}



