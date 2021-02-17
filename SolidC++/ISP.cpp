#include "ISP.h"

void ISP_Invoice::print() {
    cout << "ISP_Invoice::print : number :" + std::to_string(getNumber()) + " time:" + getDate() +"\n";
}

string ISP_Document::getDate()
{
    return getDateFormatFromTime(_date);
}

void ISP_ElectronicInvoice::sendEmail()
{
    cout << "ISP_ElectronicInvoice::sendEmail : number :" + std::to_string(getNumber()) + " time:" + getDate() + "\n";
}

void ISP_ElectronicInvoice::print() {
    cout << "ISP_ElectronicInvoice::print : number :" + std::to_string(getNumber()) + " time:" + getDate() + "\n";
}

void ISP::startPrinciple() {

    cout << "\n\n" + getName() + "\n";

    ISP_Invoice invoice(123, time(NULL));
    invoice.print();

    ISP_ElectronicInvoice eInvoice(333, time(NULL));
    eInvoice.sendEmail();
    eInvoice.print();

    std::cout << "\nEnd : " + getName() + "\n";
}

