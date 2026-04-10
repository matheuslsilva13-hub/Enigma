#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Estrutura das Chaves
typedef struct {
    int chave;
    char sequencia[20];
} Chave;

// Banco de chaves (cada chave tem uma sequencia)
Chave chaves[] = {
    {2010, "ABCD"},
    {2009, "ZXCV"},
    {2020, "QWER"},
    {2026, "TYUI"},
    {2014, "GHJK"}
};

int totalChaves = 5;

// Buscar sequência (Procura a sequecia correspondente com a chave que usou)
char* buscarSequencia(int chave) {
    for(int i = 0; i < totalChaves; i++) {
        if(chaves[i].chave == chave) {
            return chaves[i].sequencia;
        }
    }
    return NULL;
}

// Criptografia estilo Vigenère
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

    int i, j = 0;

    // Substituir espaço por "#"
    for(i = 0; texto[i] != '\0'; i++) {
        if(texto[i] == ' ') {
            texto[i] = '#';
        }
    }

    for(i = 0; texto[i] != '\0'; i++) {

        if(isalpha(texto[i])) {
            char base = isupper(texto[i]) ? 'A' : 'a';

            int desloc = toupper(seq[j]) - 'A';

            texto[i] = (texto[i] - base + desloc) % 26 + base;

            j++;
            if(seq[j] == '\0') j = 0;
        }
        else if(texto[i] == '#') {
            // espaço também avança a chave
            j++;
            if(seq[j] == '\0') j = 0;
        }
    }

    printf("Mensagem criptografada: %s\n", texto);
}

// Descriptografia (Usa a chave para a descriptação da mensagem se usar outra chave terá outra resposta)
void descriptografia (){
    char texto[100];
    int chave;
    char *seq;

    printf("Digite a mensagem criptografada: ");
    scanf(" %[^\n]", texto);

    printf("Digite a chave: ");
    scanf("%d", &chave);

    seq = buscarSequencia(chave);

    if(seq == NULL) {
        printf("Chave invalida!\n");
        return;
    }

    int i, j = 0;

    for(i = 0; texto[i] != '\0'; i++) {

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

    // Converter "#" de volta para espaço
    for(i = 0; texto[i] != '\0'; i++) {
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
