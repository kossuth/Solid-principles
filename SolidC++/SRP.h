#pragma once
#include "SolidPrinciple.h"


class Client
{
private:
    string nombre;
    string apellido;
public:
    Client(string _nombre, string _apellido) : nombre(_nombre), apellido(_apellido) {};

};

class Product
{
private:
    string description;
    double price;
public:
    Product(string _description, double _price) : description(_description), price(_price) {}
    double getPrice();

    string getDescription();
};


class Item
{
private:
    Product product;
    int quantity;
public:
    Item(Product _product, int _quantity) : product(_product), quantity(_quantity) {};
    double subTotal(void);
    Product getProduct();
    int getQuantity();

};

class Invoice {
private:
    int numero;
    Client client;
    list<Item> items;
public:

    Invoice(int _numero, Client _client) :numero(_numero), client(_client) {};

    void addItem(Item _item);

    double total();
    list<Item> getItems();

};


class SRP : public SolidPrinciple
{    
public:
    SRP(string name) :SolidPrinciple(name){};
    void startPrinciple() override;
};

