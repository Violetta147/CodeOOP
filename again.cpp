#include <bits/stdc++.h>

using namespace std;
typedef unsigned int u_int;
#define MAX_STRING_LENGTH 1000
const string RED = "\033[1;31m"; // Red color & bold
const string YELLOW = "\033[1;33m"; // Yellow color & bold 
const string RESET = "\033[0m"; // Reset graphic

class Stack
{

private:
    int *arr;
    int top; // chi so cua phan tu tren cung cua stack
    int capacity;

    // Function to resize the stack
    void resize(int newCapacity)
    {
        int *newArr = new int[newCapacity];
        if (newArr == nullptr)
        {   
            cout << RED;
            cout << "Memory is not enough\n";
            cout << RESET;
            exit(-1);
        }
        for (int i = 0; i <= top; ++i)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

public:
    //Default Constructor
    Stack() : arr(new int[10]), top(-1), capacity(10) {}
    // Constructor
    Stack(int n) : arr(new int[n]), top(-1), capacity(n) {}

    // Copy Constructor
    Stack(const Stack &other) : arr(new int[other.capacity]), top(other.top), capacity(other.capacity)
    {
        for (int i = 0; i <= other.top; ++i)
        {
            arr[i] = other.arr[i];
        }
    }

    // Copy Assignment aka "=" Operator
    Stack &operator=(const Stack &other)
    {
        if (this == &other)
        {
            return *this; // Case: self-assignment s1 = s1;
        }
        // Free existing memory
        delete[] arr;

        // Allocate new memory and copy data
        arr = new int[other.capacity];
        if (arr == nullptr)
        {   
            cout << RED;
            cout << "Memory is not enough\n";
            cout << RESET;
            exit(-1);
        }
        top = other.top;
        capacity = other.capacity;
        for (int i = 0; i <= other.top; ++i)
        {
            arr[i] = other.arr[i];
        }
        return *this;
    }

    // Destructor
    ~Stack()
    {
        delete[] arr;
    }

    // Push function
    void Push(int x)
    {
        if (isFull())
        {   
            cout << YELLOW;
            cout << "The Stack is full! Proceed to double the size\n";
            cout << RESET;
            resize(2 * capacity);
        }
        arr[++top] = x;
    }

    // Pop function
    int Pop()
    {
        if (isEmpty())
        {   
            cout << RED;
            cout << "The Stack is empty!\n";
            cout << RESET;
            return -1;
        }
        return arr[top--];
    }

    // IsEmpty function
    bool isEmpty() const
    {
        return top == -1; // Neu top = -1 thi stack rong
    }
    // IsFull function
    bool isFull() const
    {
        return top == capacity - 1; // Neu top = capacity - 1 thi stack day
    }

    // Show stack in LIFO order
    void show()
    {
        for (int i = top; i >= 0; --i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

string DecimalToHex(long long num)
{       
    const char hexLookupTable[] = "0123456789ABCDEF";
    bool isNegative = false;
    
    if (num < 0)
    {
        num = ~num + 1;
        isNegative = true;
    }

    Stack s(64);
    while(num > 0)
    {
        
    }
}

int main()
{
    long long num = -10;
    DecimalToHex(num);
    return 0;
}


