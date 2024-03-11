#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item {
public:
    int numero;
    string nome;
    double precoCompra;
    double precoVenda;
    double lucro;
    int quantidade;
    int quantidadeComprar;

    Item(int num, string n, double pc, double pv, int q) {
        numero = num;
        nome = n;
        precoCompra = pc;
        precoVenda = pv;
        lucro = pv - pc;
        quantidade = q;
        quantidadeComprar = 0;
    }
};

int main() {
    vector<Item> estoque;

    // Adicionando os itens ao estoque
    estoque.push_back(Item(1, "Caneta", 0.25, 0.90, 130));
    estoque.push_back(Item(2, "Caderno", 2.00, 10.00, 50));
    estoque.push_back(Item(3, "Lápis", 0.25, 0.50, 150));
    estoque.push_back(Item(4, "Borracha", 0.30, 0.60, 80));
    estoque.push_back(Item(5, "Régua", 1.00, 1.50, 70));

    // Exibindo os itens do estoque
    cout << "Estoque atual:\n";
    for (const auto& item : estoque) {
        cout << "Número do item: " << item.numero << endl;
        cout << "Nome do item: " << item.nome << endl;
        cout << "Preço de compra: " << item.precoCompra << endl;
        cout << "Preço de venda: " << item.precoVenda << endl;
        cout << "Lucro: " << item.lucro << endl;
        cout << "Quantidade em estoque: " << item.quantidade << endl;
        cout << "--------------------------\n";
    }

    return 0;
}
