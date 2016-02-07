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

struct contato{

    char *nome; 
    char *sobrenome; 
    char *endereco; 
    char *telefone;
    char *email;

    struct contato * prox;
};
typedef struct contato *agenda;

// Funcao que recebe uma string 'str' e remove
// as quebras de linhas e espacos do final.
void strtrim(char* str) {
    int idx, size;
    size = strlen(str);
    for (idx = size - 1; idx >= 0 && 
            (str[idx] == '\n' || str[idx] == ' '); str[idx--] = '\0');
}

agenda createAgenda() {
    agenda ag;
    ag = (agenda) malloc(sizeof(*ag));
    ag->prox = NULL;

    return ag;
}

int agendaVazia(agenda ag){
    return ag->prox == NULL;
}
// Um exemplo de como ler as entradas
int addEntry(char *cmd, int argc, char **argv, agenda ag) {
    int flag = 0;
    agenda novo, anterior, atual;
    char *nome, *sobrenome, *endereco, *telefone, *email;

    // Quando estiver fazendo o codigo, lembre-se que essas strings
    // (esses char*) devem ser liberados usando a funcao 'free' em
    // algum momento antes do programa terminar!
    nome = malloc(STRING_SIZE * sizeof(char));
    sobrenome = malloc(STRING_SIZE* sizeof(char));
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
    printf("E-mail: ");
    fgets(email, STRING_SIZE, stdin);

    strtrim(nome);
    strtrim(sobrenome);
    strtrim(endereco);
    strtrim(telefone);
    strtrim(email);

    novo = createAgenda();
    novo->nome = nome;
    novo->sobrenome = sobrenome;
    novo->endereco = endereco;
    novo->telefone = telefone;
    novo->email = email;

    if(agendaVazia(ag)){
        novo->prox = ag->prox;
        ag->prox = novo;
    }else {
        anterior = ag;
        atual = ag->prox;

        while(atual != NULL){
            if(strncmp(atual->nome,novo->nome,3) >= 0){
                anterior->prox = novo;
                novo->prox = atual;
                flag = 1;
                break;
            }
            anterior = anterior->prox;
            atual = atual->prox;
        }
        if(flag == 0){
            anterior->prox = novo;
        }
    }

    printf("Salvo\n");
    return 0;
}

int deleteEntry(char *cmd, int argc, char **argv, agenda ag) {
    agenda atual, anterior;
    char *opcao, *nome, *sobrenome, *endereco, *telefone, *email, *aux;

    anterior = ag;
    atual = ag->prox;

    opcao = *argv;

    if(agendaVazia(ag)){
        printf("Agenda vazia\n");
        return 0;
    }

    nome = malloc(STRING_SIZE * sizeof(char));
    sobrenome = malloc(STRING_SIZE * sizeof(char));
    endereco = malloc(STRING_SIZE * sizeof(char));
    telefone = malloc(TEL_SIZE * sizeof(char));
    email = malloc(STRING_SIZE * sizeof(char));
    aux = malloc(STRING_SIZE * sizeof(char));

    if(strcmp(opcao, "nome") == 0){
        printf("Nome: ");
        fgets(nome, STRING_SIZE, stdin);
        strtrim(nome);

        while(1){
            if(atual != NULL){
                aux = atual->nome;
                strtrim(aux);
                if(strcmp(aux, nome) == 0){
                    anterior->prox = atual->prox;
                    free(atual->nome);
                    free(atual->sobrenome);
                    free(atual->endereco);
                    free(atual->telefone);
                    free(atual);
                    printf("%s deletado!\n", nome);
                    break;
                }else{
                    atual = atual->prox;
                    anterior = anterior->prox;
                }
            }else{
                printf("Nome nao encontrado\n");
                break;
            }
        }
    }

    if(strcmp(opcao, "sobrenome") == 0){
        printf("Sobrenome: ");
        fgets(sobrenome, STRING_SIZE, stdin);
        strtrim(sobrenome);

        while(1){
            if(atual != NULL){
                aux = atual->sobrenome;
                strtrim(aux);
                if(strcmp(aux, sobrenome) == 0){
                    anterior->prox = atual->prox;
                    free(atual->nome);
                    free(atual->sobrenome);
                    free(atual->endereco);
                    free(atual->telefone);
                    free(atual);
                    printf("%s deletado!\n", sobrenome);
                    break;
                }else{
                    atual = atual->prox;
                    anterior = anterior->prox;
                }
            }else{
                printf("Sobrenome nao encontrado\n");
                break;
            }
        }
    }

    if(strcmp(opcao, "endereco") == 0){
        printf("Endereco: ");
        fgets(endereco, STRING_SIZE, stdin);
        strtrim(endereco);

        while(1){
            if(atual != NULL){
                aux = atual->endereco;
                strtrim(aux);
                if(strcmp(aux, endereco) == 0){
                    anterior->prox = atual->prox;
                    free(atual->nome);
                    free(atual->sobrenome);
                    free(atual->endereco);
                    free(atual->telefone);
                    free(atual);
                    printf("%s deletado!\n", endereco);
                    break;
                }else{
                    atual = atual->prox;
                    anterior = anterior->prox;
                }
            }else{
                printf("Endereco nao encontrado\n");
                break;
            }
        }
    }

        if(strcmp(opcao, "telefone") == 0){
        printf("Telefone: ");
        fgets(telefone, TEL_SIZE, stdin);
        strtrim(telefone);

        while(1){
            if(atual != NULL){
                aux = atual->telefone;
                strtrim(aux);
                if(strcmp(aux, telefone) == 0){
                    anterior->prox = atual->prox;
                    free(atual->nome);
                    free(atual->sobrenome);
                    free(atual->endereco);
                    free(atual->telefone);
                    free(atual);
                    printf("%s deletado!\n", telefone);
                    break;
                }else{
                    atual = atual->prox;
                    anterior = anterior->prox;
                }
            }else{
                printf("Telefone nao encontrado\n");
                break;
            }
        }
    }
    	if(strcmp(opcao, "email") == 0){
        printf("E-mail: ");
        fgets(email, STRING_SIZE, stdin);
        strtrim(email);

        while(1){
            if(atual != NULL){
                aux = atual->email;
                strtrim(aux);
                if(strcmp(aux, email) == 0){
                    anterior->prox = atual->prox;
                    free(atual->nome);
                    free(atual->sobrenome);
                    free(atual->endereco);
                    free(atual->telefone);
                    free(atual);
                    printf("%s deletado!\n", email);
                    break;
                }else{
                    atual = atual->prox;
                    anterior = anterior->prox;
                }
            }else{
                printf("E-mail nao encontrado\n");
                break;
            }
        }
    }
    

    return 0;
}

int listEntries(char *cmd, int argc, char **argv, agenda ag) {

agenda primeiro = ag->prox;


    if(agendaVazia(ag)){
        printf("Agenda vazia!!\n");
        return 0;
    }



    printf("%-10s | %-15s | %-15s | %-10s | %-15s\n", "Nome", "Sobrenome", "Endereco", "Telefone", "E-mail");

    while(primeiro != NULL){
        printf("%-10s | %-15s |  %-15s | %-10s | %-15s\n", primeiro->nome, primeiro->sobrenome, primeiro->endereco, primeiro->telefone, primeiro->email);
        primeiro = primeiro->prox;
    }



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
