#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>
#include <vector>

class Category
{
public:
    Category(int id, const std::string &name) : name(name){};

    std::string getName() const
    {
        return name;
    };

private:
    int id;
    std::string name;
};

#endif // CATEGORY_H