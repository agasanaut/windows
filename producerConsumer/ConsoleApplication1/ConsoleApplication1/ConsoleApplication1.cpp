// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <windows.h>
#include <condition_variable>

using namespace std;

mutex m;
condition_variable cv;

bool ready = false;

void threadProducer()
{
	while (1)
	{
		std::unique_lock<mutex>uLock(m);
		cv.wait(uLock, []() {return(ready == false); });

		cout << "Producer" << std::endl;
		Sleep(1000);
		ready = true;

		uLock.unlock();
		cv.notify_all();
	}
}

void threadConsumer()
{
	while (1)
	{
		std::unique_lock<mutex>uLock(m);
		cv.wait(uLock, []() {return(ready == true); });

		cout << "Consumer" << std::endl;
		Sleep(1000);
		ready = false;
		uLock.unlock();

		cv.notify_all();
	}
}


int main()
{
	thread t2(threadConsumer);
	thread t1(threadProducer);


	if (t1.joinable()) {
		t1.join();
	}

	if (t2.joinable()) {
		t2.join();
	}

	return EXIT_SUCCESS;
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
