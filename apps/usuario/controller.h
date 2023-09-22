#ifndef USER_H
#define USER_H

#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class User
{
public:
    User(int id, const std::string &email, const std::string &password, const std::string &name, double money, const std::string &role, bool state)
        : id(id), email(email), password(password), name(name), money(money), role(role), state(state){};

    int getId() const
    {
        return id;
    };
    std::string getEmail() const
    {
        return email;
    };
    std::string getPassword() const
    {
        return password;
    };
    std::string getName() const
    {
        return name;
    };
    double getMoney() const
    {
        return money;
    };
    std::string getRole() const
    {
        return role;
    };
    bool getState() const
    {
        return state;
    };

    // Puedes agregar otros métodos y setters según sea necesario

    json toJson() const
    {
        json userJson = {
            {"id", id},
            {"email", email},
            {"password", password},
            {"name", name},
            {"money", money},
            {"role", role},
            {"state", state}};
        return userJson;
    };

private:
    int id;
    std::string email;
    std::string password;
    std::string name;
    double money;
    std::string role;
    bool state;
};

#endif // USER_H
