#include <cstdlib>
#include <iostream>

#include "lista.h"

using namespace std;

/*Função para iniciar as Pilhas e Filas*/
tArmazenamento* iniciar_tipo(){
    tArmazenamento* tmp = new (tArmazenamento);
    tmp->info = NULL;
    tmp->prox = NULL;
    tmp->tam = 0;
    return tmp;
}

/*Função para remover Pilhas e Filas*/
tArmazenamento* encerra_tipo(tArmazenamento * tipo1){
    tArmazenamento * ant = tipo1->prox;
    tArmazenamento * pont = tipo1->prox;
	
	while(ant != NULL){
		pont = ant->prox;
		delete(ant);
		ant = pont;
	}
	delete(tipo1);
	
        return NULL;
    
}

/*Função para inserir no início - serve para a Pilha*/
void inserir_inicio(tArmazenamento * tipo1, no * ptr){
    if(tipo1->tam == 0){
        tArmazenamento * novo;
        novo = new(tArmazenamento);
        novo->info = ptr;
        novo->prox = NULL;
        tipo1->prox = novo;
        tipo1->tam++;
    }
    else{
        tArmazenamento * novo;
        novo = new(tArmazenamento);
        novo->info = ptr;
        novo->prox = tipo1->prox;
        tipo1->tam++;
        tipo1->prox = novo;       
    }   
}

/*Função para inserir no final - serve para a Fila*/
void inserir_fim(tArmazenamento * tipo1, no * ptr){
    if(tipo1->tam == 0){
        /*Lista Vazia = inicio igual a fim*/
        inserir_inicio(tipo1, ptr);
    }
    else{
        tArmazenamento * novo;
        novo = new(tArmazenamento);
        
        tArmazenamento* p = tipo1->prox;
        while (p->prox != NULL)
            /*Obtendo o último elemento*/
            p = p->prox;
        
        novo->info = ptr;
        novo->prox = NULL;
        p->prox = novo;
        tipo1->tam++;      
    }   
}

/*Função de busca de veículos*/
/*Parâmetros:
 * lista1 - recebe a lista principal
 * busca1 - recebe o primeiro parâmetro / elemento de busca
 * busca2 - recebe o segundo parâmetro / elemento de busca
 * opcao - serve para saber se é uma PILHA ou FILA 
 */

tArmazenamento * busca (tLista * lista1, string elemento1, string elemento2, int opcao){
    no * pont = lista1->inicio;
    int tamanho = lista1->tam;
    /*Foi selecionado uma PILHA*/
    if (opcao == 1){
        tArmazenamento * pilha1; 
        pilha1 = iniciar_tipo();
        while(tamanho > 0){
            if(procura(elemento1, pont)){    
                if(procura(elemento2, pont)){
                    inserir_inicio(pilha1, pont);   
                }
            }
            pont = pont->prox;
            tamanho--;
        }
        return pilha1;
        
    }/*Foi selecionado uma FILA*/
    else{
        tArmazenamento * fila1;
        fila1 = iniciar_tipo();
        while(tamanho > 0){
            if(procura(elemento1, pont)){    
                if(procura(elemento2, pont)){
                    inserir_fim(fila1, pont);   
                }
            }
            pont = pont->prox;
            tamanho--;
        }
        return fila1;
    }
}

/*Função que compara um elemento com as informações do veículo para ver se são iguais*/
bool procura (string busca, no * pont){
    if(busca == pont->marca){
        return true;
    }
    if(busca == pont->tipo){
        return true;                    
    }
    if(busca == pont->ano){
        return true;                
    }
    if(busca == pont->km){
        return true;
    }
    if(busca == pont->potenciaMotor){
        return true;                
    }
    if(busca == pont->combustivel){
        return true;                
    }
    if(busca == pont->cambio){
        return true;                
    }
    if(busca == pont->direcao){
        return true;                
    }
    if(busca == pont->cor){
        return true;                
    }
    if(busca == pont->portas){
        return true;                
    }
    if(busca == pont->placa){
        return true;                
    }   
    return false;   
}

/*Função para imprimir a Pilha/Fila*/
void imprime(tArmazenamento * tipo1){
    tArmazenamento * aux = tipo1->prox;
    int num = tipo1->tam;
    /*Caso a Pilha/Fila for vazia*/
    if(num == 0){
        cout << "  +------------------------------------------------------+" << endl;
        cout << "  |       Não existe nenhum veículo correspondete        |"<< endl;
        cout << "  |          com as características desejadas            |"<< endl;
        cout << "  +------------------------------------------------------+" << endl; 
    }
    else{
        cout << "  +-----------------------------------+" << endl;
        cout << "  |           ESTADO ATUAL:           |"<< endl;
        cout << "  |            TAMANHO = " << tipo1->tam << "            |"<< endl;
        cout << "  |           (INÍCIO)                |"<< endl;
        cout << "  |               |                   |"<< endl;
        while(num > 0){
            cout << "  |           (" << aux->info->placa<< ")               | "<< endl;
                cout << "  |               |                   |"<< endl;
                num--;
                aux= aux->prox;
            }
            cout << "  |             (FIM)                 |"<< endl;
            cout << "  +-----------------------------------+" << endl;
            cout << endl;
    }
    
}

/*Função para imprimir o estado atual da Lista */
void relatorio(tLista * lista1){
	no * ptr = lista1->inicio;
        cout << "  +-----------------------------------+" << endl;
        cout << "  |      ESTADO ATUAL DA LISTA:       |"<< endl;
        cout << "  |           TAMANHO = " << lista1->tam << "             |"<< endl;
        cout << "  |           (INÍCIO)                |"<< endl;
        cout << "  |               |                   |"<< endl;
	while(ptr != NULL){
            cout << "  |           (" << ptr->placa << ")               | "<< endl;
            cout << "  |               |                   |"<< endl;
            ptr = ptr->prox;
	}
        cout << "  |             (FIM)                 |"<< endl;
        cout << "  +-----------------------------------+" << endl;
        cout << endl;
}



/*Função que verifica se o elemento já existe na Lista*/
bool busca_lista(tLista * lista1, no * novo){
    no * ant = lista1->inicio;
    no * pont = lista1->inicio;
    while (pont != NULL){
        if (pont->placa == novo->placa){
            return true;
        }
        else{
            ant = pont;
            pont = pont->prox; 
        }
    }
    return false;
    
}
/*Função para incluir um elemento de maneira ordenada na Lista*/
/*Parametros:
 * novo - nó a ser incluido
 * placa - parâmetro de ordenação
 * lista1 - lista para o nó ser inserido
 */
bool incluir (no * novo, tLista * lista1){
    no * ant = lista1->inicio;
    no * ptr = lista1->inicio;
    /*Se a lista estiver vazia: */
    if (lista1->tam == 0){
        //lista1->lista = new(no);
        lista1->inicio = novo;
        lista1->fim = novo;
        lista1->inicio->prox = NULL;
        lista1->tam++;
        return true;
    }
    /*Verificando se o elemento já existe na Lista*/
    if(busca_lista(lista1, novo)){
        return false;
    }

        
    lista1->tam++;
    /*Se o elemento for o menor*/
    if(novo->placa < lista1->inicio->placa){
        novo->prox = lista1->inicio;  
        lista1->inicio = novo;          
    }
    else{
        /*Acha onde o elemento tem que ser colocado*/
        while(novo->placa > ptr->placa ){
            ant = ptr;
            ptr = ant->prox;
            /* Caso ptr = NULL siginifica q o elemento a ser inserido
            é o último da lista. O break serve para evitar a comparação
            com NULL, pois dá erro*/
            if(ptr == NULL){
                break;
            }
        }
        /*Caso o novo nó a ser inserido for o último elemento*/
        if (ptr == NULL){
            lista1->fim = novo;
        }
        ant->prox = novo;
        novo->prox = ptr;
            
    }
    return true;
    
}

/*Função para encerrar a Lista*/
tLista * encerra_lista(tLista * lista1) {
    no * ant = lista1->inicio;
    no * pont = lista1->inicio;
    while(ant != NULL){
	pont = ant->prox;
	delete(ant);
	ant = pont;
    }
    delete(lista1);
    cout << "  A lista foi REMOVIDA."<<endl;
	
    return NULL;
}

/*Função para iniciar a Lista*/
tLista* inicia_lista() {
    tLista* tmp = new (tLista);
    tmp->tam = 0;
    tmp->inicio = NULL;
    tmp->fim = NULL;

    cout << "  A lista foi INICIADA."<<endl;
    return tmp;
}

/*Função para remover um elemento da Lista*/
no * remover_lista(string busca1, tLista * lista1){
    no * ant = lista1->inicio;
    no * pont= lista1->inicio;
    if(lista1->tam == 0){
        cout << "  Não foi possível remover o veículo de placa ("<< busca1 <<") , pois a Lista está vazia." <<endl;
        return NULL;
    }
    /*Achando o elemento*/
    while(pont != NULL){
        if(pont->placa == busca1){
            if(pont->placa == lista1->inicio->placa){
                lista1->inicio = pont->prox;
            }
            if(pont->placa == lista1->fim->placa){
                lista1->fim = ant;
            }
            if(lista1->tam==1){
                lista1->inicio = NULL;
                lista1->fim = NULL;
                ant->prox = NULL;
                ant = NULL;
                pont->prox = NULL;
                lista1->tam--;

                return pont;
            }
            else{
                ant->prox = pont->prox;
                pont->prox = NULL;
                lista1->tam--;
            }         

            return pont;
        }
        ant = pont;
        pont = ant->prox;
    }
    cout << "  Não foi possível remover o veículo de placa ("<< busca1 <<") , pois ele não existe na Lista." <<endl;
    return NULL;
    
}




