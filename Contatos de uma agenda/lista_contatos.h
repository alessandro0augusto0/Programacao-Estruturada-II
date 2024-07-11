#ifndef LISTA_CONTATOS_H
#define LISTA_CONTATOS_H

#include "contato.h"

typedef struct ListaContatos {
    Contato* primeiro;
    Contato* ultimo;
    int tamanho;
} ListaContatos;

ListaContatos* inicializarLista();
void adicionarContatoInicio(ListaContatos* lista, Contato* novoContato);
void adicionarContatoFim(ListaContatos* lista, Contato* novoContato);
void adicionarContatoPosicao(ListaContatos* lista, Contato* novoContato, int posicao);
void removerContatoInicio(ListaContatos* lista);
void removerContatoFim(ListaContatos* lista);
void removerContatoPosicao(ListaContatos* lista, int posicao);
void editarContato(ListaContatos* lista, char* nome);
void listarContatos(ListaContatos* lista);
void buscarContato(ListaContatos* lista, char* nome);
void liberarLista(ListaContatos* lista);
void ajustarTamanho(ListaContatos* lista, int novoTamanho);

#endif
