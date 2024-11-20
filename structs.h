#ifndef STRUCTS_H
#define STRUCTS_H

#define MAX_USUARIOS 100
#define MAX_CRIPTOMOEDAS 50
#define MAX_NOME_CRIPTO 50
#define CPF_SIZE 15

// Estrutura para armazenar informações de um usuário
typedef struct {
    char nome[50];
    char cpf[CPF_SIZE];
    double saldoBRL;
    char extrato[500];
} Usuario;

// Estrutura para armazenar informações de uma criptomoeda
typedef struct {
    char nome[50];
    double cotacaoAtual;
    double taxaCompra;
    double taxaVenda;
} Criptomoeda;

// Estrutura para armazenar as cotações de moedas
typedef struct {
    double brl;
    double bitcoin;
} Cotacoes;

#endif
