#include "DIP.h"

double DIP_CreditNote::total()
{
    return getAmount();
}

void DIP_CreditNote::print()
{    
    cout << (string)typeid(*this).name() + " : number :" + std::to_string(getNumber()) + " : total :" + std::to_string(total()) + " time:" + getDate() + "\n";
}

double DIP_Invoice::total()
{
    return getAmount();
}

void DIP_Invoice::print()
{
    cout << (string)typeid(*this).name() + " : number :" + std::to_string(getNumber()) + " : total :" + std::to_string(total()) + " time:" + getDate() + "\n";
}

void DIP_Taxes::print()
{
    cout << (string)typeid(*this).name() +  " : total :" + std::to_string(total()) + "\n";
}

double DIP_LocalTaxes::total()
{
    return getAmount();
}

void DIP_LocalTaxes::print()
{
    cout << (string)typeid(*this).name() + " : total :" + std::to_string(total()) + "\n";
}

double DIP_GeneralTaxes::total()
{
    return getAmount();
}

void DIP_GeneralTaxes::print()
{
    cout << (string)typeid(*this).name() + " : total :" + std::to_string(total()) + "\n";
}

void Salary::print()
{
    cout << (string)typeid(*this).name() + " : quantity :" + std::to_string(_quantity) + " : total :" + std::to_string(_total) + "\n";
}

void ISP_Remit::print()
{
    cout << (string)typeid(*this).name() + " : number :" + std::to_string(_number) + " : quantity :" + std::to_string(_quantity) + " time:" + getDate() + "\n";
}

void DIP_Printer::print(IDIP_Printer* printer)
{
    printer->print();
}



void DIP::startPrinciple() {

    cout << "\n\n" + getName() + "\n";

    DIP_CreditNote creditNote(1,time(NULL),10);
    DIP_Invoice invoice(2, time(NULL), 20);

    DIP_LocalTaxes localTaxes(1000);
    DIP_GeneralTaxes generalTaxes(1000);

    Salary salary(5,5000);
    ISP_Remit remit(5, time(NULL), 6);


    //xample list interface pointer
    list<IDIP_Printer *> autoList;

    autoList.push_back(&creditNote);
    autoList.push_back(&invoice);
    autoList.push_back(&localTaxes);
    autoList.push_back(&generalTaxes);
    autoList.push_back(&salary);
    autoList.push_back(&remit);

    DIP_Printer printer;

    for (IDIP_Printer* it : autoList)
    {
        printer.print(it);
    }

    printer.print(&creditNote);

    std::cout << "\nEnd : " + getName() + "\n";
}


