# Enigma
Este repositório contém um pequeno protótipo da Máquina Enigma, equipamento utilizado durante a Segunda Guerra Mundial para criptografar e descriptografar mensagens dos líderes alemães.



#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Função de criptografia uzando cesar
void criptografia (){
    char texto[100];
    int i;
    printf("Digite a mensagem: ");
    scanf(" %[^\n]", texto);

    for(i = 0; texto[i] != '\0'; i++) {
        texto[i] = texto[i] + 3;
    }

    printf("Mensagem criptografada: %s\n", texto);
}

// Função de descriptografia uzando cesar
void descriptografia (){
    char texto[100];
    int i;
    printf("Digite a mensagem criptografada: ");
    scanf(" %[^\n]", texto);

    for(i = 0; texto[i] != '\0'; i++) {
        texto[i] = texto[i] - 3;
    }

    printf("Mensagem decifrada: %s\n", texto);
}



int main()
{
    int opcao;

    do {
        printf("\n--- SISTEMA DE PROCESSAMENTO DE DADOS ---\n");
        printf("1 - Criptografia\n");
        printf("2 - Descriptografia\n");
        printf("0 - Sair\n");

        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                criptografia();
                break;

            case 2:
                descriptografia();
                break;

            case 0:
                printf("Encerrando do programa...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
