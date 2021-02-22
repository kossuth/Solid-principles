#include "SRP.h"
double Product::getPrice() {
	return _price;
}

string Product::getDescription(){
    return _description;
};


double Item::subTotal() {
	return _quantity * _product.getPrice();
}

Product Item::getProduct() {
    return _product;
}
int Item::getQuantity() {
    return _quantity;
}

void Invoice::addItem(Item _item)
{
    _items.push_back(_item);

}

double Invoice::total() {
    double _total = 0;
    for (Item& item : _items)
    {
        _total += item.subTotal();
    }

    return _total;
}

list<Item> Invoice::getItems() {
    return _items;
}

void SRP::startPrinciple() {

    cout << "\n\n"+getName() + "\n";

    Client client("Test", "Solid");

    Item i1(Product("p1", 20.3), 2);
    Item i2(Product("p2", 30.3), 3);

    Invoice f1(1123, client);

    f1.addItem(i1);
    f1.addItem(i2);
    
    // todo OCP - Reporter or Formater.
    for (Item& it : f1.getItems())
    {
        Product prod = it.getProduct();
        std::cout << "Product Description: " << prod.getDescription() <<"\t quantity:"<< it.getQuantity()  << "\t Price: " << prod.getPrice() << "\t subTotal: " << it.subTotal() << "\n";
    }

    std::cout << "Total : \t" << f1.total() << "\nEnd : "+ getName() + "\n";
}