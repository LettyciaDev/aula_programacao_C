#include <stdio.h>
#include <string.h>

#define TAM 100
#define TAM_NOME 50
#define TAM_CPF 15
#define TAM_TELEFONE 15

struct Conta {
    int numero;
    char nome[TAM_NOME];
    char cpf[TAM_CPF];
    char telefone[TAM_TELEFONE];
    float saldo;
};


int buscarConta(struct Conta contas[], int qtd, int numero);
void cadastrarConta(struct Conta contas[], int *qtd, int numero);
void consultarSaldo(struct Conta contas[], int qtd, int numero);
void depositar(struct Conta contas[], int qtd, int numero);
void sacar(struct Conta contas[], int qtd, int numero);
void exibirContas(struct Conta contas[], int qtd);

int main() {
    struct Conta contas[TAM];
    int qtd = 0; 
    int escolha, numero;

    do {
        printf("\nBanco Dinheiro Certo\n");
        printf("1. Cadastrar conta\n");
        printf("2. Consultar saldo\n");
        printf("3. Depositar\n");
        printf("4. Sacar\n");
        printf("5. Exibir contas\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o número da conta: ");
                scanf("%d", &numero);
                cadastrarConta(contas, &qtd, numero);
                break;
            case 2:
                printf("Digite o número da conta para consultar saldo: ");
                scanf("%d", &numero);
                consultarSaldo(contas, qtd, numero);
                break;
            case 3:
                printf("Digite o número da conta para depósito: ");
                scanf("%d", &numero);
                depositar(contas, qtd, numero);
                break;
            case 4:
                printf("Digite o número da conta para saque: ");
                scanf("%d", &numero);
                sacar(contas, qtd, numero);
                break;
            case 5:
                exibirContas(contas, qtd);
                break;
            case 6:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (escolha != 6);

    return 0;
}


int buscarConta(struct Conta contas[], int qtd, int numero) {
    if (qtd == 0) {
        return -1; 
    }
    for (int i = 0; i < qtd; i++) {
        if (contas[i].numero == numero) {
            return i; 
        }
    }
    return -2; 
}

void cadastrarConta(struct Conta contas[], int *qtd, int numero) {
    if (*qtd >= TAM) {
        printf("Limite de contas atingido!\n");
        return;
    }

    if (buscarConta(contas, *qtd, numero) >= 0) {
        printf("Número de conta já cadastrado!\n");
        return;
    }

    contas[*qtd].numero = numero;
    printf("Digite o nome do titular: ");
    getchar(); 
    fgets(contas[*qtd].nome, TAM_NOME, stdin);
    contas[*qtd].nome[strcspn(contas[*qtd].nome, "\n")] = 0; 
    printf("Digite o CPF do titular: ");
    fgets(contas[*qtd].cpf, TAM_CPF, stdin);
    contas[*qtd].cpf[strcspn(contas[*qtd].cpf, "\n")] = 0; 
    printf("Digite o telefone de contato: ");
    fgets(contas[*qtd].telefone, TAM_TELEFONE, stdin);
    contas[*qtd].telefone[strcspn(contas[*qtd].telefone, "\n")] = 0; 
    contas[*qtd].saldo = 0.0; 

    (*qtd)++;
    printf("Conta cadastrada com sucesso!\n");
}

void consultarSaldo(struct Conta contas[], int qtd, int numero) {
    int pos = buscarConta(contas, qtd, numero);
    if (pos == -1) {
        printf("Cadastro vazio!\n");
    } else if (pos == -2) {
        printf("Conta não encontrada!\n");
    } else {
        printf("Saldo da conta %d: R$ %.2f\n", contas[pos].numero, contas[pos].saldo);
    }
}

void depositar(struct Conta contas[], int qtd, int numero) {
    int pos = buscarConta(contas, qtd, numero);
    if (pos == -1) {
        printf("Cadastro vazio!\n");
    } else if (pos == -2) {
        printf("Conta não encontrada!\n");
    } else {
        float valor;
        printf("Digite o valor para depósito: ");
        scanf("%f", &valor);
        if (valor <= 0) {
            printf("Valor inválido!\n");
        } else {
            contas[pos].saldo += valor;
            printf("Depósito efetuado. Saldo atual: R$ %.2f\n", contas[pos].saldo);
        }
    }
}

void sacar(struct Conta contas[], int qtd, int numero) {
    int pos = buscarConta(contas, qtd, numero);
    if (pos == -1) {
        printf("Cadastro vazio!\n");
    } else if (pos == -2) {
        printf("Conta não encontrada!\n");
    } else {
        float valor;
        printf("Digite o valor para saque: ");
        scanf("%f", &valor);
        if (valor <= 0) {
            printf("Valor inválido!\n");
        } else if (valor > contas[pos].saldo) {
            printf("Saldo insuficiente!\n");
        } else {
            contas[pos].saldo -= valor;
            printf("Saque efetuado. Saldo atual: R$ %.2f\n", contas[pos].saldo);
        }
    }
}

void exibirContas(struct Conta contas[], int qtd) {
    if (qtd == 0) {
        printf("Nenhuma conta cadastrada.\n");
        return;
    }
    printf("\nContas cadastradas:\n");
    for (int i = 0; i < qtd; i++) {
        printf("Número da conta: %d, Titular: %s, Telefone: %s\n",
               contas[i].numero, contas[i].nome, contas[i].telefone);
    }
}

/*
1
1001
João da Silva
123.456.789-00
(11) 98765-4321
1
1002
Maria Oliveira
234.567.890-01
(21) 99876-5432
5
2
1001
3
1001
500
2
1001
4
1001
200
6
*/