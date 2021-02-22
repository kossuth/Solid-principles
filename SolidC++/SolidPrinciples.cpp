// SolidPrinciples.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "SRP.h"
#include "OCP.h"
#include "LSP.h"
#include "ISP.h"
#include "DIP.h"

void start(list<SolidPrinciple*> principles) {
    for (SolidPrinciple* principle : principles)
    {
        principle->startPrinciple();
    }
}


int main()
{

    list<SolidPrinciple*> solid;


    //Start 
    //"Example : Single responsibility principle"
    //SRP srp();
    //solid.push_back(&srp);

    //"Example : Open/closed principle"
    //OCP ocp();
    //solid.push_back(&ocp);

    //"Example : Liskov substitution principle"
    //LSP lsp();
    //solid.push_back(&lsp);

    //"Example : Interface segregation principle"
    //ISP isp();
    //solid.push_back(&isp);

    //"Example : Dependency inversion principle"
    //DIP dip();
    //solid.push_back(&dip);
    
    
    //Other example:
    solid.push_back((SolidPrinciple*)(new SRP()));
    solid.push_back((SolidPrinciple*)(new OCP()));
    solid.push_back((SolidPrinciple*)(new LSP()));
    solid.push_back((SolidPrinciple*)(new ISP()));
    solid.push_back((SolidPrinciple*)(new DIP()));

    start(solid);

}

//Video https://www.youtube.com/watch?v=YslS8105XCw