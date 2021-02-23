#include "SRP.h"
double Product::getPrice() {
	return _price;
}

string Product::getDescription(){
    return _description;
};


double Order::subTotal() {
	return _quantity * _product.getPrice();
}

Product Order::getProduct() {
    return _product;
}
int Order::getQuantity() {
    return _quantity;
}

void Invoice::addOrder(Order tmpOrder)
{
    _orders.push_back(tmpOrder);

}

double Invoice::total() {
    double _total = 0;
    for (Order& item : _orders)
    {
        _total += item.subTotal();
    }

    return _total;
}

list<Order> Invoice::getOrders() {
    return _orders;
}

void SRP::startPrinciple() {

    cout << "\n\n"+getName() + "\n";

    Client client("Test", "Solid");

    Order order(Product("p1", 20.3), 2);
    Order order2(Product("p2", 30.3), 3);

    Invoice invoice(1123, client);

    invoice.addOrder(order);
    invoice.addOrder(order2);
    
    // todo OCP - Reporter or Formater.
    for (Order& tmpOrder : invoice.getOrders())
    {
        Product prod = tmpOrder.getProduct();
        std::cout << "Product Description: " << prod.getDescription() <<"\t quantity:"<< tmpOrder.getQuantity()  << "\t Price: " << prod.getPrice() << "\t subTotal: " << tmpOrder.subTotal() << "\n";
    }

    std::cout << "Total : \t" << invoice.total() << "\nEnd : "+ getName() + "\n";
}