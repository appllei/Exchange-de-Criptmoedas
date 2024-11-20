#include "funcoes.h"
#include <stdio.h>
#include <string.h>

// Funções para gerenciar usuários
int carregarUsuarios(Usuario usuarios[]) {
    // Implementar a lógica de carregar usuários
    return 0; // Retornar quantidade de usuários
}

int salvarUsuarios(Usuario usuarios[], int qtdUsuarios) {
    // Implementar a lógica de salvar os usuários
    return 0;
}

int cadastrarUsuario(Usuario usuarios[], int *qtdUsuarios) {
    // Implementar a lógica de cadastro de usuário
    return 0;
}

int efetuarLogin(Usuario usuarios[], int qtdUsuarios) {
    // Implementar a lógica de login
    return 0;
}

void consultarSaldos(Usuario *usuario) {
    // Exibe os saldos de cada criptomoeda
    printf("\nSaldo da Carteira de %s:\n", usuario->nome);
    printf("R$: %.2lf\n", usuario->saldoBRL);  // Saldo total em Reais
    printf("Bitcoin: %.6lf (R$ %.2lf)\n", usuario->saldoBitcoin, usuario->saldoBitcoin * usuario->cotacaoBitcoin);  // Saldo em Bitcoin
    printf("Ethereum: %.6lf (R$ %.2lf)\n", usuario->saldoEthereum, usuario->saldoEthereum * usuario->cotacaoEthereum);  // Saldo em Ethereum
    printf("Ripple: %.6lf (R$ %.2lf)\n", usuario->saldoRipple, usuario->saldoRipple * usuario->cotacaoRipple);  // Saldo em Ripple

    // Exibe o valor total das criptomoedas em Reais
    double totalEmReais = usuario->saldoBitcoin * usuario->cotacaoBitcoin +
                          usuario->saldoEthereum * usuario->cotacaoEthereum +
                          usuario->saldoRipple * usuario->cotacaoRipple;
    printf("Valor total das criptomoedas em Reais: R$ %.2lf\n", totalEmReais);
}

void consultarExtrato(const Usuario *usuario) {
    printf("Extrato: %s\n", usuario-> extrato);
}

void depositarBRL(Usuario *usuario) {
    double valor;
    printf("Valor a depositar: ");
    scanf("%lf", &valor);
    usuario->saldoBRL += valor;
    printf("Depósito realizado com sucesso.\n");
}

void sacarBRL(Usuario *usuario) {
    double valor;
    printf("Valor a sacar: ");
    scanf("%lf", &valor);
    if (usuario->saldoBRL >= valor) {
        usuario->saldoBRL -= valor;
        printf("Saque realizado com sucesso.\n");
    } else {
        printf("Saldo insuficiente.\n");
    }
}

void excluirUsuario(Usuario usuarios[], int *qtdUsuarios) {
    char cpf[CPF_SIZE];  // Usa CPF_SIZE para definir o tamanho do CPF
    printf("Informe o CPF do usuário a ser excluído: ");
    scanf("%s", cpf);  // Lê o CPF do usuário

    for (int i = 0; i < *qtdUsuarios; i++) {
        // Verifica se o CPF do usuário coincide com o informado
        if (strcmp(usuarios[i].cpf, cpf) == 0) {
            printf("Usuário encontrado: %s\n", usuarios[i].nome);
            printf("Confirmar exclusão? (1 - Sim, 0 - Não): ");
            int confirmacao;
            scanf("%d", &confirmacao);

            if (confirmacao == 1) {
                // Move todos os usuários para a posição anterior
                for (int j = i; j < (*qtdUsuarios) - 1; j++) {
                    usuarios[j] = usuarios[j + 1];
                }
                (*qtdUsuarios)--;  // Decrementa o número de usuários
                printf("Usuário excluído com sucesso!\n");
                return;
            } else {
                printf("Operação cancelada.\n");
                return;
            }
        }
    }
    printf("Usuário não encontrado.\n");
}


// Funções para gerenciar criptomoedas
int carregarCriptomoedas(Criptomoeda criptomoedas[]) {
    // Implementar a lógica de carregar criptomoedas
    return 0; // Retornar quantidade de criptomoedas
}

int salvarCriptomoedas(Criptomoeda criptomoedas[], int qtdCriptomoedas) {
    // Implementar a lógica de salvar as criptomoedas
    return 0;
}

void cadastrarCriptomoeda(Criptomoeda criptomoedas[], int *qtdCriptomoedas) {
    if (*qtdCriptomoedas >= MAX_CRIPTOMOEDAS) {
        printf("Limite máximo de criptomoedas atingido.\n");
        return;
    }

    Criptomoeda novaCriptomoeda;
    printf("Nome da criptomoeda: ");
    scanf("%s", novaCriptomoeda.nome);
    printf("Cotação inicial: ");
    scanf("%lf", &novaCriptomoeda.cotacaoAtual);
    printf("Taxa de compra (em %%): ");
    scanf("%lf", &novaCriptomoeda.taxaCompra);
    printf("Taxa de venda (em %%): ");
    scanf("%lf", &novaCriptomoeda.taxaVenda);

    criptomoedas[*qtdCriptomoedas] = novaCriptomoeda;
    (*qtdCriptomoedas)++;
    printf("Criptomoeda cadastrada com sucesso!\n");
}

void excluirCriptomoeda(Criptomoeda criptomoedas[], int *qtdCriptomoedas) {
    char nome[MAX_NOME_CRIPTO];
    printf("Informe o nome da criptomoeda a ser excluída: ");
    scanf("%s", nome);

    for (int i = 0; i < *qtdCriptomoedas; i++) {
        if (strcmp(criptomoedas[i].nome, nome) == 0) {
            printf("Criptomoeda encontrada: %s\n", criptomoedas[i].nome);
            printf("Confirmar exclusão? (1 - Sim, 0 - Não): ");
            int confirmacao;
            scanf("%d", &confirmacao);

            if (confirmacao == 1) {
                for (int j = i; j < (*qtdCriptomoedas) - 1; j++) {
                    criptomoedas[j] = criptomoedas[j + 1];
                }
                (*qtdCriptomoedas)--;
                printf("Criptomoeda excluída com sucesso!\n");
                return;
            } else {
                printf("Operação cancelada.\n");
                return;
            }
        }
    }
    printf("Criptomoeda não encontrada.\n");
}

void inicializarCotacoes(Cotacoes *cotacoes) {
    cotacoes->cotacoes[0] = 1.0;
    cotacoes->cotacoes[1] = 2.0;
    cotacoes->cotacoes[2] = 3.0;
}

void atualizarCotacoes(Criptomoeda criptomoedas[], int qtdCriptomoedas) {
    // Lógica para atualizar as cotações das criptomoedas
    for (int i = 0; i < qtdCriptomoedas; i++) {
        criptomoedas[i].cotacaoAtual *= 1.05; // Exemplo de aumento de 5%
    }
    printf("Cotações atualizadas!\n");
}

void comprarCriptomoeda(Usuario *usuario, Criptomoeda criptomoedas[], int qtdCriptomoedas) {
    // Lógica de compra de criptomoeda
}

void venderCriptomoeda(Usuario *usuario, Criptomoeda criptomoedas[], int qtdCriptomoedas) {
    // Lógica de venda de criptomoeda
}
