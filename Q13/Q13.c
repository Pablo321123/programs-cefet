//Autores: Pablo Vasconcelos da Cruz e Vitor Godinho Rausch

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define numero_elementos 100

typedef struct dadosArquivos
{
    FILE *arquivo[2];        // Arquivo texto [0]; Arquivo binario [1];
    char nomeArquivo[2][31]; //Nome do Arquivo texto [0]; Nome do Arquivo binario [1];
    int tamanhoArquivo[2];   //[0] Tamanho no Arquivo texto; [1] Tamanho no Arquivo binario ;
} arq;

void reabrirArquivos(arq dadosArquivo)
{
    _fcloseall();
    dadosArquivo.arquivo[0] = fopen(dadosArquivo.nomeArquivo[0], "w");
    dadosArquivo.arquivo[1] = fopen(dadosArquivo.nomeArquivo[1], "wb");

    if (dadosArquivo.arquivo[0] == NULL || dadosArquivo.arquivo[1] == NULL)
    {
        printf("Impossivel limpar os arquivos no momento!!");
    }
    else
    {
        printf("Arquivos limpos com sucesso!!");
    }
}

int main()
{
    arq arq;
    int numerosGravacao[numero_elementos], cont = 0, op = 0;
    srand(time(NULL)); //Semente para gerar numeros aleatorios dentro dos intervalos propostos

    printf("Digite o nome do arquivo que voc%c deseja criar e gravar em modo TEXTO: (SEM O .txt)\n", 136);
    scanf(" %s", arq.nomeArquivo[0]);
    strcat(arq.nomeArquivo[0], ".txt");

    system("cls");

    printf("Digite o nome do arquivo que voc%c deseja criar e gravar em modo BIN%cRIO: (SEM O .txt)\n", 136, 181);
    scanf(" %s", arq.nomeArquivo[1]);
    strcat(arq.nomeArquivo[1], ".txt");

    arq.arquivo[0] = fopen(arq.nomeArquivo[0], "w");
    arq.arquivo[1] = fopen(arq.nomeArquivo[1], "wb");

    while (1)
    {
        system("cls");
        printf("1 - Gerar n%cmeros entre 0 a 9\n2 - Gerar n%cmeros entre 1000 a 9999\n3 - Gerar n%cmeros entre 10000 a 99999\n4-Limpar os arquivos\nDigite 0 para sair\n", 163, 163, 163);
        scanf(" %d", &op);
        cont = 0;
        int resto;                  //[0] representa o tempo do arquivo texto e [1] representa o tempo do arquivo binario
        clock_t t_ini[2], t_fim[2]; //Variaveis para capturar o tempo de execucao de um determinado intervalo. Ademais, o clock_t é derivado da biblioteca time.h. Encontrado em: http://wurthmann.blogspot.com/2015/04/medir-tempo-de-execucao-em-c.html#:~:text=Função%20clock()%20e%20a,o%20tempo%20final%20da%20execução.

        switch (op) //Fizemos um menu para que facilite os nossos casos de testes
        {
        case 1:
            while (cont < numero_elementos)
            {
                resto = rand() % 10;
                numerosGravacao[cont++] = resto;
            }
            break;
        case 2:
            while (cont < numero_elementos)
            {
                resto = rand() % 10000;
                numerosGravacao[cont++] = resto < 1000 ? resto + 1000 : resto;
            }
            break;
        case 3:
            while (cont < numero_elementos)
            {
                resto = rand() % 100000;
                numerosGravacao[cont++] = resto < 10000 ? resto + 10000 : resto; // 10.000 -  99.999
            }
            break;
        case 4:
            reabrirArquivos(arq); //Sobrescrevemos ambos os arquivos por um arquivo vazio.
            system("pause");
            continue;
            break;
        case 0:

            _fcloseall(); //Fecha todos os arquivos abertos; Encontrado no forum da microsoft: https://docs.microsoft.com/pt-br/cpp/c-runtime-library/reference/fclose-fcloseall?view=msvc-160

            return 1;
            break;

        default:
            printf("Op%c%co inv%clida!\n", 135, 198, 160);
            system("pause");
            break;
        }

        t_ini[0] = clock(); //Função para medir o tempo
        for (int i = 0; i < numero_elementos; i++)
        {
            fprintf(arq.arquivo[0], "%d", numerosGravacao[i]); //fprintf para realizar a gravação de dados no arquivo texto
        }
        t_fim[0] = clock() - t_ini[0];

        t_ini[1] = clock();
        if (fwrite(numerosGravacao, sizeof(int), numero_elementos, arq.arquivo[1]) != numero_elementos) //fwrite  para realizar a gravação de dados no arquivo binario
        {
            printf("Erro na grava%c%co  no arquivo BIN%cRIO!\n", 135, 198, 160);
            system("pause");
            continue;
        }
        t_fim[1] = clock() - t_ini[1];

        system("cls");

        fseek(arq.arquivo[0], 0, SEEK_END); //Posicionamento no fim do arquivo TEXTO para realizar a contagem dos bytes para determinarmos o tamanho do arquivo
        arq.tamanhoArquivo[0] = ftell(arq.arquivo[0]);
        rewind(arq.arquivo[0]);

        fseek(arq.arquivo[1], 0, SEEK_END); //Posicionamento no fim do arquivo BINÁRIO para realizar a contagem dos bytes para determinarmos o tamanho do arquivo
        arq.tamanhoArquivo[1] = ftell(arq.arquivo[1]);
        rewind(arq.arquivo[1]);

        printf("O tamanho do arquivo TEXTO com n%cmeros entre %d e %d %c: %d\n", 163, op == 1 ? 0 : op == 2 ? 1000
                                                                                                            : 10000,
               op == 1 ? 9 : op == 2 ? 9999
                                     : 99999,
               130, arq.tamanhoArquivo[0]);

        printf("O arquivo TEXTO foi gravado em %lf ms\n\n", ((double)t_fim[0] / (CLOCKS_PER_SEC / 1000))); //(CLOCKS_PER_SEC / 1000) pegar o valor em segundos

        printf("O tamanho do arquivo BIN%cRIO: com n%cmeros entre %d e %d %c: %d\n", 181, 163, op == 1 ? 0 : op == 2 ? 1000
                                                                                                                     : 10000,
               op == 1 ? 9 : op == 2 ? 9999
                                     : 99999,
               130, arq.tamanhoArquivo[1]);

        printf("O arquivo BIN%cRIO foi gravado em %lf ms\n", 181, ((double)t_fim[1] / (CLOCKS_PER_SEC / 1000))); //(CLOCKS_PER_SEC / 1000) pegar o valor em mili segundos

        system("pause");
    }

    return 0;
}