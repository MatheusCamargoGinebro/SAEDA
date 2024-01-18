#include <stdio.h>
#include <windows.h>

// Funções de interface:
void pause()
{
    system("pause");
}

void clear()
{
    system("cls");
}

// Funções de sistema:

void executeInstaller(char *path)
{
    if (path == NULL || strlen(path) == 0)
    {
        printf("Caminho invalido.\n");
        return;
    }
    HINSTANCE result;

    result = ShellExecute(NULL, "runas", path, "/S", NULL, SW_HIDE);

    if ((int)result > 32)
    {
        printf("Arquivo executado com sucesso.\n");
    }
    else
    {
        printf("Erro ao executar o arquivo. Codigo: %d\n", (int)result);
    }
}

int main()
{
    char fileName[1024];
    char rUser;

    printf("O======================================================O\n");
    printf("| SAEDA - Sistema de Automacao de Abertura de Arquivos |\n");
    printf("O------------------------------------------------------O\n");
    printf("| ver 1.0 18/01/2024 - Testes e impressoes.            |\n");
    printf("O======================================================O\n");

    printf("\nDigite o caminho do arquivo de lista de arquivos a serem executados.\nR: ");
    scanf("%s", fileName);

    printf("\nArquivo: %s\n", fileName);

    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        printf("\nErro ao procurar lista de caminhos.\n");
        pause();
        return 1;
    }
    else
    {
        printf("\nLista de caminhos encontrada!\n\nOs seguintes arquivos serao executados:\n\n");

        // Percorrendo o arquivo e executando os arquivos:
        char path[1024];

        while (fscanf(file, "%s", path) != EOF)
        {
            printf("%s\n", path);
        }

        do
        {
            printf("\nDeseja continuar? [S/N]\nR: ");
            setbuf(stdin, NULL);
            scanf("%c", &rUser);

            if (rUser == 'S' || rUser == 's')
            {
                printf("\nExecutando arquivos...\n");
                while (fscanf(file, "%s", path) != EOF)
                {
                    printf("Executando arquivo: %s\n\n", path);
                    executeInstaller(path);
                }

                printf("Todos os arquivos foram executados.\n");
            }
            else if (rUser == 'N' || rUser == 'n')
            {
                printf("\nOperacao cancelada.\n");
            }
            else
            {
                printf("\nOpcao invalida.\n");
            }
        } while (rUser != 'S' && rUser != 's' && rUser != 'N' && rUser != 'n');
    }

    fclose(file);
    return 0;
}