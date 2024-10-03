#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "Fila.h" // Inclui a implementa��o da Fila
#include "Pilha.h" // Inclui a implementa��o da Pilha
#include "struct.h"

using namespace std;

// Cabe�alho do programa
// Nome do aluno: Jo�o Pedro Furiati
// Objetivo: Armazenar notas e matr�culas em uma fila e orden�-las em uma pilha.
// Entrada: Matr�culas e notas fornecidas pelo usu�rio.
// Resultado: Exibi��o das matr�culas e notas ordenadas na tela (da maior � menor).

void imprimir(){
    TipoDado aluno;
    while(!Pilha_Vazia){
        Pilha_Desempilhar(aluno);
        cout << "matricula:" << aluno.matricula;
        cout << "nota:" << aluno.nota;
    }
}

int main() {
    Pilha_Construtor(); // Pilha para armazenar dados
    Fila_Construtor(); // Fila para ordenar dados
    TipoDado aluno;
    TipoDado Frente;
    TipoDado Top;
    int opcao;

    do {
        system("cls"); // Limpa a tela
        cout << "Menu:" << endl;
        cout << "1 - Adicionar nota e matricula" << endl;
        cout << "2 - Desempilhar" << endl;
        cout << "3 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << endl << "Digite a matricula do aluno: ";
                cin >> aluno.matricula;
                cout << "Digite a nota do aluno: ";
                cin >> aluno.nota;

                // Enfileira o aluno
                Fila_Enfileirar(aluno);

                cout << endl << "Aluno adicionado com sucesso!\n";
                system("pause"); // Pausa para visualizar a mensagem
                break;

            case 2:
                if(Fila_Frente(Frente) && Pilha_Topo(Top)){
                    if(Pilha_Vazia()){
                        Pilha_Empilhar(Frente);
                    }
                    else if(!Pilha_Vazia){
                        if(Pilha_Topo(Top) > Fila_Frente(Frente)){
                            Fila_Enfileirar(Top);
                            Pilha_Desempilhar(Top);
                        }
                        else {
                            Pilha_Empilhar(Frente);
                            Fila_Desenfileirar(Frente);
                        }
                    }
                }
                imprimir();
                system("pause"); // Pausa para visualizar a mensagem
                break;

            case 3:
                cout << "Saindo...\n";
                break;

            default:
                cout << "Opcao invalida. Tente novamente.\n";
                system("pause"); // Pausa para visualizar a mensagem
        }
    } while (opcao != 3);

    Pilha_Destrutor();
    Fila_Destrutor();
    return 0;
}
