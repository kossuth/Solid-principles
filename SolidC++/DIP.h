#pragma once
#include "SolidPrinciple.h"

struct IDIP_Printer {
	virtual void print() = 0;
};

class DIP_Printer {
public:
	void print(IDIP_Printer* printer);
};

class DIP_Document : public IGetTime, public IDIP_Printer {
private:
	int _number;
	time_t _date;
	double _amount;
public:
	DIP_Document(int number, time_t date, int amount ) : _number(number),_date(date),_amount(amount){};
	int getNumber() { return _number; };
	string getDate() { return getDateFormatFromTime(_date); };
	double getAmount() { return _amount; };
	
	virtual double total() = 0;
	virtual void print() = 0;
};

class DIP_CreditNote : public DIP_Document
{
public:
	DIP_CreditNote(int number, time_t date, int amount) : DIP_Document(number, date, amount) { };
	double total() override;
	void print() override;
};

class DIP_Invoice : public DIP_Document
{
public:
	DIP_Invoice(int number, time_t date, int amount) : DIP_Document(number, date, amount) {};
	double total() override;
	void print() override;
};


class DIP_Taxes : public IDIP_Printer {
private:
	double _amount;
public:
	DIP_Taxes(int amount) : _amount(amount) {};
	double getAmount() { return _amount; };
	virtual double total() = 0;
	virtual void print() = 0;
};

class DIP_LocalTaxes: public DIP_Taxes
{
public:
	DIP_LocalTaxes(int amount) :DIP_Taxes(amount) {};
	double total() override;
	void print() override;
};

class DIP_GeneralTaxes :public DIP_Taxes
{
public:
	DIP_GeneralTaxes(int amount) :DIP_Taxes(amount) {};
	double total() override;
	void print() override;
};


class Salary : public IDIP_Printer
{
public:
	Salary(int quantity, double total) :_quantity(quantity), _total(total) {};
	void print() override;
private:
	int _quantity;
	double _total;

};

class ISP_Remit :public IGetTime, public IDIP_Printer
{
public:
	ISP_Remit(int number, time_t date, int quantity) :_number(number),_date(date), _quantity(quantity) {};
	void print() override;
	string getDate() { return getDateFormatFromTime(_date); };
private:
	int _number;
	time_t _date;
	int _quantity;
};



class DIP : public SolidPrinciple
{
public:
	DIP() :SolidPrinciple("Dependency inversion principle") {};
	void startPrinciple() override;
};


