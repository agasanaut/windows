#include <iostream>

class Singleton
{
private:
    static Singleton* obj;
    Singleton() {}
public:
    static Singleton* getInstance()
    {
        if (obj == nullptr)
        {
            obj = new Singleton();
        }
        return obj;
    }
};

Singleton* Singleton::obj = nullptr;

int main()
{
    Singleton::getInstance();
    std::cout << "Singleton obj created !!!\n";
}

