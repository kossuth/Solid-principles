from principles.base import SolidPrinciple

from principles.ocp.utils import OCP_Invoice, OCP_CreditNote, OCP_DebitNote

class Ocp(SolidPrinciple):

    def __init__(self):
        super().__init__('Example : Open/closed principle')

    def start_principle(self):

        print(self.get_name())

        invoice = OCP_Invoice(123)
        print(invoice.get_description())

        credit_note = OCP_CreditNote(123)
        print(credit_note.get_description())

        debit_note = OCP_DebitNote(123)
        print(debit_note.get_description())

        print(f'End : {self.get_name()} \n')
