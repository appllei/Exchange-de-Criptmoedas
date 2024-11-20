#ifndef FUNCOES_H
#define FUNCOES_H

#define MAX_USUARIOS 100
#define MAX_CRIPTOMOEDAS 10
#define MAX_EXTRATO_SIZE 1000
#define MAX_NOME_CRIPTO 50
#define CPF_SIZE 12  // Definição do tamanho do CPF (sem contar o '\0')

// Estrutura de Usuario com CPF
typedef struct {
    char nome[100];
    char cpf[15];
    double saldoBRL;
    double saldoBitcoin;
    double saldoEthereum;
    double saldoRipple;
    double cotacaoBitcoin;
    double cotacaoEthereum;
    double cotacaoRipple;
    char extrato[MAX_EXTRATO_SIZE];
} Usuario;


typedef struct {
    char nome[MAX_NOME_CRIPTO];
    double cotacaoAtual;
    double taxaCompra;
    double taxaVenda;
} Criptomoeda;

typedef struct {
    double cotacoes[MAX_CRIPTOMOEDAS];
} Cotacoes;

// Declaração das funções para gerenciar usuários
int carregarUsuarios(Usuario usuarios[]);
int salvarUsuarios(Usuario usuarios[], int qtdUsuarios);
int cadastrarUsuario(Usuario usuarios[], int *qtdUsuarios);
int efetuarLogin(Usuario usuarios[], int qtdUsuarios);
void excluirUsuario(Usuario usuarios[], int *qtdUsuarios);
void consultarSaldo(const Usuario *usuario);
void consultarExtrato(const Usuario *usuario);
void depositarBRL(Usuario *usuario);
void sacarBRL(Usuario *usuario);

// Declaração das funções para gerenciar criptomoedas
int carregarCriptomoedas(Criptomoeda criptomoedas[]);
int salvarCriptomoedas(Criptomoeda criptomoedas[], int qtdCriptomoedas);
void cadastrarCriptomoeda(Criptomoeda criptomoedas[], int *qtdCriptomoedas);
void excluirCriptomoeda(Criptomoeda criptomoedas[], int *qtdCriptomoedas);
void inicializarCotacoes(Cotacoes *cotacoes);
void atualizarCotacoes(Criptomoeda criptomoedas[], int qtdCriptomoedas);
void comprarCriptomoeda(Usuario *usuario, Criptomoeda criptomoedas[], int qtdCriptomoedas);
void venderCriptomoeda(Usuario *usuario, Criptomoeda criptomoedas[], int qtdCriptomoedas);

#endif
