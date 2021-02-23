from abc import ABCMeta, abstractmethod
from datetime import datetime

from principles.base import IGetTime


class IPrinter:
    __metaclass__ = ABCMeta
    @abstractmethod
    def print(self) -> str: raise NotImplementedError


class LSP_Document(IPrinter, IGetTime):

    __acronym: str
    __number: int
    __date: datetime

    def __init__(self, number: int, date: datetime):
        self.__number = number
        self.__date = date

    def set_acronym(self, acronym: str):
        self.__acronym = acronym

    def get_acronym(self):
        return self.__acronym

    def set_number(self, number: int):
        self.__number = number

    def get_number(self):
        return self.__number

    def set_date(self, date: datetime):
        self.__date = date

    def get_date(self):
        return self.__date

    def print(self) -> str:
        return f'Print {self.description()}'

    def description(self) -> str:
        return f'acronym : {self.get_acronym()} number : {self.get_number()} + time: {self.get_date_format_from_time(self.get_date())}'


class LSP_Invoice(LSP_Document):
    def __init__(self, number: int, date: datetime):
        self.set_acronym("LSP_Invoice")
        super().__init__(number, date)


class LSP_CreditNote(LSP_Document):
    def __init__(self, number: int, date: datetime):
        self.set_acronym("LSP_CreditNote")
        super().__init__(number, date)


class Remit(IPrinter, IGetTime):
    __number: int
    __quantity: int
    __date: datetime

    def __init__(self, number: int, date: datetime, quantity: int):
        self.__number = number
        self.__date = date
        self.__quantity = quantity

    def get_number(self):
        return self.__number

    def get_quantity(self):
        return self.__quantity

    def get_date(self):
        return self.__date

    def print(self) -> str:
        return f'Remit::print --- number : {self.get_number()}  quantity : {self.get_quantity()} time: {self.get_date_format_from_time(self.get_date())}'


class Printer:
    def print_document(self, document: IPrinter) -> str:
        print(document.print())
