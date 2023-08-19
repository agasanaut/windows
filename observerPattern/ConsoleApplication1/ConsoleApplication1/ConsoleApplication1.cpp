// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
using namespace std;



class Observer
{
public:
	virtual void update() = 0;

};

class Observer1 : public Observer
{
public:
	void update()
	{
		cout << "update obs 1" << endl;
	}

};

class Observer2 : public Observer
{
public:
	void update()
	{
		cout << "update obs 2" << endl;
	}

};

class Subject
{
	std::set<Observer*> observerList;

public:
	void registerObserver(Observer* obs)
	{
		observerList.insert(obs);
	}

	void unregisterObserver(Observer* obs)
	{
		observerList.erase(obs);
	}
	void notify()
	{
		for (auto& ob : observerList)
		{
			ob->update();
		}
	}
};

int main()
{
	Subject sb;
	Observer1 ob1;
	Observer2 ob2;

	sb.registerObserver(&ob1);
	sb.registerObserver(&ob2);
	sb.notify();

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
