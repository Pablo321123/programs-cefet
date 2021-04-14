//Autores: Pablo Vasconcelos da Cruz e Vitor Godinho Rausch

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct estruturaArquivo //Struct para facilitar o obtenção de dados do arquivo
{
    FILE *arquivo[2];
    char nome_arquivo[30];
} archive;

void remove_palavra(int tam, char *texto, char *local_para_armazenamento, char *texto_remover)
{
    int lenght_t_r = strlen(texto_remover), letras_iguais = 0, indice = 0; //lenght_t_r = tamanho do texto a ser removido

    for (int j = 0, k = 0; j <= tam; j++, indice++) //Como estamos procurando um ocorrencia de uma certa palavra no texto, basta nós acharmos uma determinada sequencia
    {                                               //na qual seja igual a palavra escolhida pelo usuarioa para ser removida
        local_para_armazenamento[indice] = texto[j];

        if (tolower(texto[j]) == tolower(texto_remover[k])) //Aqui procuramos a primeira letra da string a ser removida
        {
            letras_iguais++; //Se acharmos, vamos incrementar no contador 'letras iguais'
            k++;
        }
        else
        {
            if (tolower(texto[j]) == tolower(texto_remover[0]) && letras_iguais == 1) //Caso contrario, verificamos primeiro se a proxima letra do texto original
            {                                                                         // é igual a primeira letra da string a ser removida
                continue;                                                             //caso seja, nos contamos denovo. Aqui é caso de optimizacao.
            }

            letras_iguais = k = 0; //Caso seja totalmente difente e fora de sequencia ele zera as letras iguais e k (controlador do indice da string a ser removida)
        }

        if (letras_iguais == lenght_t_r)
        {
            indice -= letras_iguais; //Quando o letras iguais fica igual ao tamnho da variavel a ser removida, significa que encontramos uma ocorrencia.
            letras_iguais = k = 0;   //E entao, basta decrementarmos a variavel indince (controladora da local_para_armazenamento do novo texto)
        }                            //e sobrescrevermos com o que vem adjacente a esta ocorrencia do texto original.
    }

    local_para_armazenamento[indice] = '\0';
}

int main()
{
    archive arq;
    char palavra[48];

    puts("Digite o nome_arquivo do arquivo texto (sem o .txt)");

    scanf(" %s", arq.nome_arquivo);
    strcat(arq.nome_arquivo, ".txt");

    arq.arquivo[0] = fopen(arq.nome_arquivo, "rw"); //w: Permissao para escrita. Fazendo alusão ao shell do linux e com alguns cuidados é possivel sobreescrever um arquivo existente, ou criar um caso ainda não exista, com este parametro.
    arq.arquivo[1] = fopen("temp.txt", "w"); //Geramos um arquivo temporario.

    if (arq.arquivo[0] == NULL) //Caso o fopen nao encontre o arquivo, seu ponteiro estara vazio e resultara em um ponteiro apontando para o "nada" e entao ele entrara neste if.
    {
        puts("Impossivel abrir o arquivo.");
    }
    else
    {
        system("cls");
        printf("Digite a palavra que voc%c deseja remover do texto: \n", 136);
        scanf(" %s", palavra);

        fseek(arq.arquivo[0], 0, SEEK_END);
        int tam = ftell(arq.arquivo[0]), tamanhoreal; //Aqui, por meio da ftell, capturamos a quantidade de bytes do arquivo texto e utilizamos essa quantidade para criar uma string que recebra todo o arquivo.
        char nova_string[tam], aux[tam];              //Portanto, nessa situação, será impossível o arquivo "estourar" a capacidade maxima do vetor.

        strcpy(nova_string, " ");
        strcpy(aux, " ");

        rewind(arq.arquivo[0]);

        fread(aux, sizeof(char), tam, arq.arquivo[0]);

        tamanhoreal = strlen(aux); //Como as vezes o arquivo fica um pouco maior do que a quantidade real dos caracteres, aqui colocamos um str len para garantir a quantidade exata de caracteres.
        aux[tamanhoreal] = '\0';

        remove_palavra(tamanhoreal, aux, nova_string, palavra);

        system("cls"); //limpa o prompt

        if (fprintf(arq.arquivo[1], nova_string)) //Escrevemos o novo texto sem as ocorrencias da palavra a ser removida no arquivo temporario.
        {
            printf("A palavra %s foi removida com sucesso!\n", palavra); 
            _fcloseall(); //Fechamos todos os arquivos abertos
            remove(arq.nome_arquivo); //Apagamos o arquivo base
            rename("temp.txt", arq.nome_arquivo); //Renomeamos o arquivo temporario para o nome original
        }
        else
        {
            printf("Imposs%cvel realizar a grava%c%co no arquivo!\n", 161, 135, 198);
        }
    }

    system("pause");

    return 0;
}
