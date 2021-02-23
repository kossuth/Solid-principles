from principles.base import SolidPrinciple

from .utils import LSP_Invoice, LSP_CreditNote, Remit, Printer


class Lsp(SolidPrinciple):

    def __init__(self):
        super().__init__('Example : Liskov substitution principle')

    def start_principle(self):

        print(self.get_name())

        invoice = LSP_Invoice(123, None)
        creditNode = LSP_CreditNote(444, None)

        remit = Remit(777, None, 8)

        printer = Printer()

        printer.print_document(invoice)
        printer.print_document(creditNode)
        printer.print_document(remit)

        print(f'End : {self.get_name()} \n')
