/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*
 |           UNIFAL − Universidade Federal de Alfenas.        |
 |             BACHARELADO EM CIENCIA DA COMPUTACAO.          |
 | Trabalho...: Gerenciador de Busca de Carros                |
 | Componentes:                                               |
 | 1) Daniel da Costa Lima - R.A.: 2021.1.08.026              |
 | 2) Renan Magalhães Lage - R.A.: 2021.1.08.020              |
 *−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/

#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

#include "lista.h"

using namespace std;


tLista * lista1;

int main(int argc, char** argv) {
    /*Variável para guardar o valor da opção a ser requisitada*/
    int opcao;
            
    /*Variável para saber as opções de dados de busca dos veículos
     Também irá ser usada para saber a placa do veículo que o usuário 
     * deseja remover*/
    string elemento1, elemento2;
    
    tArmazenamento * fila1;
    tArmazenamento * pilha1;
    
    /*Variável que servirá para constar se já foi feita uma busca
     se =0 significa que a Pilha/Fila está vazia, ou seja, não foi armazenado
     nenhum dado de busca nesses lugares, caso seja =1 significa que precisamos
     deletar o conteúdo que está na Pilha/Fila*/
    int testePilha = 0, testeFila = 0;
    
    /*Variável que servirá para averiguar se o arquivo existe ou não*/
    int arquivo = 0;
    
    /*Variável que irá receber o nome do arquivo a ser lido*/
    string nomearq;
    
    
    /*Mensagem inicial exibida para a leitura do nome do arquivo que deseja ser aberto*/
    cout << "+------------------------------------------------+" << endl;
    cout << "| Digite o nome do arquivo txt que deseja abrir: |" <<endl;
    cout << "|           EX: BD_veiculos.txt                  |"<<endl;
    cout << "+------------------------------------------------+" << endl;
    /*O nome da imagem deverá conter o formato da imagem como indicado no exemplo*/
    cin >> nomearq ;
    
    /*Obtendo as informações do Arquivo*/
    ifstream myfile1 (nomearq);
    if (myfile1.is_open()){
        /*Inicialização da Lista*/
        lista1 = inicia_lista();
        while (!myfile1.eof() ){
            no * novo = new no();
            myfile1 >> novo->modelo;
            myfile1 >> novo->marca;
            myfile1 >> novo->tipo;
            myfile1 >> novo->ano;
            myfile1 >> novo->km;
            myfile1 >> novo->potenciaMotor;
            myfile1 >> novo->combustivel;
            myfile1 >> novo->cambio;
            myfile1 >> novo->direcao;
            myfile1 >> novo->cor;
            myfile1 >> novo->portas;
            myfile1 >> novo->placa;  
            novo->prox = NULL;
            incluir (novo, lista1);
            arquivo = 1;
        }
        myfile1.close();
    }
    else{
        cout << "Arquivo não encontrado."<<endl;
    }


    
    if(arquivo == 1){
        do{
            cout << "  +--------------------+"<<endl;
            cout << "  |   MENU DE OPÇÕES   |"<<endl;
            cout << "  +--------------------+"<<endl;
            cout << "  |   1) INSERIR       |"<<endl;
            cout << "  |   2) REMOVER       |"<<endl;
            cout << "  |   3) BUSCAR        |"<<endl;
            cout << "  |   4) RELATÓRIO     |"<<endl;
            cout << "  |   0) SAIR          |"<<endl;
            cout << "  +--------------------+"<<endl;

            cout << " Digite a opção desejada : " << endl;
            cin >> opcao;

            /*Caso o usuario digitar algum número que esta fora das 
            opções exibe a seguinte mensagem:*/
            while ( opcao < 0 || opcao > 4){
                cout << " ATENÇÃO - Digite um número que esteja entre as opções: " << endl;
                cin >> opcao;
            }

            /*Caso digitar ZERO o programa ira ser 
            fechado e exibira a seguinte mensagem:*/ 
            if ( opcao == 0){
                ofstream myfile2;
                nomearq = "NOVO_" + nomearq;
                myfile2.open (nomearq);
                    if (myfile2.is_open()){
                        no * aux = lista1->inicio;
                        while(aux != NULL){
                            if(lista1->tam == 1){
                                myfile2 << aux->modelo << " ";
                                myfile2 << aux->marca<< " ";
                                myfile2 << aux->tipo<< " ";
                                myfile2 << aux->ano<< " ";
                                myfile2 << aux->km<< " ";
                                myfile2 << aux->potenciaMotor<< " ";
                                myfile2 << aux->combustivel<< " ";
                                myfile2 << aux->cambio<< " ";
                                myfile2 << aux->direcao<< " ";
                                myfile2 << aux->cor<< " ";
                                myfile2 << aux->portas<< " ";
                                myfile2 << aux->placa;
                                aux = aux->prox;
                            }
                            else{
                                myfile2 << aux->modelo << " ";
                                myfile2 << aux->marca<< " ";
                                myfile2 << aux->tipo<< " ";
                                myfile2 << aux->ano<< " ";
                                myfile2 << aux->km<< " ";
                                myfile2 << aux->potenciaMotor<< " ";
                                myfile2 << aux->combustivel<< " ";
                                myfile2 << aux->cambio<< " ";
                                myfile2 << aux->direcao<< " ";
                                myfile2 << aux->cor<< " ";
                                myfile2 << aux->portas<< " ";
                                myfile2 << aux->placa<<endl;
                                aux = aux->prox;
                            }
                            lista1->tam--;     
                        }
                        myfile2.close();
                    }
                    else {
                        cout << "Nao foi possivel gerar o arquivo";
                    } 
                /*Removendo a Pilha/Fila*/
                if (testePilha == 1 ){
                    encerra_tipo(pilha1);
                    testePilha = 0;
                }
                if (testeFila == 1){
                    encerra_tipo(fila1);
                    testeFila = 0;
                }
                /*Removendo a Lista*/
                lista1 = encerra_lista(lista1);
                cout << "  +------------------+" << endl;
                cout << "  |       EXIT       |" << endl;
                cout << "  +------------------+" << endl;
            }

            /* 1 - Inserir */
            if(opcao == 1){
            cout << " A opção 1 - Inserir foi selecionada" <<endl;
                no * novo = new no();
                cout << " Digite o modelo do veículo: " << endl;
                cin >> novo->modelo;

                cout << " Digite a marca do veículo: " << endl;
                cin >> novo->marca;

                cout << " Digite o tipo do veículo: " << endl;
                cin >> novo->tipo;

                cout << " Digite o ano do veículo: " << endl;
                cin >> novo->ano;

                cout << " Digite a km do veículo: " << endl;
                cin >> novo->km;

                cout << " Digite a Potência do Motor do veículo: " << endl;
                cin >> novo->potenciaMotor;

                cout << " Digite o combustível do veículo: " << endl;
                cin >> novo->combustivel;

                cout << " Digite o câmbio do veículo: " << endl;
                cin >> novo->cambio;

                cout << " Digite a direção do veículo: " << endl;
                cin >> novo->direcao;

                cout << " Digite a cor do veículo: " << endl;
                cin >> novo->cor;

                cout << " Digite a quantidade de portas do veículo: " << endl;
                cin >> novo->portas;

                cout << " Digite a placa do veículo: " << endl;
                cin >> novo->placa;

                novo->prox = NULL;
                if (incluir (novo, lista1)){
                    cout << " Veículo inserido com sucesso! " << endl;
                    cout << endl;
                }
                else{
                    cout << "  +--------------------------------------+" << endl;
                    cout << "  |   O veículo já está existe na Lista  |" << endl;
                    cout << "  +--------------------------------------+" << endl;
                }


            }

            /* 2 - Remover */
            if(opcao == 2){
                cout << " A opção 2 - Remover foi selecionada" <<endl;
                cout << " Digite a placa do veículo que deseja remover: " << endl;
                cin >> elemento1;
                no * deletar;
                deletar = remover_lista(elemento1, lista1);
                if(deletar != NULL){
                    cout << "O veículo de placa (" << deletar->placa << ") foi removido com sucesso!" << endl;
                }
            }

            /* 3 - Buscar */
            if(opcao == 3){
                cout << "  A opção 3 - Buscar foi selecionada" <<endl;
                cout << "  +-----------------------------------+" << endl;
                cout << "  | Escolha a forma de armazenamento: |" << endl;
                cout << "  |           1) PILHA                |" << endl;
                cout << "  |           2) FILA                 |" << endl;
                cout << "  +-----------------------------------+" << endl;
                cout << " Digite a opção de armazenamento desejada : " << endl;
                cin >> opcao;
                while ( opcao <= 0 || opcao > 2){
                    cout << " ATENÇÃO - Digite um número que esteja entre as opções: " << endl;
                    cin >> opcao;
                }
                /* 1 - PILHA */
                if (opcao == 1){              
                    /*Desalocando a Pilha para realização de nova busca*/
                    if (testePilha == 1){
                        encerra_tipo(pilha1);
                        testePilha = 0;
                    }
                    cout << " Você selecionou a opção Pilha" <<endl;
                    cout <<endl;
                    cout << " Digite o PRIMEIRO elemento de busca desejada : " << endl;
                    cout << " EX: Se deseja buscar por carros de quatro portas digite: 4 " << endl;
                    cin >> elemento1;
                    cout << " Digite o SEGUNDO elemento de busca desejada : " << endl;
                    cout << " EX: Se deseja buscar por carros de câmbio automático digite: Automatico " << endl;
                    cin >> elemento2;
                    /*Chamando a função busca*/
                    pilha1 = busca (lista1, elemento1, elemento2, opcao);
                    imprime(pilha1);
                    testePilha = 1;


                }
                else{ /* 2 - FILA*/
                    /*Desalocando a Pilha para realização de nova busca*/
                    if (testeFila == 1){
                        encerra_tipo(fila1);
                        testeFila = 0;
                    }
                    cout << "Você selecionou a opção Fila" <<endl;
                    cout <<endl;
                    cout << " Digite o PRIMEIRO elemento de busca desejada : " << endl;
                    cout << " EX: Se deseja buscar por carros de quatro portas digite: 4 " << endl;
                    cin >> elemento1;
                    cout << " Digite o SEGUNDO elemento de busca desejada : " << endl;
                    cout << " EX: Se deseja buscar por carros de câmbio automático digite: Automatico " << endl;
                    cin >> elemento2;
                    /*Chamando a função busca*/
                    fila1 = busca (lista1, elemento1, elemento2, opcao);
                    imprime(fila1);
                    testeFila = 1;


                }
            }

            /* 4 - Relatório */
            if(opcao == 4){
                cout << "  A opção 4 - Relatório foi selecionada" <<endl;
                relatorio(lista1);
            }

        }while (opcao != 0);
    }
              


    return 0;
}

