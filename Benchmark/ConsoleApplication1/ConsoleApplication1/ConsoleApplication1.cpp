// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <windows.h>
#include "Instrumentor.h"

using namespace std;

void myFunc()
{
    InstrumentationTimer timer("myFunc");   // Place code like this in scopes you'd like to include in profiling
    // Code

    Sleep(2000);
}


void myFunc1()
{
    InstrumentationTimer timer("myFunc1");   // Place code like this in scopes you'd like to include in profiling

    // Code

    Sleep(1000);
}

int main()
{
   Instrumentor::Get().BeginSession("Session Name");        // Begin session 
 {

    std::thread t1 ( myFunc);
    std::thread t2(myFunc1);

    t1.join();
    t2.join();
 }
 Instrumentor::Get().EndSession();   

    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
