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


class Item
{
private:
    Product _product;
    int _quantity;
public:
    Item(Product product, int quantity) : _product(product), _quantity(quantity) {};
    double subTotal(void);
    Product getProduct();
    int getQuantity();

};

class Invoice {
private:
    int _numero;
    Client _client;
    list<Item> _items;
public:

    Invoice(int numero, Client client) :_numero(numero), _client(client) {};

    void addItem(Item item);

    double total();
    list<Item> getItems();

};


class SRP : public SolidPrinciple
{    
public:
    SRP() :SolidPrinciple("Example : Single responsibility principle"){};
    void startPrinciple() override;
};

