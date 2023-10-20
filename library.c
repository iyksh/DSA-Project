#include "library.h"
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>

int tamanho_TFunc() {
    return sizeof(int)  //cod
           + sizeof(char) * 50 //nome
           + sizeof(char) * 15 //cpf
           + sizeof(char) * 11 //data_nascimento
           + sizeof(double); //salario
}

int tamanho_TEdit(){
    return sizeof(char)*50; //Nome

}

int tamaho_TLivro(){
    return sizeof(int) //cod
        + sizeof(char) * 50 //nome
        + sizeof(char) * 11 //data_lançamento
        + tamanho_TEdit(); //Editora do livro
}

//---------------------------------------*--------------------------------------

// Cria funcionario. 
TFunc *newFuncionario(int cod, char *nome, char *cpf, char *data_nascimento, double salario) {
    TFunc *func = (TFunc *) malloc(sizeof(TFunc)); //inicializa espaco de memoria com ZEROS

    if (func) memset(func, 0, sizeof(TFunc));
    func->cod = cod;        //copia valores para os campos de func
    strcpy(func->nome, nome);
    strcpy(func->cpf, cpf);
    strcpy(func->data_nascimento, data_nascimento);
    func->salario = salario;
    return func;
}


//---------------------------------------*--------------------------------------


// Salva funcionario no arquivo out, na posicao atual do cursor
void salvaFunc(TFunc *func, FILE *out) {
    fwrite(&func->cod, sizeof(int), 1, out);
    //func->nome ao inves de &func->nome, pois string ja eh um ponteiro
    fwrite(func->nome, sizeof(char), sizeof(func->nome), out);
    fwrite(func->cpf, sizeof(char), sizeof(func->cpf), out);
    fwrite(func->data_nascimento, sizeof(char), sizeof(func->data_nascimento), out);
    fwrite(&func->salario, sizeof(double), 1, out);
}

//---------------------------------------*--------------------------------------


// Le um funcionario do arquivo in na posicao atual do cursor
// Retorna um ponteiro para funcionario lido do arquivo
TFunc *leFunc(FILE *in) {
    TFunc *func = (TFunc *) malloc(sizeof(TFunc));
    if (0 >= fread(&func->cod, sizeof(int), 1, in)) {
        free(func);
        return NULL;
    }
    fread(func->nome, sizeof(char), sizeof(func->nome), in);
    fread(func->cpf, sizeof(char), sizeof(func->cpf), in);
    fread(func->data_nascimento, sizeof(char), sizeof(func->data_nascimento), in);
    fread(&func->salario, sizeof(double), 1, in);
    return func;
}

//---------------------------------------*--------------------------------------


// Imprime funcionario
void imprimeFunc(TFunc *func) {
    printf("**********************************************");
    printf("\nFuncionario de codigo ");
    printf("%d", func->cod);
    printf("\nNome: ");
    printf("%s", func->nome);
    printf("\nCPF: ");
    printf("%s", func->cpf);
    printf("\nData de Nascimento: ");
    printf("%s", func->data_nascimento);
    printf("\nSalario: ");
    printf("%4.2f", func->salario);
    printf("\n**********************************************");
}

void sistemaBiblioteca(FILE *arquivoFuncionarios){
int opcao;
int funcionaryCode;
double funcionarySalary;
char funcionaryName[50], funcionaryBirthday[11], cpf[15];

    while (1) {
        printf("Selecione uma opção:\n");
        printf("1 - Novo Funcionário\n");
        printf("2 - Novo Livro\n");
        printf("3 - Nova Editora\n");
        printf("8 - Imprimir Funcionário\n");
        printf("9 - Imprimir Livro\n");
        printf("10 - Imprimir Editora\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("\nInsira o codigo do funcionario: "); scanf("%d", &funcionaryCode);
                printf("\nInsira o salario do funcionario: "); scanf("%lf", &funcionarySalary);
                printf("\nInsira o nome do funcionario: "); scanf("%s", &funcionaryName);
                printf("\nInsira a data de nascimento do funcionario: "); scanf("%s", &funcionaryBirthday);
                printf("\nInsira o CPF do funcionario: "); scanf("%s", &cpf);
                
                TFunc *temp = newFuncionario(funcionaryCode, funcionaryName, cpf, funcionaryBirthday, funcionarySalary);
                salvaFunc(temp, arquivoFuncionarios);
                break;
            case 2:
                // Código para criar um novo livro
                break;
            case 3:
                // Código para criar uma nova editora
                break;
            case 4:
                // Código para salvar um funcionário em um arquivo
                break;
            case 5:
                // Código para salvar um livro em um arquivo
                break;
            case 6:
                // Código para salvar uma editora em um arquivo
                break;
            case 7:
                // Código para ler um funcionário de um arquivo
                break;
            case 8:
                // Código para ler um livro de um arquivo
                break;
            case 9:
                // Código para ler uma editora de um arquivo
                break;
            case 10:
                // Código para imprimir um funcionário
                break;
            case 11:
                // Código para imprimir um livro
                break;
            case 12:
                // Código para imprimir uma editora
                break;
            case 0:
                printf("Saindo...\n");
                return;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    }




}