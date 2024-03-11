#include <iostream>
#include <iomanip> // Para manipulação de saída formatada

int main() {
    // Definindo os preços dos produtos
    double preco_caderno = 5.00;
    double preco_caneta = 1.50;
    double preco_afia = 0.75;
    double preco_borracha = 0.50;
    double preco_lapis = 0.75;

    // Valor fornecido pelo cliente
    double valor_fornecido = 10.00;

    // Calculando o troco para cada produto
    double troco_caderno = valor_fornecido - preco_caderno;
    double troco_caneta = valor_fornecido - preco_caneta;
    double troco_afia = valor_fornecido - preco_afia;
    double troco_borracha = valor_fornecido - preco_borracha;
    double troco_lapis = valor_fornecido - preco_lapis;

    // Imprimindo a tabela com preços e troco
    std::cout << "+--------------+----------+---------+" << std::endl;
    std::cout << "|   Produto    |  Preço   |  Troco  |" << std::endl;
    std::cout << "+--------------+----------+---------+" << std::endl;
    std::cout << "|   Caderno    |  $5.00   |  $" << std::fixed << std::setprecision(2) << troco_caderno << "  |" << std::endl;
    std::cout << "|   Caneta     |  $1.50   |  $" << std::fixed << std::setprecision(2) << troco_caneta << "  |" << std::endl;
    std::cout << "|   Afia       |  $0.75   |  $" << std::fixed << std::setprecision(2) << troco_afia << "  |" << std::endl;
    std::cout << "|   Borracha   |  $0.50   |  $" << std::fixed << std::setprecision(2) << troco_borracha << "  |" << std::endl;
    std::cout << "|   Lápis      |  $0.75   |  $" << std::fixed << std::setprecision(2) << troco_lapis << "  |" << std::endl;
    std::cout << "+--------------+----------+---------+" << std::endl;

    return 0;
}
