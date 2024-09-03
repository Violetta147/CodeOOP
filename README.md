# OOP Constructor & Destructor 

- Cài đặt lớp ngăn xếp Stack dùng mảng động với các hàm: 
  - hàm dựng 
  - hàm dựng sao chép 
  - hàm hủy 
  - hàm Push để đẩy phần tử vào ngăn xếp 
  - hàm Pop để lấy phần tử ra khỏi ngăn xếp 
  - hàm kiểm tra ngăn xếp rỗng isEmpty() 
  - kiểm tra ngăn xếp đầy isFull().
- Viết chương trình ứng dụng lớp Stack để đổi một số nguyên từ hệ thập phân (10) sang hệ thập lục phân (16).

string Binary(long long num)
{   
    string res = "";
    Stack s(10);

    int place_value = 1;
    while (!(num == 0 || num == -1))
    {
        int lastBit = num & 1;
        num = num >> 1;
        s.Push(lastBit * place_value);
        place_value *= 10;
    }
    cout << "Stack: ";
    s.show();
    while (!s.isEmpty())
    {
        res += to_string(s.Pop());
    }
    return res;
}

string TwoComplement(long long num)
{
    string binaryStr = Binary(num);

    if (num >= 0)
    {
        return binaryStr;
    }

    string flippedStr = "";
    for (int i = 0; i < binaryStr.length(); i++)
    {
        flippedStr += binaryStr[i] == '0' ? '1' : '0';
    }

    Stack s(10);
    int carry = 1;
    for (int i = flippedStr.length() - 1; i >= 0; i--)
    {
        int bit = flippedStr[i] - '0';
        int sum = bit + carry;
        s.Push(sum % 2);
        carry = sum / 2;
    }

    string res = "";
    while (!s.isEmpty())
    {
        res += to_string(s.Pop());
    }
    return res;
}
string Binary(long long num)
{
    string res = "";
    Stack s(10);

    while (num > 0)
    {
        int lastBit = num & 1;
        num = num >> 1;
        s.Push(lastBit);
    }
    cout << "Stack: ";
    s.show();
    while (!s.isEmpty())
    {
        res += to_string(s.Pop());
    }
    return res;
}

string TwoComplement(long long num)
{
    string binaryStr = Binary(num);

    if (num >= 0)
    {
        return binaryStr;
    }

    string flippedStr = "";
    for (int i = 0; i < binaryStr.length(); i++)
    {
        flippedStr += binaryStr[i] == '0' ? '1' : '0';
    }

    Stack s(10);
    int carry = 1;
    for (int i = flippedStr.length() - 1; i >= 0; i--)
    {
        int bit = flippedStr[i] - '0';
        int sum = bit + carry;
        s.Push(sum % 2);
        carry = sum / 2;
    }

    string res = "";
    while (!s.isEmpty())
    {
        res += to_string(s.Pop());
    }
    return res;
}

