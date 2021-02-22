#pragma once
#include "SolidPrinciple.h"

struct IISP_Printer
{
	virtual void print() = 0;
};

struct IISP_Mail
{
	virtual void sendEmail() = 0;
};

class ISP_Document :public IGetTime {
private:
	int _number;
	time_t _date;
public:
	ISP_Document(int number, time_t date) :_number(number), _date(date) {};
	int getNumber() { return _number; };
	string getDate();
};

class ISP_Invoice : public ISP_Document, public IISP_Printer {
private:
	string CAI;
public:
	ISP_Invoice(int number, time_t date) :ISP_Document(number, date) {};
	void print() override;
};

class ISP_ElectronicInvoice : public ISP_Document, public IISP_Printer, public IISP_Mail {
private:
	string CAI;
public:
	ISP_ElectronicInvoice(int number, time_t date) :ISP_Document(number, date) {};
	void print() override;
	void sendEmail() override;
};


class ISP : public SolidPrinciple
{
public:
	ISP() :SolidPrinciple("Example : Interface segregation principle") {};
	void startPrinciple() override;
};

