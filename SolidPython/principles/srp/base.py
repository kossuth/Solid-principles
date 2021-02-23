from principles.base import SolidPrinciple

from .utils import Client, Order, Product, Invoice


class Srp(SolidPrinciple):

    def __init__(self):
        super().__init__('Example : Single responsibility principle')

    def start_principle(self):
        print(self.get_name())

        client = Client("Test", "Solid")
        order = Order(Product("p1", 20.3), 2)
        order2 = Order(Product("p2", 30.3), 3)

        invoice = Invoice(1123, client)

        invoice.add_order(order)
        invoice.add_order(order2)
        
        for it in invoice.get_orders():
            prod = it.get_product()
            print(
                f'Product Description: {prod.get_description()} \t quantity: {it.get_quantity()} \t Price: {prod.get_price()} \t subTotal: {it.get_sub_total()}')

        print(f'Total : \t {invoice.total()} \nEnd : {self.get_name()} \n')
