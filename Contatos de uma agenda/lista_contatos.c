#include "lista_contatos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ListaContatos *inicializarLista()
{
    ListaContatos *lista = (ListaContatos *) calloc(1,sizeof(ListaContatos));
    if (lista != NULL)
    {
        lista->primeiro = NULL;
        lista->ultimo = NULL;
        lista->tamanho = 0;
    }
    return lista;
}

void adicionarContatoInicio(ListaContatos *lista, Contato *novoContato)
{
    if (lista != NULL && novoContato != NULL)
    {
        novoContato->proximo = lista->primeiro;
        lista->primeiro = novoContato;
        if (lista->ultimo == NULL)
        {
            lista->ultimo = novoContato;
        }
        lista->tamanho++;
    }
}

void adicionarContatoFim(ListaContatos *lista, Contato *novoContato)
{
    if (lista != NULL && novoContato != NULL)
    {
        if (lista->ultimo == NULL)
        {
            lista->primeiro = novoContato;
            lista->ultimo = novoContato;
        }
        else
        {
            lista->ultimo->proximo = novoContato;
            lista->ultimo = novoContato;
        }
        novoContato->proximo = NULL;
        lista->tamanho++;
    }
}

void adicionarContatoPosicao(ListaContatos *lista, Contato *novoContato, int posicao)
{
    if (lista != NULL && novoContato != NULL && posicao >= 0 && posicao <= lista->tamanho)
    {
        if (posicao == 0)
        {
            adicionarContatoInicio(lista, novoContato);
        }
        else if (posicao == lista->tamanho)
        {
            adicionarContatoFim(lista, novoContato);
        }
        else
        {
            Contato *anterior = lista->primeiro;
            for (int i = 0; i < posicao - 1; i++)
            {
                anterior = anterior->proximo;
            }
            novoContato->proximo = anterior->proximo;
            anterior->proximo = novoContato;
            lista->tamanho++;
        }
    }
}

void removerContatoInicio(ListaContatos *lista)
{
    if (lista != NULL && lista->primeiro != NULL)
    {
        Contato *removido = lista->primeiro;
        lista->primeiro = removido->proximo;
        free(removido);
        lista->tamanho--;
        if (lista->primeiro == NULL)
        {
            lista->ultimo = NULL;
        }
    }
}

void removerContatoFim(ListaContatos *lista)
{
    if (lista != NULL && lista->ultimo != NULL)
    {
        if (lista->primeiro == lista->ultimo)
        {
            free(lista->primeiro);
            lista->primeiro = NULL;
            lista->ultimo = NULL;
        }
        else
        {
            Contato *penultimo = lista->primeiro;
            while (penultimo->proximo != lista->ultimo)
            {
                penultimo = penultimo->proximo;
            }
            free(lista->ultimo);
            lista->ultimo = penultimo;
            penultimo->proximo = NULL;
        }
        lista->tamanho--;
    }
}

void removerContatoPosicao(ListaContatos *lista, int posicao)
{
    if (lista != NULL && posicao >= 0 && posicao < lista->tamanho)
    {
        if (posicao == 0)
        {
            removerContatoInicio(lista);
        }
        else if (posicao == lista->tamanho - 1)
        {
            removerContatoFim(lista);
        }
        else
        {
            Contato *anterior = lista->primeiro;
            for (int i = 0; i < posicao - 1; i++)
            {
                anterior = anterior->proximo;
            }
            Contato *removido = anterior->proximo;
            anterior->proximo = removido->proximo;
            free(removido);
            lista->tamanho--;
        }
    }
}

void editarContato(ListaContatos *lista, char *nome)
{
    char numero[10];
    if (lista != NULL && nome != NULL)
    {
        Contato *atual = lista->primeiro;
        while (atual != NULL)
        {
            if (strcmp(atual->nome, nome) == 0)
            {
                fflush(stdin);
                printf("Nome: ");
                fgets(atual->nome, sizeof(atual->nome), stdin);
                atual->nome[strlen(atual->nome) - 1] = '\0';
                fflush(stdin);
                printf("E-mail: ");
                fgets(atual->email, sizeof(atual->email), stdin);
                atual->email[strlen(atual->email) - 1] = '\0';
                fflush(stdin);
                printf("Rua: ");
                fgets(atual->endereco.rua, sizeof(atual->endereco.rua), stdin);
                atual->endereco.rua[strlen(atual->endereco.rua) - 1] = '\0';
                fflush(stdin);
                printf("Numero: ");
                fgets(numero, 10, stdin);
                numero[strlen(numero) - 1] = '\0';
                atual->endereco.numero = atoi(numero);
                fflush(stdin);
                printf("Bairro: ");
                fgets(atual->endereco.bairro, sizeof(atual->endereco.bairro), stdin);
                atual->endereco.bairro[strlen(atual->endereco.bairro) - 1] = '\0';
                fflush(stdin);
                printf("Cidade: ");
                fgets(atual->endereco.cidade, sizeof(atual->endereco.cidade), stdin);
                atual->endereco.cidade[strlen(atual->endereco.cidade) - 1] = '\0';
                fflush(stdin);
                printf("DDD (Telefone 1): ");
                fgets(atual->telefone[0].ddd, sizeof(atual->telefone[0].ddd), stdin);
                fflush(stdin);
                printf("Numero (Telefone 1): ");
                fgets(atual->telefone[0].numero, sizeof(atual->telefone[0].numero), stdin);
                fflush(stdin);
                printf("DDD (Telefone 2): ");
                fgets(atual->telefone[1].ddd, sizeof(atual->telefone[1].ddd), stdin);
                fflush(stdin);
                printf("Numero (Telefone 2): ");
                fgets(atual->telefone[1].numero, sizeof(atual->telefone[1].numero), stdin);
                fflush(stdin);
            }
            atual = atual->proximo;
        }
    }
}

void listarContatos(ListaContatos *lista)
{
    if (lista != NULL)
    {
        Contato *atual = lista->primeiro;
        while (atual != NULL)
        {
            printf("Nome: %s\n", atual->nome);
            printf("E-mail: %s\n", atual->email);
            printf("Endereco: %s, %d, %s -  %s\n",
                   atual->endereco.rua, atual->endereco.numero,
                   atual->endereco.bairro, atual->endereco.cidade);
            printf("Telefone 1: (%s) %s\n", atual->telefone[0].ddd, atual->telefone[0].numero);
            printf("Telefone 2: (%s) %s\n", atual->telefone[1].ddd, atual->telefone[1].numero);
            printf("\n");
            atual = atual->proximo;
        }
    }
}

void buscarContato(ListaContatos *lista, char *nome)
{
    if (lista != NULL && nome != NULL)
    {
        Contato *atual = lista->primeiro;
        int encontrados = 0;
        while (atual != NULL)
        {
            if (strcmp(atual->nome, nome) == 0)
            {
                printf("Nome: %s\n", atual->nome);
                printf("E-mail: %s\n", atual->email);
                printf("Endereco: %s, %d, %s -  %s\n",
                       atual->endereco.rua, atual->endereco.numero,
                       atual->endereco.bairro, atual->endereco.cidade);
                printf("Telefone 1: (%s) %s\n", atual->telefone[0].ddd, atual->telefone[0].numero);
                printf("Telefone 2: (%s) %s\n", atual->telefone[1].ddd, atual->telefone[1].numero);
                printf("\n");
                encontrados++;
            }
            if (strstr(atual->nome, nome) != NULL)
            {
                printf("Nome: %s\n", atual->nome);
                printf("E-mail: %s\n", atual->email);
                printf("Endereco: %s, %d, %s -  %s\n",
                       atual->endereco.rua, atual->endereco.numero,
                       atual->endereco.bairro, atual->endereco.cidade);
                printf("Telefone 1: (%s) %s\n", atual->telefone[0].ddd, atual->telefone[0].numero);
                printf("Telefone 2: (%s) %s\n", atual->telefone[1].ddd, atual->telefone[1].numero);
                printf("\n");
                encontrados++;
            }
            atual = atual->proximo;
        }
        if (encontrados == 0)
        {
            printf("Nenhum contato encontrado com o nome '%s'\n", nome);
        }
    }
}

void liberarLista(ListaContatos *lista)
{
    if (lista != NULL)
    {
        Contato *atual = lista->primeiro;
        while (atual != NULL)
        {
            Contato *proximo = atual->proximo;
            free(atual);
            atual = proximo;
        }
        free(lista);
    }
}

void ajustarTamanho(ListaContatos *lista, int novoTamanho)
{
    char opc;
    if (lista != NULL)
    {
        if (novoTamanho > lista->tamanho)
        {
            // Aumentar o tamanho da lista
            while (lista->tamanho < novoTamanho)
            {
                Contato *novoContato = (Contato *)malloc(sizeof(Contato));
                if (novoContato != NULL)
                {
                    novoContato->proximo = NULL;
                    adicionarContatoFim(lista, novoContato);
                }
            }
        }
        else if (novoTamanho < lista->tamanho)
        {
            printf("Essa acao ira remover os contatos excedentes do fim da lista\n deseja continuar? pressione s para sim outra para nao.\n");
            scanf(" %c", &opc); // Lê a entrada do usuário
            if (opc == 's' || opc == 'S')
            {
                // Diminuir o tamanho da lista
                while (lista->tamanho > novoTamanho)
                {
                    removerContatoFim(lista);
                }
            }
        }
    }
}

