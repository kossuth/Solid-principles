#pragma once
#include <ctime>
#include <iostream>
#include <string>
#include <list>
using namespace std;
struct IGetTime
{
public:
	string getDateFormatFromTime(time_t _date) {

		struct tm ts;
		char       buf[80];

		//For test Time = now
		if (!_date) {
			_date = time(NULL);
		}

		/* Format and print the time, "ddd yyyy-mm-dd hh:mm:ss zzz" */
		localtime_s(&ts, &_date);
		strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", &ts);
		return buf;
	}
};
class SolidPrinciple
{
private:
		string _name;
public:
	SolidPrinciple(string name) :_name(name) {};
	string getName() { return _name; };
	virtual void startPrinciple()=0;
};
