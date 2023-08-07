#include <iostream>
#include <mutex>
using namespace std;

class Singleton
{
private:
	static Singleton* obj;
	Singleton() {}
	static mutex m;
public:
	static Singleton* getInstance()
	{
		if (obj == nullptr)
		{
			lock_guard<mutex>lg(m);
			if (obj == nullptr)
			{
				obj = new Singleton();
			}
		}
		return obj;
	}
};

Singleton* Singleton::obj = nullptr;
mutex Singleton::m;

int main()
{
	auto obj1 = Singleton::getInstance();
	auto obj2 = Singleton::getInstance();
	std::cout << "Singleton obj created - !!!\n" << "  " << obj1 << " , " << obj2;
	return EXIT_SUCCESS;
}

