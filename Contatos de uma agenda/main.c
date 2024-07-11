/*

Este código foi criado pelo aluno Alessandro Augusto no 3º período do curso de Engenharia de Computação
 * a fim de desenvolver as estruturas para representar os contatos de uma agenda.
 * Professor: Dr Ricardo Ramos de Oliveira
 * Disciplina: Programação Estruturada II

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contato.h"
#include "lista_contatos.h"

int main() {


    char numero[10];
    ListaContatos* agenda = inicializarLista();
    if (agenda == NULL) {
        fprintf(stderr, "Erro ao alocar memÃ³ria para a agenda.\n");
        return 1;
    }

    Contato* contato1 = (Contato*)malloc(sizeof(Contato));
    if (contato1 != NULL) {
        strcpy(contato1->nome, "Harry Potter");
        strcpy(contato1->email, "potter@hogwarts.com");
        strcpy(contato1->endereco.rua, "Rua 111");
        contato1->endereco.numero = 111;
        strcpy(contato1->endereco.bairro, "Bairro um");
        strcpy(contato1->endereco.cidade, "Cidade um");
        strcpy(contato1->telefone[0].ddd, "11");
        strcpy(contato1->telefone[0].numero, "111111111");
        strcpy(contato1->telefone[1].ddd, "22");
        strcpy(contato1->telefone[1].numero, "222222222");
        contato1->proximo = NULL;
    }

    Contato* contato2 = (Contato*)malloc(sizeof(Contato));
    if (contato2 != NULL) {
        strcpy(contato2->nome, "Draco Malfoy");
        strcpy(contato2->email, "malfoy@hogwarts.com");
        strcpy(contato2->endereco.rua, "Rua 222");
        contato2->endereco.numero = 222;
        strcpy(contato2->endereco.bairro, "Bairro dois");
        strcpy(contato2->endereco.cidade, "Cidade dois");
        strcpy(contato2->telefone[0].ddd, "33");
        strcpy(contato2->telefone[0].numero, "333333333");
        strcpy(contato2->telefone[1].ddd, "44");
        strcpy(contato2->telefone[1].numero, "444444444");
        contato2->proximo = NULL;
    }

    Contato* contato3 = (Contato*)malloc(sizeof(Contato));
    if (contato3 != NULL) {
        strcpy(contato3->nome, "Hermione Granger");
        strcpy(contato3->email, "granger@hogwarts.com");
        strcpy(contato3->endereco.rua, "Rua 333");
        contato3->endereco.numero = 333;
        strcpy(contato3->endereco.bairro, "Bairro tres");
        strcpy(contato3->endereco.cidade, "Cidade tres");
        strcpy(contato3->telefone[0].ddd, "55");
        strcpy(contato3->telefone[0].numero, "555555555");
        strcpy(contato3->telefone[1].ddd, "66");
        strcpy(contato3->telefone[1].numero, "666666666");
        contato3->proximo = NULL;
    }

    Contato* contato4 = (Contato*)malloc(sizeof(Contato));
    if (contato4 != NULL) {
        strcpy(contato4->nome, "Ron Weasley");
        strcpy(contato4->email, "weasley6@example.com");
        strcpy(contato4->endereco.rua, "Rua 444");
        contato4->endereco.numero = 444;
        strcpy(contato4->endereco.bairro, "bairro quatro");
        strcpy(contato4->endereco.cidade, "Cidade quatro");
        strcpy(contato4->telefone[0].ddd, "77");
        strcpy(contato4->telefone[0].numero, "777777777");
        strcpy(contato4->telefone[1].ddd, "88");
        strcpy(contato4->telefone[1].numero, "888888888");
        contato4->proximo = NULL;
    }

    Contato* contato5 = (Contato*)malloc(sizeof(Contato));
    if (contato5 != NULL) {
        strcpy(contato5->nome, "Alvo Dumbledor");
        strcpy(contato5->email, "Alvo@example.com");
        strcpy(contato5->endereco.rua, "Rua 555");
        contato5->endereco.numero = 555;
        strcpy(contato5->endereco.bairro, "bairro cinco");
        strcpy(contato5->endereco.cidade, "Cidade cinco");
        strcpy(contato5->telefone[0].ddd, "99");
        strcpy(contato5->telefone[0].numero, "999999999");
        strcpy(contato5->telefone[1].ddd, "11");
        strcpy(contato5->telefone[1].numero, "111111111");
        contato5->proximo = NULL;
    }


    adicionarContatoFim(agenda, contato1);
    adicionarContatoFim(agenda, contato2);
    adicionarContatoFim(agenda, contato3);
    adicionarContatoFim(agenda, contato4);
    adicionarContatoFim(agenda, contato5);

    int opcao;
    do {
        printf("\n-- Menu --\n");
        printf("1. Adicionar contato no inicio\n");
        printf("2. Adicionar contato no fim\n");
        printf("3. Adicionar contato em posicao especifica\n");
        printf("4. Remover contato no inicio\n");
        printf("5. Remover contato no fim\n");
        printf("6. Remover contato em posicao especifica\n");
        printf("7. Editar contato\n");
        printf("8. Listar contatos\n");
        printf("9. Buscar contato por nome\n");
        printf("10. Ajustar tamanho da agenda\n");
        printf("11. Sair\n");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                // Adicionar contato no inÃ­cio
                Contato* novoContato = (Contato*)malloc(sizeof(Contato));
                if (novoContato != NULL) {
                    fflush(stdin);
                    printf("Nome: ");
                    fgets(novoContato->nome, sizeof(novoContato->nome), stdin);
                    novoContato->nome[strlen(novoContato->nome) - 1] = '\0'; 
                    fflush(stdin);

                    printf("E-mail: ");
                    fgets(novoContato->email, sizeof(novoContato->email), stdin);
                    novoContato->email[strlen(novoContato->email) - 1] = '\0'; 
                    fflush(stdin);


                    printf("Rua: ");
                    fgets(novoContato->endereco.rua, sizeof(novoContato->endereco.rua), stdin);
                    novoContato->endereco.rua[strlen(novoContato->endereco.rua) - 1] = '\0'; 
                    fflush(stdin);

                    
                    printf("Numero: ");
                    fgets(numero,10,stdin);
                    numero[strlen(numero) - 1]= '\0';
                    novoContato->endereco.numero = atoi(numero);
                    fflush(stdin);


                    printf("Bairro: ");
                    fgets(novoContato->endereco.bairro, sizeof(novoContato->endereco.bairro), stdin);
                    novoContato->endereco.bairro[strlen(novoContato->endereco.bairro) - 1] = '\0';
                    fflush(stdin);


                    printf("Cidade: ");
                    fgets(novoContato->endereco.cidade, sizeof(novoContato->endereco.cidade), stdin);
                    novoContato->endereco.cidade[strlen(novoContato->endereco.cidade) - 1] = '\0'; 
                    fflush(stdin);


                    printf("DDD (Telefone 1): ");
                    fgets(novoContato->telefone[0].ddd, sizeof(novoContato->telefone[0].ddd), stdin);
                    fflush(stdin);


                    printf("Numero (Telefone 1): ");
                    fgets(novoContato->telefone[0].numero, sizeof(novoContato->telefone[0].numero), stdin);
                    fflush(stdin);


                    printf("DDD (Telefone 2): ");
                    fgets(novoContato->telefone[1].ddd, sizeof(novoContato->telefone[0].ddd), stdin);
                    fflush(stdin);


                    printf("Numero (Telefone 2): ");
                    fgets(novoContato->telefone[1].numero, sizeof(novoContato->telefone[0].numero), stdin);
                    fflush(stdin);


                    novoContato->proximo = NULL;
                    adicionarContatoInicio(agenda, novoContato);
                }
                break;
            }
            case 2: {
                // Adicionar contato no fim
                Contato* novoContato = (Contato*)malloc(sizeof(Contato));
                if (novoContato != NULL) {
                     fflush(stdin);
                    printf("Nome: ");
                    fgets(novoContato->nome, sizeof(novoContato->nome), stdin);
                    novoContato->nome[strlen(novoContato->nome) - 1] = '\0'; 
                    fflush(stdin);


                    printf("E-mail: ");
                    fgets(novoContato->email, sizeof(novoContato->email), stdin);
                    novoContato->email[strlen(novoContato->email) - 1] = '\0'; 
                    fflush(stdin);


                    printf("Rua: ");
                    fgets(novoContato->endereco.rua, sizeof(novoContato->endereco.rua), stdin);
                    novoContato->endereco.rua[strlen(novoContato->endereco.rua) - 1] = '\0'; 
                    fflush(stdin);


                    printf("Numero: ");
                    fgets(numero,10,stdin);
                    numero[strlen(numero) - 1]= '\0';
                    novoContato->endereco.numero = atoi(numero);
                    fflush(stdin);


                    printf("Bairro: ");
                    fgets(novoContato->endereco.bairro, sizeof(novoContato->endereco.bairro), stdin);
                    novoContato->endereco.bairro[strlen(novoContato->endereco.bairro) - 1] = '\0';
                    fflush(stdin);


                    printf("Cidade: ");
                    fgets(novoContato->endereco.cidade, sizeof(novoContato->endereco.cidade), stdin);
                    novoContato->endereco.cidade[strlen(novoContato->endereco.cidade) - 1] = '\0'; 
                    fflush(stdin);


                    printf("DDD (Telefone 1): ");
                    fgets(novoContato->telefone[0].ddd, sizeof(novoContato->telefone[0].ddd), stdin);
                    fflush(stdin);


                    printf("Numero (Telefone 1): ");
                    fgets(novoContato->telefone[0].numero, sizeof(novoContato->telefone[0].numero), stdin);
                    fflush(stdin);


                    printf("DDD (Telefone 2): ");
                    fgets(novoContato->telefone[1].ddd, sizeof(novoContato->telefone[0].ddd), stdin);
                    fflush(stdin);


                    printf("Numero (Telefone 2): ");
                    fgets(novoContato->telefone[1].numero, sizeof(novoContato->telefone[0].numero), stdin);
                    fflush(stdin);


                    novoContato->proximo = NULL;
                    adicionarContatoFim(agenda, novoContato);
                }
                break;
            }
            case 3: {
                // Adicionar contato em posiÃ§Ã£o especÃ­fica
                int posicao;
                printf("Posicao: ");
                scanf("%d", &posicao);
                posicao--;
                if (posicao >= 0 && posicao <= agenda->tamanho) {
                    Contato* novoContato = (Contato*)malloc(sizeof(Contato));
                    if (novoContato != NULL) {
                        fflush(stdin);
                        printf("Nome: ");
                        fgets(novoContato->nome, sizeof(novoContato->nome), stdin);
                        novoContato->nome[strlen(novoContato->nome) - 1] = '\0'; 
                        fflush(stdin);


                        printf("E-mail: ");
                        fgets(novoContato->email, sizeof(novoContato->email), stdin);
                        novoContato->email[strlen(novoContato->email) - 1] = '\0'; 
                        fflush(stdin);


                        printf("Rua: ");
                        fgets(novoContato->endereco.rua, sizeof(novoContato->endereco.rua), stdin);
                        novoContato->endereco.rua[strlen(novoContato->endereco.rua) - 1] = '\0'; 
                        fflush(stdin);


                        printf("Numero: ");
                        fgets(numero,10,stdin);
                        numero[strlen(numero) - 1]= '\0';
                        novoContato->endereco.numero = atoi(numero);
                        fflush(stdin);


                        printf("Bairro: ");
                        fgets(novoContato->endereco.bairro, sizeof(novoContato->endereco.bairro), stdin);
                        novoContato->endereco.bairro[strlen(novoContato->endereco.bairro) - 1] = '\0';
                        fflush(stdin);


                        printf("Cidade: ");
                        fgets(novoContato->endereco.cidade, sizeof(novoContato->endereco.cidade), stdin);
                        novoContato->endereco.cidade[strlen(novoContato->endereco.cidade) - 1] = '\0'; 
                        fflush(stdin);


                        printf("DDD (Telefone 1): ");
                        fgets(novoContato->telefone[0].ddd, sizeof(novoContato->telefone[0].ddd), stdin);
                        fflush(stdin);


                        printf("Numero (Telefone 1): ");
                        fgets(novoContato->telefone[0].numero, sizeof(novoContato->telefone[0].numero), stdin);
                        novoContato->telefone[0].numero[strlen(novoContato->telefone[0].numero) - 1] = '\0';
                        fflush(stdin);


                        printf("DDD (Telefone 2): ");
                        fgets(novoContato->telefone[1].ddd, sizeof(novoContato->telefone[0].ddd), stdin);
                        fflush(stdin);


                        printf("Numero (Telefone 2): ");
                        fgets(novoContato->telefone[1].numero, sizeof(novoContato->telefone[0].numero), stdin);
                        novoContato->telefone[1].numero[strlen(novoContato->telefone[1].numero) - 1] = '\0';
                        fflush(stdin);


                        novoContato->proximo = NULL;
                        adicionarContatoPosicao(agenda, novoContato, posicao);
                    }
                } else {
                    printf("Posicao invalida.\n");
                }
                break;
            }
            case 4: {
                // Remover contato no inÃ­cio
                removerContatoInicio(agenda);
                break;
            }
            case 5: {
                // Remover contato no fim
                removerContatoFim(agenda);
                break;
            }
            case 6: {
                // Remover contato em posiÃ§Ã£o especÃ­fica
                int posicao;
                printf("Posicao: ");
                scanf("%d", &posicao);
                posicao--;
                if (posicao >= 0 && posicao < agenda->tamanho) {
                    removerContatoPosicao(agenda, posicao);
                } else {
                    printf("Posicao invalida.\n");
                }
                break;
            }
            case 7: {
                // Editar contato
                char nome[MAX_CHAR];
                fflush(stdin);
                printf("Nome do contato a ser editado: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strlen(nome) - 1]= '\0';
                editarContato(agenda, nome);
                break;
            }
            case 8: {
                // Listar contatos
                listarContatos(agenda);
                break;
            }
            case 9: {
                // Buscar contato por nome
                char nome[MAX_CHAR];
                fflush(stdin);
                printf("Nome do contato a ser buscado: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strlen(nome) - 1]= '\0';
                buscarContato(agenda, nome);
                break;
            }

            case 10: {
                // Aumentar tamanho da agenda
                int novoTamanho;
                printf("Novo tamanho da agenda: ");
                scanf("%d", &novoTamanho);
                ajustarTamanho(agenda, novoTamanho);
                break;
            }
            case 11: {
                // Sair
                liberarLista(agenda);
                break;
            }
            default: {
                printf("Opcao invalida. Tente novamente.\n");
            }
        }
    } while (opcao != 11);

    return 0;
}
