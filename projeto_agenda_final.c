/*****************************************************/
/* Nome: Marcus Vinicius Costa Berger                */
/* Topicos de Programacao 2016                       */
/*****************************************************/
/* Arquivo final (gerado dia 08/01/2016)             */
/*****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 100
#define ARGS_SIZE 10
#define TEL_SIZE 20

struct celula{

    char nome[STRING_SIZE];
    char sobrenome[STRING_SIZE];
    char endereco[STRING_SIZE];
    char telefone[TEL_SIZE];
    char email[STRING_SIZE];

    struct celula *prox;
    
};

typedef struct celula *agenda;

// Funcao que recebe uma string 'str' e remove
// as quebras de linhas e espacos do final.
void strtrim(char* str) {
    int idx, size;
    size = strlen(str);
    for (idx = size - 1; idx >= 0 && 
            (str[idx] == '\n' || str[idx] == ' '); str[idx--] = '\0');
}

agenda createAgenda() {
    // ME COMPLETE!
    return NULL;
}

// Um exemplo de como ler as entradas
int addEntry(char *cmd, int argc, char **argv, agenda ag) {
    // ME COMPLETE!
    char *nome, *endereco, *telefone, *sobrenome, *email;

    // Quando estiver fazendo o codigo, lembre-se que essas strings
    // (esses char*) devem ser liberados usando a funcao 'free' em
    // algum momento antes do programa terminar!
    nome = malloc(STRING_SIZE * sizeof(char));
    sobrenome = malloc(STRING_SIZE * sizeof(char));
    endereco = malloc(STRING_SIZE * sizeof(char));
    telefone = malloc(TEL_SIZE * sizeof(char));
    email = malloc(STRING_SIZE * sizeof(char));

    printf("Nome: ");
    fgets(nome, STRING_SIZE, stdin);
    printf("Sobrenome: ");
    fgets(sobrenome, STRING_SIZE, stdin);
    printf("Endereco: ");
    fgets(endereco, STRING_SIZE, stdin);
    printf("Telefone: ");
    fgets(telefone, TEL_SIZE, stdin);
    printf("e-mail: ");
    fgets(email, STRING_SIZE, stdin);

    strtrim(nome);
    strtrim(sobrenome);
    strtrim(endereco);
    strtrim(telefone);
    strtrim(email);

    // ME COMPLETE!
    printf("Eu deveria salvar a entrada de\n nome '%s'\n sobrenome '%s'\n telefone '%s'\n endereco '%s'\n email '%s\n'", nome, sobrenome, telefone, endereco, email);

    printf("Salvo\n");
    return 0;
}

int deleteEntry(char *cmd, int argc, char **argv, agenda ag) {
    // ME COMPLETE!
    printf("Deletado!\n");
    return 0;
}

int listEntries(char *cmd, int argc, char **argv, agenda ag) {
    // ME COMPLETE!
    printf("Listando...\n");
    return 0;
}

// A partir daqui não precisa mexer... mas é BEM interessante olhar :)

int unknown(char* cmd, int argc, char **argv, agenda ag) {
    printf("Comando '%s' não conhecido\n", cmd);
    return 0;
}

int normalexit() {
    printf("Fechando agenda e saindo...\n");
    exit(0);
}

int helptext() {
    printf("Comandos aceitos\n");
    printf(" novo: cria uma nova entrada na agenda\n");
    printf(" listar: lista as entradas da agenda\n");
    printf(" apagar: deleta uma entrada da agenda\n");
    printf(" sair (ou exit): sair do programa\n");
    printf(" help (ou comandos): lista os comandos validos\n");
    return 0;
}

int (*findCommand(char *cmdName)) (char*, int, char**, agenda) {
    if (strcmp(cmdName, "novo") == 0) {
        return &addEntry;
    }
    if (strcmp(cmdName, "apagar") == 0) {
        return &deleteEntry;
    }
    if (strcmp(cmdName, "listar") == 0) {
        return &listEntries;
    }
    if (strcmp(cmdName, "sair") == 0 || strcmp(cmdName, "exit") == 0) {
        return (int (*)(char*, int, char**, agenda)) &normalexit;
    }
    if (strcmp(cmdName, "help") == 0 || strcmp(cmdName, "comandos") == 0) {
        return (int (*)(char*, int, char**, agenda)) &helptext;
    }
    return &unknown;
} 

int main() {
    char *s, *buf, *cmd, **args;
    int i, pos;
    buf = malloc(STRING_SIZE * sizeof(char));
    cmd = malloc(STRING_SIZE * sizeof(char));

    agenda ag = createAgenda();

    args = malloc(ARGS_SIZE * sizeof(char*));
    for (i = 0; i < ARGS_SIZE; i++) {
        args[i] = malloc(STRING_SIZE * sizeof(char));
    }

    printf("Agenda Topicos de Programacao 2016\n");
    while (1) {
        printf("> ");
        if (fgets(buf, STRING_SIZE, stdin) == NULL) normalexit();

        sscanf(buf, "%s %n", cmd, &pos);

        s = buf + pos;

        i = 0;
        while (sscanf(s, "%s %n", args[i], &pos) != EOF) {
            i++;
            s = s + pos;
        }

        int (*foo)(char*, int, char**, agenda) = findCommand(cmd);
        (*foo)(cmd, i, args, ag);
    }

    free(buf);
    free(cmd);

    return 0;
}
