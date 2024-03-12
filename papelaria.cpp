#include <iostream>
#include <iomanip>
#include <string>

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
    const int tamanho = 5;
    Item itens[tamanho] = {
        {1, "Caderno", 1.5, 2.5, 100, 65, 150},
        {2, "Caneta", 0.5, 0.75, 150, 40, 200},
        {3, "Afia", 1.0, 1.50, 50, 170, 100},
        {4, "Borracha", 0.45, 0.75, 3, 250, 120},
        {5, "Lápis", 0.25, 0.75, 75, 40, 80}
    };

    imprimirTabela(itens, tamanho);

    return 0;
}

