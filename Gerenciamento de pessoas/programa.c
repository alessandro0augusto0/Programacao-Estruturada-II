/*

Este código foi criado pelo aluno Alessandro Augusto no 3º período do curso de Engenharia de Computação
 * a fim de desenvolver um programa para "Gerenciamento de pessoas".
 * Professor: Lênio Oliveira Prado Júnior
 * Disciplina: Programação Estruturada II

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa {
    int id;
    char nome[50];
    int idade;
    char endereco[100];
    int numero;
    char cidade[50];
    char estado[2];
} Pessoa;

char arquivo[20] = "pessoas.dat";

void inicializar();
void inserir();
void editar();
void remover();
void listar_por_codigo();
void listar_tudo();
void voltar();
void ajuda();
void menu();
void menu_pessoas();
void ler_pessoa(Pessoa *p);
void mostrar_pessoa(Pessoa p);
int validar_estado(char *estado);
int buscar_pessoa(int id, Pessoa *p);
int gerar_id();

int main() {
    menu();
    return 0;
}

void inicializar() {
    char opcao;
    printf("Tem certeza que deseja apagar todos os dados? (S/N)\n");
    scanf(" %c", &opcao);
    if (opcao == 'S' || opcao == 's') {
        FILE *fp = fopen(arquivo, "wb");
        if (fp == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return;
        }
        fclose(fp);
        printf("Todos os dados foram apagados.\n");
    } else {
        printf("Operacao cancelada.\n");
    }
}

void inserir() {
    Pessoa p;
    ler_pessoa(&p);
    p.id = gerar_id();
    FILE *fp = fopen(arquivo, "ab");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fwrite(&p, sizeof(Pessoa), 1, fp);
    fclose(fp);
    printf("Pessoa inserida com sucesso.\n");
}

void editar() {
    int id;
    Pessoa p;
    printf("Digite o id da pessoa que deseja editar:\n");
    scanf("%d", &id);
    if (buscar_pessoa(id, &p) == 0) {
        printf("Pessoa nÃ£o encontrada.\n");
        return;
    }
    printf("Pessoa encontrada:\n");
    mostrar_pessoa(p);
    printf("Digite os novos dados da pessoa:\n");
    ler_pessoa(&p);
    p.id = id;
    FILE *fp = fopen(arquivo, "r+b");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fseek(fp, (id - 1) * sizeof(Pessoa), SEEK_SET);
    fwrite(&p, sizeof(Pessoa), 1, fp);
    fclose(fp);
    printf("Pessoa editada com sucesso.\n");
}

void remover() {
    int id;
    Pessoa p;
    printf("Digite o id da pessoa que deseja remover:\n");
    scanf("%d", &id);
    if (buscar_pessoa(id, &p) == 0) {
        printf("Pessoa nao encontrada.\n");
        return;
    }
    printf("Pessoa encontrada:\n");
    mostrar_pessoa(p);
    char opcao;
    printf("Tem certeza que deseja remover essa pessoa? (S/N)\n");
    scanf(" %c", &opcao);
    if (opcao == 'S' || opcao == 's') {
        p.id = -1;
        FILE *fp = fopen(arquivo, "r+b");
        if (fp == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return;
        }
        fseek(fp, (id - 1) * sizeof(Pessoa), SEEK_SET);
        fwrite(&p, sizeof(Pessoa), 1, fp);
        fclose(fp);
        printf("Pessoa removida com sucesso.\n");
    } else {
        printf("Operacao cancelada.\n");
    }
}

void listar_por_codigo() {
    int id;
    Pessoa p;
    printf("Digite o id da pessoa que deseja listar:\n");
    scanf("%d", &id);
    if (buscar_pessoa(id, &p) == 0) {
        printf("Pessoa nao encontrada.\n");
        return;
    }
    printf("Pessoa encontrada:\n");
    mostrar_pessoa(p);
}

void listar_tudo() {
    FILE *fp = fopen(arquivo, "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    Pessoa p;
    int cont = 0;
    while (fread(&p, sizeof(Pessoa), 1, fp) == 1) {
        if (p.id != -1) {
            mostrar_pessoa(p);
            cont++;
        }
    }
    fclose(fp);
    if (cont == 0) {
        printf("Nenhuma pessoa cadastrada.\n");
    } else {
        printf("%d pessoa(s) cadastrada(s).\n", cont);
    }
}

void voltar() {
    menu();
}

void ajuda() {
    printf("Este eh um programa que gerencia um cadastro de pessoas usando uma estrutura e um arquivo binario.\n\n");
    printf("Voce pode escolher entre as opcoes do menu principal para acessar o menu de gerencia de pessoas ou sair do programa.\n\n");
    printf("No menu de gerencia de pessoas, voce pode inicializar, inserir, editar, remover, listar por codigo ou listar tudo.\n\n");
    printf("Para cada operacao, voce deve informar os dados solicitados e seguir as instrucoes na tela.\n\n");
    printf("O programa utiliza ponteiros para manipular as entidades e valida os campos de entrada.\n\n");
    printf("O programa gera um id Ãºnico para cada pessoa cadastrada e utiliza esse id para buscar, editar ou remover uma pessoa.\n\n");
    printf("O programa armazena os dados das pessoas em um arquivo binÃ¡rio chamado pessoas.dat.\n\n");
    printf("O programa marca as pessoas removidas com um id negativo, mas nÃ£o apaga os seus dados do arquivo.\n\n");
    printf("O programa foi criado pelo aluno Alesssandro estudante de Engenharia de computacao - IFSULDEMINAS.\n\n");
}

void menu() {
    int opcao;
    printf("Menu Principal\n");
    printf("1. Gerencia de Pessoas\n");
    printf("2. Sair\n");
    printf("3. Ajuda\n");
    printf("Digite a opcao desejada:\n");
    scanf("%d", &opcao);
    switch (opcao) {
        case 1: menu_pessoas(); break;
        case 2: exit(0); break;
        case 3: ajuda(); break;
        default: printf("OpÃ§Ã£o invalida.\n");
    }
    menu();
}

void menu_pessoas() {
    int opcao;
    printf("Menu de Gerencia de Pessoas\n");
    printf("1. Inicializar\n");
    printf("2. Inserir\n");
    printf("3. Editar\n");
    printf("4. Remover\n");
    printf("5. Listar por Codigo\n");
    printf("6. Listar Tudo\n");
    printf("7. Voltar\n");
    printf("Digite a opcao desejada:\n");
    scanf("%d", &opcao);
    switch (opcao) {
        case 1: inicializar(); break;
        case 2: inserir(); break;
        case 3: editar(); break;
        case 4: remover(); break;
        case 5: listar_por_codigo(); break;
        case 6: listar_tudo(); break;
        case 7: voltar(); break;
        default: printf("Opcao invalida.\n");
    }
    menu_pessoas();
}

void ler_pessoa(Pessoa *p) {
    printf("Digite o nome completo da pessoa:\n");
    scanf(" %[^\n]", p->nome);
    printf("Digite a idade da pessoa:\n");
    scanf("%d", &p->idade);
    printf("Digite o endereco da pessoa:\n");
    scanf(" %[^\n]", p->endereco);
    printf("Digite o numero da pessoa:\n");
    scanf("%d", &p->numero);
    printf("Digite a cidade da pessoa:\n");
    scanf(" %[^\n]", p->cidade);
    printf("Digite a sigla do estado da pessoa:\n");
    scanf(" %s", p->estado);
    while (validar_estado(p->estado) == 0) {
        printf("Sigla invalida. Digite novamente:\n");
        scanf(" %s", p->estado);
    }
}

void mostrar_pessoa(Pessoa p) {
    printf("Id: %d\n", p.id);
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    printf("Endereco: %s\n", p.endereco);
    printf("Numero: %d\n", p.numero);
    printf("Cidade: %s\n", p.cidade);
    printf("Estado: %s\n", p.estado);
    printf("\n");
}

int validar_estado(char *estado) {
    char estados[27][3] = {"AC", "AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO", "MA", "MT", "MS", "MG", "PA", "PB", "PR", "PE", "PI", "RJ", "RN", "RS", "RO", "RR", "SC", "SP", "SE", "TO"}; // vetor com as siglas dos estados
    for (int i = 0; i < 27; i++) {
        if (strcmp(estado, estados[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int buscar_pessoa(int id, Pessoa *p) {
    FILE *fp = fopen(arquivo, "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }
    fseek(fp, (id - 1) * sizeof(Pessoa), SEEK_SET); 
    if (fread(p, sizeof(Pessoa), 1, fp) == 1) {
        if (p->id != -1) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

int gerar_id() {
    FILE *fp = fopen(arquivo, "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    Pessoa p;
    int id = 1;
    while (fread(&p, sizeof(Pessoa), 1, fp) == 1) {
        if (p.id == id) {
            id++;
        }
    }
    fclose(fp);
    return id;
}
