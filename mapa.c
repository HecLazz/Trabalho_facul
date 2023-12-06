/*
Aluno: Hector Lazzari
Curso: Engenharia de Software
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

// Struct do cliente
typedef struct{
    char nome[100];
    char cpf[50];
    int setor;
}pessoa;

// Cadastro do cliente
pessoa cad_cliente(pessoa *cad, int *numAtendimento){
    system("cls");
    printf("Opção - Solicitar Atendimento\n");
    printf("Digite seu nome: ");
    fflush(stdin);
    fgets(cad[*numAtendimento].nome, 100, stdin);

    printf("Digite seu CPF: ");
    fflush(stdin);
    fgets(cad[*numAtendimento].cpf, 50, stdin);

    printf("Digite uma das opções de atendimento\n");
    printf("1 - Abertura de Conta\n");
    printf("2 - Caixa\n");
    printf("3 - Gerente Pessoa Física\n");
    printf("4 - Gerente Pessoa Jurídica\n");
    fflush(stdin);
    scanf("%d", &cad[*numAtendimento].setor);

    
    (*numAtendimento)++;
    return cad[*numAtendimento];
}

// Listar todos os clientes registrados
void imprimirPessoa(pessoa *atendimento, int *numAtendimento){
    system("cls");
    int i = 0;
    for(i = 0; i < *numAtendimento; i++){
      printf("Nome: %s", atendimento[i].nome);
      printf("CPF: %s", atendimento[i].cpf);
      printf("Tipo de atendimento: ");

      switch(atendimento[i].setor){
        case 1:
            printf("Abertura de conta\n");
        break;
        case 2:
            printf("Caixa\n");
        break;
        case 3:
            printf("Gerente Pessoa Física\n");
        break;
        case 4:
            printf("Gerente Pessoa Jurídica\n");
        break;
        default:
            printf("Escolha uma das opções...");
      }
      printf("=====================================================\n");
    }
}

// Listar clientes com filtro em qual atendimento o usuário preencher.
void listarPeloTipo(pessoa *atendimento, int *numAtendimento){
    system("cls");
    int op;
    int tipo_atendimento = 0;
    printf("Digite uma das opções de atendimento: \n");
    printf("1 - Abertura de Conta\n");
    printf("2 - Caixa\n");
    printf("3 - Gerente Pessoa Física\n");
    printf("4 - Gerente Pessoa Jurídica\n");
    scanf("%d", &op);
    fflush(stdin);

    switch(op){
        case 1:
            printf("Abertura de conta\n");
        break;
        case 2:
            printf("Caixa\n");
        break;
        case 3:
            printf("Gerente Pessoa Física\n");
        break;
        case 4:
            printf("Gerente Pessoa Jurídica\n");
        break;
        default:
            printf("Escolha uma das opções...");
    }

    tipo_atendimento = op;

    int i = 0;
    for(i = 0; i < *numAtendimento; i++){
        if (atendimento[i].setor == tipo_atendimento){
            printf("Nome: %s", atendimento[i].nome);
            printf("CPF: %s", atendimento[i].cpf);
            printf("Tipo de atendimento: ");

            switch(atendimento[i].setor){
                case 1:
                    printf("Abertura de conta\n");
                break;
                case 2:
                    printf("Caixa\n");
                break;
                case 3:
                    printf("Gerente Pessoa Física\n");
                break;
                case 4:
                    printf("Gerente Pessoa Jurídica\n");
                break;
                default:
                    printf("Escolha uma das opções...");
            }
            printf("=====================================================\n");
        }
    }
}

// Corpo principal do algoritmo, onde tem as chamadas das funções.
int main(){
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    pessoa p[999];
    int op = 0;
    int numAtendimento;

    printf("Bem-vindo ao atendimento eletrônico\n");
    do{
        printf("Digite uma das opções\n");
        printf("1 - Solicitar Atendimento\n");
        printf("2 - Listar Atendimento Registrados\n");
        printf("3 - Listar Atendimento por setor\n");
        printf("4 - Sair\n");
        fflush(stdin);
        scanf("%d", &op);
        
        switch (op){
        case 1:
            cad_cliente(p, &numAtendimento);
            break;
        case 2:
            printf("Listagem de Atendimentos\n");
            imprimirPessoa(p, &numAtendimento);
            
            break;
        case 3:

            listarPeloTipo(p, &numAtendimento);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Escolhar uma das opções listadas\n");
            break;

        }
    }while (op != 4);    

    return 0;
}