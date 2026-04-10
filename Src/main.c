#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Estrutura
typedef struct {
    int chave;
    char sequencia[20];
} Chave;

// Banco de chaves
Chave chaves[] = {
    {1992, "ABCD"},
};

int totalChaves = 5;

// Buscar sequência
char* buscarSequencia(int chave) {
    for(int i = 0; i < totalChaves; i++) {
        if(chaves[i].chave == chave) {
            return chaves[i].sequencia;
        }
    }
    return NULL;
}

// Criptografia
void criptografia (){
    char texto[100];
    int chave;
    char *seq;

    printf("Digite a mensagem: ");
    scanf(" %[^\n]", texto);

    printf("Digite a chave: ");
    scanf("%d", &chave);

    seq = buscarSequencia(chave);

    if(seq == NULL) {
        printf("Chave invalida!\n");
        return;
    }

    // 🔹 aleatoriedade controlada
    srand(time(NULL));
    int inicio = rand() % strlen(seq);

    printf("Codigo de inicio (GUARDE): %d\n", inicio);

    // substituir espaço por #
    for(int i = 0; texto[i] != '\0'; i++) {
        if(texto[i] == ' ') {
            texto[i] = '#';
        }
    }

    int j = inicio;

    for(int i = 0; texto[i] != '\0'; i++) {

        if(isalpha(texto[i])) {
            char base = isupper(texto[i]) ? 'A' : 'a';

            int desloc = toupper(seq[j]) - 'A';

            texto[i] = (texto[i] - base + desloc) % 26 + base;

            j++;
            if(seq[j] == '\0') j = 0;
        }
        else if(texto[i] == '#') {
            j++;
            if(seq[j] == '\0') j = 0;
        }
    }

    printf("Mensagem criptografada: %s\n", texto);
}

// Descriptografia
void descriptografia (){
    char texto[100];
    int chave;
    int inicio;
    char *seq;

    printf("Digite a mensagem criptografada: ");
    scanf(" %[^\n]", texto);

    printf("Digite a chave: ");
    scanf("%d", &chave);

    printf("Digite o codigo de inicio: ");
    scanf("%d", &inicio);

    seq = buscarSequencia(chave);

    if(seq == NULL) {
        printf("Chave invalida!\n");
        return;
    }

    int j = inicio;

    for(int i = 0; texto[i] != '\0'; i++) {

        if(isalpha(texto[i])) {
            char base = isupper(texto[i]) ? 'A' : 'a';

            int desloc = toupper(seq[j]) - 'A';

            texto[i] = (texto[i] - base - desloc + 26) % 26 + base;

            j++;
            if(seq[j] == '\0') j = 0;
        }
        else if(texto[i] == '#') {
            j++;
            if(seq[j] == '\0') j = 0;
        }
    }

    // voltar espaço
    for(int i = 0; texto[i] != '\0'; i++) {
        if(texto[i] == '#') {
            texto[i] = ' ';
        }
    }

    printf("Mensagem decifrada: %s\n", texto);
}

int main()
{
    int opcao;

    do {
        printf("\n--- SISTEMA DE CRIPTOGRAFIA ---\n");
        printf("1 - Criptografia\n");
        printf("2 - Descriptografia\n");
        printf("0 - Sair\n");

        printf("Digite a opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                criptografia();
                break;
            case 2:
                descriptografia();
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
