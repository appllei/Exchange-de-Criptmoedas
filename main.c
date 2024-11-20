#include <stdio.h>
#include <string.h>
#include "funcoes.h"

int main() {
    Usuario usuarios[MAX_USUARIOS];
    Criptomoeda criptomoedas[MAX_CRIPTOMOEDAS];
    Cotacoes cotacoes;
    int qtdUsuarios = carregarUsuarios(usuarios);
    int qtdCriptomoedas = carregarCriptomoedas(criptomoedas);

    inicializarCotacoes(&cotacoes);

    if (qtdUsuarios == 0) {
        printf("Nenhum usuário encontrado. Cadastre um novo usuário.\n");
        if (cadastrarUsuario(usuarios, &qtdUsuarios) != 0) {
            printf("Falha no cadastro. Encerrando o programa.\n");
            return 0;
        }
    }

    int userIndex = -1;
    while (userIndex == -1) {
        userIndex = efetuarLogin(usuarios, qtdUsuarios);
        if (userIndex == -1) {
            printf("Deseja cadastrar um novo usuário? (1 - Sim, 0 - Não): ");
            int escolha;
            scanf("%d", &escolha);
            if (escolha == 1) {
                cadastrarUsuario(usuarios, &qtdUsuarios);
            } else {
                printf("Sessão finalizada.\n");
                return 0;
            }
        }
    }

    int opcao;
    do {
        printf("\nMenu Principal\n");
        printf("1. Consultar Saldo\n");
        printf("2. Consultar Extrato\n");
        printf("3. Depositar R$\n");
        printf("4. Sacar R$\n");
        printf("5. Comprar Criptomoeda\n");
        printf("6. Vender Criptomoeda\n");
        printf("7. Atualizar Cotações\n");
        printf("8. Cadastrar Criptomoeda\n");
        printf("9. Excluir Criptomoeda\n");
        printf("10. Excluir Usuário\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                consultarSaldos(&usuarios[userIndex]);
                break;
            case 2:
                consultarExtrato(&usuarios[userIndex]);
                break;
            case 3:
                depositarBRL(&usuarios[userIndex]);
                salvarUsuarios(usuarios, qtdUsuarios);
                break;
            case 4:
                sacarBRL(&usuarios[userIndex]);
                salvarUsuarios(usuarios, qtdUsuarios);
                break;
            case 5:
                comprarCriptomoeda(&usuarios[userIndex], criptomoedas, qtdCriptomoedas);
                salvarUsuarios(usuarios, qtdUsuarios);
                break;
            case 6:
                venderCriptomoeda(&usuarios[userIndex], criptomoedas, qtdCriptomoedas);
                salvarUsuarios(usuarios, qtdUsuarios);
                break;
            case 7:
                atualizarCotacoes(criptomoedas, qtdCriptomoedas);
                salvarCriptomoedas(criptomoedas, qtdCriptomoedas);
                break;
            case 8:
                cadastrarCriptomoeda(criptomoedas, &qtdCriptomoedas);
                salvarCriptomoedas(criptomoedas, qtdCriptomoedas);
                break;
            case 9:
                excluirCriptomoeda(criptomoedas, &qtdCriptomoedas);
                salvarCriptomoedas(criptomoedas, qtdCriptomoedas);
                break;
            case 10:
                excluirUsuario(usuarios, &qtdUsuarios);
                salvarUsuarios(usuarios, qtdUsuarios);
                break;
            case 0:
                printf("Sessão finalizada.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    salvarUsuarios(usuarios, qtdUsuarios);
    salvarCriptomoedas(criptomoedas, qtdCriptomoedas);
    return 0;
}
