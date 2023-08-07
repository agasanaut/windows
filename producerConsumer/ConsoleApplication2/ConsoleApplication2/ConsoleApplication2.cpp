// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <windows.h>
#include <condition_variable>
using namespace std;
bool produced = false;
mutex m;
std::condition_variable cv;

void producer()
{
    cout << "produced" << std::endl;
    produced = true;
    cv.notify_one();
}

void consumer()
{
    std::unique_lock<std::mutex> ul(m);

    while (produced == false)
    {
        cv.wait(ul);
    }

    cout << "consumed" << std::endl;
}

int main()
{
    thread t2(consumer);
    Sleep(1000);
    thread t1(producer);



    if (t1.joinable())t1.join();
    if (t2.joinable())t2.join();

    return 0;
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
