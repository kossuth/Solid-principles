#pragma once
#include "SolidPrinciple.h"


using namespace std;

class AccountingDocument
{
private:
	int _number;
	
public:
	virtual string description() = 0;
	AccountingDocument(int number) :_number(number) {};

	int getNumber() { return _number; };
};


class OCP_Invoice: AccountingDocument
{
public:
	OCP_Invoice(int number) :AccountingDocument(number) {};
	string description() override;
};

class OCP_CreditNote : AccountingDocument
{
public:
	OCP_CreditNote(int number) :AccountingDocument(number) {};
	string description() override;
};

class OCP_DebitNote : AccountingDocument
{
public:
	OCP_DebitNote(int number) :AccountingDocument(number) {};
	string description() override;
};


class OCP : public SolidPrinciple
{
public:
	OCP() :SolidPrinciple("Example : Open/closed principle") {};
	void startPrinciple() override;
};

