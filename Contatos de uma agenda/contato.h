#ifndef CONTATO_H
#define CONTATO_H

#define MAX_CHAR 51
#define MAX_DDD 3
#define MAX_NUMERO 10
#define MAX_EMAIL 31

typedef struct Telefone {
    char ddd[MAX_DDD];
    char numero[MAX_NUMERO];
} Telefone;

typedef struct Endereco {
    char rua[MAX_CHAR];
    int numero;
    char bairro[MAX_CHAR];
    char cidade[MAX_CHAR];
} Endereco;

typedef struct Contato {
    char nome[MAX_CHAR];
    char email[MAX_EMAIL];
    Endereco endereco;
    Telefone telefone[2];
    struct Contato* proximo;
} Contato;

#endif
