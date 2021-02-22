from principles.base import SolidPrinciple

from .utils import *


class Srp(SolidPrinciple):

    def __init__(self):
        super().__init__('Example : Single responsibility principle')

    def start_principle(self):
        print(self.get_name())

        client = Client("Test", "Solid")
        i1 = Item(Product("p1", 20.3), 2)
        i2 = Item(Product("p2", 30.3), 3)

        f1 = Invoice(1123, client)

        f1.add_item(i1)
        f1.add_item(i2)

        # todo OCP - Reporter or Formater.
        for it in f1.get_items():
            prod = it.get_product()
            print(
                f'Product Description: {prod.get_description()} \t quantity: {it.get_quantity()} \t Price: {prod.get_price()} \t subTotal: {it.get_sub_total()}')

        print(f'Total : \t {f1.total()} \nEnd : {self.get_name()} \n')
