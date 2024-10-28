#include <stdio.h>
#include <string.h>

#define TAM 40

struct Produto{
    int codigo;
    char descricao[100];
    float valor_unitario;
    int quantidade_estoque;
};

struct Produto produtos[TAM];
void cadastrarProduto();
void alterarValorUnitario(int codigo);
float obterValorUnitario(int codigo);
int obterQuantidadeEstoque(int codigo);
void realizarVenda(int codigo, int quantidade_desejada);
void atualizarQuantidadeEstoque(int codigo);
void exibirProdutos();
void exibirProdutosEstoqueZero();


int main() {
    int opcao, codigo, quantidade;

    do {
        printf("\n1. Cadastrar Produto\n2.Alterar Valor Unitário\n3. Consultar Valor Unitário\n4. Consultar Quantidade em Estoque\n5. Realizar Venda\n6. Atualizar Estoque\n7. Exibir Produtos\n8. Exibir Produtos com Estoque Zero\n9. Sair\nEscolha uma opção: ");

        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                printf("Digite o código do produto: ");
                scanf("%d", &codigo);
                alterarValorUnitario(codigo);
                break;
            case 3:
                printf("Digite o código do produto: ");
                scanf("%d", &codigo);
                float valor = obterValorUnitario(codigo);
                if (valor != -1)
                    printf("Valor unitário: %.2f\n", valor);
                else
                    printf("Produto não encontrado!\n");
                break;
            case 4:
                printf("Digite o código do produto: ");
                scanf("%d", &codigo);
                int estoque = obterQuantidadeEstoque(codigo);
                if (estoque != -1)
                    printf("Quantidade em estoque: %d\n", estoque);
                else
                    printf("Produto não encontrado!\n");
                break;
            case 5:
                printf("Digite o código do produto: ");
                scanf("%d", &codigo);
                printf("Digite a quantidade desejada: ");
                scanf("%d", &quantidade);
                realizarVenda(codigo, quantidade);
                break;
            case 6:
                printf("Digite o código do produto: ");
                scanf("%d", &codigo);
                atualizarQuantidadeEstoque(codigo);
                break;
            case 7:
                exibirProdutos();
                break;
            case 8:
                exibirProdutosEstoqueZero();
                break;
            case 9:
                printf("Sair\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 9);

    return 0;
}

int total_produtos = 0;

void cadastrarProduto() {
    if (total_produtos >= TAM) {
        printf("Limite de produtos atingido!\n");
        return;
    }
    
    struct Produto p;
    printf("Digite o código do produto: ");
    scanf("%d", &p.codigo);
    printf("Digite a descrição do produto: ");
    scanf(" %[^\n]", p.descricao);
    printf("Digite o valor unitário do produto: ");
    scanf("%f", &p.valor_unitario);
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &p.quantidade_estoque);
    
    produtos[total_produtos] = p;
    total_produtos++;
    printf("Produto cadastrado com sucesso!\n");
}

void alterarValorUnitario(int codigo) {
    for (int i = 0; i < total_produtos; i++) {
        if (produtos[i].codigo == codigo) {
            printf("Digite o novo valor unitário: ");
            scanf("%f", &produtos[i].valor_unitario);
            printf("Valor unitário atualizado!\n");
            return;
        }
    }
    printf("Produto não encontrado!\n");
}

float obterValorUnitario(int codigo) {
    for (int i = 0; i < total_produtos; i++) {
        if (produtos[i].codigo == codigo) {
            return produtos[i].valor_unitario;
        }
    }
    return -1;
}

int obterQuantidadeEstoque(int codigo) {
    for (int i = 0; i < total_produtos; i++) {
        if (produtos[i].codigo == codigo) {
            return produtos[i].quantidade_estoque;
        }
    }
    return -1; 
}

void realizarVenda(int codigo, int quantidade_desejada) {
    for (int i = 0; i < total_produtos; i++) {
        if (produtos[i].codigo == codigo) {
            if (produtos[i].quantidade_estoque == 0) {
                printf("Produto sem estoque!\n");
                return;
            } else if (produtos[i].quantidade_estoque < quantidade_desejada) {
                char confirmar;
                printf("Estoque insuficiente. Deseja comprar toda a quantidade disponível (%d unidades)? (s/n): ", produtos[i].quantidade_estoque);
                scanf(" %c", &confirmar);
                if (confirmar == 's') {
                    float valor_total = produtos[i].quantidade_estoque * produtos[i].valor_unitario;
                    printf("Compra efetuada. Valor a pagar: %.2f\n", valor_total);
                    produtos[i].quantidade_estoque = 0;
                }
            } else {
                produtos[i].quantidade_estoque -= quantidade_desejada;
                float valor_total = quantidade_desejada * produtos[i].valor_unitario;
                printf("Compra efetuada. Valor a pagar: %.2f\n", valor_total);
            }
            return;
        }
    }
    printf("Produto não encontrado!\n");
}

void atualizarQuantidadeEstoque(int codigo) {
    for (int i = 0; i < total_produtos; i++) {
        if (produtos[i].codigo == codigo) {
            printf("Digite a nova quantidade em estoque: ");
            scanf("%d", &produtos[i].quantidade_estoque);
            printf("Quantidade em estoque atualizada!\n");
            return;
        }
    }
    printf("Produto não encontrado!\n");
}

void exibirProdutos() {
    for (int i = 0; i < total_produtos; i++) {
        printf("Código: %d | Descrição: %s\n", produtos[i].codigo, produtos[i].descricao);
    }
}

void exibirProdutosEstoqueZero() {
    int encontrou = 0;
    for (int i = 0; i < total_produtos; i++) {
        if (produtos[i].quantidade_estoque == 0) {
            printf("Código: %d | Descrição: %s\n", produtos[i].codigo, produtos[i].descricao);
            encontrou = 1;
        }
    }
    if (!encontrou) {
        printf("Nenhum produto com estoque zero.\n");
    }
}

/*1
101
Caderno
15.50
30

1
102
Caneta
2.00
100

3
101

4
102

5
102
50

6
101
25

7

8

9
*/
