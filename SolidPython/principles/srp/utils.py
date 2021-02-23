
class Client():
    __name: str
    __last_name: str

    def __init__(self, name: str, last_name: str):
        self.__name = name
        self.__last_name = last_name


class Product():
    __description: str
    __price: float

    def __init__(self, description: str, price: float):
        self.__description = description
        self.__price = price

    def get_price(self) -> float:
        return self.__price

    def get_description(self) -> str:
        return self.__description


class Order():
    __product: Product
    __quantity: int

    def __init__(self, product: Product, quantity: int):
        self.__product = product
        self.__quantity = quantity

    def get_product(self) -> Product:
        return self.__product

    def get_quantity(self) -> int:
        return self.__quantity

    def get_sub_total(self) -> int:
        return self.__quantity * self.__product.get_price()


class Invoice():
    __number: int
    __client: Client
    __orders: list[Order]

    def __init__(self, number: int, client: Client):
        self.__number = number
        self.__client = client
        self.__orders = []

    def add_order(self, order: Order) -> None:
        self.__orders.append(order)

    def total(self) -> float:
        total = 0.0
        for item in self.__orders:
            total += item.get_sub_total()

        return total

    def get_orders(self) -> list[Order]:
        return self.__orders
