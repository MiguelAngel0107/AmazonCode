#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Product
{
public:
    Product(const std::string &name, double price, int stock) : name(name), price(price), stock(stock){};

    std::string getName() const
    {
        return name;
    };
    double getPrice() const
    {
        return price;
    };
    int getStock() const
    {
        return stock;
    };

    json toJson() const
    {
        json productJson = {
            {"name", name},
            {"price", price},
            {"stock", stock},
        };
        return productJson;
    };

private:
    std::string name;
    double price;
    int stock;
};

#endif // PRODUCT_H