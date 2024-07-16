Trabalhos feitos no 2º período de Engenharia de computação no IFSULDEMINAS - Campus Poços de Caldas

Descrição (Contatos de uma agenda):

Desenvolva as estruturas para representar os contatos de uma agenda conforme a descrição a seguir:
1. endereço com char rua[50], int numero, char bairro[50] e char cidade[50];
2. telefone com char ddd[2] e char numero[9];
3. contato com char nome[50], char email[30], endereco e um array para armazenar 2 telefones um para o fixo e outro para o celular telefone[2].

Observação: Utilize a diretiva #dene para estabelecer os valores dos tamanhos de cada string.

Crie uma agenda com capacidade de armazenar 10 contatos através de um ponteiro com o nome agenda para contato. Faça todo o gerenciamento de memória com alocação dinâmica calloc() ou malloc() e libere a memória com free() quando não for mais necessária, para otimizar o uso da memória.

Crie uma lista simplesmente encadeada e utilize modularização por meio de funções para as seguintes operações. Todas as operações é necessário fazer o uso das funções scanf() ou do fgets().

1. Adicionar um contato na primeira e na última posição;
2. Adicionar um contato em qualquer posição;
3. Remover um contato na primeira e na última posição;
4. Remover um contato em qualquer posição;
5. Editar um contato qualquer;
6. Listar todos os contatos;
7. Buscar um contato através do nome, se houver mais de um contato com o mesmo nome listar todos os contatos encontrados;
8. Utilizar a função realloc() para realocar a memória caso o usuário queira aumentar ou diminuir o tamanho da agenda. Porém se o usuário for diminuir deverá ser impresso uma mensagem avisando que se ele diminuir o tamanho da agenda poderá perder algumas informações de contatos. Por exemplo, foi solicitado o tamanho 10 contatos, mas se o usuário desejar aumentar para 20 contatos ele poderá aumentar mesmo que a agenda não possua 10 contatos completos, mas supondo que a agenda já possua 8 contatos e ele deseje reduzir o tamanho da agenda para 5, ele perderá os últimos 3 contatos.
9. Tome cuidado ao utilizar a função realloc() e faça o devido tratamento de erro caso a função retorne NULL. Esse erro é conhecido por Memory Leak.
10. Por último, para exibir o menu de opções para o usuário utilize o comando switch/case.

Observação: Apenas para facilitar as correções pelo professor, armazene na memória da agenda os dados de 5 contatos xos, faça uso das funções strcpy() ou do strncpy(), essas duas funções possibilitam armazenar copiar um valor para os respectivos campos de um contato sem precisar utilizar a função scanf() para isso. O
objetivo de armazenar esses valores xo seria apenas para o professor poder realizar os testes já na primeira execução e não precisar car preenchendo sempre os dados de um contato através do scanf() na correção dos trabalhos. Quem não zer essa parte vai perder nota!

Criação de bibliotecas

Fazer uso de 2 bibliotecas uma para armazenar as estruturas e outra para armazenar as funções das listas.

Deixar apenas a função main() com o menu de opções com switch/case no arquivo principal. Faça o #include das bibliotecas no arquivo principal.

1. No arquivo de cabeçalho (header le .h) vão as declarações de funções (assinaturas) e denições de estruturas;
2. No arquivo de unidade (arquivo .c) vão as denições de funções (corpo da função);
3. Então, para usar as funções, é necessário incluir o arquivo de cabeçalho (.h) com o uso de aspas duplas
( ).

#######################################################################################################################################################################################################################

Descrição (Gerenciamento de pessoas):

Criar uma estrutura conforme detalhamento abaixo:
● Pessoa:
○ Identificador único inteiro
○ Nome completo
○ Idade
○ Endereço
○ Número
○ Cidade
○ Sigla estado

Desenvolver um programa que atenda os seguintes requisitos:
● O programa deve possuir métodos e funções para cadastro, edição, exclusão de registros e listagem geral de todos os atributos;
● Deve-se utilizar um único arquivo para manipular os dados;
● Em todos os métodos e funções devem ser utilizados ponteiros para manipular as entidades

Exibir um menu para o usuário com as opções na seguinte ordem:
1. Gerência de Pessoas
2. Sair
3. Ajuda (exibir uma descrição sobre o programa)

Dentro do menu de gerência de pessoas, exibir as opções na seguinte ordem:
1. Inicializar (apagar tudo o que já foi inserido, mediante confirmação)
2. Inserir
3. Editar
4. Remover
5. Listar por Código
6. Listar Tudo
7. Voltar

OBS: Em todas as opções do menu deve haver uma descrição detalhada para que o usuário saiba o que inserir,
quais opções são válidas, e para que serve cada um dos campos solicitados. Deve ser feita a validação dos
campos: números, valores permitidos, valores de enum, etc.
