#ifndef USER_H
#define USER_H

#include <string>

class User
{
public:
    User(int id, const std::string &email, const std::string &password, const std::string &name, double money, const std::string &role, bool state)
        : id(id), email(email), password(password), name(name), money(money), role(role), state(state) {};

    int getId() const
    {
        return id;
    }

    void setId(int newId)
    {
        id = newId;
    }

    std::string getEmail() const
    {
        return email;
    }

    void setEmail(const std::string &newEmail)
    {
        email = newEmail;
    }

    std::string getPassword() const
    {
        return password;
    }

    void setPassword(const std::string &newPassword)
    {
        password = newPassword;
    }

    std::string getName() const
    {
        return name;
    }

    void setName(const std::string &newName)
    {
        name = newName;
    }

    double getMoney() const
    {
        return money;
    }

    void setMoney(double newMoney)
    {
        money = newMoney;
    }

    std::string getRole() const
    {
        return role;
    }

    void setRole(const std::string &newRole)
    {
        role = newRole;
    }

    bool getState() const
    {
        return state;
    }

    void setState(bool newState)
    {
        state = newState;
    }

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
