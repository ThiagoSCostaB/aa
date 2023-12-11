#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>


struct ContaBancaria {
    int numeroConta;
    char nomeTitular[50];
    double saldo;
    char tipoConta[20];  
};


void deposito(struct ContaBancaria* conta, double valor) {
    if (valor > 0) {
        conta->saldo += valor;
        printf("Depósito de R$ %.2f realizado com sucesso. Saldo atual: R$ %.2f\n", valor, conta->saldo);
    } else {
        printf("Valor de depósito inválido. Tente novamente.\n");
    }
}


void saque(struct ContaBancaria* conta, double valor) {
    if (valor > 0 && valor <= conta->saldo) {
        conta->saldo -= valor;
        printf("Saque de R$ %.2f realizado com sucesso. Saldo atual: R$ %.2f\n", valor, conta->saldo);
    } else {
        printf("Valor de saque inválido ou saldo insuficiente. Tente novamente.\n");
    }
}


void imprimirSaldo(const struct ContaBancaria* conta) {
    printf("Saldo atual da conta: R$ %.2f\n", conta->saldo);
}

int main() {
    struct ContaBancaria minhaConta = {123456, "Joao da Silva", 1000.0, "corrente"};
    int codigo;
    double valor;

    do {
       
        printf("\nMenu:\n");
        printf("1 - Depositar dinheiro\n");
        printf("2 - Sacar dinheiro\n");
        printf("3 - Imprimir saldo\n");
        printf("4 - Sair do programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &codigo);

        switch (codigo) {
            case 1:
                
                printf("Digite o valor a ser depositado: ");
                scanf("%lf", &valor);
                deposito(&minhaConta, valor);
                break;

            case 2:
               
                printf("Digite o valor a ser sacado: ");
                scanf("%lf", &valor);
                saque(&minhaConta, valor);
                break;

            case 3:
                
                imprimirSaldo(&minhaConta);
                break;

            case 4:
               
                printf("Saindo do programa.\n");
                break;

            default:
               
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (codigo != 4);

    return 0;
}
