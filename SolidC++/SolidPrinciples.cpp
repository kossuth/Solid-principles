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


    //Start example
    //SRP srp("Example : Single responsibility principle");
    //solid.push_back(&srp);

    //OCP ocp("Example : Open/closed principle");
    //solid.push_back(&ocp);

    //LSP lsp("Example : Liskov substitution principle");
    //solid.push_back(&lsp);

     //ISP isp("Example : Interface segregation principle");
    //solid.push_back(&isp);

     //DIP dip("Example : Dependency inversion principle");
    //solid.push_back(&dip);
    
    
    //Other example:
    solid.push_back((SolidPrinciple*)(new SRP("Example : Single responsibility principle")));
    solid.push_back((SolidPrinciple*)(new OCP("Example : Open/closed principle")));
    solid.push_back((SolidPrinciple*)(new LSP("Example : Liskov substitution principle")));
    solid.push_back((SolidPrinciple*)(new ISP("Example : Interface segregation principle")));
    solid.push_back((SolidPrinciple*)(new DIP("Dependency inversion principle")));

    start(solid);

}

//Video https://www.youtube.com/watch?v=YslS8105XCw