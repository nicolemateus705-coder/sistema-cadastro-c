#include <stdio.h>
#include <string.h>

#define MAX 100
#define TAM_NOME 50

char nomes[MAX][TAM_NOME];
int total = 0;

// cadastrar nome
void cadastrar() {
    if (total >= MAX) {
        printf("Limite de cadastros atingido!\n");
        return;
    }

    printf("Digite o nome: ");
    scanf(" %[^\n]", nomes[total]);
    total++;

    printf("Cadastro realizado com sucesso!\n");
}

// listar nomes
void listar() {
    if (total == 0) {
        printf("Nenhum cadastro encontrado.\n");
        return;
    }

    printf("\nLista de nomes:\n");
    for (int i = 0; i < total; i++) {
        printf("%d - %s\n", i + 1, nomes[i]);
    }
}

// busca sequencial
void buscar() {
    char busca[TAM_NOME];
    int encontrado = 0;

    printf("Digite o nome para buscar: ");
    scanf(" %[^\n]", busca);

    for (int i = 0; i < total; i++) {
        if (strcmp(nomes[i], busca) == 0) {
            printf("Nome encontrado na posição %d\n", i + 1);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Nome não encontrado.\n");
    }
}

int main() {
    int opcao;

    do {
        printf("\n=== MENU ===\n");
        printf("1 - Cadastrar\n");
        printf("2 - Listar\n");
        printf("3 - Buscar\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar();
                break;
            case 2:
                listar();
                break;
            case 3:
                buscar();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}
