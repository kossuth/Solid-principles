from abc import ABC, ABCMeta, abstractmethod
from datetime import datetime


class IGetTime:
    __metaclass__ = ABCMeta

    def get_date_format_from_time(self, date: datetime = None) -> str:
        if date == None:
            date = datetime.now()
        return date.strftime("%m/%d/%Y, %H:%M:%S")


class SolidPrinciple(ABC):
    __name: str

    def __init__(self, name: str):
        self.__name = name

    def get_name(self) -> str:
        return self.__name

    @abstractmethod
    def start_principle(self):
        pass
