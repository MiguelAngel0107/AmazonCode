#ifndef PRODUCT_H
#define PRODUCT_H

#include "../categoria/controller.h"
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Product
{
public:
    Product(int id, const std::string &name, double price, int stock, const Category &category) :id(id), name(name), price(price), stock(stock), category(category){};

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
    const Category &getCategory() const
    {
        return category;
    };

    json toJson() const
    {
        json productJson = {
            {"id", id},
            {"name", name},
            {"price", price},
            {"stock", stock},
        };
        return productJson;
    };

private:
    int id;
    std::string name;
    double price;
    int stock;
    Category category;
};

#endif // PRODUCT_H