#pragma once
#include "SolidPrinciple.h"

class IPrinter
{
public:
	virtual string print() = 0;
};



class LSP_Document : public IPrinter, public IGetTime
{
	string _acronym;
	int _number;
	time_t _date;
public:
	
	LSP_Document(int number, time_t date) :_number(number), _date(date) {};
	void setAcronym(string acronym) {_acronym = acronym;}
	string getAcronym() { return _acronym; }
	string print();
	string description();
		

};


class LSP_Invoice : public LSP_Document {
public:
	LSP_Invoice(int number, time_t date);
};

class LSP_CreditNote : public LSP_Document {
public:
	LSP_CreditNote(int number, time_t date);
};


class Remit : public IPrinter, public IGetTime
{
private:
	int _number;
	int _quantity;
	time_t _date;
public:
	Remit(int number, time_t date, int quantity) :_number(number), _date(date), _quantity(quantity){};
	string print();

private:

};


class Printer
{
public:
	void printDocument(IPrinter* document);
};

class LSP : public SolidPrinciple
{
public:
	LSP(string name) :SolidPrinciple(name) {};
	void startPrinciple() override;
};

