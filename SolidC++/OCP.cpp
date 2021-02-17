#include "OCP.h"
string OCP_Invoice::description() {

	return "OCP_Invoice-" + std::to_string(getNumber());

}

string OCP_CreditNote::description() {

	return "OCP_CreditNote-" + std::to_string(getNumber());

}

string OCP_DebitNote::description() {

	return "OCP_DebitNote-" + std::to_string(getNumber());

}



void OCP::startPrinciple() {

	cout << "\n\n" + getName() + "\n";
	OCP_Invoice invoice(123);
	cout << invoice.description()<<"\n";
	
	OCP_CreditNote creditNote(123);
	cout << creditNote.description() << "\n";

	OCP_DebitNote debitNote(123);
	cout << debitNote.description() << "\nEnd : " + getName() + "\n";

}