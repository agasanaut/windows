// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

template < typename T >
class SmartPtr
{
    T* ptr = nullptr;
    int* count = nullptr;
public:
    explicit SmartPtr(T* p ):
        ptr(p)
    {
        if (!count)
        {
            count = new int(0);
        }
    }

    SmartPtr(const SmartPtr& obj)
    {
        ptr = obj.ptr;
        count = obj.count;
        ++(*count);
    }

    ~SmartPtr()
    {
        if (count)
        {
            if (--(*count) == 0)
            {
                delete count;
                count = nullptr;

                if (ptr)
                {
                    delete ptr;
                    ptr = nullptr;
                }
            }
        }
    }

    T& operator *()
    {
        return *ptr;
    }

    T& operator =(const T& obj)
    {
        if (&obj == this)
        {
            return *this;
        }

        if (ptr)
        {
            delete ptr;
            ptr = obj.ptr;
            count = obj.count;
            ++(*count);
        }

        return *ptr;
    }


};


int main()
{
    SmartPtr<int> iPtr(new int(5));
    *iPtr = 6;
    cout << *iPtr;

    SmartPtr<int> iPtr2(iPtr);
    cout << *iPtr2;

    SmartPtr<int> iPtr3(new int(6));
    iPtr3 = iPtr2;
    cout << *iPtr3;
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
