#include <stdio.h>
#include <windows.h>

// Funções de interface:
void pause(){
    system("pause");
}

void clear(){
    system("cls");
}

// Funções de sistema:


int main(){
    printf("O======================================================O\n");
    printf("| SAEDA - Sistema de Automacao de Abertura de Arquivos |\n");
    printf("O------------------------------------------------------O\n");
    printf("| ver 1.0 18/01/2024 - Testes e impressoes.            |\n");
    printf("O======================================================O\n");

    printf("\nDigite o caminho do arquivo de lista de arquivos a serem executados.\nR: ");
    char fileName[1024];
    scanf("%s", fileName);
    
    FILE *file = fopen(fileName, "r");

    if(file == NULL){
        printf("Erro ao procurar lista de caminhos.\n");
        pause();
        return 1;
    } else {
        printf("lista de caminhos encontrada!\n");
        pause();

        // configurando para permitir que o programa execute os arquivos como administrador:
        
    }
    return 0;
}