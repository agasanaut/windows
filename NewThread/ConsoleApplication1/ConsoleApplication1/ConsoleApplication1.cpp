// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <windows.h>

using namespace std;



int main()
{
	std::mutex m;

	thread t1([]() { 
	while (1)
	{
	
		cout << ".";
		Sleep(1000);
	}
	});


	thread t2([]() { 
		while (1)
		{
			cout << "-";
			Sleep(1000);
		}});

	if (t1.joinable())
	{
		t1.join();
	}

	if (t2.joinable())
	{
		t2.join();
	}

	return EXIT_SUCCESS;
}

