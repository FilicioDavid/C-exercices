#include <stdio.h>
#include <stdlib.h>

// Function to clear the screen
void clearScreen() {
#ifdef _WIN32
    system("cls");  // For Windows
#else
    system("clear"); // For Unix/Linux
#endif
}

int main(void) {
    int opcao, i = 0;

    struct todo {
        int status, id;
        char nome[20];
        char desc[500];
    };

    struct todo cadastro[100];

    printf("Bem vindo ao Gerenciador de Tarefas\n ");

    do {
        printf("1. Adicionar nova tarefa\n");
        printf("2. Listar tarefas pendentes\n");
        printf("3. Marcar tarefas como concluídas\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastro[i].id = i;
                printf("\nDigite o nome da tarefa:\n");
                scanf(" %19[^\n]", cadastro[i].nome);
                printf("\nDigite a descrição da tarefa:\n");
                scanf(" %499[^\n]", cadastro[i].desc);
                cadastro[i].status = 1;
                i++;
                break;
            case 2:
                clearScreen();
                printf("Tarefas pendentes:\n");
                for (int j = 0; j < i; j++) {
                    if (cadastro[j].status == 1) {
                        printf("\n ID: %d\n", cadastro[j].id);
                        printf(" Nome: %s\n", cadastro[j].nome);
                        printf(" Descrição: %s\n", cadastro[j].desc);
                        printf(" Status: Pendente\n");
                        printf("\n");
                    }
                }
                break;
            case 3:
                clearScreen();
                printf("\nDigite o código da tarefa que deseja marcar como concluída: ");
                scanf("%d", &opcao);
                for (int j = 0; j < i; j++) {
                    if (cadastro[j].id == opcao) {
                        cadastro[j].status = 2;
                    }
                }
                break;
            case 4:
                clearScreen();
                printf("Saindo do Gerenciador de Tarefas.\n");
                break;
            default:
                clearScreen();
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
