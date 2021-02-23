#pragma once
#include "SolidPrinciple.h"


class Client
{
private:
    string _name;
    string _lastName;
public:
    Client(string name, string lastName) : _name(name), _lastName(lastName) {};

};

class Product
{
private:
    string _description;
    double _price;
public:
    Product(string description, double price) : _description(description), _price(price) {}
    double getPrice();

    string getDescription();
};


class Order
{
private:
    Product _product;
    int _quantity;
public:
    Order(Product product, int quantity) : _product(product), _quantity(quantity) {};
    double subTotal(void);
    Product getProduct();
    int getQuantity();

};

class Invoice {
private:
    int _numero;
    Client _client;
    list<Order> _orders;
public:

    Invoice(int numero, Client client) :_numero(numero), _client(client) {};

    void addOrder(Order item);

    double total();
    list<Order> getOrders();

};


class SRP : public SolidPrinciple
{    
public:
    SRP() :SolidPrinciple("Example : Single responsibility principle"){};
    void startPrinciple() override;
};

