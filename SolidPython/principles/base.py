from abc import ABC, abstractmethod

class SolidPrinciple(ABC):
    __name: str
    def __init__(self, name:str):
        self.__name=name

    def get_name(self)->str:
        return self.__name
    
    @abstractmethod
    def start_principle(self):
        pass
   