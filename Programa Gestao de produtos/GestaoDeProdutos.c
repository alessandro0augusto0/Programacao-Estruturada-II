#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct produto{
	char nome[200];
	char descricao[500];
	float preco;
	int id;
	char removido;
} Produto;

void copiaProduto(Produto *destino, Produto *origem){
	strcpy(destino->nome, origem->nome);
	strcpy(destino->descricao, origem->descricao);
	destino->preco = origem->preco;
	destino->id = origem->id;
	destino->removido = origem->removido;
}

int cadastrarProduto(Produto *produtos, int tam){
	if(tam == 1000){
		printf("\nNao eh possivel cadastrar! Lista cheia!\n");
		return 0;
	}
	
	int i, j;
	Produto aux;
	
	printf("\nCADASTRO DE PRODUTOS\n");
	printf("ID: ");
	scanf("%d", &aux.id);
	
	printf("Nome: ");
	fflush(stdin);
	fgets(aux.nome, 200, stdin);
	
	for(i = 0; aux.nome[i] != '\n'; i++);
	aux.nome[i] = 0;	
	
	printf("Descricao: ");
	fflush(stdin);
	fgets(aux.descricao, 500, stdin);
	
	for(i = 0; aux.descricao[i] != '\n'; i++);
	aux.descricao[i] = 0;
	
	printf("Preco: R$ ");
	scanf("%f", &aux.preco);
	
	aux.removido = 0;
	
	if(tam == 0){
		copiaProduto(&produtos[0], &aux);
		printf("\nProduto cadastrado com sucesso!\n\n");
		
		return 1;
	}
	
	i = 0;
	while(strcmp(produtos[i].nome, aux.nome) < 0 && i < tam){
	++i;
	}
	for(j = tam-1; j >= i; --j){
		copiaProduto(&produtos[j+1], &produtos[j]);
	}
	copiaProduto(&produtos[i], &aux);
	printf("\nProduto cadastrado com sucesso!\n\n");
	
	return 1;
}

void exibirProdutos(Produto *produtos, int tam){
	
	printf("\nTODOS OS PRODUTOS\n\n");
	
	int i;
	for(i = 0; i < tam; i++){
		if(!produtos[i].removido){
			printf("ID: %d\n", produtos[i].id);
			printf("Nome: %s\n", produtos[i].nome);
			printf("Descricao: %s\n", produtos[i].descricao);
			printf("Preco: R$ %0.2f\n", produtos[i].preco);
			printf("\n");
		}
	}
}

void consultarProduto(Produto *produtos, int tam){
	int op, i, encontrado;
	char nome[200];
	
	printf("\nCONSULTA DE PRODUTOS\n");
	printf("1-) Exibir todos os produtos\n");
	printf("2-) Consultar produto\n");
	printf("3-) Voltar\n");
	while(1){
		printf(">>> ");
		scanf("%d", &op);
		fflush(stdin);
		
		if(op < 1 || op > 3)
			printf("\nOpcao invalida!\n\n");
		else
			break;
	}
	
	switch(op){
	case 1:
		exibirProdutos(produtos, tam);
		break;
	case 2:
		printf("Nome: ");
		fflush(stdin);
		fgets(nome, 200, stdin);
		for(i = 0; nome[i] != '\n'; i++);
			nome[i] = 0;	
		
		encontrado = 0;
		for(i = 0; i < tam; i++)
			if(strcmp(produtos[i].nome, nome) == 0 && !produtos[i].removido){
				encontrado = 1;
				printf("\nID: %d\n", produtos[i].id);
				printf("Nome: %s\n", produtos[i].nome);
				printf("Descricao: %s\n", produtos[i].descricao);
				printf("Preco: R$ %0.2f\n", produtos[i].preco);
				printf("\n");
			}
		if(!encontrado)
			printf("\nProduto nao encontrado!\n\n");
		
		break;
	case 3:
		printf("\n");
		return;
	}	
}
void deletarProdutos(Produto *produtos, int tam){
	int i, encontrado = 0;
	char nome[200];
	printf("Nome: ");
	fflush(stdin);
	fgets(nome, 200, stdin);
	for(i = 0; nome[i] != '\n'; i++);
		nome[i] = 0;
	for(i = 0; i < tam; i++){
		if(strcmp(produtos[i].nome, nome) == 0 && !produtos[i].removido){
			encontrado = 1;
			produtos[i].removido = 1;
			printf("\nProduto removido com sucesso!\n\n");
			break;
		}
	}
	
	if(!encontrado)
		printf("\nProduto nao encotrado!\n\n");
}

int main(){
	int op, i, tam = 0, continua = 1;
	Produto produtos[1000];
	FILE *arquivo = fopen("dados.dat", "r");
	
	if(arquivo == NULL){
		arquivo = fopen("dados.dat", "a");
		fclose(arquivo);
	} else {
		while(fread(&produtos[tam], sizeof(Produto), 1, arquivo) == 1){
			tam++;
		}
		fclose(arquivo);
	}	
	while(continua){
		printf("MENU\n");
		printf("1-) Cadastrar novo produto\n");
		printf("2-) Exibir todos os produtos\n");
		printf("3-) Consultar produto\n");
		printf("4-) Deletar produto\n");
		printf("5-) Sair\n");
		while(1){
			printf(">>> ");
			scanf("%d", &op);
			fflush(stdin);
			
			if(op < 1 || op > 5)
				printf("\nOpcao invalida!\n\n");
			else
				break;
		}
		switch(op){
		case 1:
			tam += cadastrarProduto(produtos, tam);
			break;
		case 2:
			exibirProdutos(produtos, tam);
			break;
		case 3:
			consultarProduto(produtos, tam);
			break;
		case 4:
			deletarProdutos(produtos, tam);
			break;
		case 5:
			continua = 0;	
		}
	}	
	arquivo = fopen("dados.dat", "wb");
	for(i = 0; i < tam; i++)
		fwrite(&produtos[i],sizeof(Produto),1,arquivo);
	fclose(arquivo);
	
	return 0;
}

