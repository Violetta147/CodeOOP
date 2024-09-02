#include <bits/stdc++.h>

using namespace std;

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
            cout << "Memory is not enough\n";
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
            cout << "Memory is not enough\n";
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
            cout << "The Stack is full! Proceed to double the size\n";
            resize(2 * capacity);
        }
        arr[++top] = x;
    }

    // Pop function 
    int Pop()
    {
        if (isEmpty())
        {
            cout << "The Stack is empty!\n";
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

// Function to convert decimal to hexadecimal using stack (LIFO)

string decToHex1(int decimal)
{
    Stack stack(10);
    string hexDigits = "0123456789ABCDEF";
    string result;

    while (decimal > 0)
    {
        int rem = decimal % 16; // 0 - 15
        stack.Push(rem);
        decimal /= 16;
    }

    cout << "Stack: ";
    stack.show();
    while (!stack.isEmpty())
    {
        result += hexDigits[stack.Pop()];
    }

    return result;
}

string decToHex2(int decimal)
{
    Stack stack(10);
    string hex = "";
    while (decimal > 0)
    {
        int rem = decimal % 16;
        if (rem < 10)
        {
            stack.Push(rem + 48);
        }
        else
        {
            stack.Push(rem + 55);
        }
        decimal /= 16;
    }
    cout << "Stack: ";
    stack.show();
    while (!stack.isEmpty())
    {
        hex += stack.Pop();
    }
    return hex;
}

int main() {
    int dec;
    cout << "Enter a number in decimal: ";
    cin >> dec;
    string hex = decToHex1(dec);
    cout << "The number converted to hexadecimal is: " << hex << endl;
    hex = decToHex2(dec);
    cout << "The number converted to hexadecimal is: " << hex << endl;
    return 0;
}

