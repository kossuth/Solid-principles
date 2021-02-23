from abc import ABC, abstractmethod


class AccountingDocument(ABC):
    __number: int

    def __init__(self, number: int):
        self.__number = number

    def get_number(self) -> int:
        return self.__number

    @abstractmethod
    def get_description(self) -> str:
        pass


class OCP_Invoice(AccountingDocument):
    def __init__(self, number: int):
        super().__init__(number)

    def get_description(self) -> str:
        return "OCP_Invoice-%s" % self.get_number()


class OCP_CreditNote(AccountingDocument):
    def __init__(self, number: int):
        super().__init__(number)

    def get_description(self) -> str:
        return "OCP_CreditNote-%s" % self.get_number()


class OCP_DebitNote(AccountingDocument):
    def __init__(self, number: int):
        super().__init__(number)

    def get_description(self) -> str:
        return "OCP_CreditNote-%s" % self.get_number()
