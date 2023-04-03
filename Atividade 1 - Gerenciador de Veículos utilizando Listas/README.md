#### Universidade Federal de Alfenas - UNIFAL-MG
Bacharelado em Ciência da Computação

<hr>
<div align="center">
  <h1>Trabalho de Programação</h1>
   <p>Atividade 1 - Busca de Carros, Vans e Utilitários com Lista</p>
</div>

## Objetivo
Adquirir conhecimentos de manipulação de listas com alocação dinâmica (lista ligada ou encadeada) numa aplicação que cria uma pilha e uma fila como resultado da busca numa lista principal de carros, vans e utilitários.

## Descrição
O aplicativo desenvolvido no projeto deve criar uma lista ligada principal com os dados lidos de um arquivo de entrada. Cada linha do arquivo deve ser armazenada em um nó da lista. Então o aplicativo deve construir uma pilha e uma fila a partir de buscas realizadas na lista principal, sem realocar ou duplicar os nós da lista principal, mediante as 2 opções selecionadas. Além disso também devem ser implementadas as funções de inserção e remoção de nós da lista principal.

## Arquivo de Dados
Conterá um número ilimitado de linhas, onde cada linha conterá os dados de um veículo: modelo, marca, tipo, ano, quilometragem, potência do motor, combustível, câmbio, direção, cor, número de portas e placa. Segue em anexo um arquivo-texto de exemplo.

## Requisitos
O aplicativo deverá:

1) Apresentar um menu ao usuário com as opções de inclusão, exclusão, buscas e relatório;
2) Realizar buscas na lista criada permitindo configurar as opções com algumas características: resultado em pilha ou fila, escolha da 1ª opção e escolha da 2ª opção;
3) O resultado da busca deve permanecer na memória até que uma nova busca for realizada;
4) As opções são escolhidas pelos dados do veículo;
5) Quando terminar a busca apresente os dados na tela;
6) Realizar a operação de inclusão de forma ordenada pela placa do veículo;
7) Apresentar o relatório de todos os clientes na tela do computador;
8) Ao final da execução todas as estruturas devem ser desalocadas.

## Estrutura de Dados
![estrutura2](https://user-images.githubusercontent.com/89847080/229587653-cf1646e5-f73c-420a-8964-0432bcf76e70.png)
