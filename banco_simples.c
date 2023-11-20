#include <stdio.h>
#include <string.h>

struct acc {
    int id, numag;
    char nome[20], numconta[20];
    float saldo;
};

// Função para encontrar a conta no cadastro
int encontrarConta(struct acc* cadastro, int tamanho, int tipoBusca, void* valorBusca) {
    for (int j = 0; j < tamanho; j++) {
        switch (tipoBusca) {
            case 1:  // Buscar por número da conta
                if (strcmp(cadastro[j].numconta, (char*)valorBusca) == 0) {
                    return j; // Retorna o índice da conta no cadastro
                }
                break;

            case 2:  // Buscar por número da agência
                if (cadastro[j].numag == *((int*)valorBusca)) {
                    return j; // Retorna o índice da conta no cadastro
                }
                break;

            case 3:  // Buscar por ID
                if (cadastro[j].id == *((int*)valorBusca)) {
                    return j; // Retorna o índice da conta no cadastro
                }
                break;
        }
    }

    return -1; // Retorna -1 se a conta não for encontrada
}

int main(void) {
    int opcao, i = 0;

    struct acc cadastro[100];

    printf("Bem vindo ao Sistema Banco Nengue\n");

    do {
        printf("1. Realizar saque\n");
        printf("2. Realizar depósito\n");
        printf("3. Transferencia Pix\n");
        printf("4. Cadastrar novo cliente\n");
        printf("5. Transferencia entre contas\n");
        printf("6. Consulta de saldo\n");
        printf("7. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        int indiceConta; // Variável para armazenar o índice da conta no cadastro

        switch (opcao) {
            case 1:
                // Saque
                printf("\nDigite o Numero da conta: ");
                scanf("%s", cadastro[i].numconta);
                printf("\nDigite o numero da agencia: ");
                scanf("%d", &cadastro[i].numag);
                printf("\nSistema de Saque\n");

                char numContaSaque[20];
                strcpy(numContaSaque, cadastro[i].numconta);

                indiceConta = encontrarConta(cadastro, i, 1, numContaSaque);

                if (indiceConta != -1) {
                    float saque;
                    printf("\n Valor a ser sacado: ");
                    scanf("%f", &saque);
                    cadastro[indiceConta].saldo -= saque;
                    printf("%f", cadastro[indiceConta].saldo);
                } else {
                    printf("Conta não encontrada.\n");
                }
                break;

            case 2:
                // Depósito
                printf("\nDigite o Numero da conta: ");
                scanf("%s", cadastro[i].numconta);
                printf("\nDigite o numero da agencia: ");
                scanf("%d", &cadastro[i].numag);
                printf("\nSistema de Depósito\n");

                int numAgDeposito;
                strcpy(numContaSaque, cadastro[i].numconta);

                indiceConta = encontrarConta(cadastro, i, 1, numContaSaque);

                if (indiceConta != -1) {
                    float deposito;
                    printf("\n Valor a ser Depositado: ");
                    scanf("%f", &deposito);
                    cadastro[indiceConta].saldo += deposito;
                    printf("\n");
                    printf("%f", cadastro[indiceConta].saldo);
                } else {
                    printf("Conta não encontrada.\n");
                }
                break;

            case 3:
                // Transferencia Pix
                printf("\nSistema de Transferencia Pix\n");
                printf("\nDigite o ID da conta emitente: ");
                int idEmitente;
                scanf("%d", &idEmitente);

                int contaEmitenteEncontrada = 0;
                int indexContaEmitente = -1;

                // Encontrar a conta emitente no cadastro
                for (int j = 0; j < i; j++) {
                    if (cadastro[j].id == idEmitente) {
                        contaEmitenteEncontrada = 1;
                        indexContaEmitente = j;
                        break;
                    }
                }

                if (!contaEmitenteEncontrada) {
                    printf("\nConta emitente não encontrada.\n");
                    break;
                }

                float transfPix;
                printf("\nDigite o valor a ser transferido: ");
                scanf("%f", &transfPix);

                printf("\nDigite o ID da conta destinatária: ");
                int idDestinatario;
                scanf("%d", &idDestinatario);

                int contaDestinoEncontradaPix = 0;

                // Encontrar a conta destinatária no cadastro
                for (int k = 0; k < i; k++) {
                    if (cadastro[k].id == idDestinatario) {
                        contaDestinoEncontradaPix = 1;
                        cadastro[k].saldo += transfPix;
                        cadastro[indexContaEmitente].saldo -= transfPix;
                        printf("Transferência Pix realizada com sucesso.\n");
                        break;
                    }
                }

                if (!contaDestinoEncontradaPix) {
                    printf("Conta destinatária não encontrada.\n");
                }
                break;

            case 4:
                // Cadastrar novo cliente
                cadastro[i].id = i + 1;
                printf("\nDigite o nome do usuario da conta: \n");
                scanf(" %19[^\n]", cadastro[i].nome);
                printf("\nDigite o numero da agencia: \n");
                scanf(" %d", &cadastro[i].numag);
                printf("\nDigite o numero da conta: ");
                scanf(" %19[^\n]", cadastro[i].numconta);
                printf("\nDigite o Saldo: ");
                scanf(" %f", &cadastro[i].saldo);
                printf("\n");
                i++;
                break;

            case 5:
                // Transferencia entre contas
                  printf("\nSistema de Transferencia\n");
                  printf("\n");
                  printf("\nDigite o Numero da conta emitente: ");
                  scanf("%s", cadastro[i].numconta);
                  printf("\nDigite o numero da agencia emitente: ");
                  scanf("%d", &cadastro[i].numag);

                  // Encontrar a conta emitente no cadastro
                  for (int j = 0; j < i; j++) {
                      if (strcmp(cadastro[j].numconta, cadastro[i].numconta) == 0 &&
                          cadastro[j].numag == cadastro[i].numag) {
                          contaEmitenteEncontrada = 1;
                          indexContaEmitente = j;
                          break;
                      }
                  }

                  if (!contaEmitenteEncontrada) {
                      printf("\nConta emitente não encontrada.\n");
                      break;
                  }

                  float transfConta;
                  printf("\nDigite o valor a ser transferido: ");
                  scanf("%f", &transfConta);

                  printf("\nDigite o numero da agencia Destinataria: ");
                  int numAgDestinatario;
                  scanf("%d", &numAgDestinatario);
                  printf("\nDigite o Numero da conta Destinataria: ");
                  char numContaDestinatario[20];
                  scanf("%s", numContaDestinatario);
                  int contaDestinoEncontradaConta = 0;

                  // Encontrar a conta destinatária no cadastro
                  for (int k = 0; k < i; k++) {
                      if (strcmp(cadastro[k].numconta, numContaDestinatario) == 0 &&
                          cadastro[k].numag == numAgDestinatario) {
                          contaDestinoEncontradaConta = 1;
                          cadastro[k].saldo += transfConta;
                          cadastro[indexContaEmitente].saldo -= transfConta;
                          printf("Transferência entre contas realizada com sucesso.\n");
                          break;
                      }
                  }

                  if (!contaDestinoEncontradaConta) {
                      printf("Conta destinatária não encontrada.\n");
                  }
                break;

            case 6:
                // Consulta de saldo
                printf("\nDigite o Numero da conta: ");
                scanf("%s", cadastro[i].numconta);
                printf("\nDigite o numero da agencia: ");
                scanf("%d", &cadastro[i].numag);

                int contaEncontrada = 0;
                for (int j = 0; j < i; j++) {
                    // Validação de numero de conta e agencia
                    if (strcmp(cadastro[j].numconta, cadastro[i].numconta) == 0 &&
                        cadastro[j].numag == cadastro[i].numag) {
                    //com a validaçao da conta, é impresso na tela as informações e o saldo
                        printf("\nID: %d", cadastro[j].id);
                        printf("\nNome: %s", cadastro[j].nome);
                        printf("\nAgencia: %d", cadastro[j].numag);
                        printf("\nConta: %s", cadastro[j].numconta);
                        printf("\nSaldo: %f\n", cadastro[j].saldo);
                        printf("\n");
                        contaEncontrada = 1;
                        break;
                    }
                }

                if (!contaEncontrada) {
                    printf("\nConta não encontrada.\n");
                }
                break;

            case 7:
                // Sair do programa
                printf("Saindo do programa.\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 7);

    return 0;
}
