#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct Item {
    int numero;
    string nome;
    double precoCompra;
    double precoVenda;
    int quantidadeEstoque;
    int quantidadeComprar;
    int totalVendas;
    bool reporEstoque;
};

void imprimirTabela(Item itens[], int tamanho) {
    cout << "-------------------------------------------------------------------------------------------------------" << endl;
    cout << "| Numero |          Papelaria           | Preço Compra | Preço Venda | Stock | Compras | Vendas| Repor |" << endl;
    cout << "-------------------------------------------------------------------------------------------------------" << endl;
    
    double lucroTotal = 0;
    
    for (int i = 0; i < tamanho; ++i) {
        double lucroItem = (itens[i].precoVenda - itens[i].precoCompra) * itens[i].totalVendas;
        lucroTotal += lucroItem;
        
        itens[i].reporEstoque = (itens[i].quantidadeEstoque < 80);
                
        cout << "|   " << setw(2) << itens[i].numero << "    |  " << setw(28) << left << itens[i].nome 
             << "| " << setw(12) << fixed << setprecision(2) << itens[i].precoCompra 
             << "| " << setw(11) << fixed << setprecision(2) << itens[i].precoVenda        
             << "| " << setw(7) << itens[i].quantidadeEstoque
             << " | " << setw(7) << itens[i].quantidadeComprar
             << " | " << setw(6) << itens[i].totalVendas
             << " | " << (itens[i].reporEstoque ? "Sim" : "Não")
             << "  |" << endl;
    }
    
    cout << "-------------------------------------------------------------------------------------------------------" << endl;
    cout << "Lucro Total: €" << lucroTotal << endl;
}

int main() {
    const int MAX_ITENS = 100;
    Item itens[MAX_ITENS] = {
        {1, "Caderno", 1.5, 2.5, 100, 0, 150},  
        {2, "Caneta", 0.5, 0.75, 150, 0, 200},
        {3, "Afia", 1.0, 1.50, 50, 0, 100},
        {4, "Borracha", 0.45, 0.75, 3, 0, 120},
        {5, "Lápis", 0.25, 0.75, 75, 0, 80}
    };
    int tamanho = 5;

    imprimirTabela(itens, tamanho);

    // Selecionar itens para compra
    vector<Item> listaCompra;
    int numeroItem;

    cout << "\nSelecione os itens para compra (digite 0 para finalizar):" << endl;
    do {
        cout << "Numero do item (0 para finalizar): ";
        cin >> numeroItem;
        if (numeroItem != 0) {
            bool encontrado = false;
            for (int i = 0; i < tamanho; ++i) {
                if (itens[i].numero == numeroItem) {
                    listaCompra.push_back(itens[i]); // Adiciona o item selecionado à lista de compras
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                cout << "Item não encontrado. Por favor, digite um número de item válido." << endl;
            }
        }
    } while (numeroItem != 0);

    // Exibir lista de compras
    cout << "\nLista de Compras:" << endl;
    for (const auto& item : listaCompra) {
        cout << "Nome: " << item.nome << ", Preço: €" << item.precoVenda << endl;
    }

    // Solicitar o valor total pago pelo cliente
    double totalPago;
cout << "Digite o valor total pago pelo cliente: ";
    cin >> totalPago;


    // Calcular o valor total da compra
    double totalCompra = 0;
    for (const auto& item : listaCompra) {
        totalCompra += item.precoVenda;
    }

    // Calcular o troco
    double troco = totalPago - totalCompra;
    cout << "Troco a ser dado ao cliente: €" << troco << endl;

    return 0;
}