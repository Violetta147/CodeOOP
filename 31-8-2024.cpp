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

// Function to convert decimal to hexadecimal using stack (LIFO)

// positive & lookup table idea
string decToHex1(long long decimal)
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
// positive & ASCII value '0' = 48, 'A' = 65
string decToHex2(long long decimal)
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
//positive and negative
string Hex(long long num)
{

    // check if num is 0 and return 0
    if (!num)
    {
        return "0";
    }

    // map for dec --> hex 0-9 & 10-15(A-F)
    map<int, char> m;
    char digit = '0';
    char c = 'A';
    for (int i = 0; i < 16; i++)
    {
        if (i < 10)
        {
            m[i] = digit++;
        }
        else
        {
            m[i] = c++;
        }
    }
    string res = "";
    Stack s(10);

    // convert decimal to hex
    if (num > 0)
    {
        while (num > 0)
        {
            s.Push(num % 16);
            num /= 16;
        }
    }
    // if num < 0
    else
    {
        // Store num in a u_int, most significant bit is 1
        unsigned long long n = num;
        while (n)
        {
            s.Push(n % 16);
            n /= 16;
        }
    }
    cout << "Stack: ";
    s.show();
    // pop from stack and add to res
    while (!s.isEmpty())
    {
        res += m[s.Pop()];
    }
    return res;
}
//positive and negative using unordered_map (lookup table)
string Hex2(long long num) {

    if (num == 0) {
        return "0";
    }
    unordered_map<int, char> hexLookupTable {
        {0, '0'}, {1, '1'}, {2, '2'}, {3, '3'},
        {4, '4'}, {5, '5'}, {6, '6'}, {7, '7'},
        {8, '8'}, {9, '9'}, {10, 'A'}, {11, 'B'},
        {12, 'C'}, {13, 'D'}, {14, 'E'}, {15, 'F'}
    };
    string res = "";
    Stack s(10);
    if (num > 0) {
        while (num) {
            s.Push(num % 16);
            num /= 16;
        }
    }
    else {
        unsigned long long n = static_cast<unsigned long long>(num);
        while (n) {
            s.Push(n % 16);
            n /= 16;
        }
    }
    cout << "Stack: ";
    s.show();
    while (!s.isEmpty()) {
        res += hexLookupTable[s.Pop()];
    }
    return res;
}

bool parseInt(char* string, long long *num)
{   
    //Check if user enter 'enter'
    if (string[0] == '\n')
    {
        return false;
    }
    int stringLength = strlen(string);
    //Remove leading white spaces
    int startSliceIndex = 0;
    for (int i = 0; i < stringLength; i++)
    {
        if (string[i] != ' ' && string[i] != '\t' && string[i] != '\n')
        {
            startSliceIndex = i;
            break;
        }
    }
    //Remove trailing white spaces
    int endSliceIndex = stringLength - 1;
    for (int i = stringLength - 1; i >= 0; i--)
    {
        if (string[i] != ' ' && string[i] != '\t' && string[i] != '\n')
        {
            endSliceIndex = i;
            break;
        }
    }
    // Extract the string without white spaces
    char *newString = new char[endSliceIndex - startSliceIndex + 1];
    int newStringLength = 0;
    for (int i = startSliceIndex; i <= endSliceIndex; i++)
    {
        newString[newStringLength++] = string[i];
    }
    newString[newStringLength] = '\0'; // Null-terminate the string

    // Check if the string is negative number
    bool isNegative = false;
    if (newString[0] == '-')
    {
        isNegative = true;
        
        // Remove the negative sign
        newStringLength--;
        for (int i = 0; i < newStringLength; i++)
        {
            newString[i] = newString[i + 1];
        }
    }

    // Check if the string is empty
    if (newStringLength == 0)
    {
        return false;
    }

    // Check if the string contains only digits by using ASCII values
    for (int i = 0; i < newStringLength; i++)
    {
        if (newString[i] < '0' || newString[i] > '9')
        {
            return false;
        }
    }
    // Convert the string to an integer
    *num = 0;
    for (int i = 0; i < newStringLength; i++)
    {
        int digit = newString[i] - '0'; // Example '5' - '0' = 5 => 53 - 48 = 5
        if (isNegative)
        {
            long long nextNum = *num * 10 - digit; // Example: -123 = 0 * 10 - 1 = -1 * 10 - 2 = -12 * 10 - 3 = -123
            if (nextNum > *num)
            {   
                // Overflow
                cout << RED;
                cout << "Error: Integer Overflow\n";
                cout << RESET;
                return false;
            }
            *num = nextNum;
        }
        else
        {
            long long nextNum = *num * 10 + digit; // Example: 123 = 0 * 10 + 1 = 1 * 10 + 2 = 12 * 10 + 3 = 123
            if (nextNum < *num)
            {   
                cout << RED;
                cout << "Error: Integer Overflow\n";
                cout << RESET;
                return false;
            }
            *num = nextNum;
        }
    }
    return true;
}

bool input(const char* question, char* string)
{
  cout << question;
    cin.getline(string, MAX_STRING_LENGTH);
    if (strlen(string) > 0)
    {
        return true;
    }
    return false;
}

void inputLongLong (const char* question, long long *num)
{
    bool isValid = false;
    while (!isValid)
    {
        char* temp = new char[MAX_STRING_LENGTH];
        isValid = input(question, temp) && parseInt(temp, num);
        if (!isValid)
        {   
            cout << RED;
            cout << "Please enter integer!\n";
            cout << RESET;
        }
        delete[] temp;
    }
}
int main()
{   
    long long num;
    inputLongLong("Enter a decimal number: ", &num);
    // cout << "Decimal: " << num << endl;
    // cout << "Hexadecimal: " << decToHex1(num) << endl;
    // cout << "Hexadecimal: " << decToHex2(num) << endl;
    // cout << "Hexadecimal: " << Hex(num) << endl;
    // cout << "Hexadecimal: " << Hex2(num) << endl;
    string binary = Binary(num);
    cout << "Binary: " << binary << endl;
    cout << "Two's Complement: " << TwoComplement(num) << endl;
    return 0;
}
