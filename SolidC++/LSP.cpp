#include "LSP.h"


string LSP_Document::print() {
	return "Print :" + description();
}

string LSP_Document::description() {
	return "acronym :" + getAcronym() + " number :" + std::to_string(_number) + " time:" + getDateFormatFromTime(_date);
}

LSP_Invoice::LSP_Invoice(int numero, time_t date) :LSP_Document(numero, date) {
	setAcronym("LSP_Invoice");
};

LSP_CreditNote::LSP_CreditNote(int numero, time_t date) :LSP_Document(numero, date) {
	setAcronym("LSP_CreditNote");
};

string Remit::print()
{
	return "Remit::print --- number :" + std::to_string(_number) + " quantity :" + std::to_string(_quantity) + " time:" + getDateFormatFromTime(_date);
};

void Printer::printDocument(IPrinter* document) {
	cout << document->print()+"\n";	
};


void LSP::startPrinciple() {

	cout << "\n\n" + getName() + "\n";

	LSP_Invoice invoice(123, time(NULL));
	LSP_CreditNote creditNode(444,time(NULL));
	
	Remit remit(777, time(NULL),8);

	Printer printer;
	printer.printDocument(&invoice);
	printer.printDocument(&creditNode);
	printer.printDocument(&remit);

	cout << "\nEnd : " + getName() + "\n";

}