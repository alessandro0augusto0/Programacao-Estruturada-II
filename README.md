# Trabalhos de Programação Estruturada II

Trabalhos feitos no 2º período de Engenharia de Computação para a disciplina "Programação Estruturada II" - IFSULDEMINAS - Campus Poços de Caldas

## Descrição

### Contatos de uma Agenda

Desenvolva as estruturas para representar os contatos de uma agenda conforme a descrição a seguir:

- **Endereço:**
  - `char rua[50]`
  - `int numero`
  - `char bairro[50]`
  - `char cidade[50]`
- **Telefone:**
  - `char ddd[2]`
  - `char numero[9]`
- **Contato:**
  - `char nome[50]`
  - `char email[30]`
  - Endereço
  - Um array para armazenar 2 telefones: telefone fixo e celular `telefone[2]`

**Observação:** Utilize a diretiva `#define` para estabelecer os valores dos tamanhos de cada string.

Crie uma agenda com capacidade de armazenar 10 contatos através de um ponteiro com o nome `agenda` para contato. Faça todo o gerenciamento de memória com alocação dinâmica `calloc()` ou `malloc()` e libere a memória com `free()` quando não for mais necessária, para otimizar o uso da memória.

### Lista Simplesmente Encadeada

Crie uma lista simplesmente encadeada e utilize modularização por meio de funções para as seguintes operações. Todas as operações devem usar as funções `scanf()` ou `fgets()`.

- Adicionar um contato na primeira e na última posição;
- Adicionar um contato em qualquer posição;
- Remover um contato na primeira e na última posição;
- Remover um contato em qualquer posição;
- Editar um contato qualquer;
- Listar todos os contatos;
- Buscar um contato através do nome. Se houver mais de um contato com o mesmo nome, listar todos os contatos encontrados;
- Utilizar a função `realloc()` para realocar a memória caso o usuário queira aumentar ou diminuir o tamanho da agenda. Se o usuário diminuir o tamanho da agenda, uma mensagem deve avisar que ele pode perder algumas informações de contatos. Por exemplo, se a agenda possui 8 contatos e o usuário deseja reduzir para 5, ele perderá os últimos 3 contatos.

Tome cuidado ao utilizar a função `realloc()` e faça o devido tratamento de erro caso a função retorne `NULL`. Esse erro é conhecido por "Memory Leak".

### Menu de Opções

Para exibir o menu de opções para o usuário, utilize o comando `switch/case`.

**Observação:** Para facilitar as correções pelo professor, armazene na memória da agenda os dados de 5 contatos fixos. Faça uso das funções `strcpy()` ou `strncpy()`. O objetivo é permitir ao professor realizar testes já na primeira execução sem precisar preencher os dados de um contato através do `scanf()` na correção dos trabalhos. Quem não fizer essa parte vai perder nota!

### Criação de Bibliotecas

Fazer uso de 2 bibliotecas, uma para armazenar as estruturas e outra para armazenar as funções das listas.

- Deixe apenas a função `main()` com o menu de opções com `switch/case` no arquivo principal. Faça o `#include` das bibliotecas no arquivo principal.
- No arquivo de cabeçalho (header `.h`) vão as declarações de funções (assinaturas) e definições de estruturas.
- No arquivo de unidade (arquivo `.c`) vão as definições de funções (corpo da função).

Para usar as funções, é necessário incluir o arquivo de cabeçalho (`.h`) com o uso de aspas duplas (`""`).

---

# Gerenciamento de Pessoas

### Estrutura Pessoa

Crie uma estrutura conforme detalhamento abaixo:

- **Pessoa:**
  - Identificador único inteiro
  - Nome completo
  - Idade
  - Endereço
  - Número
  - Cidade
  - Sigla do estado

### Requisitos do Programa

Desenvolver um programa que atenda os seguintes requisitos:

- O programa deve possuir métodos e funções para cadastro, edição, exclusão de registros e listagem geral de todos os atributos;
- Deve-se utilizar um único arquivo para manipular os dados;
- Em todos os métodos e funções devem ser utilizados ponteiros para manipular as entidades.

### Menu de Opções

Exibir um menu para o usuário com as opções na seguinte ordem:

- **Gerência de Pessoas**
- **Sair**
- **Ajuda** (exibir uma descrição sobre o programa)

Dentro do menu de gerência de pessoas, exibir as opções na seguinte ordem:

- **Inicializar** (apagar tudo o que já foi inserido, mediante confirmação)
- **Inserir**
- **Editar**
- **Remover**
- **Listar por Código**
- **Listar Tudo**
- **Voltar**

**OBS:** Em todas as opções do menu deve haver uma descrição detalhada para que o usuário saiba o que inserir, quais opções são válidas, e para que serve cada um dos campos solicitados. Deve ser feita a validação dos campos: números, valores permitidos, valores de enum, etc.
