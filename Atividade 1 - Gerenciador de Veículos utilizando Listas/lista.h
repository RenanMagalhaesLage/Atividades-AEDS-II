#ifndef LISTA_H
#define LISTA_H

using namespace std;

/*Estrutura para guardar as informações dos veículos*/
typedef struct no_ {
        string modelo, marca, tipo, combustivel ,cambio, direcao, cor, placa; 
        string ano, km, portas; 
        string potenciaMotor;
	struct no_ * prox;  // ponteiro para o próximo nó da lista encadeada
} no;

/*Estrutura de cabeçalho da Lista*/
typedef struct {
	int tam;              //Variável para medir a quantidade de elementos
	struct no_ * inicio; // Ponteiro para o primeiro nó da lista encadeada
        struct no_ * fim;   //Ponteiro para o ultimo nó da lista encadeada
} tLista;

/*Estrutura para Pilhas e Filas*/
typedef struct tipo{
    int tam;              //Variável para medir a quantidade de elementos
    struct no_ * info;   //Ponteiro para apontar para as informações dos veículos
    struct tipo * prox; //Ponteiro para o próximo elemento
}tArmazenamento;


tArmazenamento* iniciar_tipo();
tArmazenamento* encerra_tipo(tArmazenamento * tipo1);
void inserir_inicio(tArmazenamento * tipo1, no * ptr);
void inserir_fim(tArmazenamento * tipo1, no * ptr);
tArmazenamento * busca (tLista * lista1, string elemento1, string elemento2, int opcao);
bool procura (string busca, no * pont);
void imprime(tArmazenamento * tipo1);

void relatorio(tLista * lista1);
bool busca_lista(tLista * lista1, no * novo);
bool incluir (no * novo, tLista * lista1);
tLista * encerra_lista(tLista * lista1);
tLista* inicia_lista();
no * remover_lista(string busca1, tLista * lista1);


#endif /* LISTA_H */

